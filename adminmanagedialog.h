#ifndef ADMINMANAGEDIALOG_H
#define ADMINMANAGEDIALOG_H

#include<QDialog>
#include<QString>

#include "Manage.h"
#include<ui_adminmanagedialog.h>

class AdminManageDialog :public QDialog, public Ui::AdminManageDialog,public ToolNeed
{
  Q_OBJECT
public:
  AdminManageDialog(Manage *m, int, QWidget *parents = 0);
private slots:
  void Okbutton();
private:
  Manage *adminptr;
  int mod;
};

#endif // ADMINMANAGEDIALOG

