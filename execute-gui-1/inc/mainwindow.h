//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@media.mit.edu
// 02/2016
//****************************************************************************
// MainWindow: Qt GUI Main file
//****************************************************************************

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//****************************************************************************
// Include(s)
//****************************************************************************

#include <QMainWindow>
#include <QSerialPort>
#include "qcustomplot.h"

//****************************************************************************
// Definition(s):
//****************************************************************************

//Timers:
//======

#define TIM_FREQ_TO_P(f)        (1000/f)    //f in Hz, return in ms

//Stream:
//======

#define STREAM_MIN_FREQ         1
#define STREAM_MAX_FREQ         1000
#define STREAM_DEFAULT_FREQ     25

//Log:
//======

#define LOG_MIN_FREQ         1
#define LOG_MAX_FREQ         1000
#define LOG_DEFAULT_FREQ     100

//Plot:
//=====

//Axis:
#define INIT_PLOT_LEN           101
#define INIT_PLOT_XMIN          0
#define INIT_PLOT_XMAX          100
#define INIT_PLOT_YMIN          0
#define INIT_PLOT_YMAX          200
#define VAR_NUM                 6
#define PLOT_BUF_LEN            1000

//Refresh:
#define PLOT_DEFAULT_FREQ       25

//****************************************************************************
// Class(es)
//****************************************************************************

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void array_minmax(int *arr, int len, int *min, int *max);

private:
    int stream_status, fake_data;

    int plot_buf[PLOT_BUF_LEN]; //ToDo!

    unsigned char usb_rx[256];
    int exp_pwm;

    QTimer *timer_stream, *timer_log, *timer_plot;
    QSerialPort USBSerialPort;

    //Plot:

    //X array never changes after initialization
    int graph_xarray[PLOT_BUF_LEN];
    //We store the graph Y arrays in that variable. 1x 1D array per trace (NUM_VAR)
    int graph_yarray[VAR_NUM][PLOT_BUF_LEN];

    void makePlot(void);
    void refreshPlot(int *x, int *y, int len, uint8_t plot_index);
    int gen_test_data(void);
    QCustomPlot customPlot;
    int plot_xmin, plot_ymin, plot_xmax, plot_ymax, plot_len;

    void gen_graph_xarray(void);
    void init_yarrays(void);
    void update_graph_array(int graph, int new_data);

    void update_plot_buf(int new_data);
    void update_plot_buf_single(int *buf, int *idx, int new_data);

    int OpenUSBSerialPort(QString name, int tries, int delay);
    void CloseUSBSerialPort(void);
    int USBSerialPort_Write(char bytes_to_send, unsigned char *serial_tx_data);
    int USBSerialPort_Read(unsigned char *buf);

private slots:

    void on_openComButton_clicked();

    void on_streamONbutton_clicked();

    void on_streamOFFbutton_clicked();

    void timerStreamEvent();

    void timerPlotEvent();

    void on_updateRefreshButton_clicked();

    void on_UpdatePlotpushButton_clicked();

    void on_closeComButton_clicked();

    void on_hSlider_PWM_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
