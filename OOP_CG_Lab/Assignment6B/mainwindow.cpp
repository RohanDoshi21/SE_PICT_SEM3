#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <math.h>
#define height 400
#define width 400

QImage img(height, width, QImage::Format_RGB888);
QRgb rgb(qRgb(255, 255, 255));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Assignment6B();
}

void MainWindow::Assignment6B(){
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_3->toPlainText().toInt();
    int y2 = ui->textEdit_4->toPlainText().toInt();

    DDALine(x1,y1,x2,y1);
    DDALine(x2,y1,x2,y2);
    DDALine(x2,y2,x1,y2);
    DDALine(x1,y2,x1,y1);

    int x1c = (x1 + x2)/2;
    int y1c = (y1 + y2)/2;

    // cordinats (x1c, y1), (x2,y1c), (x1c, y2), (x1, y1c)

    BresenhamLine(x1c, y1, x2, y1c);
    BresenhamLine(x2, y1c, x1c, y2);
    BresenhamLine(x1c, y2, x1, y1c);
    BresenhamLine(x1, y1c, x1c, y1);

//    int _x1 = x1 + (x1+x2)/8;
//    int _x2 = x1 + 3*(x1+x2)/8;
//    int _y1 = y1 + (y1+y2)/8;
//    int _y2 = y1 + 3*(y1+y2)/8;

    // cordinates ( (x1c+x1)/2 , (y1 + y1c)/2 ) , center cordinates = x1+x2/2 , y1+y2/2

    // center = x1c, y1c

    float h1 = abs(x1-x2)/2;
    float w1 = abs(y1-y2)/2;

    float reqRadius = h1 * w1 / sqrt(h1*h1+w1*w1);

    BresenhamCircle(x1c, y1c, reqRadius);


}

void MainWindow::on_pushButton_2_clicked()
{
    QRgb color(QColorDialog::getColor().rgb()); //Able to select any color to draw
    rgb = color;                                //sets the value of the selected color to the global variable
}


void MainWindow::on_pushButton_3_clicked()
{
    for (int x = 0; x < height; ++x)
        {
            for (int y = 0; y < width; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
     ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::BresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1; // condition to check if x1 > x2 then we need to decrement
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy; // error value as we have taken dy negative so its dx - dy
    // err is to get the integer value of the nearest pixel

    while (true)
    {
        img.setPixel(x1, y1, rgb);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err; // decision parameter
        if (e2 >= dy)
        {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDALine(float x1, float y1, float x2, float y2)
{

    float dx = (x2 - x1);
    float dy = (y2 - y1);
    float step = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy); // this is the no of steps the program must run
    // also checks if slope > 1 or < 1

    dx = dx / step; // this is the increment that must happen in each step
    dy = dy / step;

    float x = x1, y = y1;
    int i = 1;

    while (i <= step) // repeat the loop till step gets over
    {
        img.setPixel(x, y, rgb);
        x += dx;
        y += dy;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::BresenhamCircle(int xCenter, int yCenter, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - (2 * radius);
    while (x <= y)
    {
        if (d > 0)
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        else
        {
            d = d + (4 * x) + 6;
        }
        x++;
        img.setPixel(xCenter + x, yCenter + y, rgb);
        img.setPixel(xCenter + x, yCenter - y, rgb);
        img.setPixel(xCenter - x, yCenter - y, rgb);
        img.setPixel(xCenter - x, yCenter + y, rgb);
        img.setPixel(xCenter + y, yCenter - x, rgb);
        img.setPixel(xCenter + y, yCenter + x, rgb);
        img.setPixel(xCenter - y, yCenter - x, rgb);
        img.setPixel(xCenter - y, yCenter + x, rgb);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();
}
