#include "adminmanagedialog.h"

#include <QMessageBox>
#include <QWidget>

AdminManageDialog::AdminManageDialog(Manage* m, int mo, QWidget *parents)
  :QDialog(parents), adminptr(m), mod(mo)
{
  setupUi(this);
  QRegExp acnumRE("[0-9]{19}");
  lineEdit->setValidator(new QRegExpValidator(acnumRE, this));
  QRegExp acpswRE("[0-9]{6}");
  lineEdit_2->setValidator(new QRegExpValidator(acpswRE, this));
  QRegExp acCreditRE("[0-9]{1,}[.]{0,1}[0-9]{1,}");
  lineEdit_2->setEchoMode(QLineEdit::Password);
  lineEdit_3->setValidator(new QRegExpValidator(acCreditRE, this));
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(Okbutton()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(close()));
  setWindowOpacity(0.8);
  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_DeleteOnClose);
  if (mod == 1)
    {
      lineEdit_3->setVisible(false);
      label_3->setVisible(false);
    }
}
void AdminManageDialog::Okbutton()
{//TODO
  if (mod == 1)
    {
      string acnum = lineEdit->text().toStdString();
      string acpsw = lineEdit_2->text().toStdString();
      int index = adminptr->search(acnum);
      if (index != -1)
        {
          if (adminptr->AccountPtrArray[index]->getpassword() == acpsw)
            {
              adminptr->deleteact(adminptr->AccountPtrArray[index]);
              QMessageBox::information(this,
                                       "Success",
                                       "Delete account "+QString::fromStdString(adminptr->AccountPtrArray[index]->getaccountnumber())
                                       , QMessageBox::Ok);
            }
          else QMessageBox::critical(this, "PassWord Wrong", "Please input it again!", QMessageBox::Ok);
        }
      else QMessageBox::critical(this, "Account Wrong", "Please input it again!", QMessageBox::Ok);
    }
  else
    {
      string acnum = lineEdit->text().toStdString();
      string acpsw = lineEdit_2->text().toStdString();
      string moneystring = lineEdit_3->text().toStdString();
      double creditmoney = StringToDouble(moneystring);
      int index = adminptr->search(acnum);
      if (index != -1)
        {
          if (adminptr->AccountPtrArray[index]->getpassword() == acpsw)
            {//TODO
              adminptr->AccountPtrArray[index]->credit(creditmoney);
              adminptr->store();
              QMessageBox::information(this, "Success", "Credit successfully", QMessageBox::Ok);
            }
          else QMessageBox::critical(this, "PassWord Wrong", "Please input it again!", QMessageBox::Ok);
        }
      else QMessageBox::critical(this, "Account Wrong", "Please input it again!", QMessageBox::Ok);
    }

}

