#include <iostream>

using namespace std;

// Hàm tính số ngày tối đa của một tháng bất kỳ trong một năm cụ thể
int max_days(int monthh, int yearr) {
	if (monthh == 2) {
		// Kiểm tra năm nhuận: Chia hết cho 400 HOẶC (chia hết cho 4 nhưng không chia hết cho 100)
		if ((yearr % 400 == 0) || (yearr % 4 == 0 && yearr % 100 != 0)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	// Nhóm các tháng có 31 ngày (Tháng 1, 3, 5, 7, 8, 10, 12)
	else if (monthh == 1 || monthh == 3 || monthh == 5 || monthh == 7 || monthh == 8 || monthh == 10 || monthh == 12) {
		return 31;
	}
	// Các tháng còn lại (Tháng 4, 6, 9, 11) có 30 ngày
	else {
		return 30;
	}
}

class Date {
	int day, month, year;
public:
	void nhap() {
		char a, b;
		cout << "Nhap ngay/thang/nam (dd/mm/yyyy): ";
		// Dùng biến char a, b để nhận dấu gạch chéo, giúp người dùng nhập tự nhiên hơn
		cin >> day >> a >> month >> b >> year;
	}

	void xuat() {
		cout << day << '/' << month << '/' << year;
	}

	Date next_date() // Method tính toán và trả về một đối tượng Date tiếp theo.
	{
		Date tem_date;
		tem_date.day = day + 1; // Giả định ngày tiếp theo chỉ đơn giản là cộng thêm 1
		tem_date.month = month;
		tem_date.year = year;

		// Xử lý "tràn" ngày: Nếu ngày cộng thêm vượt quá số ngày cho phép của tháng hiện tại
		if (tem_date.day > max_days(month, year)) {
			tem_date.day = 1;   
			tem_date.month++;      

			// Xử lý "tràn" tháng: Nếu tháng vượt quá 12 (chuyển giao năm mới)
			if (tem_date.month > 12) {
				tem_date.month = 1; 
				tem_date.year++;    
			}
		}
		return tem_date;
	}
};

int main() {
	Date ngay_hien_tai;
	ngay_hien_tai.nhap();
	Date ngay_tiep_theo = ngay_hien_tai.next_date(); // Khởi tạo đối tượng mới để nhận kết quả trả về từ hàm next_date()

	cout << "Ngay tiep theo cua ngay da nhap la : ";
	ngay_tiep_theo.xuat();

	return 0;
}