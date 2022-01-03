#include <iostream>
using namespace std;

void In_cac_so_tu_1_den_n(int n)
{
	if (n == 0)
	{
		return;
	}
	In_cac_so_tu_1_den_n(n - 1);
	cout << n << " ";
}

int main()
{
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	In_cac_so_tu_1_den_n(n);

	return 0;
}