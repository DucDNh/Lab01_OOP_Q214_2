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
		return b; // Khi a = 0, b là UCLN. Hàm trả về b.
	else
		return a; // Khi b = 0, a là UCLN. Hàm trả về a.
}

class Phanso 
{
	int tu, mau;
public:
	void nhap() 
	{
		char gachcheo;
		cout << "Nhap phan so (a/b) : ";
		cin >> tu >> gachcheo >> mau; // Định dạng nhập vào : a/b .
		while (mau == 0) // Yêu cầu nhập lại khi mẫu = 0.
		{
			cout << "Mau so khong the bang 0! Vui long nhap lai: ";
			cin >> tu >> gachcheo >> mau;
		}
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
	void xuat() // Hiển thị phân số dưới định dạng phù hợp.
	{
		if (mau == 1) // Xây dựng định dạng khi in cho phân số.
			cout << tu << endl; 
		else if (tu == 0)
			cout << 0 << endl; 
		else
			cout << tu << '/' << mau << endl; 
	}
};

int main() {
	Phanso ps1;
	ps1.nhap();
	ps1.rut_gon();
	ps1.xuat();
	return 0;
}