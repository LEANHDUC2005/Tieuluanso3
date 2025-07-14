#pragma once  
#include <stdio.h>  
#include <math.h>  
#include <string.h>  
// Chủ Nhật , ngày 13 tháng 7 năm 2025
// Viết bởi Lê Anh Đức - 23701131

// Khai báo các cấu trúc  
typedef struct thuvien {  
    char maTruyen[10];  
    char tenTruyen[40];  
    char tacGia[50];  
    char theloai[30];  
    int namxuatban;   
    char tinhtrang[40];
} thuvien; // Add the name of the struct after the closing brace to fix the typedef issue  

typedef struct date {  
    int ngay;  
    int thang;  
    int nam;  
} date; // Add the name of the struct after the closing brace  

typedef struct Node {  
    thuvien data;  
    struct Node* pNext;  
} Node; // Add the name of the struct after the closing brace  

typedef struct Queue {  
    Node* front, * rear;  
} Queue; // Add the name of the struct after the closing brace  

void Init(Queue *q);  
// Kiểm tra Queue có rỗng không?  
int isEmpty(Queue *q);  
// Kiểm tra Queue đầy?   
int isFull(Queue *q);  
// Thêm một phần tử vào Queue  
void EnQueue(Queue *q, thuvien x);  
// Lấy thông tin và hủy phần tử ở đầu Queue  ( cho thuê truyện )    
thuvien DeQueue(Queue *q);  
// Xem thông tin phần tử đầu Queue  
thuvien Front(Queue *q);  
// Xem thông tin phần tử cuối Queue
thuvien Rear(Queue* q);
// Hàm nhập chuỗi  
void nhapChuoi(char str[], int size);  
// Hàm hoán đổi giá trị phần tử
void swap(thuvien* a, thuvien* b);
//1. Thêm một phần tử mới(sinh viên / sách / nhân viên...).  
void Nhap(Queue *q);  
//2. Hiển thị danh sách các phần tử.  
void xuat(Queue *q);  
//3. Tìm kiếm phần tử theo một tiêu chí(ví dụ : mã số, tên...).  
Queue TimkiemTruyen(Queue *q, char inforSearch[]);  
//5. Cập nhật thông tin của một phần tử.  
void CapnhatTruyen(Queue *q, char maTruyen[]);  
//6. Sắp xếp truyện
void sapxepMatruyenTangdan(Queue* q);
void sapxepMatruyenGiamdan(Queue* q);
void sapxepTentruyenTangdan(Queue* q);
void sapxepTentruyenGiamdan(Queue* q);
void sapxepNamxuatbanTangdan(Queue* q);
void sapxepNamxuatbanGiamdan(Queue* q);
//. Ghi dữ liệu ra tệp và đọc dữ liệu từ tệp(file text)  
void DocFile(Queue *q, const char *filename);  
void GhiFile(Queue *q, const char *filename);  
//. Giải phóng danh sách  
void freelist(Queue* q);
// Sao chép danh sách   
void copyList(Queue* q, Queue* q2); 
// Hàm chọn chiều sắp xếp
char up_or_down();