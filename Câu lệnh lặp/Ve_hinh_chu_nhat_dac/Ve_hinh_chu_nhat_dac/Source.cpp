#include <iostream>
using namespace std;
int main()
{
	int m, n;
	cout << " Nhap chieu rong va chieu dai: ";
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << " * ";
		}
		cout << "\n";
	}

	return 0;
}