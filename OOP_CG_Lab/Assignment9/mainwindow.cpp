#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h> // for rotation computing sinx and cosx
#include <QMouseEvent>
using namespace std;

QImage img(600, 600, QImage::Format_RGB888);
QRgb rgb(qRgb(0, 0, 255));

void MainWindow::ClearScreen(){
    // clearing the screeen
    for (int x = 0; x < 600; ++x)
    {
        for (int y = 0; y < 600; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    dda(-300, 0, 300, 0);  // Initial cross line horizontal
    dda(0, -300, 0, 300); // Initial cross line vertical
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    QMessageBox message;
    message.information(0, "Alert!", "You can draw objects using left click, press right click to disable");

    // Constructor for initializing the required values
    ui->setupUi(this);
    // changing the origin to center
    dda(-300, 0, 300, 0); // Initial cross line horizontal
    dda(0, -300, 0, 300); // Initial cross line vertical
    start = true;         // for mouse press event
    ver = 0;              // no of vertices = 0
}

MainWindow::~MainWindow()
{
    delete ui;
}

class Matrix
{
public:
    // P' = T*P
    float a[2][3];              // Used mainly for P matrix
    float b[3][3];              // Used mainly for T,R,S matrix
    Matrix operator*(Matrix ob) //operator overloading for * operator in class matrix
    {
        Matrix temp;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.a[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    temp.a[i][j] += a[i][k] * ob.b[k][j];
                }
            }
        }
        return temp; // final product of multiplication
    }
};

void MainWindow::on_translate_clicked()
{
    QMessageBox message;
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty())
    {
        message.information(0, "Warning!", "Fields left empty!"); //EH for empty inputs
    }
    else if (ui->textEdit->toPlainText().toFloat() && ui->textEdit_2->toPlainText().toFloat())
    {
        ClearScreen();
        tx = ui->textEdit->toPlainText().toFloat();   //taking translation vectorx
        ty = ui->textEdit_2->toPlainText().toFloat(); //taking translation vectory

        for (int i = 0; i < ver; i++)
        {

            Matrix M, N, ans;
            // p=  [x1, y1, 1]
            //     [x2, y2, 1]

            // T = [1, 0, tx]
            //     [0, 1, ty]
            //     [0, 0, 1]
            float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};
            float T[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is P matrix, array A is used

                    M.a[i][j] = P[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    N.b[i][j] = T[i][j];
                }
            }
            // P' = T*P
            // ans means P' matrix
            ans = M * N;                                             // use of operator overloading
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1]); // now drawing line after translation
        }
    }
    else
    {
        message.information(0, "Warning!", "Fields accept only numerical inputs!"); //EH for empty inputs
    }
}
void MainWindow::on_scaling_clicked()
{
    QMessageBox message;
    if (ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty())
    {
        message.information(0, "Warning!", "Fields left empty!"); //EH for empty inputs
    }
    else if (ui->textEdit_3->toPlainText().toFloat() && ui->textEdit_4->toPlainText().toFloat())
    {
         ClearScreen();
        sx = ui->textEdit_3->toPlainText().toFloat(); //scaling vector x
        sy = ui->textEdit_4->toPlainText().toFloat(); // scaling vector y

        for (int i = 0; i < ver; i++)
        {

            Matrix M, N, ans;
            // p=  [x1, y1, 1]
            //     [x2, y2, 1]

            // S = [Sx, 0, 0]
            //     [0, Sy, 0]
            //     [0, 0, 1]
            float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};
            float S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is P matrix, array A is used
                    M.a[i][j] = P[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    N.b[i][j] = S[i][j];
                }
            }
            // ans means P' matrix
            ans = M * N;                                             // use of operator overloading
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1]); // now drawing line after scaling
        }
    }
    else
    {
        message.information(0, "Warning!", "Fields accept only numerical inputs!"); //EH for empty inputs
    }
}
void MainWindow::on_rotation_clicked() // here rotation happens anticlock wise
{
    QMessageBox message;
    if (ui->textEdit_5->toPlainText().isEmpty())
    {
        message.information(0, "Warning!", "Fields left empty!"); //EH for empty inputs
    }
    else if (ui->textEdit_5->toPlainText().toFloat())
    {
        ClearScreen();
        x = ui->textEdit_5->toPlainText().toFloat();
        x *= 3.142 / 180; // convert degree to radian

        for (int i = 0; i < ver; i++)
        {

            Matrix M, N, ans;
            // p' = R*P

            // p=  [x1, y1, 1]
            //     [x2, y2, 1]

            // R = [cosx, -sinx, 0]
            //     [sinx, cosx, 0]
            //     [0, 0, 1]
            float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};
            float R[3][3] = {{cos(x), (-sin(x)), 0}, {sin(x), cos(x), 0}, {0, 0, 1}};
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is P matrix, array A is used
                    M.a[i][j] = P[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    N.b[i][j] = R[i][j];
                }
            }
            // ans means P' matrix
            ans = M * N;                                             // use of operator overloading
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1]); // now drawing line after rotation
        }
    }
    else
    {
        message.information(0, "Warning!", "Fields accept only numerical inputs!"); //EH for empty inputs
    }
}
void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    // to change the origin
    x1 += 300;
    y1 += 300;
    x2 += 300;
    y2 += 300;

    float dx, dy, length, x, y;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        length = abs(dx);
    }
    else
    {
        length = abs(dy);
    }
    dx = dx / length;
    dy = dy / length;
    x = x1;
    y = y1;
    int i = 0;
    img.setPixel(x, y, rgb);

    while (i < length)
    {
        x = x + dx;
        y = y + dy;
        img.setPixel(x, y, rgb);
        i++;
    }
    ui->label_6->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (start)
    {
        int p = ev->pos().x(); // get x position of object
        int q = ev->pos().y(); // get y position of object
        a[ver] = p - 300;      // storing x the position of object
        b[ver] = q - 300;      // storing y the position of object

        if (ev->button() == Qt::RightButton)
        {
            dda(a[ver], b[ver], a[ver - 1], b[ver - 1]);
            dda(a[0], b[0], a[ver], b[ver]);
            QMessageBox message;
            message.information(0, "Alert!", "Drawing disabled");
            start = false;
        }
        else
        {
            if (ver > 0)
            {
                dda(a[ver], b[ver], a[ver - 1], b[ver - 1]);
            }
        }
        ver++;
    }
    a[ver] = a[0];
    b[ver] = b[0];
}

