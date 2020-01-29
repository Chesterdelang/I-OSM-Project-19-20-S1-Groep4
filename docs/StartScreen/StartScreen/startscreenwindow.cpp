#include "startscreenwindow.hpp"
#include "ui_startscreenwindow.h"

startScreenWindow::startScreenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startScreenWindow)
{
    ui->setupUi(this);
QString buttonName = "continueButton";
    connect(startScreenWindow::findChild<QPushButton *>(buttonName), SIGNAL(released()), this, SLOT(continueButtonPressed()));
}

startScreenWindow::~startScreenWindow()
{
    delete ui;
}

void startScreenWindow::continueButtonPressed(){
QString sysName = ui->nameEdit->text();
QString style = ui->styleEdit->currentText();
QString duration = ui->durationEdit->text();
if(duration== "" && sysName == ""){
    QString warning = "Je bent alle velden vergeten in te vullen";
    ui->label_4->setText(warning);
}else if(duration==""){
    QString warning = "Je bent vergeten de duration in te vullen";
    ui->label_4->setText(warning);
}else if(sysName == ""){
    QString warning = "Je bent vergeten de naam in te vullen";
    ui->label_4->setText(warning);
}else{
    if(duration.contains("-")){
        QString warning = "De duration mag niet negatief zijn";
        ui->label_4->setText(warning);
    }else{
        //yeet naar t volgende scherm
        QString warning = "Volgende scherm";
                ui->label_4->setText(warning);
    }
}
}
