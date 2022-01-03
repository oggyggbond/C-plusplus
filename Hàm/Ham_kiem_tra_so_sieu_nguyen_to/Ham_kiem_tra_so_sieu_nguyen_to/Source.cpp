#include <iostream>
#include <cmath>
using namespace std;

bool Kiem_tra_so_sieu_nguyen_to(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
		else
			while (n != 0)
			{
				int x = n / 10;
				for (int j = 2; j <= sqrt(x); j++)
				{
					if (x % j == 0)
						return 0;
					else
						return 1;
				}
			}	
	}
}

int main()
{
	int n;
	do
	{
		cout << " Nhap n: ";
		cin >> n;
		if (n <= 0)
		{
			cout << " Nhap n > 0! " << endl;
		}
	} while (n <= 0);
	if (Kiem_tra_so_sieu_nguyen_to(n) == true)
	{
		cout << n << " la so sieu nguyen to " << endl;
	}
	else
		cout << n << " khong phai so sieu nguyen to " << endl;

	return 0;
}