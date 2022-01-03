#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int x, n, s = 0;
	cout << " Nhap x va n: ";
	cin >> x >> n;
	for (int i = 1; i <= n; i++)
	{
		s = s + pow(x, 2 * i);
	}
	cout << " Tong la s = " << s << endl;

	return 0;
}