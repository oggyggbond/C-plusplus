#include <iostream>
using namespace std;
//#define MAX 100
int main()
{
	int a[100], n;
	cout << " Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu a[" << i << "] = ";
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}