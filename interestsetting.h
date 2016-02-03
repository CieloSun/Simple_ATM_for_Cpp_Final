#ifndef INTERESTSETTING_H
#define INTERESTSETTING_H

#include <QDialog>
#include "Manage.h"
#include "ui_interestsetting.h"

class InterestSetting : public QDialog, public Ui::InterestSetting
{
  Q_OBJECT

public:
  explicit InterestSetting(Manage *m, QWidget *parent = 0);
private slots:
  void okButton();
private:
  Manage *admin;
};

#endif // INTERESTSETTING_H
