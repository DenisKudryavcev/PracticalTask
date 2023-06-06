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
    void on_radioButtonScroll_clicked(bool checked);

    void on_radioButtonSpin_clicked(bool checked);

    void on_radioButtonSlider_clicked(bool checked);

    void on_radioButtonDial_clicked(bool checked);

    void on_scrollBarPozitive_valueChanged(int value);

    void on_scrollBarNigative_valueChanged(int value);

    void on_sliderNegative_valueChanged(int value);

    void on_sliderPozitive_valueChanged(int value);

    void on_dialPositive_valueChanged(int value);

    void on_dialNigative_valueChanged(int value);

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    int *mas;
    int n;
    int pozitive, negative;
    static int randomBetween(int max1, int min1){
        return (qrand() % ((max1 + 1) - min1) + min1);
    }
    void writeFile(QString line);
};
#endif // MAINWINDOW_H
