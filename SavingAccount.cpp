#include"SavingAccount.h"

SavingAccount::SavingAccount(SavingAccount* a)
{
  interest = a->interest;
  balance = a->balance;
  for (int i = 0; i < 7; i++) password[i] = a->password[i];
  for (int i = 0; i < 40; i++) name[i] = a->name[i];
  for (int i = 0; i < 20; i++) accountnumber[i] = a->accountnumber[i];
  for (int i = 0; i < 100; i++) timelist[i] = a->timelist[i];
  for (int i = 0; i < 12; i++) phone[i] = a->phone[i];
  lasttime = a->lasttime;
  savetime = a->savetime;
  debtflag = a->debtflag;
  timelistindex = a->timelistindex;
}
SavingAccount::SavingAccount(string user, string pswd, string na, string ph)//Normal SavingAccount
  :Account(user, pswd, na, ph)
{
}
double SavingAccount::getbalance()
{
  settime(time(0));
  int day = int(gettime() / 86400);
  double nowmoney = Account::getbalance()*(1 + interest*day / 360);//The formular
  setbalance(nowmoney);
  return Account::getbalance();
}
void SavingAccount::setinterest(double nowinterest)
{
  interest = nowinterest;
}
void SavingAccount::setinterest(string nowinterest)
{
  interest = StringToDouble(nowinterest);
}

double SavingAccount::getinterest() const
{
  return interest;
}
void SavingAccount::credit(double money)
{
  double newbalance = getbalance() + money;
  setbalance(newbalance);
  record(money);
}
void SavingAccount::debt(double money)//TODO
{
  if (Account::getbalance() >= money)
    {
      double newbalace = getbalance() - money;
      setbalance(newbalace);
      record(-money);
      setdebtflag(true);
    }
  else setdebtflag(false);
}
void SavingAccount::record(double money)
{
  if (timelistindex < 0 || timelistindex > 99)
    {
      timelistindex = 99;
    }
  timelist[timelistindex].time = getlasttime();
  timelist[timelistindex].changemoney = money;
  timelist[timelistindex].balance = Account::getbalance();
  Record Temp;
  for (int i = 0; i < 99; i++)
    {
      for (int j = 0; j < 99 - i; j++)
        {
          if (timelist[j + 1].time > timelist[j].time)
            {
              Temp = timelist[j];
              timelist[j] = timelist[j + 1];
              timelist[j + 1] = Temp;
            }
        }
    }
  timelistindex++;
}
