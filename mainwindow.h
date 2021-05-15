#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSettings>
#include "client.h"
#include "bfsalgorithm.h"
#include "dfsalgorithm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);

private:
    Ui::MainWindow *ui;
    QSettings* settings;
    Client* client;

protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_EXITbn_clicked(void);
};
#endif // MAINWINDOW_H
