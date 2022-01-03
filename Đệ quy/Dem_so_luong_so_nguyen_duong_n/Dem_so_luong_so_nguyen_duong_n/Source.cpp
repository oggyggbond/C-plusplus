#include <iostream>
using namespace std;

int Dem_so_chu_so(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return Dem_so_chu_so(n / 10) + 1;
}

int main()
{
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	cout << " So " << n << " co " << Dem_so_chu_so(n) << " chu so ";

	return 0;
}