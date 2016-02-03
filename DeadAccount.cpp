#include"DeadAccount.h"

DeadAccount::DeadAccount(DeadAccount* a)
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
  threemonth = a->threemonth;
  halfyear = a->halfyear;
  oneyear = a->oneyear;
  twoyear = a->twoyear;
  threeyear = a->threeyear;
  fiveyear = a->fiveyear;
  accounttype = a->accounttype;
}
DeadAccount::DeadAccount(string user, string pswd, string na, string ph, int type)
  :SavingAccount(user, pswd, na, ph), accounttype(type)
{
  setchooseninterest();
}
void DeadAccount::setchooseninterest()
{
  switch (accounttype)
    {
    case 1:
      setinterest(threemonth);
      break;
    case 2:
      setinterest(halfyear);
      break;
    case 3:
      setinterest(oneyear);
      break;
    case 4:
      setinterest(twoyear);
      break;
    case 5:
      setinterest(threeyear);
      break;
    case 6:
      setinterest(fiveyear);
      break;
    default:
      break;
    }
}

void DeadAccount::setDeadAccountinterest(string thmon, string hy, string oy, string ty, string thy, string fy)
{
  threemonth = StringToDouble(thmon);
  halfyear = StringToDouble(hy);
  oneyear = StringToDouble(oy);
  twoyear = StringToDouble(ty);
  threeyear = StringToDouble(thy);
  fiveyear = StringToDouble(fy);
}
bool DeadAccount::getflag()
{
  bool canget = false;
  int day = int(gettime() / 86400);
  switch (accounttype)
    {
    case 1:
      canget = (day >= 90);
      break;
    case 2:
      canget = (day >= 180);
      break;
    case 3:
      canget = (day >= 360);
      break;
    case 4:
      canget = (day >= 720);
      break;
    case 5:
      canget = (day >= 1080);
      break;
    case 6:
      canget = (day >= 1800);
      break;
    default:
      break;
    }
  return canget;
}

void DeadAccount::debt(double money)
{
  if (getflag())
    {
      SavingAccount::debt(money);
    }
}
string DeadAccount::showaccount()
{
  //cout << left << setw(15) << "Account type" << setw(10);
  string straccounttype = "Account type\t\t\t";
  switch (accounttype)
    {
    case 1:
      straccounttype += "threemonth";
      break;
    case 2:
      straccounttype += "halfyear";
      break;
    case 3:
      straccounttype += "oneyear";
      break;
    case 4:
      straccounttype += "twoyear";
      break;
    case 5:
      straccounttype += "threeyear";
      break;
    case 6:
      straccounttype += "fiveyear";
      break;
    default:
      break;
    }
  straccounttype += "\n";
  return straccounttype + Account::showaccount();
}
