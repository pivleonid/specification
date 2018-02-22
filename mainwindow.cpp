#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextCodec>
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
    for (int i = 1; i < 50 ; i++){
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
    for(int i = line + 1; i < 500 ; i++){
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

     //Чтение известных групп
     QString  str;
     QFile file("Названия групп.txt");
     QTextCodec::codecForName("CP1251");
     if(file.open(QIODevice::ReadOnly |QIODevice::Text)){
         while (!file.atEnd()){
             QByteArray line = file.readLine();
             QTextCodec *codec = QTextCodec::codecForName("CP1251");
             str += codec->toUnicode(line);
         }
     }
     else qDebug()<< "don't open file";
     QStringList splitStr = str.split("\n");
     QMap<QString, QString> tem;
     foreach (auto st, splitStr) {
         QStringList split = st.split("-");
         tem[split[0]] = split[1];
     }

     ///
     /// \brief allBom



QMap <QString, QList<TData> >  allBom;
     foreach (auto key1, data1.keys()) {
         bool keyFound = false;
         foreach (auto key2, tem.keys()) {
             if(key1 == key2){
                 keyFound = true;
                 allBom[tem[key2]]; //копирую ключ
                 //копирую данные
                 allBom[tem[key2]].append( data1[key2]);
                 break;
             }
         }

         if(keyFound == false){
             allBom["Прочие"];
             allBom["Прочие"].append( data1[key1]);
             }
         }




     //теперь это дело надо перевести в QList<QStringList>  и засандалить в Word таблицу
     QList<QStringList> tableDat;
int j = 20; // число берется из gui
     foreach (auto key, allBom.keys()) {
         QStringList per;
         per << "" << "" << "" << ""  << "" << "" << "";
         tableDat << per;
         per.clear();
         per << "" << "" << "" << ""  << key << "" << "";
         tableDat << per;
         per.clear();
         per << "" << "" << "" << ""  << "" << "" << "";
         tableDat << per;
         per.clear();
         //i == кол-во TData
         for(int i = 0; i < allBom[key].count(); i++, j+=2){
             per << "" << "" ;
             per << QString::number(j);
             per << "" ;
             per << allBom[key][i].part;
             per << QString::number(allBom[key][i].counts);
             per << allBom[key][i].notes;
             tableDat << per;
             per.clear();
             per << "" << "" << "" << ""  << "" << "" << "";
             tableDat << per;
             per.clear();
           }
}
//
     //
     QList<QStringList> varList;// = tableDat; // шоб не похерить данные
// в 6 и 4 ячейках слов должно быть не больше 32 и 18 соответственно
//иначе word будет увеливать размер ячеек.
     for(int i = 0; i < tableDat.count(); i++){ //--------------------------------------------------------------------begin
     QString text = tableDat[i].at(6);
     QString note = tableDat[i].at(4);
     if(text == ""  || (text.count() < 18)){
         if(note == ""  || (note.count() < 32)){
          varList.append(tableDat[i]);
             continue;
         }
     }
     QString count = tableDat[i].at(5); // кол-во компоненов
     QString num = tableDat[i].at(2);   // порядковый номер в спецификации
      QStringList textL, textLout, noteL, noteLout;
      textL = text.split(" ");
      noteL = note.split(" ");
      textLout.append("");// заполняю пустыми значениями, чтобы можно было обратиться по индексу
      noteLout.append("");
      for(int i = 0, j = 0; i < textL.count(); i++){

          if((textLout[j].count() + textL[i].count()) < 18){

              textLout[j] += textL[i];
              continue;
          }
          else{
              textLout.append("");
              textLout[++j] += textL[i];
          }

      }
      for(int i = 0, j = 0; i < noteL.count(); i++){
          if((noteLout[j].count() + noteL[i].count()) < 32){

              noteLout[j] += noteL[i];
              continue;
          }
          else{
              noteLout.append("");
              noteLout[++j] += noteL[i];
          }

      }
      QList<QStringList> newline;
      QStringList per;
      //Где больше строк?
      int countNote = noteLout.count();
      int countText = textLout.count();
      if(countNote > countText){
        for(int i = 0; i < noteLout.count(); i++ ){
            if(i != 0)
                per << "" << "" <<"" << "";
            if(i == 0)
                per << "" << "" << num << "";
            per << noteLout[i];
            if( i == 0)
                per << count;
            if( i != 0)
                per << "";
            if(i < countText)
                per <<textLout[i];
            if(i >= countText)
                per << "";
            newline << per;
            per.clear();
        }
      }
      else{
          for(int i = 0; i < textLout.count(); i++ ){

              //1-4
              if(i != 0)
                      per << "" << "" <<"" << "";
              if(i == 0)
                      per << "" << "" << num << "";
              //5
              if(i < countNote)
                  per << noteLout[i];
              if(i >= countNote)
                  per << "";
              //6
              if( i == 0)
                  per << count;
              if( i != 0)
                  per << "";
              //7
              per <<textLout[i];
              newline << per;
              per.clear();
          }
        }


//исходную строку надо заменить на стройки newLine
    varList.append(newline);



      int jj;
      jj++;

     }//----------------------------------------------------------------------------------------------------------------end

     // делаю первый и второй лист с пустыми полями
     QStringList space;
     space << "" << "" << "" <<"" << "" << "" << "";
     for(int i = 0; i < 55; i++)
     varList.prepend(space);




     //Заполняю документ пустой таблицей до конца
        int count = varList.count();
        double z = floor((count - 25)/30);
        int x = count - ( 25 + z * 30);
        int lineAdd = 30 - x;
        for (int i = 0; i < lineAdd; i++)
            varList.append(space);

     QStringList listLabel;
    int ret = word.tableGetLabels(1, 2, listLabel);


    ret = word.tableFill(varList,listLabel,1,2) ;
word.setVisible();
     int ii;
     ii++;
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


