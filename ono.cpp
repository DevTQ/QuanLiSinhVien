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

// void loadFile(int soSinhVien, int soMonHoc, SinhVien sinhvien[], Monhoc monhoc[]) {
//     ifstream fileIn;
//     fileIn.open("C:\\Users\\tiens\\Desktop\\data.txt", ios_base::in);
//     if (fileIn.fail()) {
//         cout << "khong the mo tep! kiem tra lai.";
//         return;
//     }
//     while (!fileIn.eof()) {
//         fileIn>>soMonHoc;
    //     for(int i = 0; i < soMonHoc; i++) {
    //         getline(fileIn, monhoc[i].tenMonHoc);
    //         fileIn>>monhoc[i].tinchi;
    //     }
    //     fileIn.ignore();
    //     for(int i = 0; i < soSinhVien; i++) {
    //         getline(fileIn, sinhvien[i].hoten);
    //         getline(fileIn, sinhvien[i].lop);
    //         getline(fileIn, sinhvien[i].mssv);
    //         for(int j = 0; j < soMonHoc; j++) {
    //             fileIn>>sinhvien[i].diem_tx1[j]>>sinhvien[i].diem_tx2[j]>>sinhvien[i].diem_kt[j]>>sinhvien[i].dtk[j]>>sinhvien[i].diem_he_4[j]>>sinhvien[i].diem_chu[j];
    //         }
    //     fileIn >> sinhvien[i].GPA;
    //     }
    // }
    // fileIn.close();
//     }
//     cout << "Doc du lieu thanh cong." << endl;
// }

int main() {
    int soSinhVien, soMonHoc;
    ifstream fileIn;
    fileIn.open("C:\\Users\\tiens\\Desktop\\data.txt", ios_base::in);
    if (fileIn.fail()) {
        cout << "khong the mo tep! kiem tra lai.";
        return -1;
    }
    while (!fileIn.eof()) {
        fileIn>>soMonHoc;
        cout<<soMonHoc<<endl;
        for(int i = 0; i < soMonHoc; i++) {
            fileIn.ignore();
            getline(fileIn, monhoc[i].tenMonHoc);
            fileIn>>monhoc[i].tinchi;
        }
        cout<<"doc file thanh cong\n"; 
        for(int i = 0; i < soSinhVien; i++) {
            fileIn.ignore();
            getline(fileIn, sinhvien[i].hoten);
            getline(fileIn, sinhvien[i].lop);
            getline(fileIn, sinhvien[i].mssv);
            for(int j = 0; j < soMonHoc; j++) {
                fileIn>>sinhvien[i].diem_tx1[j]>>sinhvien[i].diem_tx2[j]>>sinhvien[i].diem_kt[j]>>sinhvien[i].dtk[j]>>sinhvien[i].diem_he_4[j]>>sinhvien[i].diem_chu[j];
            }
        fileIn >> sinhvien[i].GPA;
        }
        cout<<"Doc file thanh cong tiep";
    }
   
    return 0;
}