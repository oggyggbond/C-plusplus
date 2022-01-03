#include <iostream>
using namespace std;

int main()
{
	int n, m;
	
	cout << " Nhap m: ";
	cin >> m;
	cout << " Nhap n: ";
	cin >> n;

	for (int i = n; i <= m; i++)
	{
		int k = true;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				k = false;
				break;
			}
		}
		if (k == true)
		{
			cout << i << endl;
		}
	}

	return 0;
}