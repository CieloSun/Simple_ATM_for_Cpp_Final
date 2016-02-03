#ifndef MANAGE_H
#define MANAGE_H

#include"DeadAccount.h"

class Manage :public ToolNeed
{
  friend class MainWindow;
public:
  Manage();
  //read function
  void read();
  void readAccount();
  void readSavingAccount(fstream &);
  void readDeadAccount(fstream &);
  //store function
  void store();
  void writeSavingAccount();
  void writeDeadAccount();
  //search function
  int search(string user);
  int searchSavingAccount(string);
  int searchDeadAccount(string);
  //action function
  void add(Account*);
  void add(SavingAccount &);
  void add(DeadAccount &);
  void update(Account*);
  void update(SavingAccount &);
  void update(DeadAccount &);
  void deleteact(Account *);
  void deleteact(SavingAccount);
  void deleteact(DeadAccount);
  ~Manage()
  {
    store();
  }

  vector<SavingAccount> SavingAccountArray;
  vector<DeadAccount> DeadAccountArray;
  vector<Account *> AccountPtrArray;
  string alive = "0.0035";
  string threemonth = "0.021";
  string halfyear = "0.023";
  string oneyear = "0.025";
  string twoyear = "0.03";
  string threeyear = "0.035";
  string fiveyear = "0.0375";
  bool updatesuccess = true;
};
#endif
