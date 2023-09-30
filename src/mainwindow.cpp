#include <QClipboard>
#include <QApplication>

#include "optiondialog.h"
#include "taskgn.h"

#include "helper.h"
#include "globals.h"

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    optionDialog_ = new OptionDialog(this);

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
    if(!GetClipboardFirstLine(&line))
        return;

    ui->lineStart->setText(line);
}

void MainWindow::on_actionOption_triggered()
{
    optionDialog_->exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    gSettings->sync();
    QMainWindow::closeEvent(event);
}


void MainWindow::on_pbAnalize_clicked()
{
    startAnalyze();
}


void MainWindow::on_pbGnDesc_clicked()
{
    TaskGn* pTaskGn = new TaskGn(TaskGn::TASK_KIND_DESC,
                                 optionDialog_->depot_tools(),
                                 optionDialog_->sourceRoot(),
                                 optionDialog_->outDir(),
                                 ui->lineStart->text());
    pTaskGn->start();
    pTaskGn->wait();

    ui->txtResult->setText(pTaskGn->getResults());

}

