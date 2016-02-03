#include "adminenterdialog.h"


#include <QMessageBox>
#include <QWidget>

AdminEnterDialog::AdminEnterDialog(QWidget *parents)
  :QDialog(parents)
{
  setupUi(this);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(Okbutton()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(close()));
  setWindowOpacity(0.8);
  setWindowFlags(Qt::FramelessWindowHint);
  lineEdit_2->setEchoMode(QLineEdit::Password);
  setAttribute(Qt::WA_DeleteOnClose);
}
void AdminEnterDialog::Okbutton()
{
  if ((QString(lineEdit->text()) == adminNumber) && (QString(lineEdit_2->text()) == adminPassWord))
    {
      emit entersuccess(true);
      QMessageBox::information(this, "Success", "Log in successfully", QMessageBox::Ok);
    }
  else QMessageBox::critical(this, "Wrong", "Log in failed", QMessageBox::Ok);
}



