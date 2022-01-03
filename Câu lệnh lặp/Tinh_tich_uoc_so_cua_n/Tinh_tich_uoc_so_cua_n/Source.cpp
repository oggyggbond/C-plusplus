#include <iostream>
using namespace std;
int main()
{
	int n, s = 1;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << i << endl;
			s = s * i;
		}
	}
	cout << " Tich cac uoc so cua " << n << " la " << s << endl;

	return 0;
}