#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include <iostream>
#include <string>
#include <iomanip>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_continueButton_clicked();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionStart_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    /**
       * @brief update Buffer Value
       * \author Merel
       *
       * @param aValue
       *
       *  Updates the buffer value label
       */
    void updateBufferValue(int aValue);

    /**
       * @brief update downtime value
       * \author Merel
       *
       * @param aValue
       *
       *  Updates the downtime value label
       */
    void updateDowntimeValue(int aValue);

    /**
       * @brief update progress bar downtime
       * \author Merel
       *
       * @param aValue
       *
       *  Updates the progress bar for the downtime
       */
    void updateDowntimeProgressBar(int aValue);

    /**
       * @brief update progress bar duration
       * \author Merel
       *
       * @param aValue
       *
       *  Updates the progress bar for the duration
       */
    void updateDurationProgressBar(int aValue);

    /**
       * @brief Print downtime
       * \author Merel
       *
       * @param atext
       * @param strTime
       *
       *  Converts string to QString and prints it in the GUI
       */
    void openPopUp();

    /**
       * @brief Calculates minutes to another time type
       * \author Bram Stotijn
       *
       * @param time
       * @param timeType
       *
       *  This method calculates in which time type the time will be noted
       *  The time given is in minutes
       */
    std::string CalculateTime(double time);

    /**
       * @brief Print calculated time
       * \author Bram Stotijn
       *
       * @param aText
       * @param strTime
       *
       *  Converts string to QString and prints it in the GUI
       */
    void setSimulationTime(std::string aText);

    /**
       * @brief Print downtime
       * \author Bram Stotijn
       *
       * @param atext
       * @param strTime
       *
       *  Converts string to QString and prints it in the GUI
       */
    void setDowntime(std::string aText);

    void on_actionMenu_triggered();

    void on_popupExitButton_clicked();

    void on_popupContinueButton_clicked();

    void on_pushButton_clicked();

    /**
       * @brief round double
       * \author Bram Stotijn
       *
       * @param time
       * @param timeType
       *
       *  Rounds the time to three points decimal
       */
    std::string roundDouble(double time);

private:
    Ui::MainWindow *ui;
    QString currentFile;
    bool jsonFile = false;
    QString screenName;
    QString valueCombobox;
};

#endif // MAINWINDOW_HPP