void MainWindow::on_clear_clicked()
{
    // clearing the screeen
    for (int x = 0; x < 600; ++x)
    {
        for (int y = 0; y < 600; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ver = 0;
    dda(-300, 0, 300, 0);  // Initial cross line horizontal
    dda(0, -300, 0, 300); // Initial cross line vertical
    start = true;         // for mouse press event
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->label_6->setPixmap(QPixmap::fromImage(img));
    QMessageBox message;
    message.information(0, "Alert!", "You can draw objects using left click, press right click to disable");
}

void MainWindow::on_TRS_clicked()
{
    QMessageBox message;
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() || ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty() || ui->textEdit_5->toPlainText().isEmpty())
    {
        message.information(0, "Warning!", "Fields left empty!"); //EH for empty inputs
    }
    else if (ui->textEdit->toPlainText().toFloat() && ui->textEdit_2->toPlainText().toFloat() && ui->textEdit_3->toPlainText().toFloat() && ui->textEdit_4->toPlainText().toFloat() && ui->textEdit_5->toPlainText().toFloat())
    {
        ClearScreen();
        tx = ui->textEdit->toPlainText().toFloat();   //taking translation vectorx
        ty = ui->textEdit_2->toPlainText().toFloat(); //taking translation vectory
        sx = ui->textEdit_3->toPlainText().toFloat(); //scaling vector x
        sy = ui->textEdit_4->toPlainText().toFloat(); // scaling vector y
        x = ui->textEdit_5->toPlainText().toFloat();
        x *= 3.142 / 180; // convert degree to radian

        for (int i = 0; i < ver; i++)
        {

            Matrix M, T1, S1, R1, ans;
            float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};
            float T[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};
            float S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
            float R[3][3] = {{cos(x), (-sin(x)), 0}, {sin(x), cos(x), 0}, {0, 0, 1}};
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is P matrix, array A is used

                    M.a[i][j] = P[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    T1.b[i][j] = T[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    S1.b[i][j] = S[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    R1.b[i][j] = R[i][j];
                }
            }
            // P' = T*P
            // ans means P' matrix
            ans = (((M * T1)*S1)*R1);                                             // use of operator overloading
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1]); // now drawing line after translation
        }
    }
    else
    {
        message.information(0, "Warning!", "Fields accept only numerical inputs!"); //EH for empty inputs
    }
}


