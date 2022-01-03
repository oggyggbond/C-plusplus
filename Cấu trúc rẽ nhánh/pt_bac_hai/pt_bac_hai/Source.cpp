#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c, x, x1, x2, delta;
	cout << "Nhap a, b va c: ";
	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				cout << "Pt co vsn " << endl;
			}
			else
				cout << "Pt vo nghiem " << endl;
		}
		else
		{
			x = -c / b;
			cout << "Pt co nghiem duy nhat x = " << x << endl;
		}
	}
	else
	{
		delta = (b * b) - (4 * a * c);
		if (delta == 0)
		{
			x1 = x2 = (-b) / (2 * a);
			cout << "Pt co nghiem kep x1 = x2 = " << x1 << endl;
		}
		else if (delta < 0)
		{
			cout << "Pt vo nghiem " << endl;
		}
		else
		{
			x1 = ((-b) + (sqrt(delta))) / (2 * a);
			x2 = ((-b) - (sqrt(delta))) / (2 * a);
			cout << " Pt co 2 nghiem phan biet " << " x1 = " << x1 << " x2 = " << x2 << endl;
		}
	}
	
	return 0;
}