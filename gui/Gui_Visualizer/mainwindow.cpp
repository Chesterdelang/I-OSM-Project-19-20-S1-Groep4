#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->popup->close();

    valueCombobox = ui->styleEdit->currentText();

    ui->titleLabel->setText(valueCombobox);
    ui->titleLabel_2->setText(valueCombobox);
    qDebug() << valueCombobox;
    if(valueCombobox == "Basic"){
        QPushButton *buttons[8];
        for(int i =0; i<8; ++i ){
            QString buttonName = "Button"+ QString::number(i);
            buttons[i] = MainWindow::findChild<QPushButton *>(buttonName);
            connect(buttons[i], SIGNAL(clicked()), this, SLOT(openPopUp()));
        }
    }else if(valueCombobox == "Luxe"){
        QPushButton *buttons[11];
        for(int i =0; i<11; ++i ){
            QString buttonName = "Button"+ QString::number(i+8);
            buttons[i] = MainWindow::findChild<QPushButton *>(buttonName);
            connect(buttons[i], SIGNAL(clicked()), this, SLOT(openPopUp()));
          }
   }
    ui->exitPopup->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//handeling of the continue button
//it checks the requirements before continueing to the next screen
void MainWindow::on_continueButton_clicked()
{
    QString sysName = ui->nameEdit->text();
    unsigned long long duration = ui->durationEdit->text().toInt();
    std::string timeText = CalculateTime(duration);
    setSimulationTime(timeText);
    QString valueCombobox;
    ui->titleLabel->setText(ui->nameEdit->text());
    ui->titleLabel_2->setText(ui->nameEdit->text());
    valueCombobox = ui->styleEdit->currentText();
    if(sysName == ""){
        QString warning = "Insert a name";
        ui->warning->setText(warning);
 /*}else if(duration.contains("-")){
        QString warning = "Duration can't be negative";
       ui->warning->setText(warning); */
    }else if(!jsonFile){
        QString warning = "No JSON file selected!";
        ui->warning->setText(warning);
    }else if(valueCombobox == "Basic"){
        ui->stackedWidget->setCurrentIndex(1);
        screenName = "Basic";
    }else if(valueCombobox == "Luxe"){
        ui->stackedWidget->setCurrentIndex(2);
        screenName = "Luxe";
    }
}

//handeling of the load button
//checks if the selected file is a JSON
void MainWindow::on_actionLoad_triggered()
{
    if(ui->stackedWidget->currentIndex() == 0){
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text) || !currentFile.contains(".json"))
    {
        jsonFile = false;
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
    }else{
        jsonFile = true;
    }

    //if statement die basic en deluxe machines selecteerd.
//    if(style == "basic"){
//        Machine basic("Basic",1,2,3,4,5,6,7,8,9);
//        mConfig.readJSONData(currentFile, s, basic);
//    }else if(style == "luxe"){
//        Machine luxe("Luxe",10,11,12,2,3,4,5,6,13,7,14,15);
//        mConfig.readJSONData(currentFile, s, luxe);
//    }

//    Machine test("TEST123", 1, 123, 123, 123, 123, 123, 123); //staat ook in save
//    std::vector<Machine> s;



    file.close();
    }


}

//Handeling for the save button
void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }

//    Machine test("TEST123", 1, 123, 123, 123, 123, 123, 123); //staat ook in load
//    mConfig.saveJSONData("machineconfiguration.json", test);

    file.close();
}

//handeling of the exit button
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

//handeling of the start button
void MainWindow::on_actionStart_triggered()
{
    ui->Button1->setStyleSheet("background-color: #00FF00;");
}

//handeling of the stop button
void MainWindow::on_actionStop_triggered()
{
    ui->Button1->setStyleSheet("background-color: #FF0000;");
}

//handeling of the pause button
void MainWindow::on_actionPause_triggered()
{

}

//handeling of the update buffer
void MainWindow::updateBufferValue(int aValue){
    ui->bufferValue->setText(QString::number(aValue));
}

//handeling of the update downtime
void MainWindow::updateDowntimeValue(int aValue){
    ui->minutes->setText(QString::number(aValue));
}

//handeling of the update downtime bar
void MainWindow::updateDowntimeProgressBar(int aValue){
    ui->dowtimeBar->setValue(aValue);
}

//handeling of the update duration bar
void MainWindow::updateDurationProgressBar(int aValue){
    ui->simulationTimeBar->setValue(aValue);
}

//handeling of the openPopUp
void MainWindow::openPopUp(){
    ui->popup->show();
    updateBufferValue(5);
    updateDowntimeValue(25);
    updateDowntimeProgressBar(50);
}

//handeling of the calculate time
std::string MainWindow::CalculateTime(double time){
        std::string timeType;
        time = time/60;
        if(time >= 24){
            time = time/24;
            if(time >= 365){
                time = time/365;
                timeType = roundDouble(time) + "year(s)";
                std::cout << timeType;
                return timeType;
            }else{
                timeType = roundDouble(time) + " day(s)";
                return timeType;
            }
        }else{
            timeType = roundDouble(time) + " hour(s)";
            return timeType;
        }
    }

//handeling of the set simulation time
void MainWindow::setSimulationTime(std::string aText){
    QString strTime = QString::fromStdString(aText);
    ui->timeVariableLabel->setText(strTime);
    ui->timeVariableLabel_2->setText(strTime);
}

//handeling of the set downtime
void MainWindow::setDowntime(std::string aText){
    QString strTime = QString::fromStdString(aText);
    ui->downtime->setText(strTime);
}

//handeling of the action menu
void MainWindow::on_actionMenu_triggered()
{
    ui->exitPopup->show();
}

//handeling of the popup exit button
void MainWindow::on_popupExitButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->exitPopup->close();
}

//handeling of the popup continue button
void MainWindow::on_popupContinueButton_clicked()
{
    ui->exitPopup->close();
}

//handeling of the push button
void MainWindow::on_pushButton_clicked()
{
    ui->popup->close();
}

//function for rounding doubles to three points decimal
std::string MainWindow::roundDouble(double time){
    std::ostringstream roundedNumber;
    std::string timeType;
    roundedNumber << std::fixed;
    roundedNumber << std::setprecision(3);
    roundedNumber << time;
    timeType = roundedNumber.str();
    return timeType;
}
