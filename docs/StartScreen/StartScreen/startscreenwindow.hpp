#ifndef STARTSCREENWINDOW_HPP
#define STARTSCREENWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class startScreenWindow;
}

class startScreenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit startScreenWindow(QWidget *parent = nullptr);
    ~startScreenWindow();

private:
    Ui::startScreenWindow *ui;

private slots:
   void continueButtonPressed();
};

#endif // STARTSCREENWINDOW_HPP
