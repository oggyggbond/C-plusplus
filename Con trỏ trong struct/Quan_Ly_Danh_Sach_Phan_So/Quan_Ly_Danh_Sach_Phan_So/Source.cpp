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
	PHANSO* boss = NULL;
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t======================= QUAN LY PHAN SO =======================";
		cout << "\n\t1.Them phan so";
		cout << "\n\t2. Xuat danh sach phan so";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t============================ END ===============================";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			PHANSO* x = new PHANSO;
			cout << "\nNhap tu so: ";
			cin >> x->tuso;
			cout << "\nNhap mau so: ";
			cin >> x->mauso;
			x->pointer = NULL;
			if (boss == NULL)
			{
				boss = x;
			}
			else
			{
				for (PHANSO* k = boss; k != NULL; k = k->pointer)
				{
					if (k->pointer == NULL)
					{
						k->pointer = x;
						break;
					}
				}
			}
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\tDANH SACH PHAN SO\n";
			for (PHANSO* k = boss; k != NULL; k = k->pointer)
			{
				cout << k->tuso << "/" << k->mauso << endl;
			}
			system("pause");
		}
		else
		{
			break;
		}
	}
	
	return 0;
}