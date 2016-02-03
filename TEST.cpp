#include "Manage.h"
int main()
{
	Manage m;
	SavingAccount my("1234567890123456789", "123456", "CieloSun", "13246825184");
	Account* ptr = &my;
	m.add(ptr);
	m.read();
	int index = m.search("1234567890123456789");
	m.AccountPtrArray[index]->credit(50000.0);
	m.store();
	m.read();
	int item = m.search("1234567890123456789");
	cout << m.AccountPtrArray[item]->showaccount();
}