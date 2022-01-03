#include <iostream>
using namespace std;
int main()
{
	int n, max = 1;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0 && i % 2 != 0)
		{
			if (max < i)
			{
				max = i;
			}
		}
	}
	cout << " Uoc so le lon nhat cua " << n << " la " << max << endl;

	return 0;
}