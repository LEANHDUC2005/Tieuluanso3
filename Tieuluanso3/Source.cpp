#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
// Chủ Nhật , ngày 13 tháng 7 năm 2025
// Viết bởi Lê Anh Đức - 23701131
// Khoi tao Linked List cho danh sách truyện
// Cac ham xu ly du lieu 
void nhapChuoi(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}
void IsmaTruyen(char str[]) {
    if (strlen(str) > 10) {
        printf("Mã truyện tối đa 10 ký tự !\n");
        while (getchar() != '\n');
    }
}
void Kiemtratrungma(List* L, char makiemtra[]) {
    Nodetruyen* temp = L->head;
    while (temp != NULL) {
        if (strcmp(temp->data.maTruyen, makiemtra) == 0) {
            printf("| Mã truyện bị trùng ! Vui lòng nhập mã truyện khác.\n");
            return 1; // Trả về 1 để báo lỗi (có thể dùng giá trị đặc biệt hơn)
        }
        temp = temp->pNext;
    }
    return 0; // Không có mã truyện trùng
}
// Cac ham xu ly danh sach lien ket don cho danh sach truyen
void initList(List *L) {
    L->head = NULL;
    L->tail = NULL;
}   
// Thêm phần tử vào đầu danh sách   
void AddHead(List* L, datatruyen data) {
    Nodetruyen* p = (Nodetruyen*)malloc(sizeof(Nodetruyen));
    if (p == NULL) {
        printf("Khong du bo nho !\n");
        return;
    }
    p->data = data;
    p->pNext = L->head;
    L->head = p;
    if (L->tail == NULL) {
        L->tail = p; // Nếu danh sách rỗng, cập nhật tail
    }
}   
// Thêm phần tử vào cuối danh sách
void AddTail(List* L, datatruyen data) {
    Nodetruyen* p = (Nodetruyen*)malloc(sizeof(Nodetruyen));
    if (p == NULL) {
        printf("Khong du bo nho !\n");
        return;
    }
    p->data = data;
    p->pNext = NULL;
    if (L->tail != NULL) {
        L->tail->pNext = p; // Nối phần tử mới vào cuối danh sách
    } else {
        L->head = p; // Nếu danh sách rỗng, cập nhật head
    }
    L->tail = p; // Cập nhật tail
}
// Thêm truyện vào dau danh sách
void themTruyendau(List* L)
{
    while (true)
    {
        datatruyen data;
		printf("| Nhập mã truyện ( nhập 0 để kết thúc ): ");
        nhapChuoi(data.maTruyen, sizeof(data.maTruyen));
        if (strcmp(data.maTruyen, "0") == 0) return; // Kết thúc nhập nếu mã truyện là "0"
        if (!IsmaTruyen(data.maTruyen)) {
            printf("Mã truyện tối đa 10 ký tự !\n");
            continue;
        }
        if (Kiemtratrungma(L, data.maTruyen)) continue; // Kiểm tra trùng mã truyện
        printf("| Nhập tên truyện: ");
        nhapChuoi(data.tenTruyen, sizeof(data.tenTruyen));
        printf("| Nhập tên tác giả: ");
        nhapChuoi(data.tacGia, sizeof(data.tacGia));
        printf("| Nhập thể loại: ");
        nhapChuoi(data.theloai, sizeof(data.theloai));
        do {
            printf("| Nhập năm xuất bản của sách: ");
            scanf_s("%d", &data.namxuatban);
            while (getchar() != '\n');
            if (data.namxuatban <= 0) {
                printf("| Năm xuất bản phải là số dương !\n");
            }
        } while (data.namxuatban <= 0);
        printf("| Nhập tình trạng của truyện: ");
        nhapChuoi(data.tinhtrang, sizeof(data.tinhtrang));
		AddHead(L, data); // Thêm truyện vào cuối danh sách
    }
}
// Thêm truyện vào cuoi danh sách
void themTruyendau(List* L)
{
    while (true)
    {
        datatruyen data;
        printf("| Nhập mã truyện ( nhập 0 để kết thúc ): ");
        nhapChuoi(data.maTruyen, sizeof(data.maTruyen));
        if (strcmp(data.maTruyen, "0") == 0) return; // Kết thúc nhập nếu mã truyện là "0"
        if (!IsmaTruyen(data.maTruyen)) {
            printf("Mã truyện tối đa 10 ký tự !\n");
            continue;
        }
        if (Kiemtratrungma(L, data.maTruyen)) continue; // Kiểm tra trùng mã truyện
        printf("| Nhập tên truyện: ");
        nhapChuoi(data.tenTruyen, sizeof(data.tenTruyen));
        printf("| Nhập tên tác giả: ");
        nhapChuoi(data.tacGia, sizeof(data.tacGia));
        printf("| Nhập thể loại: ");
        nhapChuoi(data.theloai, sizeof(data.theloai));
        do {
            printf("| Nhập năm xuất bản của sách: ");
            scanf_s("%d", &data.namxuatban);
            while (getchar() != '\n');
            if (data.namxuatban <= 0) {
                printf("| Năm xuất bản phải là số dương !\n");
            }
        } while (data.namxuatban <= 0);
        printf("| Nhập tình trạng của truyện: ");
        nhapChuoi(data.tinhtrang, sizeof(data.tinhtrang));
        AddTail(L, data); // Thêm truyện vào cuối danh sách
    }
}
// Hiển thị danh sách truyện
void 
// Khởi tạo Queue
void Init(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Kiểm tra Queue có rỗng không?
int isEmpty(Queue *q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

// Kiểm tra Queue đầy? 
int isFull(Queue *q) {
    return 0; 
}

// Thêm một phần tử vào Queue
void EnQueue(Queue *q, thuetruyen x) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Không đủ dung lượng !\n");
        return;
    }
    p->data = x;
    p->pNext = NULL;

    if (isEmpty(q)) {
        q->front = p;
        q->rear = p;
    }
    else {
        q->rear->pNext = p;
        q->rear = p;
    }
}

