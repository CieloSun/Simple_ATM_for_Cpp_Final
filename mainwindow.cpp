#include <QMessageBox>
#include <QString>
#include <QMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

//Constructor
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  buttonGroup->addButton(ui->pushButton_0, 0);
  buttonGroup->addButton(ui->pushButton_1, 1);
  buttonGroup->addButton(ui->pushButton_2, 2);
  buttonGroup->addButton(ui->pushButton_3, 3);
  buttonGroup->addButton(ui->pushButton_4, 4);
  buttonGroup->addButton(ui->pushButton_5, 5);
  buttonGroup->addButton(ui->pushButton_6, 6);
  buttonGroup->addButton(ui->pushButton_7, 7);
  buttonGroup->addButton(ui->pushButton_8, 8);
  buttonGroup->addButton(ui->pushButton_9, 9);

  ui->Hintlabel->setText(tr("Please enter your Account Number:"));

  connect(ui->oKButton, SIGNAL(clicked()), this, SLOT(okAction()));
  connect(ui->CancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
  connect(ui->ClearButton, SIGNAL(clicked()), this, SLOT(clearbutton()));

  connect(ui->CheckButton, SIGNAL(clicked()), this, SLOT(checkaction()));
  connect(ui->DrawButton, SIGNAL(clicked()), this, SLOT(drawaction()));
  connect(ui->TransferButton, SIGNAL(clicked()), this, SLOT(transferaction()));

  connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(inputnumber(int)));
  connect(ui->pushButton_00, SIGNAL(clicked()), this, SLOT(inputdoublezero()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(inputpoint()));

  connect(ui->actionEnter, SIGNAL(triggered()), this, SLOT(enteradmin()));
  connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitadmin()));
  connect(ui->actionAdd, SIGNAL(triggered()), this, SLOT(add()));
  connect(ui->actionUpdate, SIGNAL(triggered()), this, SLOT(update()));
  connect(ui->actionDelete, SIGNAL(triggered()), this, SLOT(deleteaction()));
  connect(ui->actionCredit, SIGNAL(triggered()), this, SLOT(credit()));
  connect(ui->actionInterestSettings, SIGNAL(triggered()), this, SLOT(interstmanage()));

  QPixmap pixmap = QPixmap(":/image/background").scaled(this->size());
  QPalette palette(this->palette());
  palette.setBrush(QPalette::Background, QBrush(pixmap));
  this->setPalette(palette);

  setWindowOpacity(0.8);
  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_DeleteOnClose);
}
//Judge the Input
bool MainWindow::judgeInput(string needjudge, size_t needbit, string wrongMessage)
{
  if (needjudge.size() != needbit)
    {
      ShowError(wrongMessage);
      needjudge.clear();
      emit ui->ClearButton->clicked();
      return false;
    }
  else return true;
}
//A common error message box
void MainWindow::ShowError(string showmessage)
{
  QMessageBox::critical(this, tr("Input Error"), QString::fromStdString(showmessage), QMessageBox::Cancel);
}
//
void MainWindow::ChangeView(PRODUCE Toproduce)
{
  switch (produce)
    {
    case IpAcPsw:
    case TransferView:
    case Money:
      emit ui->ClearButton->clicked();
      break;
    default:
      ui->textBrowser->clear();
      break;
    }

  switch (Toproduce)
    {
    case IpAcNum:
      ui->TransferButton->setEnabled(false);
      ui->DrawButton->setEnabled(false);
      ui->CheckButton->setEnabled(false);
      ui->CancelButton->setEnabled(false);
      ui->ClearButton->setEnabled(true);
      ui->oKButton->setEnabled(true);
      ui->Hintlabel->setText(tr("Please enter your Account Number:"));
      ui->textBrowser->setText(QString::fromStdString(accountNumber));
      break;
    case IpAcPsw:
      ui->TransferButton->setEnabled(false);
      ui->DrawButton->setEnabled(false);
      ui->CheckButton->setEnabled(false);
      ui->CancelButton->setEnabled(true);
      ui->ClearButton->setEnabled(true);
      ui->oKButton->setEnabled(true);
      ui->Hintlabel->setText(tr("Please enter your Account Password:"));
      accountPSW.clear();
      showPSW.clear();
      break;
    case EnableView:
      ui->TransferButton->setEnabled(true);
      ui->DrawButton->setEnabled(true);
      ui->CheckButton->setEnabled(true);
      ui->CancelButton->setEnabled(false);
      ui->ClearButton->setEnabled(false);
      ui->oKButton->setEnabled(false);
      ui->Hintlabel->setText(tr("Please choose the option:"));
      break;
    case CheckView:
      ui->TransferButton->setEnabled(false);
      ui->DrawButton->setEnabled(false);
      ui->CheckButton->setEnabled(false);
      ui->CancelButton->setEnabled(true);
      ui->ClearButton->setEnabled(false);
      ui->oKButton->setEnabled(true);
      ui->Hintlabel->setText("Your nearest 100 records:");
      checkstring = m->AccountPtrArray[(m->search(accountNumber))]->showaccount();
      ui->textBrowser->setText(QString::fromStdString(checkstring));
      break;
    case TransferView:
      ui->TransferButton->setEnabled(false);
      ui->DrawButton->setEnabled(false);
      ui->CheckButton->setEnabled(false);
      ui->CancelButton->setEnabled(true);
      ui->ClearButton->setEnabled(true);
      ui->oKButton->setEnabled(true);
      ui->Hintlabel->setText(tr("Please enter the Account Number you want to transfer:"));
      ui->textBrowser->setText(QString::fromStdString(toaccountNumber));
      break;
    case Money:
      ui->TransferButton->setEnabled(false);
      ui->DrawButton->setEnabled(false);
      ui->CheckButton->setEnabled(false);
      ui->CancelButton->setEnabled(true);
      ui->ClearButton->setEnabled(true);
      ui->oKButton->setEnabled(true);
      ui->Hintlabel->setText(tr("Please enter the Money:"));
      moneystring.clear();
      break;
    default:
      break;
    }
  produce = Toproduce;
}
//SLOTS
void MainWindow::inputnumber(int buttonID)
{
  if (produce == IpAcNum)
    {
      accountNumber += Othertostring(buttonID);
      ui->textBrowser->setText(QString::fromStdString(accountNumber));
    }
  else if (produce == IpAcPsw)
    {
      accountPSW += Othertostring(buttonID);
      showPSW += "*";
      ui->textBrowser->setText(QString::fromStdString(showPSW));
    }
  else if (produce == Money)
    {
      moneystring += Othertostring(buttonID);
      ui->textBrowser->setText(QString::fromStdString(moneystring));
    }
  else if (produce == TransferView)
    {
      toaccountNumber += Othertostring(buttonID);
      ui->textBrowser->setText(QString::fromStdString(toaccountNumber));
    }
}
void MainWindow::inputdoublezero()
{
  emit buttonGroup->buttonClicked(0);
  emit buttonGroup->buttonClicked(0);
}
void MainWindow::inputpoint()
{
  if (produce == Money)
    {
      moneystring += ".";
      ui->textBrowser->setText(QString::fromStdString(moneystring));
    }
}

