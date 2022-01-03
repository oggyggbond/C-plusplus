#include <iostream>
using namespace std;

int main()
{
	int thang, nam;
	cout << " Nhap thang va nam: ";
	cin >> thang >> nam;
	int songay = (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) ? 29 : 28;
	cout << songay << endl;
	return 0;
	songay = (thang == 4 || thang == 6 || thang == 9 || thang == 11) ? 30 : 31;
	cout << songay << endl;

	return 0;
}