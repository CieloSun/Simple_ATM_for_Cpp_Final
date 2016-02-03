#include "interestsetting.h"
#include "ui_interestsetting.h"
#include <QMessageBox>

InterestSetting::InterestSetting(Manage *m, QWidget *parent) :
  QDialog(parent), admin(m)
{
  setupUi(this);
  QRegExp limit("[0-9]{1,}[.]{0,1}[0-9]{1,}");
  lineEdit->setValidator(new QRegExpValidator(limit, this));
  lineEdit_2->setValidator(new QRegExpValidator(limit, this));
  lineEdit_3->setValidator(new QRegExpValidator(limit, this));
  lineEdit_4->setValidator(new QRegExpValidator(limit, this));
  lineEdit_5->setValidator(new QRegExpValidator(limit, this));
  lineEdit_6->setValidator(new QRegExpValidator(limit, this));
  lineEdit_7->setValidator(new QRegExpValidator(limit, this));

  lineEdit->setText(QString::fromStdString(admin->alive));
  lineEdit_2->setText(QString::fromStdString(admin->threemonth));
  lineEdit_3->setText(QString::fromStdString(admin->halfyear));
  lineEdit_4->setText(QString::fromStdString(admin->oneyear));
  lineEdit_5->setText(QString::fromStdString(admin->twoyear));
  lineEdit_6->setText(QString::fromStdString(admin->threeyear));
  lineEdit_7->setText(QString::fromStdString(admin->fiveyear));

  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_DeleteOnClose);
  setWindowOpacity(0.8);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(okButton()));
}

void InterestSetting::okButton()
{
  admin->alive = lineEdit->text().toStdString();
  admin->threemonth = lineEdit_2->text().toStdString();
  admin->halfyear = lineEdit_3->text().toStdString();
  admin->oneyear = lineEdit_4->text().toStdString();
  admin->twoyear = lineEdit_5->text().toStdString();
  admin->threeyear = lineEdit_6->text().toStdString();
  admin->fiveyear = lineEdit_7->text().toStdString();
  admin->store();
  admin->read();
  QMessageBox::information(this, "Success", "Store the interst settings successfully!", QMessageBox::Ok);
}

