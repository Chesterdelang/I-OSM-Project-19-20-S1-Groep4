#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{


//    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
//    QFile file(fileName);
//    currentFile = fileName;
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
//    }

//        setWindowTitle(fileName);
//        QTextStream in(&file);
//        QString jsonFileText = in.readAll();
//        //ui->textEdit->setPlainText(text);
//        QString val = file.readAll();
//        file.close();


}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionStart_triggered()
{

}

void MainWindow::on_actionStop_triggered()
{

}

void MainWindow::on_actionPause_triggered()
{

}
