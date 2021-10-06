#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_plotLineButton_clicked();

    void on_scanLineButton_clicked();

    void on_colorSelectButton_clicked();

    void on_clearButton_clicked();

    void DDALine(int, int, int, int);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
