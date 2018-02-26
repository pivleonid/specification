#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "datastorage.h"
#include "activeword.h"
#include "activeexcel.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Чтение BOM файла. line- кол-во строк для отладки
    // line = 0 чтение всех данных
    QMap <QString, QList<TData> > readExcel(int line = 0);
    //Чтение групп.
    QMap<QString, QString> readGroups();
    //Замена ключей: "С" - кондернсаторы, "R" - "резисторы". Ежели ключ не найден- "Прочее"
    //И формирование контейнера для word'а
    QList<QStringList> searchKey(QMap<QString, QList<TData>>& boms,QMap<QString, QString> groups);
    //Заполнение меток
    void wordLabel(QAxObject* doc1, ActiveWord word);



    void mesOut(QString mes){
        QMessageBox msgBox;
           msgBox.setText(mes);
           msgBox.exec();
    }

public slots:
    void startOperation();
    void path();
    void load();
private:
     Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
