#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>  // for alert box
#include <QColorDialog> // to choose the colors
#include <QLabel>
#include <QMouseEvent> // to detect all the mouse events
#include <iostream>    // so console cout and cin
using namespace std;

#define height 500 // set the height of the drawing area
#define width 500  // set the width of the drawing area

QImage img(height, width, QImage::Format_RGB888); // this is the drawing area
QRgb rgb(qRgb(0, 0, 255));                        // color bit which is set to blue by default

// For random lines
int noOfLines = 0;
int x1Line[10];
int x2Line[10];
int y1Line[10];
int y2Line[10];

MainWindow::MainWindow(QWidget *parent) // Constructor
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int x = 0; x < height; ++x) // this is for initial black screen
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->ClipButton->setEnabled(false); //clip disabled
    ui->ClearButton->setEnabled(false); // clear disabled
}

MainWindow::~MainWindow() // destructor
{
    delete ui;
}

bool mouseEnabled = false;
bool mousePolygon = false;

int x_polygon[100]; // stores x-cor for all vertices of polygon
int y_polygon[100]; // stores y-cor for all vertices of polygon
int vertexNo = 0; // no of vertices

int diagonal_x[2]; // diagonal x cliping window
int diagonal_y[2]; // diagonal y cliping window

int x_left; // left of window
int x_right; // right of window
int y_top; // top of window
int y_right; // bottom of window

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
    while (i < step)
    {
        x = x + dx;
        y = y + dy;
        img.setPixel(x, y, rgb);
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}
int MainWindow::findRegionCode(double x, double y) // this is code for finding the region code
{
    // we use the 4 bit region code system in the algorithm!

    /*
            left	    central	   right
    top	    1001 =9	    1000 =1	   1010 =5
    central	0001 =8	    0000 =0	   0010 =4
    bottom	0101 =10	0100 =2	   0110 =6

     */

    if (diagonal_x[0] > diagonal_x[1])
    {
        x_left = diagonal_x[0];
        x_right = diagonal_x[1];
    }
    else
    {
        x_left = diagonal_x[1];
        x_right = diagonal_x[0];
    }
    if (diagonal_y[0] > diagonal_y[1])
    {
        y_top = diagonal_y[0];
        y_right = diagonal_y[1];
    }
    else
    {
        y_top = diagonal_y[1];
        y_right = diagonal_y[0];
    }

    int regionCode = 0;

    if (x < x_right)
    {
        regionCode |= 8;
    }
    else if (x > x_left)
    {
        regionCode |= 4;
    }
    if (y < y_right)
    {
        regionCode |= 2;
    }
    else if (y > y_top)
    {
        regionCode |= 1;
    }

    return regionCode;
}

void MainWindow::Clip(int x1, int y1, int x2, int y2)
{
    if (diagonal_x[0] > diagonal_x[1])
    {
        x_left = diagonal_x[0];
        x_right = diagonal_x[1];
    }
    else
    {
        x_left = diagonal_x[1];
        x_right = diagonal_x[0];
    }
    if (diagonal_y[0] > diagonal_y[1])
    {
        y_top = diagonal_y[0];
        y_right = diagonal_y[1];
    }
    else
    {
        y_top = diagonal_y[1];
        y_right = diagonal_y[0];
    }

    int code1 = findRegionCode(x1, y1); // find region code of 1st end point
    int code2 = findRegionCode(x2, y2); // find region code of 2nd end point

    bool isVisible = false;

    while (1)
    {
        if (code1 == 0 && code2 == 0) // line completely inside the window
        {
            isVisible = true;
            break;
        }
        else if (code1 & code2) // both are outside so ignore the line
        {
            break;
        }
        else
        {
            isVisible = true;
            int code_out;
            int x, y;
            if (code1 != 0) // check which point is inside
                code_out = code1;
            else
                code_out = code2;

            if (code_out & 1)
            {
                x = x1 + (x2 - x1) * (y_top - y1) / (y2 - y1);
                y = y_top;
            }
            else if (code_out & 2)
            {
                x = x1 + (x2 - x1) * (y_right - y1) / (y2 - y1);
                y = y_right;
            }
            else if (code_out & 4)
            {
                y = y1 + (y2 - y1) * (x_left - x1) / (x2 - x1);
                x = x_left;
            }
            else if (code_out & 8)
            {
                y = y1 + (y2 - y1) * (x_right - x1) / (x2 - x1);
                x = x_right;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = findRegionCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = findRegionCode(x2, y2);
            }
        }
    }

    if (isVisible)
        DDALine(x1, y1, x2, y2);
}

