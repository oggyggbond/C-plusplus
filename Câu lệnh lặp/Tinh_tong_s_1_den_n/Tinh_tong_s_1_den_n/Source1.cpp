#include <iostream>
using namespace std;

int main()
{
	int n, s = 0, i = 1;
	cout << " Nhap n: ";
	cin >> n;
	while (n > 0)
	{
		s = s + i;
		i++;
	}
	cout << " Tong la s = " << s << endl;

	return 0;
} 