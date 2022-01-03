#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	if (n < 100 || n > 999)
	{
		cout << "Khong hop le! Nhap lai! " << endl;
	}
	else
	{
		int donvi = n % 10;
		n = n / 10;
		int chuc = n % 10;
		int tram = n / 10;
		if (tram == 1)
		{
			cout << " Mot ";
		}
		else if (tram == 2)
		{
			cout << " Hai ";
		}
		else if (tram == 3)
		{
			cout << " Ba ";
		}
		else if (tram == 4)
		{
			cout << " Bon ";
		}
		else if (tram == 5)
		{
			cout << " Nam ";
		}
		else if (tram == 6)
		{
			cout << " Sau ";
		}
		else if (tram == 7)
		{
			cout << " Bay ";
		}
		else if (tram == 8)
		{
			cout << " Tam ";
		}
		else if (tram == 9)
		{
			cout << " Chin ";
		}
		cout << " tram ";
		if (chuc == 0)
		{
			cout << " linh ";
		}
		else if (chuc == 1)
		{
		}
		else if (chuc == 2)
		{
			cout << " hai ";
		}
		else if (chuc == 3)
		{
			cout << " ba ";
		}
		else if (chuc == 4)
		{
			cout << " bon ";
		}
		else if (chuc == 5)
		{
			cout << " nam ";
		}
		else if (chuc == 6)
		{
			cout << " sau ";
		}
		else if (chuc == 7)
		{
			cout << " bay ";
		}
		else if (chuc == 8)
		{
			cout << " tam ";
		}
		else if (chuc == 9)
		{
			cout << " chin ";
		}
		cout << " muoi ";
		if (donvi == 1)
		{
			cout << " mot ";
		}
		else if (donvi == 2)
		{
			cout << " hai ";
		}
		else if (donvi == 3)
		{
			cout << " ba ";
		}
		else if (donvi == 4)
		{
			cout << " bon ";
		}
		else if (donvi == 5)
		{
			cout << " lam ";
		}
		else if (donvi == 6)
		{
			cout << " sau ";
		}
		else if (donvi == 7)
		{
			cout << " bay ";
		}
		else if (donvi == 8)
		{
			cout << " tam ";
		}
		else if (donvi == 9)
		{
			cout << " chin ";
		}
	}

	return 0;
}