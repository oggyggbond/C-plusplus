#include <iostream>
using namespace std;
int main()
{
	int n,x = 0;
	float s = 0;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		x = x + i;
		s = s + 1.0 / x;
	}
	cout << s;

	return 0;
}