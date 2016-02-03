#include"Account.h"

Account::Account(string user, string psword, string username, string phnumber)
{
  setaccountnumber(user);
  setpassword(psword);
  setname(username);
  setphone(phnumber);
  settime(time(0));
  for (auto &item : timelist)
    {
      item.time = 0;
      item.changemoney = 0.0;
      item.balance = 0.0;
    }
}
bool Account::getflag()
{
  return true;
}

void Account::setbalance(double bal)
{
  balance = bal;
}
double Account::getbalance()
{
  return balance;
}
void Account::setaccountnumber(string user)
{
  size_t len = user.size();
  if (len == 19)
    {
      user.copy(accountnumber, len);
      accountnumber[len] = '\0';
    }
}
string Account::getaccountnumber() const
{
  return accountnumber;
}
void Account::setpassword(string psword)
{
  size_t len = psword.size();
  if (len == 6)
    {
      psword.copy(password, len);
      password[len] = '\0';
    }
}
string Account::getpassword() const//TODO,BUT NEVER...
{
  return password;
}
void Account::setname(string username)
{
  size_t len = username.size();
  len = (len < 40 ? len : 39);
  username.copy(name, len);
  name[len] = '\0';
}
string Account::getname() const
{
  return name;
}
void Account::setphone(string phnumber)
{
  size_t len = phnumber.size();
  if (len == 11)
    {
      phnumber.copy(phone, len);
      phone[len] = '\0';
    }
}
string Account::getphone() const
{
  return phone;
}
void Account::settime(time_t ltime)
{
  savetime = ltime - lasttime;
  lasttime = ltime;
}
time_t Account::gettime() const
{
  return savetime;
}
time_t Account::getlasttime() const
{
  return lasttime;
}
string Account::showaccount()
{
  string accountrecord;
  for (int i = 0; i < 100; i++)
    {
      if (timelist[i].changemoney)
        {
          string strctime = ctime(&(timelist[i].time));
          size_t l = strctime.length();
          strctime[l - 1] = '\0';
          string strchangmoney;
          double cgmoney = timelist[i].changemoney;
          if (cgmoney >= 0) strchangmoney = "+" + ToolNeed::Othertostring(cgmoney);
          else strchangmoney = ToolNeed::Othertostring(cgmoney);
          string strbalance = ToolNeed::Othertostring(timelist[i].balance);
          string perrecord = strctime + "\t\t\t" + strchangmoney + "\t\t\t" + strbalance + "\n";
          accountrecord += perrecord;
        }
    }
  return accountrecord;
}
