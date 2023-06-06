#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Task 3");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Кнопки настройки
void MainWindow::on_radioButtonScroll_clicked(bool checked)
{
    if (checked){
        ui->groupBoxScrollBars->setEnabled(true);
        ui->groupBoxSliders->setEnabled(false);
        ui->groupBoxCircles->setEnabled(false);
    }
}

void MainWindow::on_radioButtonSpin_clicked(bool checked)
{
    if (checked){
        ui->groupBoxScrollBars->setEnabled(false);
        ui->groupBoxSliders->setEnabled(false);
        ui->groupBoxCircles->setEnabled(false);
    }
}

void MainWindow::on_radioButtonSlider_clicked(bool checked)
{
    if (checked){

        ui->groupBoxScrollBars->setEnabled(false);
        ui->groupBoxSliders->setEnabled(true);
        ui->groupBoxCircles->setEnabled(false);
    }

}

void MainWindow::on_radioButtonDial_clicked(bool checked)
{
    if (checked){
        ui->groupBoxScrollBars->setEnabled(false);
        ui->groupBoxSliders->setEnabled(false);
        ui->groupBoxCircles->setEnabled(true);
    }

}


//Запись диапазона в label
void MainWindow::on_scrollBarPozitive_valueChanged(int value)
{
    ui->label_2->setText(QString::number(value));
}


void MainWindow::on_scrollBarNigative_valueChanged(int value)
{
    ui->label->setText(QString::number(value));
}

void MainWindow::on_sliderNegative_valueChanged(int value)
{
     ui->label_2->setText(QString::number(value));
}


void MainWindow::on_sliderPozitive_valueChanged(int value)
{
     ui->label->setText(QString::number(value));
}


void MainWindow::on_dialPositive_valueChanged(int value)
{
     ui->label_2->setText(QString::number(value));
}


void MainWindow::on_dialNigative_valueChanged(int value)
{
     ui->label->setText(QString::number(value));
}


void MainWindow::on_pushButton_clicked()
{
    //Проверка на ошибки длинны массива
    QString size = ui->lineEditSize->text();
    try {
        n = size.toInt();
        mas = new int [n];
        }

    catch (...) {
        ui->textEdit->setText("Меняйте размерность массива!");
        return;
    }



    //Инициализация диапазона
    if (ui->radioButtonScroll->isChecked() == true){
        pozitive = ui->scrollBarPozitive->value();
        negative = ui->scrollBarNigative->value();
    }

    else if (ui->radioButtonSlider->isChecked() == true){
        pozitive = ui->sliderPozitive->value();
        negative = ui->sliderNegative->value();
    }
    else if (ui->radioButtonDial->isChecked() == true){
        pozitive = ui->dialPositive->value();
        negative = ui->dialNigative->value();
    }

    for (int i = 0; i < n; i++) {
        mas[i] = randomBetween(pozitive, negative);
    }
    QString line;
    for (int i = 0; i < n; i++ ) {
        line += QString::number(mas[i]) + ' ';
    }

    QString count;
    if (ui->radioButtonTaskA->isChecked() == true){
        int sumA = 0;
        for (int i = 0; i < n; i+=2 ) {
          sumA += mas[i];
        }
        QString A = QString::number(sumA);
        count = line + "\n\n" + A;

    }
     else if (ui->radioButtonTaskB->isChecked() == true){
        int sumB = 0;
        bool flag = true;
        for (int i = 0; i < n ; i++ ) {
            if (mas[i] < 0){
                if (i != n - 1)
                    flag = false;
                for (int j = i + 1; j < n ; j++ ) {
                    if (mas[j] >= 0){
                        sumB += mas[j];
                    }
                    else
                        break;
                    if (j == n - 1)
                        flag = true;
                }
                break;
            }

        }
        if(flag == false){
            QString B = QString::number(sumB);
            count = line + "\n\n" + B;
        }
        else{
            count = line + "\n" + "Нет отрицательных чисел или нет второго отрицательного числа!";
        }
       }
    else{
        count = "Выберите задание";
    }
    delete[] mas;

    ui->textEdit->setText(count);
    if (ui->checkBoxIFiles->isChecked()){
        writeFile(count);
    }

}

void MainWindow::writeFile(QString line){
    QFile file("file.txt");
    file.open(QIODevice::WriteOnly);
    QByteArray ba = line.toLocal8Bit();
    const char *count = ba.data();
    file.write(count);
    file.close();
}