// Lấy thông tin và hủy phần tử ở đầu Queue
thuetruyen DeQueue(Queue *q) {
    thuetruyen error;
    strcpy(error.maTruyen, "NULL");
    strcpy(error.tenTruyen, "NULL");
    if (isEmpty(q)) {
        printf("| Queue rỗng !\n");
        return error; // Trả về 1 để báo lỗi (có thể dùng giá trị đặc biệt hơn)
    }
    Node* p = q->front;
    q->front = q->front->pNext;

    if (q->front == NULL) // Nếu sau khi xóa mà Queue rỗng
        q->rear = NULL;

    thuetruyen x = p->data;
    delete p;
    return x;
}

// Xem thông tin phần tử đầu Queue
thuetruyen Front(Queue *q) {
    thuetruyen error;
    strcpy(error.maTruyen, "NULL");
    strcpy(error.maTruyen, "NULL");
    if (isEmpty(q))
        return error;
    return q->front->data;
}
// Xem thông tin phần tử cuối Queue
thuetruyen Rear(Queue* q)
{
    thuetruyen error;
    strcpy(error.maTruyen, "NULL");
    strcpy(error.maTruyen, "NULL");
    if (isEmpty(q))
        return error;
    return q->rear->data;
}
// Hàm nhập chuỗi

// Hàm kiểm tra mã truyện
int IsmaTruyen(char str[])
{
    if (strlen(str) > 10)
        return 0;
    return 1;   
}
int Kiemtratrungma(Queue* q,char makiemtra[])
{
    Node* temp = q->front;
    while (temp != NULL)
    {
        if (strcmp(temp->data.maTruyen, makiemtra) == 0)
        {
            printf("| Mã truyện bị trùng ! Vui lòng nhập mã truyện khác.");
            return 1;
        }
        temp = temp->pNext;
    }
    return 0;
}

void Nhap(Queue *q)
{
    thuetruyen thuetruyen;
    int count = 1;
    while (true)
    {
        printf("| Số lần nhập truyện %d\n", count);
        do
        {
            printf("| Nhập mã truyện ( nhập 0 để kêt thúc ): ");
            nhapChuoi(thuetruyen.maTruyen, sizeof(thuetruyen.maTruyen));
            if (strcmp(thuetruyen.maTruyen, "0") == 0) return;
            if (!IsmaTruyen(thuetruyen.maTruyen))
            {
                printf("Mã truyện tối đa 10 ký tự !\n");
                while (getchar() != '\n');
            }
        } while (!IsmaTruyen(thuetruyen.maTruyen));
        printf("| Nhap tên truyện: ");
        nhapChuoi(thuetruyen.tenTruyen, sizeof(thuetruyen.tenTruyen));
        printf("| Nhập tên tác giả: ");
        nhapChuoi(thuetruyen.tacGia, sizeof(thuetruyen.tacGia));
        printf("| Nhập thể loại: ");
        nhapChuoi(thuetruyen.theloai, sizeof(thuetruyen.theloai));
        do {
            printf("| Nhập năm xuất bản của sách: ");
            scanf_s("%d", &thuetruyen.namxuatban);
            while (getchar() != '\n');
            if (thuetruyen.namxuatban <= 0)
            {
                printf("| Năm xuất bản phải là số dương !\n");
            }
        } while (thuetruyen.namxuatban <= 0);
        printf("| Nhập tình trạng của truyện: ");
        nhapChuoi(thuetruyen.tinhtrang, sizeof(thuetruyen.tinhtrang));
        EnQueue(q, thuetruyen);
        count++;
    }
}
//2. Hiển thị danh sách các phần tử.
void xuat1(thuetruyen* tv)
{
    printf("| %-10s | %-26s | %-22s | %-20s | %-10d | %-12s |\n",
        tv->maTruyen,
        tv->tenTruyen,
        tv->tacGia,
        tv->theloai,
        tv->namxuatban,
        tv->tinhtrang); 
}

