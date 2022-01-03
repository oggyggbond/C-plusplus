#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	do {
		cout << " Nhap n: ";
		cin >> n;		
		if (n < 0)
		{
			cout << " Nhap n >= 0! " << endl;
		}
	} while (n < 0);

	int sochuso = log10((double)n) + 1, x = n, daonguoc = 0, dem = sochuso, dem1 = sochuso;
	dem--;
	while (x != 0)
	{
		int chuso = x % 10;
		daonguoc += chuso * pow(10.0, dem--);
		x /= 10;
	}
	while (daonguoc != 0)
	{
		int chuso = daonguoc % 10;
		if (chuso == 0)
		{
			cout << " Khong ";
		}
		else if (chuso == 1)
		{
			cout << " Mot ";
		}
		else if (chuso == 2)
		{
			cout << " Hai ";
		}
		else if (chuso == 3)
		{
			cout << " Ba ";
		}
		else if (chuso == 4)
		{
			cout << " Bon ";
		}
		else if (chuso == 5)
		{
			cout << " Nam ";
		}
		else if (chuso == 6)
		{
			cout << " Sau ";
		}
		else if (chuso == 7)
		{
			cout << " Bay ";
		}
		else if (chuso == 8)
		{
			cout << " Tam ";
		}
		else if (chuso == 9)
		{
			cout << " Chin ";
		}
		if (dem1 == 9)
		{
			cout << " Tram ";
			dem1--;
		}
		else if (dem1 == 8)
		{
			if (chuso == 1)
			{
				cout << " Muoi ";
				dem1--;
			}
			else
			{
				cout << " Muoi ";
				dem1--;
			}
		}
		else if (dem1 == 7)
		{
			cout << " Trieu ";
			dem1--;
		}
		else if (dem1 == 6)
		{
			cout << " Tram ";
			dem1--;
		}
		else if (dem1 == 5)
		{
			if (chuso == 1)
			{
				cout << " Muoi ";
				dem1--;
			}
			else
			{
				cout << " Muoi ";
				dem1--;
			}
		}
		else if (dem1 == 4)
		{
			cout << " Nghin ";
			dem1--;
		}
		else if (dem1 == 3)
		{
			cout << " Tram ";
			dem1--;
		}
		else if (dem1 == 2)
		{
			if (chuso == 1)
			{
				cout << " Muoi ";
				dem1--;
			}
			else
			{
				cout << " Muoi ";
				dem1--;
			}
		}
		daonguoc /= 10;
	}

	return 0;
}