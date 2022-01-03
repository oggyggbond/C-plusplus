#include <iostream>
using namespace std;

void Chuyen_thapphan_sang_nhi_phan(int n)
{
	if (n != 0)
	{
		Chuyen_thapphan_sang_nhi_phan(n / 2);
		cout << n % 2;
	}
}

int main()
{
	int n;
	cout << "\nNhap so thap phan can chuyen: ";
	cin >> n;
	Chuyen_thapphan_sang_nhi_phan(n);

	return 0;
}