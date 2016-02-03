#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "accountdialog.h"
#include "adminenterdialog.h"
#include "adminmanagedialog.h"
#include "interestsetting.h"

void MainWindow::add()
{
  AccountDialog *accountdialog = new AccountDialog(m, 1);
  accountdialog->exec();
}
void MainWindow::update()
{
  AccountDialog *accountdialog = new AccountDialog(m, 2);
  accountdialog->exec();
}
void MainWindow::deleteaction()
{
  AdminManageDialog *a = new AdminManageDialog(m, 1);
  a->exec();

}
void MainWindow::credit()
{
  AdminManageDialog *a = new AdminManageDialog(m, 2);
  a->exec();
}
void MainWindow::interstmanage()
{
  InterestSetting *a = new InterestSetting(m);
  a->exec();
}

void MainWindow::enteradmin()
{
  AdminEnterDialog *a = new AdminEnterDialog;
  connect(a, SIGNAL(entersuccess(bool)), this, SLOT(doenteradmin(bool)));
  a->exec();
}
void MainWindow::doenteradmin(bool flag)
{
  if (flag)
    {
      ui->actionEnter->setEnabled(false);
      ui->menuOption->setEnabled(true);
      ui->actionExit->setEnabled(true);
    }
}
void MainWindow::exitadmin()
{
  ui->actionEnter->setEnabled(true);
  ui->menuOption->setEnabled(false);
  ui->actionExit->setEnabled(false);
}
