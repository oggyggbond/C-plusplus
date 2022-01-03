#include <iostream>
using namespace std;

int main()
{
	int n,dem = 0;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << i << endl;
			dem++;
		}
	}
	cout << n << " co " << dem << " uoc " << endl;

	return 0;
}