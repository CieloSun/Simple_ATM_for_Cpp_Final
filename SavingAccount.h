#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include"Account.h"

class SavingAccount :public Account
{
public:
  SavingAccount() :Account("0000000000000000000", "000000", "", "00000000000"){}
  SavingAccount(SavingAccount*);
  SavingAccount(string, string, string, string);
  void record(double);
  virtual void setinterest(double);
  virtual void setinterest(string);
  virtual double getbalance() override;//Calculate balance
  virtual double getinterest() const override;//see interest
  virtual void credit(double) override;
  virtual void debt(double) override;
  virtual ~SavingAccount(){}
protected:
  double interest = 0.0035;
};
#endif
