#include <QClipboard>
#include <QApplication>

#include "helper.h"

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(QApplication::clipboard(), SIGNAL(dataChanged()),
            this, SLOT(processClipboardChange()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processClipboardChange()
{
    qDebug() << "dataChanged() signal emitted.";

    QString line;
    if(!Helper::GetClipboardFirstLine(&line))
        return;

    ui->lineStart->setText(line);
}

void MainWindow::on_actionOption_triggered()
{
}