void MainWindow::on_SRT_clicked()
{
    QMessageBox message;
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() || ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty() || ui->textEdit_5->toPlainText().isEmpty())
    {
        message.information(0, "Warning!", "Fields left empty!"); //EH for empty inputs
    }
    else if (ui->textEdit->toPlainText().toFloat() && ui->textEdit_2->toPlainText().toFloat() && ui->textEdit_3->toPlainText().toFloat() && ui->textEdit_4->toPlainText().toFloat() && ui->textEdit_5->toPlainText().toFloat())
    {
        ClearScreen();
        tx = ui->textEdit->toPlainText().toFloat();   //taking translation vectorx
        ty = ui->textEdit_2->toPlainText().toFloat(); //taking translation vectory
        sx = ui->textEdit_3->toPlainText().toFloat(); //scaling vector x
        sy = ui->textEdit_4->toPlainText().toFloat(); // scaling vector y
        x = ui->textEdit_5->toPlainText().toFloat();
        x *= 3.142 / 180; // convert degree to radian

        for (int i = 0; i < ver; i++)
        {

            Matrix M, T1, S1, R1, ans;
            float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};
            float T[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};
            float S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
            float R[3][3] = {{cos(x), (-sin(x)), 0}, {sin(x), cos(x), 0}, {0, 0, 1}};
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is P matrix, array A is used

                    M.a[i][j] = P[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    T1.b[i][j] = T[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    S1.b[i][j] = S[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    R1.b[i][j] = R[i][j];
                }
            }
            // P' = T*P
            // ans means P' matrix
            ans = (((M * S1)*R1)*T1);                                             // use of operator overloading
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1]); // now drawing line after translation
        }
    }
    else
    {
        message.information(0, "Warning!", "Fields accept only numerical inputs!"); //EH for empty inputs
    }
}


void MainWindow::on_RTS_clicked()
{
    QMessageBox message;
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() || ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty() || ui->textEdit_5->toPlainText().isEmpty())
    {
        message.information(0, "Warning!", "Fields left empty!"); //EH for empty inputs
    }
    else if (ui->textEdit->toPlainText().toFloat() && ui->textEdit_2->toPlainText().toFloat() && ui->textEdit_3->toPlainText().toFloat() && ui->textEdit_4->toPlainText().toFloat() && ui->textEdit_5->toPlainText().toFloat())
    {
        ClearScreen();
        tx = ui->textEdit->toPlainText().toFloat();   //taking translation vectorx
        ty = ui->textEdit_2->toPlainText().toFloat(); //taking translation vectory
        sx = ui->textEdit_3->toPlainText().toFloat(); //scaling vector x
        sy = ui->textEdit_4->toPlainText().toFloat(); // scaling vector y
        x = ui->textEdit_5->toPlainText().toFloat();
        x *= 3.142 / 180; // convert degree to radian

        for (int i = 0; i < ver; i++)
        {

            Matrix M, T1, S1, R1, ans;
            float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};
            float T[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};
            float S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
            float R[3][3] = {{cos(x), (-sin(x)), 0}, {sin(x), cos(x), 0}, {0, 0, 1}};
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is P matrix, array A is used

                    M.a[i][j] = P[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    T1.b[i][j] = T[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    S1.b[i][j] = S[i][j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Converting float object to Class object
                    // as it is T matrix, array B is used of Class matrix
                    R1.b[i][j] = R[i][j];
                }
            }
            // P' = T*P
            // ans means P' matrix
            ans = (((M * R1)*T1)*S1);                                             // use of operator overloading
            dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1]); // now drawing line after translation
        }
    }
    else
    {
        message.information(0, "Warning!", "Fields accept only numerical inputs!"); //EH for empty inputs
    }
}

