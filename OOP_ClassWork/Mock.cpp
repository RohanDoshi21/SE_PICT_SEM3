#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <iostream>
using namespace std;

QImage img(500, 500, QImage::Format_RGB888);
QRgb color(qRgb(255, 0, 0));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = false;
    ui->label->setPixmap(QPixmap::fromImage(img));
    vertexNo = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDALine(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float step;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    dx /= step;
    dy /= step;

    int i = 0;
    while (i <= step)
    {
        img.setPixel(x1, y1, color);
        x1 += dx;
        y1 += dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::Scanfill()
{
    cout << "SCAN FILL" << endl;

    x_edge[vertexNo] = x_edge[0];
    y_edge[vertexNo] = y_edge[0];

    for (int i = 0; i < vertexNo; i++)
    {
        float dx = x_edge[i + 1] - x_edge[i];
        float dy = y_edge[i + 1] - y_edge[i];
        if (dy == 0.0)
        {
            slope_inverse[i] = 1;
        }
        if (dx == 0.0)
        {
            slope_inverse[i] = 0;
        }
        if (dx != 0.0 && dy != 0.0)
        {
            slope_inverse[i] = dx / dy;
        }
    }

    for (int y = 0; y < 500; y++)
    {
        int k = 0;
        for (int i = 0; i < vertexNo; i++)
        {
            if (((y_edge[i] <= y) && (y_edge[i + 1] > y)) || ((y_edge[i + 1] <= y) && (y_edge[i] > y)))
            {
                x_active[k] = x_edge[i] + slope_inverse[i] * (y - y_edge[i]);
                k++;
            }
        }
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = 0; j < k - 1 - i; j++)
            {
                if (x_active[i] > x_active[i + 1])
                {
                    auto temp = x_active[i];
                    x_active[i] = x_active[i + 1];
                    x_active[i + 1] = temp;
                }
            }
        }

        for (int i = 0; i < k; i += 2)
        {
            DDALine(x_active[i], y, x_active[i + 1], y);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *mp)
{
    if (start)
    {
        int x = mp->pos().x();
        int y = mp->pos().y();
        if (vertexNo == 0)
        {
            x_edge[vertexNo] = x;
            y_edge[vertexNo] = y;
            vertexNo++;
        }
        else if (mp->button() == Qt::RightButton)
        {
            start = false;
            DDALine(x_edge[vertexNo - 1], y_edge[vertexNo - 1], x_edge[0], y_edge[0]);
        }
        else
        {
            x_edge[vertexNo] = x;
            y_edge[vertexNo] = y;
            DDALine(x_edge[vertexNo - 1], y_edge[vertexNo - 1], x_edge[vertexNo], y_edge[vertexNo]);
            vertexNo++;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    start = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    Scanfill();
}
