#include <iostream>
using namespace std;

int main()
{
	int n, i = 0;
	float s = 0;
	cout << " Nhap n: ";
	cin >> n;
	while (i <= n)
	{
		s = (s + (1.0 / (2 * i + 1)));
		i++;
	}
	cout << " Tong la s = " << s << endl;

	return 0;
}