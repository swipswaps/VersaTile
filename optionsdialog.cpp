#include "optionsdialog.h"
#include "ui_optionsdialog.h"

#include <QCheckBox>
#include <QComboBox>
#include <QSlider>

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog),
    mSettings("mq32.de", "versa-tile")
{
	ui->setupUi(this);

	this->mSettings.beginGroup("behaviour");
	this->ui->cbEnableAutoGrid->setChecked(this->mSettings.value("autogrid", true).toBool());
	this->ui->slAutoGridThreshold->setValue(this->mSettings.value("gridthresh", 50).toInt());
	this->mSettings.endGroup();

	this->mSettings.beginGroup("display");
	this->ui->cbGroundMode->setCurrentIndex(this->mSettings.value("groundmode", 2).toInt());
	this->mSettings.endGroup();
}

OptionsDialog::~OptionsDialog()
{
	delete ui;
}

void OptionsDialog::on_buttonBox_accepted()
{
	this->mSettings.beginGroup("behaviour");
	this->mSettings.setValue("autogrid", this->ui->cbEnableAutoGrid->isChecked());
	this->mSettings.setValue("gridthresh", this->ui->slAutoGridThreshold->value());
	this->mSettings.endGroup();

	this->mSettings.beginGroup("display");
	this->mSettings.setValue("groundmode", this->ui->cbGroundMode->currentIndex());
	this->mSettings.endGroup();
}
