#include "sammainwindow.h"
#include "ui_sammainwindow.h"

#include <QApplication>
#include <QDebug>

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


SamMainWindow::SamMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SamMainWindow)
{
    ui->setupUi(this);
}

SamMainWindow::~SamMainWindow()
{
    delete ui;
}


void SamMainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, "Unable to open file", file.errorString());
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setPlainText(in.readAll());
    }
}


void SamMainWindow::on_actionClose_triggered()
{
    ui->textEdit->clear();
}


void SamMainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, "Unable to open file", file.errorString());
            return;
        }

        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
    }
}


void SamMainWindow::on_QuitButton_clicked()
{
    QApplication::quit();
//    qDebug() << "Klickade på quit";
}