void xuat(Queue* q)
{
    if (isEmpty(q))
    {
        printf("\n| Danh sách truyện rỗng!\n");
        return;
    }
    printf("\n|========================================== DANH SÁCH TRUYỆN =========================================================|\n");
    printf("| %-10s | %-26s | %-22s | %-20s | %-10s | %-12s |\n",
        "Ma truyen", "Ten truyen", "Tac gia", "The loai", "Nam XB", "Tinh trang");
    printf("|=====================================================================================================================|\n");

    Node* temp = q->front;
    while (temp != NULL)
    {
        xuat1(&temp->data);
        temp = temp->pNext;
    }
    printf("|---------------------------------------------------------------------------------------------------------------------|\n");
    printf("\n");
}

//3. Tìm kiếm phần tử theo một tiêu chí(ví dụ : mã số, tên...).
Queue TimkiemTruyen(Queue* q, char inforSearch[])
{
    Queue danhsachtimdc;
    Init(&danhsachtimdc);
    int count = 0;
    Node* temp = q->front;
    while (temp != NULL)
    {
        if (strcmp(temp->data.maTruyen, inforSearch) == 0 ||
            strcmp(temp->data.tenTruyen, inforSearch) == 0||
            strcmp(temp->data.tacGia, inforSearch) == 0   ||
            strcmp(temp->data.theloai, inforSearch) == 0  ||
            strcmp(temp->data.tinhtrang, inforSearch) == 0)
        {
            EnQueue(&danhsachtimdc, temp->data);
            count++;
        }
        temp = temp->pNext;
    }
    return danhsachtimdc;
}
// Cập nhật thông tin Truyện
void CapnhatTruyen(Queue* q, char maTruyenxoa[])
{
    Node* temp = q->front;
    while (temp != NULL)
    {
        if (strcmp(temp->data.maTruyen, maTruyenxoa) == 0)
            break;
        temp = temp->pNext;
    }

    if (temp == NULL) {
        printf("| Không tìm thấy mã truyện: %s\n", maTruyenxoa);
        return;
    }

    printf("| Thông tin của Truyện");
    xuat1(&temp->data);
    printf("| Nhập thông tin chỉnh sửa: ");
    while (true)
    {
        do
        {
            printf("| Nhập mã truyện: ");
            nhapChuoi(temp->data.maTruyen, sizeof(temp->data.maTruyen));
            if (strcmp(temp->data.maTruyen, "0") == 0)
            {
                return;
            }
            if (!IsmaTruyen(temp->data.maTruyen))
            {
                printf("Mã truyện tối đa 8 ký tự !\n");
            }
        } while (!IsmaTruyen(temp->data.maTruyen));
        printf("DEBUG: %s\n", temp->data.maTruyen);

        printf("| Nhap tên truyện: ");
        nhapChuoi(temp->data.tenTruyen, sizeof(temp->data.tenTruyen));
        printf("DEBUG: %s\n", temp->data.tenTruyen);

        printf("| Nhập tên tác giả: ");
        nhapChuoi(temp->data.tacGia, sizeof(temp->data.tacGia));
        printf("DEBUG: %s\n", temp->data.tacGia);

        printf("| Nhập thể loại: ");
        nhapChuoi(temp->data.theloai, sizeof(temp->data.theloai));

        do {
            printf("| Nhập năm xuất bản của sách: ");
            scanf_s("%d", &temp->data.namxuatban);
            while (getchar() != '\n');
            if (temp->data.namxuatban <= 0)
            {
                printf("| Năm xuất bản phải là số dương !\n");
            }
        } while (temp->data.namxuatban <= 0);

        printf("| Nhập tình trạng của truyện: ");
        nhapChuoi(temp->data.tinhtrang, sizeof(temp->data.tinhtrang));
    }  
}
// SẮP XẾP DANH SÁCH
// Hàm đổi chỗ hai phần tử
void swap(thuetruyen* a, thuetruyen* b)
{
    thuetruyen temp = *a;
    *a = *b;
    *b = temp;
}
// Sao chép danh sách
void copyList(Queue* q, Queue* q2)
{
    Init(q2);
    Node* temp = q->front;
    while (temp != NULL)
    {
        EnQueue(q2, temp->data);
        temp = temp->pNext;
    }
}
// Sắp xếp theo mã truyện
/* Thuat toan interchange sort                
Thuat toan sap xep Interchange Sort :
for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
        if s[i] > s[j]
            swap(s[i], s[j]) */
