#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

    struct Data {
        QString depot_tools_;
        QString sourceRoot_;
        QString output_;
    } data_;

public:
    explicit OptionDialog(QWidget *parent = nullptr);
    ~OptionDialog();

private:
    void OnBrowseDirCommon(QLineEdit* lineEdit, const QString& title);

private slots:
    void on_pbBrowseDepotTools_clicked();

    void on_pbBrowseSouceRoot_clicked();

    void on_buttonBox_accepted();

private:
    Ui::OptionDialog *ui;

};

#endif // OPTIONDIALOG_H
