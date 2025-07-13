#pragma once
#include <stdio.h>
#include <math.h>
#include <string.h>
// Khai báo các cấu trúc
typedef struct thuvien {
    char maTruyen[10];
    char tenTruyen[40];
    char tacGia[50];
    char theloai[30];
    int namxuatban;
    char tinhtrang[50];
};
typedef struct date {
    int ngay;
    int thang;
    int nam;
};
typedef struct Node {
    thuvien data;
    Node* pNext;
};

typedef struct Queue {
    Node* front, * rear;
} q;

void Init(Queue *q);
// Kiểm tra Queue có rỗng không?
int isEmpty(Queue *q);
// Kiểm tra Queue đầy? 
int isFull(Queue *q);
// Thêm một phần tử vào Queue
void EnQueue(Queue *q, thuvien x);
// Lấy thông tin và hủy phần tử ở đầu Queue
thuvien DeQueue(Queue *q);
// Xem thông tin phần tử đầu Queue
thuvien Front(Queue *q);
// Hàm nhập chuỗi
void nhapChuoi(char str[], int size);
//1. Thêm một phần tử mới(sinh viên / sách / nhân viên...).
void Nhap(Queue *q);
//2. Hiển thị danh sách các phần tử.
void xuat(Queue *q);
//3. Tìm kiếm phần tử theo một tiêu chí(ví dụ : mã số, tên...).
Queue TimkiemTruyen(Queue *q, char inforSearch[]);
//5. Cập nhật thông tin của một phần tử.
void CapnhatTruyen(Queue *q, char maTruyen[]);
//6. Ghi dữ liệu ra tệp và đọc dữ liệu từ tệp(file text)
void DocFile(Queue *q, const char *filename);
void GhiFile(Queue *q, const char *filename);
//7. Giải phóng danh sách
void freelist(Queue* q);