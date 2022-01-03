#include <iostream>
using namespace std;

int main()
{
	int n, i = 1;
	float s = 0;
	cout << " Nhap n: ";
	cin >> n;
	while (i <= n)
	{
		s = s + 1.0 / i;
		i++;
	}
	cout << " Tong la s = " << s << endl;

	return 0;
}