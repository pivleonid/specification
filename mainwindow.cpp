#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include "activeword.h"
#include "activeexcel.h"
#include "datastorage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButtonPath, SIGNAL(clicked(bool)), this, SLOT(path()));
    connect(ui->pushButtonLoad, SIGNAL(clicked(bool)), this, SLOT(load()));
    connect(ui->pushButtonStart, SIGNAL(clicked(bool)), this, SLOT(startOperation()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startOperation(){
    if(ui->lineEditName->text() == ""){
        MainWindow::mesOut("Не выбрано имя файла");
        return;
    }
    if(ui->labelName->text() == ""){
        mesOut("Загрузите исходный файл");
        return;
    }
    if(ui->labelPath->text() == ""){
        mesOut("Не выбрано местоположение выходного файла");
        return;
    }
    ActiveWord word;
      if(!word.wordConnect()){
          QMessageBox msgBox;
          msgBox.setText("Word не установлен");
          msgBox.exec();
          return;
        }
    QAxObject* doc1 = word.documentOpen(QApplication::applicationDirPath() + "/spec.docx");
    QString s = QApplication::applicationDirPath() + "/spec.docx";
    if(doc1 == NULL){
        QMessageBox msgBox;
          msgBox.setText("Не найден word- шаблон");
          msgBox.exec();
      return;
      }
    ActiveExcel excel;
    if(!excel.excelConnect()){
        QMessageBox msgBox;
          msgBox.setText("Не установлен Excel");
          msgBox.exec();
        return;
      }
    QCoreApplication::processEvents(); // обновление GUI

    QAxObject* ex1 = excel.workbookOpen(ui->labelName->text());
    if(ex1 == NULL){
        QMessageBox msgBox;
          msgBox.setText("Невозможно открыть книгу");
          msgBox.exec();
      return;
      }

    //Поиск индекса столбца
    QString name = excel.sheetName().toString();
    QAxObject* sheet = excel.workbookSheetActive(name);
    QVariant data;
    int line = 0;// номер строки, в которой есть  Ref Designator, Part Number и QTY (кол-во)
    int refDez = 0;
    int partNumber = 0;
    int qty = 0;
    int description = 0;
    int manufacturer = 0;
    dataStorage storage;
    QString partNumberString;
    //В каждом документе в первом столбце есть #, после которой идут элементы
    for (int i = 1; i < 100 ; i++){
        if (excel.sheetCellInsert(sheet, data, i, 1)){
            if (data.toString() == "#"){
                line = i;
                //строка найдена, теперь ищу колонки
                for (int i = 1;i <100 ; i++){
                    if (excel.sheetCellInsert(sheet, data, line, i)){
                        if(data == "Ref Designator")
                            refDez = i;
                        if(data == "Part Number")
                            partNumber = i;
                        if(data == "QTY")
                            qty = i;
                        if(data == "Manufacturer")
                            manufacturer = i;
                        if(data == "Description")
                            description = i;
                        if((refDez != 0) && (partNumber != 0) && (qty != 0) && (manufacturer != 0) && (description != 0))
                            break;
                    }
                    else  mesOut("Ошибка обработки BOM данных!");
                }
                break;
            }
        }
        else  mesOut("Ошибка обработки BOM данных!") ;
    }
    //Чтение данных
    for(int i = line + 1; i < 50 ; i++){
        QVariant refN, partNumberN, qtyN, manufacturerN, descriptionN ;
        if (excel.sheetCellInsert(sheet, data, i, refDez))
            refN = data;
        else   mesOut("Ошибка обработки BOM данных!");
        if (excel.sheetCellInsert(sheet, data, i, partNumber)){
            partNumberN = data;
        }
        else   mesOut("Ошибка обработки BOM данных!");
        if (excel.sheetCellInsert(sheet, data, i, qty)){
            qtyN = data;
        }
        else mesOut("Ошибка обработки BOM данных!");
        if (excel.sheetCellInsert(sheet, data, i, description)){
            descriptionN = data;
        }
        else mesOut("Ошибка обработки BOM данных!");
        if (excel.sheetCellInsert(sheet, data, i, manufacturer)){
            manufacturerN = data;
        }
        else mesOut("Ошибка обработки BOM данных!");



        if(refN.toString() == "" && partNumberN.toString() == "" && qtyN.toString() == ""
                && manufacturerN.toString() == "" && descriptionN.toString() == "")
            break;
partNumberString.append(partNumberN.toString());
partNumberString.append(", ");
partNumberString.append(descriptionN.toString());
partNumberString.append(", " );
partNumberString.append(manufacturerN.toString());

       storage.insert(refN.toString(), partNumberString, qtyN.toInt() );
partNumberString.clear();


    }
    excel.workbookClose(ex1);
     QMap <QString, QList<TData> > data1 = storage.ret();
    int i;
    i++;
}

void MainWindow::load(){
    QString fileName_DATA = QFileDialog::getOpenFileName(this, tr("Open Excel File"),"", tr("(*.xlsx *.xls)"));
    if(fileName_DATA.count() == 0){
        return;
      }
    ui->labelName->setText(fileName_DATA);

}

void MainWindow::path(){
    QString pathData = QFileDialog::getExistingDirectory(this, tr("Выберите папку для сохранения"),QApplication::applicationDirPath());
    ui->labelPath->clear();
    ui->labelPath->setText(pathData);
}


