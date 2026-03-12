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

class phanso {
	int tu, mau;
public:
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
	phanso operator+ (phanso ps) // Nạp chồng toán tử + để thực hiện phép cộng giữa 2 phân số.
	{
		phanso tem_ps;
		tem_ps.tu = (tu * ps.mau) + (ps.tu * mau);
		tem_ps.mau = mau * ps.mau;
		tem_ps.rut_gon();
		return tem_ps;
	}
	phanso operator- (phanso ps) // Nạp chồng toán tử - để thực hiện phép trừ giữa 2 phân số.
	{
		phanso tem_ps;
		tem_ps.tu = tu * ps.mau - ps.tu * mau;
		tem_ps.mau = mau * ps.mau;
		tem_ps.rut_gon();
		return tem_ps;
	}
	phanso operator* (phanso ps) // Nạp chồng toán tử * để thực hiện phép nhân giữa 2 phân số.
	{
		phanso tem_ps;
		tem_ps.tu = tu * ps.tu;
		tem_ps.mau = mau * ps.mau;
		tem_ps.rut_gon();
		return tem_ps;
	}
	phanso operator/ (phanso ps) // Nạp chồng toán tử / để thực hiện phép chia giữa 2 phân số.
	{
		phanso tem_ps;
		tem_ps.tu = tu * ps.mau;
		tem_ps.mau = mau * ps.tu;
		tem_ps.rut_gon();
		return tem_ps;
	}
	bool zero_check() // Kiểm tra có thể thực hiện phép chia hay không.
	{
		return (tu == 0);
	}
};

int main() {
	phanso ps1, ps2;
	ps1.nhap();
	ps2.nhap();
	phanso ps_tong = ps1 + ps2, ps_hieu = ps1 - ps2, ps_tich = ps1 * ps2;
	cout << "Tong 2 Phan So : ";
	ps_tong.xuat();
	cout << "Hieu 2 Phan So : ";
	ps_hieu.xuat();
	cout << "Tich 2 Phan So : ";
	ps_tich.xuat();
	if (ps2.zero_check())
		cout << "Ko the thuc hien phep chia !" << endl;
	else {
		phanso ps_thuong = ps1 / ps2;
		cout << "Thuong 2 Phan So : ";
		ps_thuong.xuat();
	}
	return 0;
}