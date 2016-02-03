#include"Manage.h"

Manage::Manage()
{
  read();
}

//Store
void Manage::store()
{
  writeSavingAccount();
  writeDeadAccount();
  ofstream file("InterestSettings.dat");
  double alive_f = StringToDouble(alive);
  double threemonth_f = StringToDouble(threemonth);
  double halfyear_f = StringToDouble(halfyear);
  double oneyear_f = StringToDouble(oneyear);
  double twoyear_f = StringToDouble(twoyear);
  double threeyear_f = StringToDouble(threeyear);
  double fiveyear_f = StringToDouble(fiveyear);
  file << alive_f << threemonth_f << halfyear_f << oneyear_f << twoyear_f << threeyear_f << fiveyear_f;
  file.close();
}
void Manage::writeSavingAccount()
{
  fstream setup("SavingAccount.dat", ios::out);
  setup.close();
  fstream SavingAccountFile("SavingAccount.dat", ios::in | ios::out | ios::binary);
  if (!SavingAccountFile)
    {

      cerr << "DataBase could not open" << endl;
      exit(0);
    }
  for (int i = 0; i < (int)SavingAccountArray.size(); i++)
    {
      SavingAccountFile.seekp(i*sizeof(SavingAccount));
      SavingAccountFile.write(reinterpret_cast<const char*>(&SavingAccountArray[i]), sizeof(SavingAccount));
    }
}
void Manage::writeDeadAccount()
{
  fstream setup("DeadAccount.dat", ios::out);
  setup.close();
  fstream DeadAccountFile("DeadAccount.dat", ios::in | ios::out | ios::binary);
  if (!DeadAccountFile)
    {
      cerr << "DataBase could not open" << endl;
      exit(0);
    }
  for (int i = 0; i < (int)DeadAccountArray.size(); i++)
    {
      DeadAccountFile.seekp(i*sizeof(DeadAccount));
      DeadAccountFile.write(reinterpret_cast<const char*>(&DeadAccountArray[i]), sizeof(DeadAccount));
    }
}
//Read
void Manage::read()
{
firstimesetupSavingAccount:
  fstream SavingAccountFile("SavingAccount.dat", ios::in | ios::out | ios::binary);
  if (!SavingAccountFile)
    {
      fstream setup("SavingAccount.dat", ios::out);
      setup.close();
      goto firstimesetupSavingAccount;
      //OK,maybe I find a new but too voilence way to solve a problem.
    }
firstimesetupDeadAccount:
  fstream DeadAccountFile("DeadAccount.dat", ios::in | ios::out | ios::binary);
  if (!DeadAccountFile)
    {
      fstream setup("DeadAccount.dat", ios::out);
      setup.close();
      goto firstimesetupDeadAccount;
      //TheSame
    }
  ifstream file("InterestSettings.dat");
  if (file)
    {
      double alive_f;
      double threemonth_f;
      double halfyear_f;
      double oneyear_f;
      double twoyear_f;
      double threeyear_f;
      double fiveyear_f;
      while (!file.eof())
        {
          file >> alive_f >> threemonth_f >> halfyear_f >> oneyear_f >> twoyear_f >> threeyear_f >> fiveyear_f;
        }
      alive = Othertostring(alive_f);
      threemonth = Othertostring(threemonth_f);
      halfyear = Othertostring(halfyear_f);
      oneyear = Othertostring(oneyear_f);
      twoyear = Othertostring(twoyear_f);
      threeyear = Othertostring(threeyear_f);
      fiveyear = Othertostring(fiveyear_f);
    }
  file.close();
  readSavingAccount(SavingAccountFile);
  readDeadAccount(DeadAccountFile);
  readAccount();
}
void Manage::readAccount()
{
  AccountPtrArray.clear();
  vector<SavingAccount>::iterator it;
  Account* ptrTemp;
  for (it = SavingAccountArray.begin(); it != SavingAccountArray.end(); it++)
    {
      ptrTemp = &*it;
      AccountPtrArray.push_back(ptrTemp);
    }
  vector<DeadAccount>::iterator it2;
  for (it2 = DeadAccountArray.begin(); it2 != DeadAccountArray.end(); it2++)
    {
      ptrTemp = &*it2;
      AccountPtrArray.push_back(ptrTemp);
    }
}
void Manage::readSavingAccount(fstream &readfile)
{
  SavingAccount SavingAccountTemp;
  SavingAccountArray.clear();
  for (int i = 0; !readfile.eof(); i++)
    {
      readfile.seekg(i*sizeof(SavingAccount));
      readfile.read(reinterpret_cast<char*>(&SavingAccountTemp), sizeof(SavingAccount));
      SavingAccountTemp.setinterest(alive);
      SavingAccountArray.push_back(SavingAccountTemp);
    }
}
void Manage::readDeadAccount(fstream &readfile)
{
  DeadAccount DeadAccountTemp;
  DeadAccountArray.clear();
  for (int i = 0; !readfile.eof(); i++)
    {
      readfile.seekg(i*sizeof(DeadAccount));
      readfile.read(reinterpret_cast<char*>(&DeadAccountTemp), sizeof(DeadAccount));
      DeadAccountTemp.setDeadAccountinterest(threemonth, halfyear, oneyear, twoyear, threeyear, fiveyear);
      DeadAccountArray.push_back(DeadAccountTemp);
    }
}
//Search
int Manage::search(string user)
{
  for (int i = 0; i < (int)AccountPtrArray.size(); i++)
    {
      if (AccountPtrArray[i]->getaccountnumber() == user) return i;
    }
  return -1;
}

