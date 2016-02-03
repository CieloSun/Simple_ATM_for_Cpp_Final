#include <QWidget>
#include <cstdlib>
#include <QMessageBox>

#include "accountdialog.h"

AccountDialog::AccountDialog(Manage* m, int opt, QWidget *parents)
  :QDialog(parents), option(opt), adminptr(m)
{
  setupUi(this);
  QRegExp acNumRE("[0-9]{19}");
  lineEdit->setValidator(new QRegExpValidator(acNumRE, this));
  QRegExp acPSWRE("[0-9]{6}");
  lineEdit_2->setValidator(new QRegExpValidator(acPSWRE, this));
  lineEdit_2->setEchoMode(QLineEdit::Password);
  QRegExp acPhRE("[0-9]{11}");
  lineEdit_4->setValidator(new QRegExpValidator(acPhRE, this));
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(Okbutton()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(close()));
  AliveButton->setChecked(true);
  buttonGroup->addButton(AliveButton, 1);
  buttonGroup->addButton(FixedButton, 2);
  connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroupChanged(int)));
  setWindowOpacity(0.8);
  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_DeleteOnClose);
}
void AccountDialog::Okbutton()
{
  string acnum = lineEdit->text().toStdString();
  string acpsw = lineEdit_2->text().toStdString();
  string acname = lineEdit_3->text().toStdString();
  string acphone = lineEdit_4->text().toStdString();
  int actype = FixedBox->currentIndex() + 1;
  Account *tempptr;
  if (AliveButton->isChecked()) tempptr = new SavingAccount(acnum, acpsw, acname, acphone);
  else tempptr = new DeadAccount(acnum, acpsw, acname, acphone, actype);
  if (option == 1) adminptr->add(tempptr);
  else if (option == 2)
    {
      if (adminptr->search(acnum) != -1)
        {
          adminptr->update(tempptr);
          if (!adminptr->updatesuccess)
            {
              QMessageBox::critical(this, tr("AccountType Error"),
                                    QString::fromStdString("Account tpye cannot changed!"), QMessageBox::Cancel);
            }
        }
      else QMessageBox::critical(this, tr("Input Error"),
                                 QString::fromStdString("A wrong Account Number"), QMessageBox::Cancel);
    }
  adminptr->store();
}
void AccountDialog::on_AccountButton_clicked()
{
  srand(time(0));
  string randomtext;
  for (int i = 0; i < 19; i++)
    {
      randomtext += ToolNeed::Othertostring(rand() % 10);
    }
  lineEdit->setText(QString::fromStdString(randomtext));
  randomtext.clear();
}

void AccountDialog::buttonGroupChanged(int buttonID)
{
  if (buttonID == 1)
    {
      AliveButton->setChecked(true);
      FixedButton->setChecked(false);
      FixedBox->setEnabled(false);
    }
  else
    {
      FixedButton->setChecked(true);
      AliveButton->setChecked(false);
      FixedBox->setEnabled(true);
      FixedBox->setCurrentIndex(0);
    }
}


