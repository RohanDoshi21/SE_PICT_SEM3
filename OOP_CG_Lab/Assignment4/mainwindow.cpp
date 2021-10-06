#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMessageBox>
#include <math.h>
#include <string.h>
#define height 400
#define width 400
// define a class write a dda function make other class fill this class will inherit class line dda function will call in the fill algorithm
using namespace std;
int ver,a[20],b[20],i,y,xi[20],j,temp,k; // variables used in scan line algorithm
float slope[20],dx,dy;

QImage img(height, width, QImage::Format_RGB888); // this the image
QRgb rgb(qRgb(255, 255, 255)); // this is the color of the line

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    ver = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_plotLineButton_clicked()
{
    // Algorithm Bresenham Line:
    QMessageBox messageBox;
    if(ui->plainTextEdit->toPlainText().isEmpty() || ui->plainTextEdit_2->toPlainText().isEmpty() || ui->plainTextEdit_3->toPlainText().isEmpty() || ui->plainTextEdit_4->toPlainText().isEmpty()){
        messageBox.information(0,"Alert", "Fields cannot be empty");
    }
    else{
    int x1 = ui->plainTextEdit->toPlainText().toInt();
    int y1 = ui->plainTextEdit_2->toPlainText().toInt();
    int x2 = ui->plainTextEdit_3->toPlainText().toInt();
    int y2 = ui->plainTextEdit_4->toPlainText().toInt();

    a[ver] = x2;    // set the value of vertex(x) in the array
    b[ver] = y2;    // set the vlaue of vertex(y) in the array
    ver++;          // change the number of vertex by 1

    DDALine(x1,y1,x2,y2);
    }
}



void MainWindow::on_scanLineButton_clicked()
{

            a[ver] = a[0];
            b[ver] = b[0];

             // set the slope array for all the vertices
            for(i=0;i<ver;i++)
            {
                dy = b[i+1] - b[i];
                dx = a[i+1] - a[i];
                if(dy == 0.0)
                {
                    slope[i] = 1.0;
                }
                if(dx == 0.0)
                {
                    slope[i] = 0.0;
                }
                if((dy != 0.0) && (dx != 0.0))
                {
                    slope[i] = dx / dy;
                }
            }


            for(int y=0;y<height;y++)
            {
                k = 0;

                // code to generate the scan line table
                for(i=0;i<ver;i++)
                {
                    if(((b[i]<=y) && (b[i+1]>y)) || ((b[i]>y) && (b[i+1]<=y)))
                    {
                        xi[k] = int(a[i] + (slope[i]*(y-b[i])));
                        k++;
                    }
                }

                // Code for bubble sort
                for(j=0;j<k-1;j++)
                {
                    for(i=0;i<k-j-1;i++)
                    {
                        if(xi[i]>xi[i+1])
                        {
                            temp = xi[i];
                            xi[i] = xi[i+1];
                            xi[i+1] = temp;
                        }
                    }
                }

                // code for printing the final line
                for(i=0;i<k;i+=2)
                {
                    DDALine(xi[i],y,xi[i+1]+1,y);
                }
            }
}




void MainWindow::on_colorSelectButton_clicked() // To change the line color
{
    QRgb color(QColorDialog::getColor().rgb());
    rgb = color;
}




void MainWindow::on_clearButton_clicked() // To clear the screen
{
    for (int x = 0; x < height; ++x)
        {
            for (int y = 0; y < width; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
     ver = 0;
     ui->plainTextEdit->clear();
     ui->plainTextEdit_2->clear();
     ui->plainTextEdit_3->clear();
     ui->plainTextEdit_4->clear();
     ui->label->setPixmap(QPixmap::fromImage(img));
}



void MainWindow::DDALine(int x1, int y1, int x2, int y2){ // This is line drawing algorithm

// Algorithm for bresenham line
//    int dx = abs(x2-x1);
//    int dy = abs(y2-y1);

//    int x = x1;
//    int y = y1;

//    int pk = 2*dy - dx; // This is decision parameter

//    for (int i =0; i<dx; i++){
//        img.setPixel(x,y, rgb);
//        if(pk >= 0){
//            pk += 2*(dy-dx);
//            x++;
//            y++;
//        }
//        else{
//            pk += 2*dy;
//            x++;
//        }
//    }

//    ui->label->setPixmap(QPixmap::fromImage(img));

            float dx,dy,step,x,y;
            dx=x2-x1;
            dy=y2-y1;
            if(abs(dx)>=abs(dy))
            {
                step=abs(dx);
            }
            else {
                step=abs(dy);
            }
            dx=dx/step;
            dy=dy/step;
            int i=0;
            x=x1;
            y=y1;
            //img.setPixel(x,y,qRgb(225,0,0));
            while(i<step)
            {
                x=x+dx;
                y=y+dy;
                img.setPixel(x,y,rgb);
                i++;
            }
         ui->label->setPixmap(QPixmap::fromImage(img));
}
