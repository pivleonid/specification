#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextCodec>
#include <QSettings>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButtonPath, SIGNAL(clicked(bool)), this, SLOT(path()));
    connect(ui->pushButtonLoad, SIGNAL(clicked(bool)), this, SLOT(load()));
    connect(ui->pushButtonStart, SIGNAL(clicked(bool)), this, SLOT(startOperation()));



ui->progressBar->setValue(0);
QFile file("spec.conf");
if(file.size() == 0)
  return;
QSettings settings( "spec.conf", QSettings::IniFormat );
settings.beginGroup( "LableName" );
QVariant text = settings.value("Razrab");
ui->lineEdit_Razrab->setText( text.toString());
text = settings.value("Prov");
ui->lineEdit_Proveril->setText( text.toString());
text = settings.value("Kontr");
ui->lineEdit_Hkontr->setText( text.toString());
text = settings.value("Ytb");
ui->lineEdit_Ytverdil->setText( text.toString());
text = settings.value("Firma");
ui->lineEdit_FirmaIzgotov->setText( text.toString());
text = settings.value("DecimltyiNomerIzdelia");
ui->lineEdit_DecimalNumber->setText( text.toString());
text = settings.value("naim1");
ui->lineEdit_Naimenovanie1->setText( text.toString());
text = settings.value("naim2");
ui->lineEdit_Naimenovanie2->setText( text.toString());
text = settings.value("numberStroki");
ui->lineEdit_Numeracia->setText( text.toString());
text = settings.value("nameFile");
ui->lineEditName->setText( text.toString());
text = settings.value("text1");
ui->labelName->setText( text.toString());
text = settings.value("text2");
ui->labelPath->setText( text.toString());
settings.endGroup();



}
void MainWindow::wordLabel(QAxObject *doc1, ActiveWord word){

            if( word.colontitulReplaseLabel(doc1, "[Разраб]", ui->lineEdit_Razrab->text(), true) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[пров]", ui->lineEdit_Proveril->text(), true) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[Наим.1]", ui->lineEdit_Naimenovanie1->text(), true) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[конт]", ui->lineEdit_Hkontr->text(), true) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[утв]", ui->lineEdit_Ytverdil->text(), true) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[Дец.Номер изд.]", ui->lineEdit_DecimalNumber->text(), true) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[Дец.Номер изд.]", ui->lineEdit_DecimalNumber->text(), false) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[Наим.2]", ui->lineEdit_Naimenovanie2->text(), true) < 0)
                mesOut("Ошибка замены метки");
            if( word.colontitulReplaseLabel(doc1, "[Фирма]", ui->lineEdit_FirmaIzgotov->text(), true) < 0)
                mesOut("Ошибка замены метки");

}


