#include <QFileDialog>

#include "helper.h"
#include "globals.h"
#include "consts.h"

#include "optiondialog.h"
#include "ui_optiondialog.h"

using namespace Consts;

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

    data_.depot_tools_ = gSettings->valueString(KEY_DEPOT_TOOLS);
    data_.sourceRoot_=gSettings->valueString(KEY_SOURCE_ROOT);
    data_.output_=gSettings->valueString(KEY_OUTPUT);

    ui->lineDepotTools->setText(data_.depot_tools_);
    ui->lineSourceRoot->setText(data_.sourceRoot_);
    ui->lineOutput->setText(data_.output_);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::OnBrowseDirCommon(QLineEdit* lineEdit, const QString& title)
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    title,
                                                    lineEdit->text());
    if(dir.isEmpty())
        return;

    lineEdit->setText(dir);
}
void OptionDialog::on_pbBrowseDepotTools_clicked()
{
    OnBrowseDirCommon(ui->lineDepotTools, tr("Choose depot_tools Directory"));
}


void OptionDialog::on_pbBrowseSouceRoot_clicked()
{
    OnBrowseDirCommon(ui->lineSourceRoot, tr("Choose the root directory of source tree"));
}


void OptionDialog::on_buttonBox_accepted()
{
    data_.depot_tools_ = ui->lineDepotTools->text();
    data_.sourceRoot_=ui->lineSourceRoot->text();
    data_.output_=ui->lineOutput->text();

    gSettings->setValue(KEY_DEPOT_TOOLS, data_.depot_tools_);
    gSettings->setValue(KEY_SOURCE_ROOT, data_.sourceRoot_);
    gSettings->setValue(KEY_OUTPUT, data_.output_);
}

