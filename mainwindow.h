#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

#include "Manage.h"
#include "adminenterdialog.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow, public ToolNeed
{
  Q_OBJECT

public:
  enum PRODUCE { IpAcNum, IpAcPsw, EnableView, CheckView, Money, TransferView } produce = IpAcNum;

  explicit MainWindow(QWidget *parent = 0);//

  bool judgeInput(string, size_t, string);//
  void ShowError(string);//
  void ChangeView(PRODUCE);//

  ~MainWindow();//
private slots:
  //for administor
  void enteradmin();
  void doenteradmin(bool);
  void exitadmin();
  void add();
  void update();
  void deleteaction();
  void credit();
  void interstmanage();
  //for user
  void cancel();//
  void okAction();//
  void clearbutton();//

  void inputnumber(int);//
  void inputdoublezero();//
  void inputpoint();//

  void checkaction();//
  void drawaction();//
  void transferaction();//

  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);




private:
  Ui::MainWindow *ui;
  QButtonGroup *buttonGroup = new QButtonGroup;
  Manage *m = new Manage;

  QPoint m_DragPosition;
  bool m_Drag = false;
  bool transferflag = false;
  string accountNumber;
  string accountPSW;
  string showPSW;
  double inputmoney;
  string moneystring;
  int AccountPtrIndex;
  string toaccountNumber;
  int ToIndex;
  string checkstring;


};

#endif // MAINWINDOW_H
