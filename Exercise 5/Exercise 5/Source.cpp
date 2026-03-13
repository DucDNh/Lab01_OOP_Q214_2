#include <iostream>
#include <string>

using namespace std;

class HocSinh {
	string ho_Ten;
	double d_toan, d_van, d_tb;

public:
	void nhap_thong_tin() // Xây dựng method để nhập vào thông tin của học sinh và tính điểm trung bình. 
	{
		cout << "Nhap ho va ten : ";
		getline(cin, ho_Ten);
		cout << "Nhap diem toan : ";
		cin >> d_toan;
		cout << "Nhap diem van : ";
		cin >> d_van; 
		d_tb = (d_toan + d_van) / 2.0; // Tính điểm trung bình.
	}

	void xuat_thong_tin() // Xây dựng method để xuất ra các thông tin của học sinh.
	{
		cout << "--- Thong tin cua " << ho_Ten << " ---" << endl;
		cout << "Diem Toan : " << d_toan << endl;
		cout << "Diem Van : " << d_van << endl;
		cout << "Diem trung binh : " << d_tb << endl;
	}
};

int main() {
	HocSinh hocsinh1;
	hocsinh1.nhap_thong_tin();
	hocsinh1.xuat_thong_tin();
	return 0;
}