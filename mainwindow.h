#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>
#include <QSettings>
#include <QRadioButton>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
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
    void saveSettings(void);
    void loadSettings(void);
    ~MainWindow(void);

private:
    Ui::MainWindow *ui;
    QSettings* settings;
    Client* client;

protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_EXITbn_clicked(void);
    void on_actionGitHub_triggered();
    void on_Searchbn_clicked();
    void on_OPENDIRbn_clicked();
    void on_actionOpen_triggered();
};
#endif // MAINWINDOW_H
