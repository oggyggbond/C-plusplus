#include <iostream>
using namespace std;

void In_cac_so_tu_n_ve_1(int n)
{
	if (n == 0)
	{
		return;
	}
	cout << n << " ";
	In_cac_so_tu_n_ve_1(n - 1);
}

int main()
{
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	In_cac_so_tu_n_ve_1(n);

	return 0;
}