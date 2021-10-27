#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Line{
public:
    void DDALine(int, int, int, int, Ui::MainWindow*);
};

class Fill: public Line{
public:
    void ScanFill(Ui::MainWindow*);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    void on_plotLineButton_clicked();

    void on_scanLineButton_clicked();

    void on_colorSelectButton_clicked();

    void on_clearButton_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;
    ~MainWindow();
    Fill obj;
};



#endif // MAINWINDOW_H
