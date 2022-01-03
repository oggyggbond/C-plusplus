#include <iostream>
using namespace std;

int main()
{
	int n,vitri;
	cout << " Nhap n: ";
	cin >> n;

	// vd: nhap 15642
	int v = n / 10000 % 10;
	int w = n / 1000 % 10;
	int x = n / 100 % 10;
	int y = n / 10 % 10;
	int z = n % 10;
	cout << " Nhap vi tri: ";
	cin >> vitri;

	switch (vitri)
	{
	case 1:
		cout << v << endl;
		break;
	case 2:
		cout << w << endl;
		break;
	case 3:
		cout << x << endl;
		break;
	case 4:
		cout << y << endl;
		break;
	case 5:
		cout << z << endl;
		break;

	}

	return 0;
}