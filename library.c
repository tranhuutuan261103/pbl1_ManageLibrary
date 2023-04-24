#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

typedef char infor[40];

struct Book
{
    infor ma_so_sach;
    infor ten_sach;
    infor ten_tac_gia;
    infor nha_xuat_ban;
    int nam_xuat_ban;
    int trang_thai_sach;
    struct Book *next;
};
typedef struct Book *book; // thuvien.txt

void setw(int n);
void Intro_start();
void Intro_Library();

book makeBook();

int Size(book a);
book file_data(book a); // 1
book InsertFirst(book a);
book InsertLast(book a);
book InsertAfter(book a);

book Insert_Book(book a); // 2
book DeleteFirst(book a);
book DeleteLast(book a);
book DeleteAfter(book a, int pos);

book DeleteMaso(book a);
book DeleteName(book a);
book DeleteTacGia(book a);

book Delete_Book(book a); // 3

void Search_Ten_Sach(book a);
void Search_Ten_Tac_Gia(book a);
void Search_Nha_Xuat_Ban(book a);
void SearchBook(book a); // 4

void Intro();
void Display(book a);
void Intro_(int n);
void Xem_Toan_Bo_Sach(book a);
void Xem_Sach_Da_Muon(book a);
void Xem_Sach_Chua_Muon(book a);

void swapstring(char *x, char *y);
void swapint(int *x, int *y);

void Theo_Van_Ten_Sach(book a);
void Theo_Van_Ten_Tac_Gia(book a);
void Theo_Van_Nha_Xuat_Ban(book a);
void Theo_Ngay_Xuat_Ban(book a);
void Xem_Danh_Sach_Theo_Thu_Tu(book a);
void Xem_Sach(book a); // 5

book Muon_sach(book a);
book Tra_sach(book a);
void Muon_tra_sach(book a); // 6

book Sua_ten_sach(book a);
book Sua_ten_tac_gia(book a);
book Sua_nha_xuat_ban(book a);
book Sua_nam_san_xuat(book a);
void Cap_nhat_noi_dung_cua_sach(book a); // 7

void save_data(book a); // 8

