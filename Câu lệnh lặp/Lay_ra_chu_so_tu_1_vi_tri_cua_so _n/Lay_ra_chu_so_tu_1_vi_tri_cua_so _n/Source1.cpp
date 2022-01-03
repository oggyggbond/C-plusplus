#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, vt;
	cout << " Nhap n: ";
	cin >> n;
	cout << " Nhap vi tri: ";
	cin >> vt;
	double a = pow(10, vt);
	n = n % (int)a;
	n = n / pow(10, vt - 1);
	cout << n;

	return 0;
}
