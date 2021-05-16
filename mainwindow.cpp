#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , settings(new QSettings(this))
    , client(new Client(new BFSAlgorithm(), this))
{
    ui->setupUi(this);
    QObject::connect(this->ui->DFSrb, &QRadioButton::clicked, client, [this](){
        client->setAlgorithm(new DFSAlgorithm);
    });
    QObject::connect(this->ui->BFSrb, &QRadioButton::clicked, client, [this](){
        this->client->setAlgorithm(new BFSAlgorithm);
    });
    this->setWindowTitle(tr("FileGraph"));
    this->ui->DIRNAMEle->setReadOnly(true);
    loadSettings();
}

void MainWindow::saveSettings()
{
    this->settings->beginGroup(tr("MainWindow"));
    this->settings->setValue(tr("Geometry"), this->geometry());
    this->settings->setValue(tr("Dir"), this->ui->DIRNAMEle->text());
    this->settings->setValue(tr("File"), this->ui->FILENAMEle->text());
    this->settings->endGroup();
}

void MainWindow::loadSettings()
{
    this->settings->beginGroup(tr("MainWindow"));
    this->setGeometry(this->settings->value(tr("Geometry"), QRect(635, 335, 635, 335)).toRect());
    this->ui->FILENAMEle->setText(this->settings->value(tr("File"), "").toString());
    this->ui->DIRNAMEle->setText(this->settings->value(tr("Dir"), "").toString());
    this->settings->endGroup();
}

MainWindow::~MainWindow(void)
{
    saveSettings();
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

void MainWindow::on_actionGitHub_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/VladYetti/FileGraph"));
}

void MainWindow::on_Searchbn_clicked()
{
    if(this->ui->FILENAMEle->text() == ""  ||  this->ui->DIRNAMEle->text() == "")
    {
        QMessageBox::warning(this,tr("FileGraph"), tr("File or Dir Name is empty!"));
        return;
    }

    this->ui->Searchbn->setDisabled(true);

    QString path = this->client->executeAlgorithm(this->ui->DIRNAMEle->text(),
                                   this->ui->FILENAMEle->text());
    if(path == "") QMessageBox::warning(this,tr("FileGraph"), tr("File not found!"));


    this->ui->Searchbn->setDisabled(false);
    QMessageBox::warning(this,tr("FileGraph"), tr("SUCCESS!!!  " ) + path);

}

void MainWindow::on_OPENDIRbn_clicked()
{
    this->ui->DIRNAMEle->setText(QFileDialog::getExistingDirectory(this, tr("Dir"), tr("C:\\")));
}

void MainWindow::on_actionOpen_triggered()
{
    this->ui->DIRNAMEle->setText(QFileDialog::getExistingDirectory(this, tr("Dir"), tr("C:\\")));
}
