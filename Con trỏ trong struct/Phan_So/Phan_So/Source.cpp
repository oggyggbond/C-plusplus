#include <iostream>
using namespace std;

struct PHANSO
{
	int tuso;
	int mauso;
	PHANSO* pointer;
};

int main()
{
	PHANSO* a = new PHANSO;
	a->tuso = 1;
	a->mauso = 2;

	PHANSO* b = new PHANSO;
	b->tuso = 2;
	b->mauso = 3;

	PHANSO* c = new PHANSO;
	c->tuso = 3;
	c->mauso = 4;

	PHANSO* d = new PHANSO;
	d->tuso = 4;
	d->mauso = 5;

	a->pointer = b;
	b->pointer = c;
	c->pointer = d;
	d->pointer = NULL;

	for (PHANSO* k = a; k != NULL; k = k->pointer)
	{
		cout << k->tuso << "/" << k->mauso << endl;
	}

	return 0;
}