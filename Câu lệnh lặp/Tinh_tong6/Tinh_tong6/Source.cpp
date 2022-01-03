#include <iostream>
using namespace std;

int main()
{
	int n;
	float s = 0;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		s = s +  (i / (i + 1.0));
	}
	cout << " Tong la s =  " << s << endl;

	return 0;
}