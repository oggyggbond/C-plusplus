#include <iostream>
#include <cmath>
using namespace std;

int Tim_snt_nho_hon_n(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	do
	{
		cout << " Nhap n > 0: ";
		cin >> n;
		if (n <= 0)
			cout << " Nhap lai! " << endl;
	} while (n <= 0);
	for (int i = 2; i < n; i++)
	{
			if (Tim_snt_nho_hon_n(i))
				cout << i << endl;
	}
	return 0;
}