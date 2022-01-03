#include <iostream>
using namespace std;

int main()
{
	int n, s = 1, i = 1;
	cout << " Nhap n: ";
	cin >> n;
	while (i <= n)
	{
		s = s * i;
		i++;
	}
	cout << " Tong la s = " << s << endl;

	return 0;
}