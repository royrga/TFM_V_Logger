#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void data_init();
    void readTemp();
    void clockfunc();
    void releTimefunc();

    void on_pushButton_on_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_UP_clicked();

    void on_pushButton_DOWN_clicked();

    void on_comboBox_auto_material_currentIndexChanged(int index);

    void on_pushButton_vacuum_clicked(bool checked);

    void on_pushButtonByMaterial_clicked();

    void on_pushButton_SetTemp_clicked();

    void on_pushButton_TouchScreen_clicked();

    void on_pushButton_Physical_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timerT;
    QTimer *releTime;
    double t;

    // Sampling temperature variables 
    int sample_temp[3];
    float average_sample_temps;
    float set_point_temp;

    // SPI variable
    typedef union
    {
        struct
        {
            unsigned short int NULB : 2;
            unsigned short int value: 12;
            unsigned short int DONT : 2;
        }data;
        unsigned char buffer[2];
    }Int16;
    char buffer[2];
    Int16 adc_data;
    int fd,fe;
    //handler SPI
    int h[3];

    // Methods to setup
    void cfg_Gpios_Coms();
    void cfg_Timers();
};

#endif // MAINWINDOW_H
