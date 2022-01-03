#include <iostream>
using namespace std;

int main()
{
	int n, m,tmp, dem = 0;
	cout << " Nhap n doi vo va m ngay: ";
	cin >> n >> m;

	tmp = n;
	while (tmp >= m)
	{
		tmp = tmp - m + 1;
		dem++;
	}
	int day = n + dem;
	cout << " Ban A mang vo " << day << " ngay thi het vo de mang " << endl;

	return 0;
}