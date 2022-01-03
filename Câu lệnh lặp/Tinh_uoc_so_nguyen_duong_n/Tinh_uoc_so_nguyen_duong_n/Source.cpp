#include <iostream>
using namespace std;

int main()
{
	int n, i = 1;
	cout << " Nhap n: ";
	cin >> n;
	while (i <= n)
	{
		if (n % i == 0)
		{
			cout << i << endl;
		}
		i++;
	}

	return 0;
}