#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i < n; i++)
	{	
		if (i % 2 == 0)
		{
			cout << " So chan la: " << i << endl;
		}
		else
			cout << " So le la: " << i << endl;
	}

	return 0;
}