// Tieuluanso3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>
#include "Header.h"
int main()
{
	SetConsoleOutputCP(65001);
	Queue q;
	Init(&q);
	char tenQuanLy[50];
	printf("===================== DANH SÁCH CHO THUÊ TRUYỆN =====================\n");
	printf("| Nhập tên người quản lý: ");
	nhapChuoi(tenQuanLy, sizeof(tenQuanLy));
	printf("| Chào mừng : %s\n", tenQuanLy);	
	int choice;
	do {
		printf("| Nhập lựa chọn của bạn:\n");
		printf("| 1. Nhập thông tin truyện\n");
		printf("| 2. Hiển thị danh sách truyện\n");
		printf("| 3. Tìm kiếm truyện theo mã truyện\n");
		printf("| 4. Cập nhật thông tin truyện\n");
		printf("| 5. Ghi dữ liệu ra tệp\n");
		printf("| 6. Đọc dữ liệu từ tệp\n");
		printf("| 7. Thoát\n");
		printf("| Nhập lựa chọn của bạn [1-7]:");
		scanf_s("%d", &choice);	
		while (getchar() != '\n');
		switch (choice)
		{
		case 1:
		{
			printf("| Nhập thông tin truyện:\n");
			Nhap(&q);
			break;
		}
		case 2:
		{
			printf("| Hiển thị danh sách truyện:\n");
			xuat(&q);
			break;
		}
		case 3:
		{
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
			char maTruyen[10];
			printf("| Nhập mã truyện cần cập nhật: ");
			nhapChuoi(maTruyen, sizeof(maTruyen));
			CapnhatTruyen(&q, maTruyen);
			break;
		}
		case 5:
		{
			char filename[50];
			printf("| Nhập tên tệp để ghi dữ liệu: ");
			nhapChuoi(filename, sizeof(filename));
			GhiFile(&q, filename);
			break;
		}
		case 6:
		{
			char filename[50];
			printf("| Nhập tên tệp để đọc dữ liệu: ");
			nhapChuoi(filename, sizeof(filename));
			DocFile(&q, filename);
			break;
		}
		case 7:
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
	} while (choice != 7);	
	printf("=============================================================================================\n");
	freelist(&q);	
	return 0;	
}

