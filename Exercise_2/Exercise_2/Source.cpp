#include <iostream>

using namespace std;

int gcd(int a, int b) // Xây dựng hàm tìm ước chung lớn nhất, phục vụ cho việc rút gọn phân số.
{
	a = abs(a);
	b = abs(b);
	while (a != 0 && b != 0) {
		if (a >= b)
			a %= b;
		else
			b %= a;
	}
	if (a == 0) 
		return b; // Khi a = 0, b là UCLN.
	else
		return a; // Khi b = 0, a là UCLN.
}

class PhanSo // Xây dựng class phân số.
{
	int tu, mau; 
public:
	void nhap() // Khởi tạo phân số từ input người dùng và tự động chuẩn hoá.
	{
		char gachcheo;
		cout << "Nhap phan so (a/b) : ";
		cin >> tu >> gachcheo >> mau;
		while (mau == 0) // Yêu cầu nhập lại khi mẫu = 0.
		{
			cout << "Mau so khong the bang 0! Vui long nhap lai: ";
			cin >> tu >> gachcheo >> mau;
		}
		rut_gon();
	}
	void xuat() // Hiển thị phân số.
	{
		if (mau == 1) // Xây dựng định dạng phù hợp khi in ra phân số.
			cout << tu << endl; 
		else if (tu == 0)
			cout << 0 << endl; 
		else
			cout << tu << '/' << mau << endl; 
	}
	void rut_gon() // Xây dựng method để rút gọn phân số, dựa trên hàm tìm ước chung lớn nhất.
	{
		int ucnn = gcd(tu, mau);
		tu /= ucnn;
		mau /= ucnn;
		if (mau < 0) // Chuẩn hoá về dấu khi mẫu âm
		{
			tu = -tu;
			mau = -mau;
		}
	}
	bool operator> (PhanSo tem_ps) // Nạp chồng toán tử > . Sử dụng phương pháp nhân chéo để so sánh.
	{
		int tem_tu1 = tu * tem_ps.mau, tem_tu2 = tem_ps.tu * mau;
		return (tem_tu1 > tem_tu2); // Trả về biểu thức boolean, đại điện cho việc so sánh 2 phân số.
	}
};

int main() {
	PhanSo ps1, ps2;
	ps1.nhap();
	ps2.nhap();
	if (ps1 > ps2)
		ps1.xuat();
	else
		ps2.xuat();
	return 0;
}