int main()
{
    system("cls");
    book head = NULL;
    int choose;
    Intro_start();
    do
    {
        printf("====================            MENU            ====================");
        printf("\n1 .Khoi tao danh sach");
        printf("\n2 .Them 1 cuon sach");
        printf("\n3 .Xoa 1 cuon sach khoi danh sach");
        printf("\n4 .Tim kiem sach");
        printf("\n5 .Chuc nang xem danh sach");
        printf("\n6 .Chuc nang muon/tra sach");
        printf("\n7 .Chinh sua noi dung cua sach");
        printf("\n8 .Luu file");
        printf("\n0 .Ket thuc chuong trinh");
        printf("\n====================================================================");
        printf("\n\nChoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            break;
        case 1:
            head = file_data(head); // doc du lieu tu file
            system("cls");
            break;
        case 2:
            system("cls");
            head = Insert_Book(head);
            break;
        case 3:
            system("cls");
            head = Delete_Book(head);
            break;
        case 4:
            system("cls");
            SearchBook(head);
            break;
        case 5:
            system("cls");
            Xem_Sach(head);
            break;
        case 6:
            system("cls");
            Muon_tra_sach(head);
            break;
        case 7:
            system("cls");
            Cap_nhat_noi_dung_cua_sach(head);
            break;
        case 8:
            save_data(head);
            system("cls");
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
    return 0;
}

void setw(int n)
{
    while (n--)
        printf(" ");
}

void Intro_start()
{
    setw(30 - 5);
    for (int i = 0; i < 60; i++)
        printf("%c", 196);
    printf("\n");
    setw(5 + 30);
    printf("Truong Dai hoc Bach Khoa - Dai hoc Da Nang");
    printf("\n");
    setw(14 + 30);
    printf("Khoa Cong nghe thong tin");
    printf("\n");
    setw(24 + 30);
    printf("*---*");
    printf("\n");
    setw(11 + 30);
    printf("PBL1: Do an lap trinh tinh toan");
    printf("\n");
    setw(16 + 30);
    printf("De tai:Quan ly thu vien");
    printf("\n\n\n");
    setw(30);
    printf("Sinh vien thuc hien:");
    setw(10);
    printf("Giang vien huong dan:\n");
    setw(30);
    printf("-Nguyen Xuan Thinh");
    setw(12);
    printf("-Nguyen Thi Le Quyen\n");
    setw(30);
    printf("-Tran Huu Tuan\n");
    setw(30 - 5);
    for (int i = 0; i < 60; i++)
        printf("%c", 196);
    printf("\n\nNhan enter de tiep tuc...");
    getchar();
    system("cls");
}

void Intro_Library()
{
    printf("\n\n");
    setw(55);
    printf("***   LIBRARY   ***");
    printf("\n");
}

book makeBook()
{
    book temp = (book)malloc(sizeof(struct Book));
    temp->next = NULL;
    printf("Nhap ma so sach:");
    fflush(stdin);
    gets(temp->ma_so_sach);
    printf("Nhap ten sach:");
    fflush(stdin);
    gets(temp->ten_sach);
    printf("Nhap ten tac gia:");
    fflush(stdin);
    gets(temp->ten_tac_gia);
    printf("Nhap nha xuat ban:");
    fflush(stdin);
    gets(temp->nha_xuat_ban);
    printf("Nhap nam xuat ban:");
    scanf("%d", &temp->nam_xuat_ban);
    printf("Nhap trang thai sach(1.Chua muon/0.Da muon):");
    scanf("%d", &temp->trang_thai_sach);
    return temp;
}

int Size(book a)
{
    int count = 0;
    while (a != NULL)
    {
        ++count;
        a = a->next;
    }
    return count;
}

book file_data(book a)
{
    infor s;
    FILE *f;
    do
    {
        printf("Nhap duong dan:");
        fflush(stdin);
        gets(s);
        f = fopen(s, "r+");
    } while (f == NULL);
    while (1)
    {
        book temp = (book)malloc(sizeof(struct Book));
        temp->next = NULL;
        char s[256];
        fgets(s, 256, f);
        fscanf(f, "%d %d", &temp->nam_xuat_ban, &temp->trang_thai_sach);
        fscanf(f, "\n");
        char *token = strtok(s, ",");

        strcpy(temp->ma_so_sach, token);

        token = strtok(NULL, ",");
        strcpy(temp->ten_sach, token);

        token = strtok(NULL, ",");
        strcpy(temp->ten_tac_gia, token);

        token = strtok(NULL, ",");
        strcpy(temp->nha_xuat_ban, token);
        if (temp->nha_xuat_ban[strlen(temp->nha_xuat_ban) - 1] == '\n')
            temp->nha_xuat_ban[strlen(temp->nha_xuat_ban) - 1] = '\0';

        if (a == NULL)
        {
            a = temp;
        }
        else
        {
            book p = a;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
        if (feof(f))
            break;
    }
    fclose(f);
    return a;
}

book InsertFirst(book a)
{
    book temp = makeBook();
    if (a == NULL)
    {
        a = temp;
    }
    else
    {
        temp->next = a;
        a = temp;
    }
    return a;
}

book InsertLast(book a)
{
    book temp = makeBook();
    if (a == NULL)
    {
        a = temp;
    }
    else
    {
        book p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return a;
}

book InsertAfter(book a)
{
    int n = Size(a), pos;
    printf("\nNhap vi tri muon chen:");
    scanf("%d", &pos);
    if (pos <= 0 || pos > n + 1)
    {
        printf("Vi tri chen khong hop le!");
        fflush(stdin);
        getchar();
        return a;
    }
    if (pos == 1)
    {
        return InsertFirst(a);
    }
    else if (pos == n + 1)
    {
        return InsertLast(a);
    }
    book p = a;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    book temp = makeBook();
    temp->next = p->next;
    p->next = temp;
    return a;
}

book Insert_Book(book a)
{
    int choose;
    do
    {
        system("cls");
        Xem_Toan_Bo_Sach(a);
        printf("\n========Them 1 cuon sach========");
        printf("\n1 .Them vao dau danh sach");
        printf("\n2 .Them vao sau 1 cuon sach nao do");
        printf("\n3 .Them vao cuoi danh sach");
        printf("\n0 .Tro ve");
        printf("\n================================");
        printf("\n\nchoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            system("cls");
            break;
        case 1:
            a = InsertFirst(a);
            break;
        case 2:
            a = InsertAfter(a);
            break;
        case 3:
            a = InsertLast(a);
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
    return a;
}

book DeleteFirst(book a)
{
    if (a == NULL)
    {
        printf("\n=>Khong co phan tu de xoa!");
        fflush(stdin);
        getchar();
        return a;
    }
    return a->next;
}

book DeleteLast(book a)
{
    if (a == NULL)
    {
        printf("\n=>Khong co phan tu de xoa!");
        fflush(stdin);
        getchar();
        return a;
    }
    book before = NULL, after = a;
    while (after->next != NULL)
    {
        before = after;
        after = after->next;
    }
    if (before == NULL)
    {
        a = NULL;
    }
    else
    {
        before->next = NULL;
    }
    return a;
}

book DeleteAfter(book a, int pos)
{
    int n = Size(a);
    if (pos <= 0 || pos > n)
    {
        printf("=>Vi tri muon xoa khong hop le!");
        fflush(stdin);
        getchar();
        return a;
    }
    book before = NULL, after = a;
    for (int i = 1; i < pos; i++)
    {
        before = after;
        after = after->next;
    }
    if (before == NULL)
    {
        a = a->next;
    }
    else
    {
        before->next = after->next;
    }
    return a;
}

book DeleteMaso(book a)
{
    infor s;
    int n = Size(a), pos = 0, i;
    book p = a;
    printf("Nhap ma so sach muon xoa:");
    fflush(stdin);
    gets(s);
    for (i = 1; i <= n; i++)
    {
        if (strcmp(p->ma_so_sach, s) == 0)
            pos = i;
        p = p->next;
    }
    if (pos == 0)
    {
        printf("\nMa so sach khong ton tai!");
        getchar();
        return a;
    }
    return DeleteAfter(a, pos);
}

book DeleteName(book a)
{
    infor s;
    int n = Size(a), pos = 0, i;
    book p = a;
    printf("Nhap ten sach muon xoa:");
    fflush(stdin);
    gets(s);
    for (i = 1; i <= n; i++)
    {
        if (strcmp(p->ten_sach, s) == 0)
            pos = i;
        p = p->next;
    }
    if (pos == 0)
    {
        printf("\nTen sach khong ton tai!");
        getchar();
        return a;
    }
    return DeleteAfter(a, pos);
}

book DeleteTacGia(book a)
{
    infor s;
    int n = Size(a), pos = 0;
    book p = a;
    printf("Nhap ten tac gia muon xoa:");
    fflush(stdin);
    gets(s);
    while (p != NULL)
    {
        pos++;
        if (strcmp(p->ten_tac_gia, s) == 0)
        {
            a = DeleteAfter(a, pos);
            pos--;
        }
        p = p->next;
    }
    if (pos == n)
    {
        printf("\nTen tac gia khong ton tai!");
        getchar();
        return a;
    }
    return a;
}

book Delete_Book(book a)
{
    int choose, pos;
    do
    {
        system("cls");
        Xem_Toan_Bo_Sach(a);
        printf("\n========Xoa 1 cuon sach========");
        printf("\n1 .Theo ma so sach");
        printf("\n2 .Theo ten sach");
        printf("\n3 .Theo ten tac gia");
        printf("\n4 .Xoa cuon sach o dau danh sach");
        printf("\n5 .Xoa cuon sach o sau cuon sach co ma so nao do");
        printf("\n6 .Xoa cuon sach o cuoi danh sach");
        printf("\n0 .Tro ve");
        printf("\n===============================");
        printf("\n\nchoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            system("cls");
            break;
        case 1:
            a = DeleteMaso(a);
            break;
        case 2:
            a = DeleteName(a);
            break;
        case 3:
            a = DeleteTacGia(a);
            break;
        case 4:
            a = DeleteFirst(a);
            break;
        case 5:
            printf("Nhap vi tri muon xoa:");
            scanf("%d", &pos);
            a = DeleteAfter(a, pos);
            break;
        case 6:
            a = DeleteLast(a);
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
    return a;
}

void Search_Ten_Sach(book a)
{
    infor s;
    int count = 0;
    printf("\nNhap ten sach:");
    fflush(stdin);
    gets(s);
    while (a != NULL)
    {
        if (strcmp(s, a->ten_sach) == 0)
        {
            count++;
            Display(a);
        }
        a = a->next;
    }
    getchar();
    if (!count)
    {
        printf("Sach khong ton tai!\n");
        fflush(stdin);
        getchar();
    }
}
void Search_Ten_Tac_Gia(book a)
{
    infor s;
    int count = 0;
    printf("\nNhap tac gia:");
    fflush(stdin);
    gets(s);
    while (a != NULL)
    {
        if (strcmp(s, a->ten_tac_gia) == 0)
        {
            count++;
            Display(a);
        }
        a = a->next;
    }
    if (!count)
    {
        printf("Sach khong ton tai!\n");
        fflush(stdin);
        getchar();
    }
}
void Search_Nha_Xuat_Ban(book a)
{
    infor s;
    int count = 0;
    printf("\nNhap nha xuat ban:");
    fflush(stdin);
    gets(s);
    while (a != NULL)
    {
        if (strcmp(s, a->nha_xuat_ban) == 0)
        {
            count++;
            Display(a);
        }
        a = a->next;
    }
    if (!count)
    {
        printf("Sach khong ton tai!\n");
        fflush(stdin);
        getchar();
    }
}

void SearchBook(book a)
{
    int choose;
    do
    {
        system("cls");
        Xem_Toan_Bo_Sach(a);
        printf("\n\n\n========Tim kiem sach theo======");
        printf("\n1 .Ten sach");
        printf("\n2 .Ten tac gia");
        printf("\n3 .Ten nha xuat ban");
        printf("\n0 .Tro ve");
        printf("\n================================");
        printf("\n\nchoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            system("cls");
            break;
        case 1:
            Search_Ten_Sach(a);
            break;
        case 2:
            Search_Ten_Tac_Gia(a);
            break;
        case 3:
            Search_Nha_Xuat_Ban(a);
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
}

void Intro()
{
    printf("\nMa so sach       Ten sach                           Ten tac gia                    Nha xuat ban                   Nam san xuat        Trang thai sach\n");
}

void Intro_(int n)
{
    while (n--)
        printf("%c", 196);
}

void Display(book a)
{
    printf("%-10s %-40s %-30s %-30s %-20d", a->ma_so_sach, a->ten_sach, a->ten_tac_gia, a->nha_xuat_ban, a->nam_xuat_ban);
    if (a->trang_thai_sach == 1)
        printf("CHUA MUON\n");
    else
        printf("DA MUON\n");
}

void Xem_Toan_Bo_Sach(book a)
{
    Intro_Library();
    Intro();
    while (a != NULL)
    {
        Display(a);

        a = a->next;
    }
    Intro_(150);
}

void Xem_Sach_Da_Muon(book a)
{
    Intro_Library();
    Intro();
    while (a != NULL)
    {
        if (a->trang_thai_sach == 0)
        {
            Display(a);
        }
        a = a->next;
    }
}

void Xem_Sach_Chua_Muon(book a)
{
    Intro_Library();
    Intro();
    while (a != NULL)
    {
        if (a->trang_thai_sach == 1)
        {
            Display(a);
        }
        a = a->next;
    }
}

void swapstring(char *x, char *y)
{
    infor temp;
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

void swapint(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Theo_Van_Ten_Sach(book a)
{
    for (book p = a; p->next != NULL; p = p->next)
    {
        book min = p;
        for (book q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(q->ten_sach, min->ten_sach) < 0)
            {
                min = q;
            }
        }
        swapstring(min->ma_so_sach, p->ma_so_sach);
        swapstring(min->ten_sach, p->ten_sach);
        swapstring(min->ten_tac_gia, p->ten_tac_gia);
        swapstring(min->nha_xuat_ban, p->nha_xuat_ban);
        swapint(&min->nam_xuat_ban, &p->nam_xuat_ban);
        swapint(&min->trang_thai_sach, &p->trang_thai_sach);
    }
    Xem_Toan_Bo_Sach(a);
}

void Theo_Van_Ten_Tac_Gia(book a)
{
    for (book p = a; p->next != NULL; p = p->next)
    {
        book min = p;
        for (book q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(q->ten_tac_gia, min->ten_tac_gia) < 0)
            {
                min = q;
            }
        }
        swapstring(min->ma_so_sach, p->ma_so_sach);
        swapstring(min->ten_sach, p->ten_sach);
        swapstring(min->ten_tac_gia, p->ten_tac_gia);
        swapstring(min->nha_xuat_ban, p->nha_xuat_ban);
        swapint(&min->nam_xuat_ban, &p->nam_xuat_ban);
        swapint(&min->trang_thai_sach, &p->trang_thai_sach);
    }
    Xem_Toan_Bo_Sach(a);
}

void Theo_Van_Nha_Xuat_Ban(book a)
{
    for (book p = a; p->next != NULL; p = p->next)
    {
        book min = p;
        for (book q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(q->nha_xuat_ban, min->nha_xuat_ban) < 0)
            {
                min = q;
            }
        }
        swapstring(min->ma_so_sach, p->ma_so_sach);
        swapstring(min->ten_sach, p->ten_sach);
        swapstring(min->ten_tac_gia, p->ten_tac_gia);
        swapstring(min->nha_xuat_ban, p->nha_xuat_ban);
        swapint(&min->nam_xuat_ban, &p->nam_xuat_ban);
        swapint(&min->trang_thai_sach, &p->trang_thai_sach);
    }
    Xem_Toan_Bo_Sach(a);
}

void Theo_Ngay_Xuat_Ban(book a)
{
    for (book p = a; p->next != NULL; p = p->next)
    {
        book max = p;
        for (book q = p->next; q != NULL; q = q->next)
        {
            if (q->nam_xuat_ban > max->nam_xuat_ban)
            {
                max = q;
            }
        }
        swapstring(max->ma_so_sach, p->ma_so_sach);
        swapstring(max->ten_sach, p->ten_sach);
        swapstring(max->ten_tac_gia, p->ten_tac_gia);
        swapstring(max->nha_xuat_ban, p->nha_xuat_ban);
        swapint(&max->nam_xuat_ban, &p->nam_xuat_ban);
        swapint(&max->trang_thai_sach, &p->trang_thai_sach);
    }
    Xem_Toan_Bo_Sach(a);
}

void Xem_Danh_Sach_Theo_Thu_Tu(book a)
{
    int choose;
    do
    {
        printf("\n\n\n========Xem danh sach theo thu tu========");
        printf("\n1 .Theo van alphabet cua ten sach");
        printf("\n2 .Theo van alphabet cua ten tac gia");
        printf("\n3 .Theo van alphabet cua nha xuat ban");
        printf("\n4 .Sach duoc xuat ban moi nhat");
        printf("\n0 .Tro ve");
        printf("\n=========================================");
        printf("\n\nchoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            Theo_Van_Ten_Sach(a);
            break;
        case 2:
            system("cls");
            Theo_Van_Ten_Tac_Gia(a);
            break;
        case 3:
            system("cls");
            Theo_Van_Nha_Xuat_Ban(a);
            break;
        case 4:
            system("cls");
            Theo_Ngay_Xuat_Ban(a);
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
}

void Xem_Sach(book a)
{
    int choose;
    do
    {
        printf("\n\n\n========Chuc nang xem danh sach========");
        printf("\n1 .Xem toan bo danh muc sach trong danh sach");
        printf("\n2 .Xem nhung cuon sach dang cho muon");
        printf("\n3 .Xem nhung cuon sach chua cho muon");
        printf("\n4 .Xem danh sach theo thu tu");
        printf("\n0 .Tro ve");
        printf("\n=======================================");
        printf("\n\nchoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            Xem_Toan_Bo_Sach(a);
            break;
        case 2:
            system("cls");
            Xem_Sach_Da_Muon(a);
            break;
        case 3:
            system("cls");
            Xem_Sach_Chua_Muon(a);
            break;
        case 4:
            system("cls");
            Xem_Danh_Sach_Theo_Thu_Tu(a);
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
}

book Muon_sach(book a)
{
    if (a == NULL)
        return a;
    book p = a;
    infor s;
    Xem_Sach_Chua_Muon(a);
    printf("\n\nNhap ma so sach muon muon:");
    fflush(stdin);
    gets(s);
    while (p != NULL)
    {
        if (strcmp(s, p->ma_so_sach) == 0 && p->trang_thai_sach == 1)
        {
            p->trang_thai_sach = 0;
            break;
        }
        p = p->next;
    }
    return a;
}
book Tra_sach(book a)
{
    if (a == NULL)
        return a;
    book p = a;
    infor s;
    Xem_Sach_Da_Muon(a);
    printf("\n\nNhap ma so sach muon tra:");
    fflush(stdin);
    gets(s);
    while (p != NULL)
    {
        if (strcmp(s, p->ma_so_sach) == 0 && p->trang_thai_sach == 0)
        {
            p->trang_thai_sach = 1;
            break;
        }
        p = p->next;
    }
    return a;
}

void Muon_tra_sach(book a)
{
    int choose;
    do
    {
        system("cls");
        printf("========Chuc nang muon/tra sach========");
        printf("\n1 .Muon sach.");
        printf("\n2 .Tra sach.");
        printf("\n0 .Tro ve");
        printf("\n=======================================");
        printf("\n\nChoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            a = Muon_sach(a);
            break;
        case 2:
            system("cls");
            a = Tra_sach(a);
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
}

book Sua_ten_sach(book a)
{
    infor s1, s2;
    printf("Nhap ma so sach:");
    fflush(stdin);
    gets(s1);
    printf("Nhap ten sach moi:");
    fflush(stdin);
    gets(s2);
    book p = a;
    int check = 0;
    while (p->next != NULL)
    {
        if (strcmp(p->ma_so_sach, s1) == 0)
        {
            check = 1;
            break;
        }
        p = p->next;
    }
    if (check == 1)
        strcpy(p->ten_sach, s2);
    else
    {
        printf("Ma so sach khong ton tai!\n");
    }
    return a;
}

book Sua_ten_tac_gia(book a)
{
    infor s1, s2;
    printf("Nhap ma so sach:");
    fflush(stdin);
    gets(s1);
    printf("Nhap ten tac gia moi:");
    fflush(stdin);
    gets(s2);
    book p = a;
    int check = 0;
    while (p->next != NULL)
    {
        if (strcmp(p->ma_so_sach, s1) == 0)
        {
            check = 1;
            break;
        }
        p = p->next;
    }
    if (check == 1)
        strcpy(p->ten_tac_gia, s2);
    else
    {
        printf("Ma so sach khong ton tai!\n");
    }
    return a;
}

book Sua_nha_xuat_ban(book a)
{
    infor s1, s2;
    printf("Nhap ma so sach:");
    fflush(stdin);
    gets(s1);
    printf("Nhap nha xuat ban moi:");
    fflush(stdin);
    gets(s2);
    book p = a;
    int check = 0;
    while (p->next != NULL)
    {
        if (strcmp(p->ma_so_sach, s1) == 0)
        {
            check = 1;
            break;
        }
        p = p->next;
    }
    if (check == 1)
        strcpy(p->nha_xuat_ban, s2);
    else
    {
        printf("Ma so sach khong ton tai!\n");
    }
    return a;
}

book Sua_nam_san_xuat(book a)
{
    int year;
    infor s;
    printf("Nhap ma so sach:");
    fflush(stdin);
    gets(s);
    printf("Nhap nam san xuat moi:");
    scanf("%d", &year);
    book p = a;
    int check = 0;
    while (p->next != NULL)
    {
        if (strcmp(p->ma_so_sach, s) == 0)
        {
            check = 1;
            break;
        }
        p = p->next;
    }
    if (check == 1)
        p->nam_xuat_ban = year;
    else
    {
        printf("Ma so sach khong ton tai!\n");
    }
    return a;
}

void Cap_nhat_noi_dung_cua_sach(book a)
{
    int choose;
    do
    {
        system("cls");
        Xem_Toan_Bo_Sach(a);
        printf("\n\n\n========Chuc nang chinh sua noi dung cua sach========");
        printf("\n1 .Sua ten sach.");
        printf("\n2 .Sua ten tac gia.");
        printf("\n3 .Sua nha xuat ban.");
        printf("\n4 .Sua nam xuat ban.");
        printf("\n0 .Tro ve");
        printf("\n=====================================================");
        printf("\n\nchoose=");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            system("cls");
            break;
        case 1:
            a = Sua_ten_sach(a);
            break;
        case 2:
            a = Sua_ten_tac_gia(a);
            break;
        case 3:
            a = Sua_nha_xuat_ban(a);
            break;
        case 4:
            a = Sua_nam_san_xuat(a);
            break;
        default:
            printf("Sai chuc nang, vui long chon lai!\n");
            break;
        }
    } while (choose);
}

void save_data(book a)
{
    infor s;
    printf("Nhap duong dan:");
    fflush(stdin);
    gets(s);
    FILE *f = fopen(s, "w+");
    while (a != NULL)
    {
        fputs(a->ma_so_sach, f);
        fputs(",", f);
        fputs(a->ten_sach, f);
        fputs(",", f);
        fputs(a->ten_tac_gia, f);
        fputs(",", f);
        fputs(a->nha_xuat_ban, f);
        fprintf(f, "\n%d %d\n", a->nam_xuat_ban, a->trang_thai_sach);
        a = a->next;
    }
    fclose(f);
}
