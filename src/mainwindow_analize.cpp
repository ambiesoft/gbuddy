#include <QClipboard>
#include <QApplication>

#include "analyzer.h"

#include "helper.h"
#include "globals.h"

#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::startAnalyze()
{
    Analyzer ana( ui->lineStart->text());
}

