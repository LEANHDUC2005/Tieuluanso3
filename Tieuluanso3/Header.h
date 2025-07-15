#pragma once  
#include <stdio.h>  
#include <math.h>  
#include <string.h>  
// Chủ Nhật , ngày 13 tháng 7 năm 2025
// Viết bởi Lê Anh Đức - 23701131

// Khai báo các cấu trúc  
// Danh sách liên kết đơn cho danh sách truyện
typedef struct datatruyen {  
    char maTruyen[10];  
    char tenTruyen[40];  
    char tacGia[50];  
    char theloai[30];  
    int namxuatban;   
    char tinhtrang[40];
	int soluong; 
} datatruyen;  
typedef struct Nodetruyen {  
    datatruyen data;  
    Nodetruyen* pNext;  
} Nodetruyen;
typedef struct List {  
    Nodetruyen* head, *tail;  
} List; 
// Queue cho thuê truyện    
typedef struct Nodethue {  
    datathue data;  
    Nodethue* pNext;  
} Nodethue; 
typedef struct datathue {
    char maTruyen[10];
    char tenNguoiThue[50];
    char ngayThue[11]; // dd/mm/yyyy
    char ngayTra[11];
}datathue;

typedef struct Queue {  
    Nodethue * front, * rear;  
} Queue;  
// Ham xu ly du lieu
void nhapChuoi(char str[], int size);
// Hàm kiểm tra mã truyện hợp lệ
int IsmaTruyen(char str[]);
// Hàm kiểm tra mã truyện có bị trùng không
int Kiemtratrungma(List* L, char makiemtra[]);
// Ham Danh sach liên kết đơn cho danh sách truyện
void initList(List *L); 
void AddHead(List* L, datatruyen data); 
void AddTail(List* L, datatruyen data); 
void themTruyen(List *L);
void xuatDSTruyen(List* L);
void capNhatTruyen(List* L, char maTruyen[]);
datatruyen* timTruyen(List* L, char ma[]);
void docFileTruyen(List* L, const char* filename);
void ghiFileTruyen(List* L, const char* filename);
void xoaTruyen(List* L, char maTruyen[]);
void xoaTatCaTruyen(List* L); // nên thêm
char up_or_down();
// Ham Queue cho thuê truyện
void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, datathue x);
datathue dequeue(Queue* q);
datathue front(Queue* q);
datathue rear(Queue* q);
void xuatQueue(Queue* q);
void docFileQueue(Queue* q, const char* filename);
void ghiFileQueue(Queue* q, const char* filename);
void giaiPhongQueue(Queue* q);
// Ham thue truyện
void thueTruyen(List* list, Queue* q);
void traTruyen(List* list, Queue* q);