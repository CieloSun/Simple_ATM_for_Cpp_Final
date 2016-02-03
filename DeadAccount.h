#ifndef DEADACCOUNT_H
#define DEADACCOUNT_H

#include"SavingAccount.h"

class DeadAccount :public SavingAccount
{

private:
  double threemonth = 0.021;
  double halfyear = 0.023;
  double oneyear = 0.025;
  double twoyear = 0.03;
  double threeyear = 0.035;
  double fiveyear = 0.0375;
  int accounttype;
public:
  DeadAccount() :SavingAccount("0000000000000000000", "000000", "", "00000000000"), accounttype(1){}
  DeadAccount(string, string, string, string, int);
  DeadAccount(DeadAccount*);
  void setDeadAccountinterest(string, string, string, string, string, string);
  void setchooseninterest();
  void setaccounttype(int a){ accounttype = a; }
  int getaccounttype(){ return accounttype; }
  virtual void debt(double);
  virtual string showaccount();
  virtual bool getflag();
  virtual ~DeadAccount(){}
};
#endif
