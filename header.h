#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<regex>
#define max 100

using namespace std;

struct SinhVien
{
    string mssv;
    string lop;
    string hoten;
    float diem_tx1[60];
    float diem_tx2[60];
    float diem_kt[60];
    float dtk[60];
    float diem_he_4[60];
    string diem_chu[60];
    float GPA;
};SinhVien sinhvien[max];

struct Monhoc
{
    string tenMonHoc;
    int tinchi;

};Monhoc monhoc[max];

void menu();
void menu1();
void in(int soMonHoc);
void Tieu_De(Monhoc monhoc[], int soMonHoc);
void NhapSoLuongSinhVien(int &soSinhVien);
void nhapThongTinMonHoc(Monhoc monhoc[], int &soMonHoc);
void nhapMonHoc(int &soMonHoc);
void xuatThongTinMonHoc(Monhoc monhoc[], int soMonHoc);
void Nhap(SinhVien sinhvien[], int &soSinhVien, int soMonHoc);
void danhSachThongTinSinhVien(SinhVien sinhvien[], int soMonHoc, Monhoc monhoc[], int soSinhVien);
void xuatThongTinSinhVien(SinhVien sinhvien, Monhoc monhoc[], int soMonHoc);
void quyDoiDiem(SinhVien sinhvien[], int soMonHoc, int soSinhVien);
void GPA(SinhVien sinhvien[], Monhoc monhoc[], int soMonHoc, int soSinhVien);
void ThemSinhVien(SinhVien sinhvien[], int &soSinhVien, int soMonHoc);
void SuaThongTinSinhVien(SinhVien sinhvien[], int &soSinhVien, Monhoc monhoc[], int soMonHoc);
int timKiemSinhVien(SinhVien sinhvien[], int soSinhVien);
void xemTimKiem(SinhVien sinhvien[], int soSinhVien, Monhoc monhoc[], int soMonHoc);
void thong_Ke(SinhVien sinhvien[], int soSinhVien, Monhoc monhoc[], int soMonHoc);
void ghiFile(SinhVien sinhvien[], int soSinhVien, int soMonHoc, Monhoc monhoc[]);
void loadFile(int &soSinhVien, int soMonHoc, SinhVien sinhvien[], Monhoc monhoc[]);
string xoaKhoangTrang(string &str);
string kiemTraTen();
string kiemTraTenMonHoc();
double kiemTraDiem();
string kiemTraMaSinhVien(int soSinhVien, SinhVien sinhvien[]);
int kiemTraSo();