#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<fstream>
#include<iostream>
#include<iomanip>
#include<typeinfo>
#include<cstdlib>
#include<ctime>
#include<vector>

#include "toolneed.h"

using namespace std;

class Account :public ToolNeed
{
  friend class MainWindow;
public:
  Account(string = "0000000000000000000", string = "000000", string = "", string = "00000000000");
  void setpassword(string);
  string getpassword() const;
  void setname(string);
  string getname() const;
  void setaccountnumber(string);
  string getaccountnumber() const;
  void setphone(string);
  string getphone() const;
  void setbalance(double);
  void settime(time_t);
  time_t gettime() const;
  time_t getlasttime() const;
  void setdebtflag(bool f) { debtflag = f; }
  bool getdebtflag() const { return debtflag; }
  virtual double getinterest() const = 0;
  virtual void credit(double) = 0;
  virtual void debt(double) = 0;
  virtual void setinterest(double) = 0;
  virtual double getbalance();
  virtual string showaccount();
  virtual bool getflag();




  virtual ~Account(){}
protected:
  double balance = 0.0;
  char password[7];
  char name[40];
  char accountnumber[20];
  char phone[12];
  time_t lasttime;
  time_t savetime;
  bool debtflag = false;
  struct Record
  {
    time_t time;
    double changemoney;
    double balance;
  } timelist[100];
  int timelistindex = 0;
};
#endif
