#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QCheckBox>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();


private slots:

    void switching();

    void on_LED_Shining_clicked();

    void on_LED_Switching_clicked();

    void keyPressEvent(QKeyEvent *k);

    void on_LED_Switching_off_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