int Manage::searchSavingAccount(string user)
{
  for (int i = 0; i < (int)SavingAccountArray.size(); i++)
    {
      if (SavingAccountArray[i].getaccountnumber() == user) return i;
    }
  return -1;
}
int Manage::searchDeadAccount(string user)
{
  for (int i = 0; i < (int)DeadAccountArray.size(); i++)
    {
      if (DeadAccountArray[i].getaccountnumber() == user) return i;
    }
  return -1;
}
//Choose the real function
void Manage::add(Account *op)
{
  if (typeid(*op) == typeid(SavingAccount))
    {
      SavingAccount* op2 = dynamic_cast<SavingAccount*>(op);
      SavingAccount ref = SavingAccount(op2);
      add(ref);
    }
  else
    {
      DeadAccount* op3 = dynamic_cast<DeadAccount*>(op);
      DeadAccount ref2 = DeadAccount(op3);
      add(ref2);
    }
}
void Manage::update(Account *op)
{
  if (typeid(*op) == typeid(SavingAccount))
    {
      SavingAccount* op2 = dynamic_cast<SavingAccount*>(op);
      SavingAccount ref = SavingAccount(op2);
      update(ref);
    }
  else
    {
      DeadAccount* op3 = dynamic_cast<DeadAccount*>(op);
      DeadAccount ref2 = DeadAccount(op3);
      update(ref2);
    }
}
void Manage::deleteact(Account *op)
{
  if (typeid(*op) == typeid(SavingAccount))
    {
      SavingAccount* op2 = dynamic_cast<SavingAccount*>(op);
      SavingAccount ref = SavingAccount(op2);
      deleteact(ref);
    }
  else
    {
      DeadAccount* op3 = dynamic_cast<DeadAccount*>(op);
      DeadAccount ref2 = DeadAccount(op3);
      deleteact(ref2);
    }
}
//Real fuction
//SavingAccount
void Manage::add(SavingAccount &op)
{
  SavingAccountArray.push_back(op);
  writeSavingAccount();
  readAccount();
}
void Manage::update(SavingAccount &op)
{
  int index = searchSavingAccount(op.getaccountnumber());
  if (index != -1)
    {
      SavingAccountArray[index].setpassword(op.getpassword());
      SavingAccountArray[index].setname(op.getname());
      SavingAccountArray[index].setphone(op.getphone());
      writeSavingAccount();
      readAccount();
      updatesuccess = true;
    }
  else updatesuccess = false;
}
void Manage::deleteact(SavingAccount op)
{
  vector<SavingAccount>::iterator it;
  for (it = SavingAccountArray.begin(); it != SavingAccountArray.end();)
    {
      if (it->getaccountnumber() == op.getaccountnumber())
        {
          it = SavingAccountArray.erase(it);
        }
      else it++;
    }
  writeSavingAccount();
  readAccount();
}
//DeadAccount
void Manage::add(DeadAccount &op)
{
  DeadAccountArray.push_back(op);
  writeDeadAccount();
  readAccount();
}
void Manage::update(DeadAccount &op)
{
  int index = searchDeadAccount(op.getaccountnumber());
  if (index != -1)
    {
      DeadAccountArray[index].setpassword(op.getpassword());
      DeadAccountArray[index].setname(op.getname());
      DeadAccountArray[index].setphone(op.getphone());
      DeadAccountArray[index].setaccounttype(op.getaccounttype());
      writeDeadAccount();
      readAccount();
      updatesuccess = true;
    }
  else updatesuccess = false;
}
void Manage::deleteact(DeadAccount op)
{
  vector<DeadAccount>::iterator it;
  for (it = DeadAccountArray.begin(); it != DeadAccountArray.end();)
    {
      if (it->getaccountnumber() == op.getaccountnumber())
        {
          it = DeadAccountArray.erase(it);
        }
      else it++;
    }
  writeDeadAccount();
  readAccount();
}
