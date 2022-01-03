#include <iostream>
using namespace std;

int Socach(int n)
{
	int t500 = 500000, t200 = 200000, t100 = 100000, t50 = 50000, dem = 0, tmp = n;
	for (int a = 0; a <= n / t500; a++)
	{
		for (int b = 0; b <= n / t200; b++)
		{
			for (int c = 0; c <= n / t100; c++)
			{
				for (int d = 0; d <= n / t50; d++)
				{
					if (a * t500 + b * t200 + c * t100 + d * t50 == n)
						dem++;
				}
			}
		}
	}
	cout << " Co " << n / t500 << " to 500k " << endl;
	tmp = tmp % t500;
	cout << " Co " << n / t200 << " to 200k " << endl;
	tmp = tmp % t200;
	cout << " Co " << n / t100 << " to 100k " << endl;
	tmp = tmp % t100;
	cout << " Co " << n / t50 << " to 50k " << endl;
	tmp = tmp % t50;

	cout << "===========================" << endl;
	// It to nhat co the
	cout << " So luong it nhat co the la: " << endl;
	cout << " Co " << n / t500 << " to 500k " << endl;
	n = n % t500;
	cout << " Co " << n / t200 << " to 200k " << endl;
	n = n % t200;
	cout << " Co " << n / t100 << " to 100k " << endl;
	n = n % t100;
	cout << " Co " << n / t50 << " to 50k " << endl;
	n = n % t50;
	cout << "===========================" << endl;
	return dem;
}

int main()
{
	int n;
	do
	{
		cout << " Nhap n: ";
		cin >> n;
		if (n % 50000 != 0 || n > 5000000)
		{
			cout << " Nhap lai! " << endl;
		}
	} while (n % 50000 != 0 || n > 5000000);
	cout << "===========================" << endl;
	/*cout << " Co " << Socach(n) << " cach " << endl;
	cout << "===========================" << endl;*/
	int tien[4] = { 500000, 200000, 100000, 50000 };
	int soto;
	for (int i = 0; i < 4; i++)
	{
		soto = n / tien[i];
		if (soto != 0)
		{
			cout << soto << " to " << tien[i] << " ";
		}
		n = n % tien[i];
	}

	return 0;
}