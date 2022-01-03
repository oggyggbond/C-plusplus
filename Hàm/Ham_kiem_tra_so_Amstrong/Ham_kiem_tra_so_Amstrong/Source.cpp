#include <iostream>
#include <cmath>
using namespace std;

bool Kiem_tra_so_Amstrong(int n)
{
	int k = log10((double)n) + 1;
	int s = 0;
	int tmp = n;
	for (int i = 1; n != 0; i++)
	{
		int x = n % 10;
		s = s + pow(x,k);
		n = n / 10;
	}
	if (tmp == s)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	if (Kiem_tra_so_Amstrong(n) == true)
	{
		cout << n << " la so Amstrong " << endl;
	}
	else
		cout << n << " khong phai so Amstrong " << endl;

	return 0;
}