#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
