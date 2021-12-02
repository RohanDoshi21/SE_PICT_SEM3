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
    void on_translate_clicked();
    void on_scaling_clicked();
    void on_rotation_clicked();
    void dda(float x1, float y1, float x2, float y2);
    void mousePressEvent(QMouseEvent *ev);
    void ClearScreen();

    void on_clear_clicked();

    void on_TRS_clicked();

    void on_SRT_clicked();

    void on_RTS_clicked();

private:
    Ui::MainWindow *ui;
    float x1,y1,x2,y2,tx,ty,sx,sy,x;
    float a[20],b[20];
    int ver;
    bool start;
};
#endif // MAINWINDOW_H
