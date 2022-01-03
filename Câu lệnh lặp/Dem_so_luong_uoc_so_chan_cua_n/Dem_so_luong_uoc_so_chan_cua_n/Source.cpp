#include <iostream>
using namespace std;
int main()
{
	int n, dem = 0;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0 && i % 2 == 0)
		{
			cout << i << endl;
			dem++;
		}
	}
	cout << " Co " << dem << " uoc so chan " << endl;

	return 0;
} 