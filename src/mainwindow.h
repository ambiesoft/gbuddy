#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "optiondialog.h"
#include "analyzer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Analyzer ana_;
    void startAnalyze();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void processClipboardChange();
    void on_actionOption_triggered();
    void on_pbAnalize_clicked();
    void on_pbGnDesc_clicked();
    void on_pbGnRefs_clicked();
    void on_pbOpenMD_clicked();
    void on_txtLine_textChanged();
};
#endif // MAINWINDOW_H
