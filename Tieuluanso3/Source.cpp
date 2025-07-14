#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

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
void EnQueue(Queue *q, thuvien x) {
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
thuvien DeQueue(Queue *q) {
    thuvien error;
    strcpy(error.maTruyen, "NULL");
    strcpy(error.maTruyen, "NULL");
    if (isEmpty(q)) {
        printf("Queue rỗng\n");
        return error; // Trả về 1 để báo lỗi (có thể dùng giá trị đặc biệt hơn)
    }

    Node* p = q->front;
    q->front = q->front->pNext;

    if (q->front == NULL) // Nếu sau khi xóa mà Queue rỗng
        q->rear = NULL;

    thuvien x = p->data;
    delete p;
    return x;
}

// Xem thông tin phần tử đầu Queue
thuvien Front(Queue *q) {
    thuvien error;
    strcpy(error.maTruyen, "NULL");
    strcpy(error.maTruyen, "NULL");
    if (isEmpty(q))
        return error;
    return q->front->data;
}

// Hàm nhập chuỗi
void nhapChuoi(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}
// Hàm kiểm tra mã truyện
int IsmaTruyen(char str[])
{
    if (strlen(str) > 8)
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
    thuvien thuvien;
    int count = 1;
    while (true)
    {
        printf("| Số lần nhập truyện %d\n ", count);
        do
        {
            printf("| Nhập mã truyện ( nhập 0 để kêt thúc ): ");
            nhapChuoi(thuvien.maTruyen, sizeof(thuvien.maTruyen));
            if (strcmp(thuvien.maTruyen,"0") == 0)
            {
                return;
            }
            if (!IsmaTruyen(thuvien.maTruyen))
            {
                printf("Mã truyện tối đa 8 ký tự !\n");
            }
        } while (!IsmaTruyen(thuvien.maTruyen));
        printf("DEBUG: %s\n", thuvien.maTruyen);

        printf("| Nhap tên truyện: ");
        nhapChuoi(thuvien.tenTruyen, sizeof(thuvien.tenTruyen));
        printf("DEBUG: %s\n", thuvien.tenTruyen);

        printf("| Nhập tên tác giả: ");
        nhapChuoi(thuvien.tacGia, sizeof(thuvien.tacGia));
        printf("DEBUG: %s\n", thuvien.tacGia);

        printf("| Nhập thể loại: ");
        nhapChuoi(thuvien.theloai, sizeof(thuvien.theloai));

        do {
            printf("| Nhập năm xuất bản của sách: ");
            scanf_s("%d", &thuvien.namxuatban);
            while (getchar() != '\n');
            if (thuvien.namxuatban <= 0)
            {
                printf("| Năm xuất bản phải là số dương !\n");
            }
        } while (thuvien.namxuatban <= 0);

        printf("| Nhập tình trạng của truyện: ");
        nhapChuoi(thuvien.tinhtrang, sizeof(thuvien.tinhtrang));
        EnQueue(q, thuvien);
        count++;
    }
}
//2. Hiển thị danh sách các phần tử.
void xuat1(thuvien *tv)
{
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-10s | %-20s | %-15s | %-12d | %-10s |\n",
            tv->maTruyen,
            tv->tenTruyen,
            tv->tacGia,
            tv->theloai,
            tv->namxuatban,
            tv->tinhtrang);
    printf("_____________________________________________________________________________________________\n");

}
void xuat(Queue *q)
{
    printf("---------------------------------------------------------------------------------------------\n");
    Node* temp = q->front;
    while (temp != NULL)
    {
        printf("| %-8s | %-10s | %-20s | %-15s | %-12d | %-10s |\n",
            temp->data.maTruyen,
            temp->data.tenTruyen,
            temp->data.tacGia,
            temp->data.theloai,
            temp->data.namxuatban,
            temp->data.tinhtrang);
        printf("_____________________________________________________________________________________________\n");
       
        temp = temp->pNext;
    }
    printf("---------------------------------------------------------------------------------------------\n");
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
    thuvien tv;
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