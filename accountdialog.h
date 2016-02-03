#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include<QDialog>
#include<QString>

#include"Manage.h"
#include<ui_accountdialog.h>

class AccountDialog :public QDialog, public Ui::AccountDialog, public ToolNeed
{
  Q_OBJECT
public:
  AccountDialog(Manage *m, int, QWidget *parents = 0);
  ~AccountDialog()
  {
    delete buttonGroup;
  }

private slots:
  void Okbutton();
  void buttonGroupChanged(int);
  void on_AccountButton_clicked();
private:
  QButtonGroup *buttonGroup = new QButtonGroup;
  int option;
  Manage *adminptr;
};

#endif // ACCOUNTDIALOG