//-----------------------------------------------------------------
MainWindow::~MainWindow()
{
    QSettings settings( "spec.conf", QSettings::IniFormat );
       settings.beginGroup( "LableName" );
       settings.setValue( "Razrab", ui->lineEdit_Razrab->text() );
       settings.setValue( "Prov", ui->lineEdit_Proveril->text() );
       settings.setValue( "Kontr", ui->lineEdit_Hkontr->text() );
       settings.setValue( "Ytb", ui->lineEdit_Ytverdil->text() );
       settings.setValue( "Firma", ui->lineEdit_FirmaIzgotov->text() );
       settings.setValue( "naim1", ui->lineEdit_Naimenovanie1->text() );
       settings.setValue( "naim2", ui->lineEdit_Naimenovanie2->text() );
       settings.setValue( "numberStroki", ui->lineEdit_Numeracia->text() );
       settings.setValue( "DecimltyiNomerIzdelia", ui->lineEdit_DecimalNumber->text() );
       settings.setValue( "nameFile", ui->lineEditName->text() );
       settings.setValue( "text1", ui->labelName->text() );
       settings.setValue( "text2", ui->labelPath->text() );

       settings.endGroup();

    delete ui;
}
//-----------------------------------------------------------------
QMap <QString, QList<TData> > MainWindow::readExcel(int lines){
    QMap <QString, QList<TData> > ret;
    ActiveExcel excel;
    if(!excel.excelConnect()){
        QMessageBox msgBox;
        msgBox.setText("Не установлен Excel");
        msgBox.exec();
        return ret;
    }


    QAxObject* ex1 = excel.workbookOpen(ui->labelName->text());
    if(ex1 == NULL){
        QMessageBox msgBox;
        msgBox.setText("Невозможно открыть книгу");
        msgBox.exec();
        return ret;
    }
    ui->progressBar->setValue(5);
    QCoreApplication::processEvents(); // обновление GUI
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
    if (lines == 0){
        for(int i = line + 1; ; i++){
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
    }
    if (lines != 0){
        for(int i = line + 1; i < lines ; i++){
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
    }
    excel.workbookClose(ex1);
    return storage.ret();
}
//-----------------------------------------------------------------
QMap<QString, QString> MainWindow::readGroups(){
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
    return tem;
}
//-----------------------------------------------------------------
QList<QStringList> MainWindow::searchKey(QMap<QString, QList<TData> > &boms, QMap<QString, QString> groups){
 QMap<QString, QList<TData> > allBom;
 ui->textBrowser->setTextColor(Qt::red);
 ui->textBrowser->insertPlainText("Элементы со следующими RefDez отображены в разделе \"Прочие\":\n");
 ui->textBrowser->setTextColor(Qt::black);
 bool flag = false;
    foreach (auto key1, boms.keys()) {
        bool keyFound = false;
        foreach (auto key2, groups.keys()) {
            if(key1 == key2){
                keyFound = true;
                allBom[groups[key2]]; //копирую ключ
                //копирую данные
                allBom[groups[key2]].append( boms[key2]);
                break;
            }
        }

        if(keyFound == false){
            allBom["Прочие"];
            allBom["Прочие"].append( boms[key1]);
            ui->textBrowser->insertPlainText(key1 + "\n");
            flag = true;
            }
        }
    if(flag == false)
    ui->textBrowser->insertPlainText("Неизвестных компонентов нет\n");



    //теперь это дело надо перевести в QList<QStringList>  и засандалить в Word таблицу
    QList<QStringList> tableDat;
int j = ui->lineEdit_Numeracia->text().toInt(); // число берется из gui
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
       return varList;
}


//-----------------------------------------------------------------
void MainWindow::startOperation(){
    ui->progressBar->setValue(0);
    QApplication::processEvents();
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
    ui->pushButtonStart->setEnabled(false);
    ui->pushButtonPath->setEnabled(false);
    ui->pushButtonLoad->setEnabled(false);

QMap <QString, QList<TData> >  allBom;
ui->progressBar->setValue(0);
QApplication::processEvents();
allBom = readExcel(100);
ui->progressBar->setValue(20);
QApplication::processEvents();
if(allBom.isEmpty() == true){
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonPath->setEnabled(true);
    ui->pushButtonLoad->setEnabled(true);
    return;
}

QMap<QString, QString> tem;
tem = readGroups();
ui->progressBar->setValue(25);
QApplication::processEvents();
QList<QStringList>  varList = searchKey(allBom, tem);
ui->progressBar->setValue(30);
QApplication::processEvents();
wordLabel(doc1, word);
ui->progressBar->setValue(40);
QApplication::processEvents();
     QStringList listLabel;
    int ret = word.tableGetLabels(1, 2, listLabel);



//Заполнение word файла
    if( word.tableFill(varList,listLabel,1,2)< 0){
        mesOut("Ошибка заполнения таблицы!");
        ui->pushButtonStart->setEnabled(true);
        ui->pushButtonPath->setEnabled(true);
        ui->pushButtonLoad->setEnabled(true);
        word.setVisible();
        return;
    }
    word.documentSave(doc1, ui->labelPath->text() + "/", ui->lineEditName->text(), "docx" );
    ui->progressBar->setValue(100);
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonPath->setEnabled(true);
    ui->pushButtonLoad->setEnabled(true);
    QCoreApplication::processEvents();
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


