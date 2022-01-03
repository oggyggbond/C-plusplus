#include <iostream>
using namespace std;

int Tim_UCLN(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	return Tim_UCLN(b % a, a);
}

int main()
{
	int a, b;
	cout << "\nNhap hai so a va b: ";
	cin >> a >> b;
	cout << "\nUCLN cua hai so " << a << " va " << b << " la " << Tim_UCLN(a, b);

	return 0;
}