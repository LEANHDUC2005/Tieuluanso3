// Tieuluanso3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>
#include "Header.h"
// Thứ hai , ngày 14 tháng 7 năm 2025
// Viết bởi Lê Anh Đức - 23701131

int main()
{
	SetConsoleOutputCP(65001);
	Queue q;
	Init(&q);
	char tenQuanLy[50];
	printf("|================================= DANH SÁCH QUẢN LÝ CHO THUÊ TRUYỆN =============================|\n");
	printf("| Nhập tên người quản lý: ");
	nhapChuoi(tenQuanLy, sizeof(tenQuanLy));
	printf("| Chào mừng : %s\n", tenQuanLy);	
	int choice;
	do {
		printf("|=================================================================================================|\n");
		printf("|                                            Bạn muốn                                             |\n");
		printf("|=================================================================================================|\n");
		printf("|  [1].Thêm thông tin truyện      | [2].Hiển thị danh sách truyện   | [3].Tìm kiếm theo mã truyện |\n");
		printf("|_________________________________|_________________________________|_____________________________|\n");
		printf("|                                 |                                 |                             |\n");
		printf("|  [4].Cập nhật thông tin truyện  | [5].Cho thuê truyện             | [6].Sắp xếp danh sách       |\n");
		printf("|_________________________________|_________________________________|_____________________________|\n");
		printf("|                                 |                                 |                             |\n");
		printf("|  [7].Xem truyện gần/mới nhất    | [8].Ghi danh sách ra file       | [9].Đọc file danh sách      |\n");
		printf("|_________________________________|_________________________________|_____________________________|\n");
		printf("|                                                                                                 |\n");
		printf("|                                   [10].Thoát danh sách quản lý                                  |\n");
		printf("|_________________________________________________________________________________________________|\n");
		printf("| Nhập lựa chọn của bạn [1-9]:");
		scanf_s("%d", &choice);
		while (getchar() != '\n');
		switch (choice)
		{
		case 1:
		{
			printf("| ĐÃ CHỌN [Thêm thông tin truyện]\n");
			Nhap(&q);
			break;
		}
		case 2:
		{
			printf("| ĐÃ CHỌN [Hiển thị danh sách truyện]\n");
			xuat(&q);
			break;
		}
		case 3:
		{
			printf("| ĐÃ CHỌN [Tìm kiếm theo mã truyện]\n");
			char inforSearch[50];
			printf("| Nhập thông tin cần tìm kiếm: ");
			nhapChuoi(inforSearch, sizeof(inforSearch));
			Queue result = TimkiemTruyen(&q, inforSearch);
			if (isEmpty(&result)) {
				printf("| Không tìm thấy truyện với mã %s\n", inforSearch);
			}
			else {
				printf("| Kết quả tìm kiếm:\n");
				xuat(&result);
			}
			freelist(&result);
			break;
		}
		case 4:
		{
			printf("| ĐÃ CHỌN [Cập nhật thông tin truyện]\n");
			char maTruyen[10];
			printf("| Nhập mã truyện cần cập nhật: ");
			nhapChuoi(maTruyen, sizeof(maTruyen));
			CapnhatTruyen(&q, maTruyen);
			break;
		}
		case 5:
		{
			printf("| ĐÃ CHỌN [Cho thuê truyện]\n");
			thuetruyen thue = DeQueue(&q);
			if (strcmp(thue.maTruyen, "NULL") == 0) {
				printf("| Không có truyện nào để cho thuê!\n");
				break;
			}
			strcpy_s(thue.tinhtrang, "Dang thue");
			printf("\n==== Cho thue thanh cong ====\n");
			printf("| Mã truyện   : %s\n", thue.maTruyen);
			printf("| Tên truyện  : %s\n", thue.tenTruyen);
			printf("| Tác giả     : %s\n", thue.tacGia);
			printf("| Số lượng    : %d\n", thue.namxuatban);
			printf("| Tình trạng  : %s\n", thue.tinhtrang);
			printf("==============================\n");
			break;
		}
		case 6:
		{
			Queue q1;
			Init(&q1);
			copyList(&q, &q1);
			int sortChoice;
			printf("| ĐÃ CHỌN [Sắp xếp danh sách]\n");
			printf("| Bạn muốn sắp xếp theo:\n");
			printf("| [1].Mã truyện \n");
			printf("| [2].Tên truyện \n");
			printf("| [3].Năm xuất bản \n");
			printf("| Nhập lựa chọn của bạn [1-3]: ");
			scanf_s("%d", &sortChoice);
			while (getchar() != '\n');
			switch (sortChoice)
			{
			case 1:
			{
				switch (up_or_down())
				{
				case 'A':
				{
					printf("| ĐÃ CHỌN [Sắp xếp mã truyện tăng dần]\n");
					sapxepMatruyenTangdan(&q1);
					xuat(&q1);
					break;
				}
				case 'B':
				{
					printf("| ĐÃ CHỌN [Sắp xếp mã truyện giảm dần]\n");
					sapxepMatruyenGiamdan(&q1);
					xuat(&q1);
					break;
				}
				default:
				{
					printf("| Lựa chọn không hợp lệ, vui lòng chọn lại!\n");
					break;
				}
				}
				break;
			}
			case 2:
			{
				switch (up_or_down())
				{
				case 'A':
				{
					printf("| ĐÃ CHỌN [Sắp xếp tên truyện tăng dần]\n");
					sapxepTentruyenTangdan(&q1);
					xuat(&q1);
					break;
				}
				case 'B':
				{
					printf("| ĐÃ CHỌN [Sắp xếp tên truyện giảm dần]\n");
					sapxepTentruyenGiamdan(&q1);
					xuat(&q1);
					break;
				}
				default:
				{
					printf("| Lựa chọn không hợp lệ, vui lòng chọn lại!\n");
					break;
				}
				}
				break;
			}
			case 3:
			{
				switch (up_or_down())
				{
				case 'A':
				{
					printf("| ĐÃ CHỌN [Sắp xếp năm xuất bản tăng dần]\n");
					sapxepNamxuatbanTangdan(&q1);
					xuat(&q1);
					break;
				}
				case 'B':
				{
					printf("| ĐÃ CHỌN [Sắp xếp năm xuất bản giảm dần]\n");
					sapxepNamxuatbanGiamdan(&q1);
					xuat(&q1);
					break;
				}
				default:
				{
					printf("| Lựa chọn không hợp lệ, vui lòng chọn lại!\n");
					break;
				}
				}
				break;
			}
			}freelist(&q1);	
			break;
		}
		case 7:
		{
			printf("| ĐÃ CHỌN [Xem truyện sắp cho thuê/mới được thêm vào]\n");
			if (isEmpty(&q)) {
				printf("| Danh sách truyện rỗng!\n");
			} else {
				thuetruyen newest = Front(&q);
				printf("| Truyện gần/mới nhất:\n");
				printf("| Mã truyện   : %s\n", newest.maTruyen);
				printf("| Tên truyện  : %s\n", newest.tenTruyen);
				printf("| Tác giả     : %s\n", newest.tacGia);
				printf("| Năm xuất bản: %d\n", newest.namxuatban);
				printf("| Tình trạng  : %s\n", newest.tinhtrang);
				printf("==============================\n");
				thuetruyen oldest = Rear(&q);	
				printf("| Truyện mới được thêm vào:\n");	
				printf("| Mã truyện   : %s\n", oldest.maTruyen);	
				printf("| Tên truyện  : %s\n", oldest.tenTruyen);
				printf("| Tác giả     : %s\n", oldest.tacGia);	
				printf("| Năm xuất bản: %d\n", oldest.namxuatban);	
				printf("| Tình trạng  : %s\n", oldest.tinhtrang);	
				printf("==============================\n");
			}
			break;
		}	
		case 8:
		{
			printf("| ĐÃ CHỌN [Ghi danh sách ra file]\n");
			char filename[50];
			printf("| Nhập tên tệp để ghi dữ liệu: ");
			nhapChuoi(filename, sizeof(filename));
			GhiFile(&q, filename);
			break;
		}
		case 9:
		{
			printf("| ĐÃ CHỌN [Đọc file danh sách]\n");
			char filename[50];
			printf("| Nhập tên tệp để đọc dữ liệu: ");
			nhapChuoi(filename, sizeof(filename));
			DocFile(&q, filename);
			break;
		}
		case 10:
		{
			printf("| Cảm ơn bạn đã sử dụng chương trình!\n");
			break;
		}
		default:
		{
			printf("| Lựa chọn không hợp lệ, vui lòng chọn lại!\n");
			break;
		}
		}
	} while (choice != 10);	
	printf("=============================================================================================\n");
	freelist(&q);	
	return 0;	
}

