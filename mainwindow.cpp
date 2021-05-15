#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , settings(new QSettings(this))
    , client(new Client(new BFSAlgorithm()))
{
    ui->setupUi(this);
    this->setWindowTitle(tr("FileGraph"));
}

MainWindow::~MainWindow(void)
{
    delete this->settings;
    delete this->client;
    delete this->ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this, tr("FileGraph"),
                             tr("Are you sure ?"),
                             QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) event->accept();
    else event->ignore();
}


void MainWindow::on_EXITbn_clicked(void) { this->close(); }
