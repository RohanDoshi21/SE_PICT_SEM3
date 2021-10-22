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
    void DDALine(float, float, float, float);
    int findRegionCode(double, double);
    void Clip(int, int, int, int);

private slots:
        void on_DrawPolygon_clicked();

        void on_DrawWindow_clicked();

        void mousePressEvent(QMouseEvent *event);

        void on_ClipButton_clicked();

        void on_ClearButton_clicked();

        void on_SelectColor_clicked();
        void on_DrawWindow_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
