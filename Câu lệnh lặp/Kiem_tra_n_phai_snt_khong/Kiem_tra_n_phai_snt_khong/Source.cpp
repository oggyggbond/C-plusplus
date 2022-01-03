#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			cout << n << " khong phai so nguyen to " << endl;
			return 0;
		}
	}
	cout << n << " la so nguyen to " << endl;

	return 0;
}