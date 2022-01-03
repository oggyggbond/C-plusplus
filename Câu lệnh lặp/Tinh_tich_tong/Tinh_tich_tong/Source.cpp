#include <iostream>
using namespace std;

int main()
{
	int n, i = 1, s = 0, tich = 1;
	cout << " Nhap n: ";
	cin >> n;
	while (i <= n)
	{
		tich = tich * i;
		s = s + tich;
		i++;
	}
	cout << " Tich cac tong la s = " << s << endl;

	return 0;
}