void sapxepMatruyenTangdan(Queue* q)
{
    Node* i= q->front;
    while (i->pNext != NULL)
    {
        Node* j = i->pNext;
        while (j != NULL)
        {
            if (strcmp(i->data.maTruyen, j->data.maTruyen) > 0)
            {
                swap(&i->data, &j->data);
            }
            j = j->pNext;
        }
        i = i->pNext;
    }
}
void sapxepMatruyenGiamdan(Queue* q)
{
    Node* i = q->front;
    while (i->pNext != NULL)
    {
        Node* j = i->pNext;
        while (j != NULL)
        {
            if (strcmp(i->data.maTruyen, j->data.maTruyen) < 0)
            {
                swap(&i->data, &j->data);
            }
            j = j->pNext;
        }
        i = i->pNext;
    }
}
// Sắp xếp theo TÊN TRUYỆN
// Từ A->Z
void sapxepTentruyenTangdan(Queue* q)
{
    Node* i = q->front;
    while (i->pNext != NULL)
    {
        Node* j = i->pNext;
        while (j != NULL)
        {
            if (strcmp(i->data.tenTruyen, j->data.tenTruyen) > 0)
            {
                swap(&i->data, &j->data);
            }
            j = j->pNext;
        }
        i = i->pNext;
    }
}
// Từ Z->A
void sapxepTentruyenGiamdan(Queue* q)
{
    Node* i = q->front;
    while (i->pNext != NULL)
    {
        Node* j = i->pNext;
        while (j != NULL)
        {
            if (strcmp(i->data.tenTruyen, j->data.tenTruyen) < 0)
            {
                swap(&i->data, &j->data);
            }
            j = j->pNext;
        }
        i = i->pNext;
    }
}
// Sắp xếp theo Năm xuất bản
// Thuat toan Selection Sort
void sapxepNamxuatbanTangdan(Queue* q)
{
    for (Node* i = q->front; i != NULL; i = i->pNext)
    {
        Node* min = i;
        for (Node* j = i; j != NULL; j = j->pNext)
        {
            if (j->data.namxuatban < min->data.namxuatban)
            {
                min = j;
            }
        }
        if (min!=i) swap(&i->data, &min->data);
    }
}
void sapxepNamxuatbanGiamdan(Queue* q)
{
    for (Node* i = q->front; i != NULL; i = i->pNext)
    {
        Node* max = i;
        for (Node* j = i; j != NULL; j = j->pNext)
        {
            if (j->data.namxuatban > max->data.namxuatban)
            {
                max = j;
            }
        }
        if(max!=i) swap(&i->data, &max->data);
    }
}
// Ghi dữ liệu ra tệp 
void GhiFile(Queue* q, const char *filename )
{
    FILE* f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("| Không tìm thấy file %s !\n", filename);
        return;
    }
    Node* temp = q->front;
    int count = 0;
    while (temp != NULL)
    {
        fprintf(f, "%s|%s|%s|%s|%d|%s\n",
            temp->data.maTruyen,
            temp->data.tenTruyen,
            temp->data.tacGia,
            temp->data.theloai,
            temp->data.namxuatban,
            temp->data.tinhtrang);
        count++;
        temp = temp->pNext;
    }
    int result = fclose(f);
    if (result == 0)
    {
        printf("| Đã ghi thành công %d truyện vào %s !\n", count, filename);
    }
    else
    {
        printf("| Ghi dữ liệu ra tệp %s thất bại !\n", filename);
    }
}
// Đọc file từ tệp
void DocFile(Queue* q, const char* filename)
{
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("| Không tìm thấy file %s !\n", filename);
        return;
    }
    int count = 0;  
    thuetruyen tv;
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%[^\n]\n",
        tv.maTruyen,
        tv.tenTruyen,
        tv.tacGia,
        tv.theloai,
        &tv.namxuatban,
        tv.tinhtrang) == 6)
    {
        EnQueue(q, tv);
        count++;
    }
    fclose(f);
    printf("| Đã đọc thành công %d truyện từ %s !\n", count, filename);
}
//7. Giải phóng danh sách
void freelist(Queue* q)
{
    Node* temp = q->front;
    while (temp != NULL)
    {
        Node* next = temp->pNext;
        free(temp);
        temp = next;
    }
    q->front = q->rear = NULL;
}
// Hàm chọn chiều sắp xếp   
char up_or_down()
{
    char updownchoice;
    printf("Ban muon sap xep theo chieu:\n");
    printf("[A].Tang dan\n");
    printf("[B].Giam dan\n");
    printf("Lua chon cua ban [A-B]:");
    scanf_s(" %c", &updownchoice, (unsigned int)sizeof(updownchoice));
    return updownchoice;
}

