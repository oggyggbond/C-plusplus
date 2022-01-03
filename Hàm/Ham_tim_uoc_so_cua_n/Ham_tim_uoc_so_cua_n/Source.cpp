#include <iostream>
using namespace std;

void Tim_uoc(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			cout << i << endl;
	}
}

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	cout << " Cac uoc so cua " << n << " la " << endl;
	Tim_uoc(n);

	return 0;
}