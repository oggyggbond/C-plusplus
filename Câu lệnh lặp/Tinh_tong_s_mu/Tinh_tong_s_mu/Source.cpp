#include <iostream>
using namespace std;

int main()
{
	int n, i = 1, s = 0;
	cout << " Nhap n: ";
	cin >> n;
	while (i <= n)
	{
		s = s + i * i;
		i++;
	}
	cout << " Tong la s = " << s << endl;

	return 0;
}