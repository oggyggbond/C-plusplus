#include <iostream>
using namespace std;
int main()
{
	int m, n;
	cout << " Nhap chieu rong va chieu dai: ";
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
			{
				cout << " * ";
			}
			else
				cout << "   ";
		}
		cout << "\n";
	}

	return 0;
}