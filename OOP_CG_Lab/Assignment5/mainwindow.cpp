#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QLabel>
#include <QMouseEvent>
#include <iostream>
using namespace std;
#define height 500
#define width 500
QImage img(500, 500, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage k(500, 500, QImage::Format_RGB888);
QRgb rgb(qRgb(355, 0, 255));

bool start = false;
bool isPoly = false;

int a[50];
int b[50];
int j = 0;

int d_x[2];
int d_y[2];

int x_max;
int x_min;
int y_max;
int y_min;

void MainWindow::DDALine(float x1, float y1, float x2, float y2)
{
    float dx, dy, step, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) >= abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }
    dx = dx / step;
    dy = dy / step;
    int i = 0;
    x = x1;
    y = y1;
    //img.setPixel(x,y,qRgb(225,0,0));
    while (i < step)
    {
        x = x + dx;
        y = y + dy;
        img.setPixel(x, y, rgb);
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}
int MainWindow::regionCode(double x, double y)
{
    if (d_x[0] > d_x[1])
    {
        x_max = d_x[0];
        x_min = d_x[1];
    }
    else
    {
        x_max = d_x[1];
        x_min = d_y[0];
    }
    if (d_y[0] > d_y[1])
    {
        y_max = d_y[0];
        y_min = d_y[1];
    }
    else
    {
        y_max = d_y[1];
        y_min = d_y[0];
    }

    int code = 0;

    if (x < x_min)
    {
        code |= 8;
    }
    else if (x > x_max)
    {
        code |= 4;
    }
    if (y < y_min)
    {
        code |= 2;
    }
    else if (y > y_max)
    {
        code |= 1;
    }

    return code;
}

void MainWindow::Clip(int x1, int y1, int x2, int y2)
{
    if (d_x[0] > d_x[1])
    {
        x_max = d_x[0];
        x_min = d_x[1];
    }
    else
    {
        x_max = d_x[1];
        x_min = d_y[0];
    }
    if (d_y[0] > d_y[1])
    {
        y_max = d_y[0];
        y_min = d_y[1];
    }
    else
    {
        y_max = d_y[1];
        y_min = d_y[0];
    }

    int code1 = regionCode(x1, y1);
    int code2 = regionCode(x2, y2);

    bool isVisible = false;

    while (1)
    {
        if (code1 == 0 && code2 == 0)
        {
            isVisible = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            isVisible = true;
            int code_out;
            int x, y;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & 1)
            {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & 2)
            {
                y = y1 + (y2 - y1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & 4)
            {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & 8)
            {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                y = x_min;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = regionCode(x1, y1);
            }
            else
            {
                x1 = x;
                y2 = y;
                code2 = regionCode(x2, y2);
            }
        }
    }

    if (isVisible)
        DDALine(x1, y1, x2, y2);
}

int k1 = 0;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (isPoly)
    {
        if (start == true)
        {
            int p = event->pos().x();
            int q = event->pos().y();
            a[j] = p;
            b[j] = q;
            if (event->button() == Qt::RightButton)
            {
                DDALine(a[j], b[j], a[0], b[0]);
                start = false;
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Polygon Complete");

                ui->pushButton->setEnabled(false);
                if (k1 != 0)
                {
                    ui->pushButton_3->setEnabled(true);
                }
            }
            else
            {
                if (j > 0)
                {
                    DDALine(a[j], b[j], a[j - 1], b[j - 1]);
                }
            }
            j++;
            if (j == 2)
            {
                ui->pushButton_4->setEnabled(true);
            }
        }
        else
        {
            if (event->button() == Qt::RightButton || event->button() == Qt::LeftButton)
            {
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Mouse Functionality is disabled");
                messageBox.setFixedSize(200, 200);
                return;
            }
        }
    }
    else
    {
        if (start == true)
        {
            int p = event->pos().x();
            int q = event->pos().y();
            d_x[k1] = p;
            d_y[k1] = q;
            k1++;
            if (event->button() == Qt::RightButton)
            {
                DDALine(d_x[0], d_y[0], d_x[1], d_y[0]);
                DDALine(d_x[0], d_y[0], d_x[0], d_y[1]);
                DDALine(d_x[1], d_y[1], d_x[1], d_y[0]);
                DDALine(d_x[1], d_y[1], d_x[0], d_y[1]);
                start = false;
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Window has been completed");
                messageBox.setFixedSize(200, 200);
                if (j > 1)
                {
                    ui->pushButton_3->setEnabled(true);
                }
                ui->pushButton_2->setEnabled(false);
            }
        }
        else
        {
            if (event->button() == Qt::RightButton || event->button() == Qt::LeftButton)
            {
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Mouse button disabled"),
                    messageBox.setFixedSize(200, 200);
                return;
            }
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < 50; i++)
    {
        a[i] = -1;
        b[i] = -1;
    }
    start = true;
    isPoly = true;
    QMessageBox messageBox;
    messageBox.information(0, "Message", "Mouse functionality enabled"),
    messageBox.setFixedSize(200, 200);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    start = true;
    isPoly = false;
    QMessageBox messageBox;
    messageBox.information(0, "Message", "Mouse functionality enabled");
    messageBox.setFixedSize(200, 200);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    QImage *k2 = new QImage(500, 500, QImage::Format_RGB888);
    img = *k2;
    ui->label->setPixmap(QPixmap::fromImage(img));
    int i = 0;
    DDALine(d_x[0], d_y[0], d_x[1], d_y[0]);
    DDALine(d_x[0], d_y[0], d_x[0], d_y[1]);
    DDALine(d_x[1], d_y[1], d_x[1], d_y[0]);
    DDALine(d_x[1], d_y[1], d_x[0], d_y[1]);
    for (i = 0; i < j - 1; i++)
    {
        Clip(a[i], b[i], a[i + 1], b[i + 1]);
    }
    Clip(a[i], b[i], a[0], b[0]);
}

void MainWindow::on_pushButton_4_clicked()
{
    j = 0;
    for (size_t i = 0; i < 50; i++)
    {
        a[i] = -1;
        b[i] = -1;
    }
    k1 = 0;
    d_x[0] = 0;
    d_x[1] = 0;
    d_y[0] = 0;
    d_y[1] = 0;
    start = true;
    isPoly = true;
    QImage *k2 = new QImage(500, 500, QImage::Format_RGB888);
    img = *k2;
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
}

void MainWindow::on_pushButton_5_clicked()
{
    QRgb col(QColorDialog::getColor().rgb());
    rgb = col;
}