int k1 = 0;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (mousePolygon)
    {
        if (mouseEnabled == true)
        {
            int p = event->pos().x();
            int q = event->pos().y();
            x_polygon[vertexNo] = p;
            y_polygon[vertexNo] = q;
            if (event->button() == Qt::RightButton)
            {
                DDALine(x_polygon[vertexNo], y_polygon[vertexNo], x_polygon[0], y_polygon[0]);
                mouseEnabled = false;
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Polygon Complete");

                ui->DrawPolygon->setEnabled(false);
                if (k1 != 0)
                {
                    ui->ClipButton->setEnabled(true);
                }
            }
            else
            {
                if (vertexNo > 0)
                {
                    DDALine(x_polygon[vertexNo], y_polygon[vertexNo], x_polygon[vertexNo - 1], y_polygon[vertexNo - 1]);
                }
            }
            vertexNo++;
            if (vertexNo == 2)
            {
                ui->ClearButton->setEnabled(true);
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
        if (mouseEnabled == true)
        {
            int p = event->pos().x();
            int q = event->pos().y();
            diagonal_x[k1] = p;
            diagonal_y[k1] = q;
            k1++;
            if (event->button() == Qt::RightButton)
            {
                DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[1], diagonal_y[0]);
                DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[0], diagonal_y[1]);
                DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[1], diagonal_y[0]);
                DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[0], diagonal_y[1]);
                mouseEnabled = false;
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Window has been completed");
                messageBox.setFixedSize(200, 200);
                if (vertexNo > 1)
                {
                    ui->ClipButton->setEnabled(true);
                }
                ui->DrawWindow->setEnabled(false);
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
void MainWindow::on_DrawPolygon_clicked()
{
    for (int i = 0; i < 100; i++)
    {
        x_polygon[i] = -1;
        y_polygon[i] = -1;
    }
    mouseEnabled = true;
    mousePolygon = true;
    QMessageBox messageBox;
    messageBox.information(0, "Message", "Mouse functionality enabled"),
    messageBox.setFixedSize(200, 200);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_DrawWindow_clicked()
{
    mouseEnabled = true;
    mousePolygon = false;
    QMessageBox messageBox;
    messageBox.information(0, "Message", "Mouse functionality enabled");
    messageBox.setFixedSize(200, 200);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_ClipButton_clicked()
{
    for (int x = 0; x < height; ++x) // this is for initial black screen
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    int i = 0;
    DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[1], diagonal_y[0]);
    DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[0], diagonal_y[1]);
    DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[1], diagonal_y[0]);
    DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[0], diagonal_y[1]);
    for (i = 0; i < vertexNo - 1; i++)
    {
        Clip(x_polygon[i], y_polygon[i], x_polygon[i + 1], y_polygon[i + 1]);
    }
    Clip(x_polygon[i], y_polygon[i], x_polygon[0], y_polygon[0]);

    // cliping for lines
    for (int i = 0; i < noOfLines; i++) {
        cout << "Performing clipping for line"<< endl;
        Clip(x1Line[i], y1Line[i], x2Line[i], y2Line[i]);
    }
}

void MainWindow::on_ClearButton_clicked()
{
    vertexNo = 0;
    for (int i = 0; i < 100; i++)
    {
        x_polygon[i] = -1;
        y_polygon[i] = -1;
    }
    k1 = 0;
    diagonal_x[0] = 0;
    diagonal_x[1] = 0;
    diagonal_y[0] = 0;
    diagonal_y[1] = 0;

    for(int i = 0; i < noOfLines; i++){
        x1Line[i] = 0;
        x2Line[i] = 0;
        y1Line[i] = 0;
        y2Line[i] = 0;
    }

    noOfLines = 0;

    mouseEnabled = true;
    mousePolygon = true;
    for (int x = 0; x < height; ++x) // this is for initial black screen
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->DrawPolygon->setEnabled(true);
    ui->DrawWindow->setEnabled(true);
    ui->ClipButton->setEnabled(false);
    ui->ClearButton->setEnabled(false);
}

void MainWindow::on_SelectColor_clicked()
{
    QRgb getColor(QColorDialog::getColor().rgb());
    rgb = getColor;
}


void MainWindow::on_DrawWindow_2_clicked()
{
    QMessageBox message;
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() || ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty())
    {
        message.information(0, "Warning!", "Fields cannot be left empty!"); //EH for not having proper inputs
    }
    else if (ui->textEdit->toPlainText().toInt() && ui->textEdit_2->toPlainText().toInt() && ui->textEdit_3->toPlainText().toInt() && ui->textEdit_4->toPlainText().toInt())
    {
        int x1 = ui->textEdit->toPlainText().toInt();
        int y1 = ui->textEdit_2->toPlainText().toInt();
        int x2 = ui->textEdit_3->toPlainText().toInt();
        int y2 = ui->textEdit_4->toPlainText().toInt();
        x1Line[noOfLines] = x1;
        x2Line[noOfLines] = x2;
        y1Line[noOfLines] = y1;
        y2Line[noOfLines] = y2;
        DDALine(x1, y1, x2, y2);
        noOfLines++;
    }
    else
    {
        message.information(0, "Warning!", "Fields accept only numerical inputs!"); //EH for not having proper inputs
    }
}

