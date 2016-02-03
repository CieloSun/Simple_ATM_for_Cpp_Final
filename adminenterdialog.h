#ifndef ADMINENTERDIALOG_H
#define ADMINENTERDIALOG_H

#include<QDialog>
#include<QString>

#include<ui_adminenterdialog.h>

class AdminEnterDialog :public QDialog, public Ui::Adminenterdialog
{
  Q_OBJECT
public:
  AdminEnterDialog(QWidget *parents = 0);
signals:
  void entersuccess(bool);
private slots:
  void Okbutton();
private:
  QString adminNumber = QString("admin");
  QString adminPassWord = QString("123456");
};

#endif // ADMINENTERDIALOG


