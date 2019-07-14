﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui
{
class MainWindow;
}
class QSerialPort;
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
protected:
    void initSerialPortList(void);
    void initBautrateList(void);
    void initDataBitList(void);
    void initStopBitList(void);
    void initCheckBitList(void);
    bool is_open_serailport;
    QSerialPort* serial_port;
    int last_combox_index;
    bool eventFilter(QObject* watched, QEvent* event);
    QTimer* send_timer;
    QMap<quint64, QByteArray>* rcv_data_map;
    QString GetCorrectUnicode(const QByteArray& ba);
private:
    Ui::MainWindow* ui;
signals:

public slots:
    void slotOnSendSerialContent(void);
};

#endif // MAINWINDOW_H