void MainWindow::checkaction()
{
  ChangeView(CheckView);
}
void MainWindow::transferaction()
{
  ChangeView(TransferView);
}
void MainWindow::drawaction()
{
  ChangeView(Money);
}

void MainWindow::clearbutton()
{
  switch (produce)
    {
    case IpAcNum:
      accountNumber.clear();
      ui->textBrowser->clear();
      break;
    case IpAcPsw:
      accountPSW.clear();
      showPSW.clear();
      ui->textBrowser->clear();
      break;
    case TransferView:
      toaccountNumber.clear();
      ui->textBrowser->clear();
      break;
    case Money:
      moneystring.clear();
      ui->textBrowser->clear();
      break;
    default:
      ShowError("Cannot clear in this screen");
      break;
    }
}
void MainWindow::cancel()
{
  switch (produce)
    {
    case IpAcPsw:
      ChangeView(IpAcNum);
      break;
    case TransferView:
    case Money:
    case CheckView:
      ChangeView(EnableView);
      break;
    default:
      break;
    }
}
void MainWindow::okAction()
{
  switch (produce)
    {
    case IpAcNum:
      if (judgeInput(accountNumber, 19, "Wrong Account Number,Please reput."))
        {
          AccountPtrIndex = m->search(accountNumber);
          if (AccountPtrIndex == -1)
            {
              ShowError("A wrong Account Number!");

              emit ui->ClearButton->clicked();
            }
          else
            {
              ChangeView(IpAcPsw);//Mark
            }
        }
      break;
    case IpAcPsw:
      if (judgeInput(accountPSW, 6, "Wrong Bit of password,Please reput."))
        {
          if (AccountPtrIndex != -1)
            {
              string temppsw = m->AccountPtrArray.at(AccountPtrIndex)->getpassword();
              if (accountPSW != temppsw)
                {
                  ShowError("A wrong Password!");

                  emit ui->ClearButton->clicked();
                }
              else
                {
                  ChangeView(EnableView);
                }
            }
        }

      break;
    case Money:
      inputmoney = StringToDouble(moneystring);
      if (m->AccountPtrArray[AccountPtrIndex]->getflag())
        {
          if (transferflag)
            {
              m->AccountPtrArray[AccountPtrIndex]->debt(inputmoney);
              if (m->AccountPtrArray[AccountPtrIndex]->getdebtflag())
                {
                  m->AccountPtrArray[ToIndex]->credit(inputmoney);
                  m->store();
                  transferflag = false;
                  toaccountNumber.clear();
                  QMessageBox::information(this, "Information", "Transfer Successfully!", QMessageBox::Ok);
                }
              else ShowError("Balance is not enough");
            }
          else
            {
              m->AccountPtrArray[AccountPtrIndex]->debt(inputmoney);
              if (m->AccountPtrArray[AccountPtrIndex]->getdebtflag()) ui->textBrowser->setText("Please receive your money.");
              else ShowError("Balance is not enough");
            }
        }
      else
        {
          ShowError("You can not do this as it is a fixed deposit account and the time is not enough.");
        }
      break;
    case TransferView:
      if (judgeInput(toaccountNumber, 19, "Wrong Account Number,Please reput."))
        {
          ToIndex = m->search(toaccountNumber);
          if (ToIndex == -1)
            {
              ShowError("A wrong Account Number !");

              emit ui->ClearButton->clicked();
            }
          else
            {
              transferflag = true;
              ChangeView(Money);//Mark
            }
        }
      break;
    case CheckView:
      ChangeView(EnableView);//Mark
      break;
    default:
      break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton) {
      m_Drag = true;
      m_DragPosition = event->globalPos() - this->pos();
      event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
  if (m_Drag && (event->buttons() && Qt::LeftButton)) {
      move(event->globalPos() - m_DragPosition);
      event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
  m_Drag = false;
}

MainWindow::~MainWindow()
{
  delete m;
  delete buttonGroup;
  delete ui;
  //cerr<<"has deleted"<<endl;
}
