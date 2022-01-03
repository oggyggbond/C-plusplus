#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout << " Nhap hai so a va b: ";
	cin >> a >> b;
	if (a == 0)
	{
		if (b == 0)
		{
			cout << " Pt co vsn " << endl;
		}
		else
			cout << " Pt vo nghiem " << endl;
	}
	else
		cout << " Pt co 1 nghiem x = " << (-b) / a << endl;

	return 0;
}