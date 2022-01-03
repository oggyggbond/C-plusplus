#include <iostream>
#include <cmath>
using namespace std;

bool Kiem_tra_snt(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	if (Kiem_tra_snt(n) == true)
	{
		cout << n << " la snt " << endl;
	}
	else
		cout << n << " khong phai snt " << endl;

	return 0;
}