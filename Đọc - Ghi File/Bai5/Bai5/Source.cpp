#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct MONHOC
{
	string tenmonhoc;
	float diem;
};

struct SINHVIEN
{
	string hoten;
	string masv;
	string namsinh;
	MONHOC ds_mh[100];
};

void Doc_file_1_sv(ifstream& filein, SINHVIEN& sv)
{
	getline(filein, sv.hoten);
	getline(filein, sv.masv);
	getline(filein, sv.namsinh);
}

void Doc_file_1_mon_hoc(ifstream &filein, MONHOC& mh)
{
	getline(filein, mh.tenmonhoc);
	filein >> mh.diem;
}

void Doc_file_sv_va_mon_hoc(ifstream& filein, SINHVIEN dssv[100])
{
	while (filein.eof() == false)
	{
		SINHVIEN sv;
		Doc_file_1_sv(filein, sv);
		int n;
		filein >> n;
		for (int i = 0; i <= n; i++)
		{
			MONHOC mh;
			Doc_file_1_mon_hoc(filein, mh);
			
		}
		
	}
}

int main()
{
	ifstream filein;
	filein.open("SINHVIEN.TXT", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong ton tai! Xin kiem tra lai";
		system("pause");
		return 0;
	}



	return 0;
}