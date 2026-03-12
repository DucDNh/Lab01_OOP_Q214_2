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
		return b; // Dựa theo thuật toán tìm ước chung lớn nhất, khi này b là UCLN, nên ta trả về b.
	else
		return a; // Dựa theo thuật toán tìm ước chung lớn nhất, khi này a là UCLN, nên ta trả về a.
}

class Phanso // Xây dựng class phân số.
{
	int tu, mau; // Xây dựng 2 thuộc tính cơ bản của một phân số gồm : Từ, mẫu.
public:
	void nhap() // Xây dựng method để nhập vào phân số.
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
	void xuat() // Xây dựng method in ra phân số.
	{
		if (mau == 1)
			cout << tu << endl; // Không in mẫu, khi mẫu = 1.
		else if (tu == 0)
			cout << 0 << endl; // Không in mẫu khi tử = 0.
		else
			cout << tu << '/' << mau << endl; // Định dạng in ra : a/b hoặc a.
	}
};

int main() {
	Phanso ps1;
	ps1.nhap();
	ps1.rut_gon();
	ps1.xuat();
	return 0;
}