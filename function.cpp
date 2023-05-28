#include"header.h"

void menu() {
    cout<<setw(90)<<"CHUONG TRINH QUAN LI DIEM CUA SINH VIEN\n";
    cout<<setw(90)<<"+--------------------------------------+\n";
    cout<<setw(90)<<"| 1. Nhap thong tin mon hoc            |\n";
    cout<<setw(90)<<"| 2. Nhap danh sach sinh vien          |\n";
    cout<<setw(90)<<"| 3. Xem danh sach thong tin sinh vien |\n";
    cout<<setw(90)<<"| 4. Sua thong tin sinh vien           |\n";
    cout<<setw(90)<<"| 5. tra cuu thong tin sinh vien       |\n";
    cout<<setw(90)<<"| 6. Thong ke diem cua sinh vien       |\n";
    cout<<setw(90)<<"| 7. Luu danh sach sinh vien ra file   |\n";
    cout<<setw(90)<<"| 8. Load file da luu                  |\n";
    cout<<setw(90)<<"| 0. Thoat khoi chuong trinh           |\n";
    cout<<setw(90)<<"+--------------------------------------+\n";
    cout<<setw(80)<<" -> Moi ban nhap vao lua chon\n";
}

void menu1() {
    cout<<"\n\t   Moi Ban Chon";
    cout<<"\n\t+------------------+";
    cout<<"\n\t|1. Them sinh vien |";
    cout<<"\n\t|2. Sua sinh vien  |";
    cout<<"\n\t+------------------+";
    cout<<"\n\t-> lua chon cua ban\n";

} 	
void NhapSoLuongSinhVien(int &soSinhVien) {
    cout<<"\nNhap so luong sinh vien : ";
    soSinhVien = kiemTraSo();
}

void nhapThongTinMonHoc(Monhoc monhoc[], int &soMonHoc) {
    nhapMonHoc(soMonHoc);
    for(int i = 0; i < soMonHoc; i++) {
        cin.ignore();
        cout<<"\nNhap ten mon hoc thu "<<i+1<< " : ";
        monhoc[i].tenMonHoc = kiemTraTenMonHoc();
        cout<<"\nNhap so tin chi : ";
        monhoc[i].tinchi = kiemTraSo();
    } 
}
void nhapMonHoc(int &soMonHoc) {
    cout<<"\nNhap so luong mon hoc : ";
    soMonHoc = kiemTraSo();
}

void xuatThongTinMonHoc(Monhoc monhoc[], int soMonHoc) {
    for(int i=0; i<soMonHoc; i++) {
        cout<<monhoc[i].tenMonHoc<<setw(14);
    }
}

void in(int soMonHoc) {
    for(int j = 0; j < soMonHoc; j++) {
        cout<<"DTK,"<<"TD4,"<<"DC"<<setw(8);
    }
}


void Tieu_De(Monhoc monhoc[], int soMonHoc) {
    cout<<"\n\t\t\t\t\tTHONG TIN SINH VIEN\n";
    cout<<"+--------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    cout<<"|"<<setw(2)<<"STT"<<setw(6)<<"LOP"<<setw(9)<<"HO TEN"<<setw(15)<<"MSSV"<<setw(10);xuatThongTinMonHoc(monhoc, soMonHoc);cout<<setw(10)<<"GPA";
    cout<<"\n|"<<setw(40);in(soMonHoc);
    cout<<"\n+------------------------------------------------------------------------------------------------------------------------------------------------+\n";

}

void Nhap(SinhVien sinhvien[], int &soSinhVien ,int soMonHoc) {
    NhapSoLuongSinhVien(soSinhVien);
    for(int i = 0; i < soSinhVien; i++) {
        cout<<"\nNhap ho ten sinh vien : ";
        sinhvien[i].hoten = kiemTraTen();
        cout<<"\nNhap ten lop sinh vien : ";
        getline(cin, sinhvien[i].lop);
        sinhvien[i].lop = xoaKhoangTrang(sinhvien[i].lop);
        cout<<"\nNhap ma so sinh vien gom 7 so(0......) : ";
        sinhvien[i].mssv = kiemTraMaSinhVien(soSinhVien, sinhvien);
        for(int j = 0; j < soMonHoc; j++) {
            cout<<"\nNhap diem thuong xuyen 1 mon "<<monhoc[j].tenMonHoc<<" : ";
            sinhvien[i].diem_tx1[j] = kiemTraDiem();
            cout<<"\nNhap diem thuong xuyen 2 "<<monhoc[j].tenMonHoc<<" : ";
            sinhvien[i].diem_tx2[j] = kiemTraDiem();
            cout<<"\nNhap diem ket thuc mon "<<monhoc[j].tenMonHoc<<" : ";
            sinhvien[i].diem_kt[j] = kiemTraDiem();
        }
    }
    cout<<"\nNhap du lieu thanh cong."<<endl;
}

void danhSachThongTinSinhVien(SinhVien sinhvien[], int soMonHoc, Monhoc monhoc[], int soSinhVien) {
    if(sinhvien[0].lop.empty() && sinhvien[0].hoten.empty() && sinhvien[0].mssv.empty()) {
        cout<<"Danh sach trong!"<<endl;
    }else {
        Tieu_De(monhoc, soMonHoc);
        for(int i = 0; i < soSinhVien; i++) {
            cout<<"|"<<setw(2)<<i+1<<setw(6)<<sinhvien[i].lop<<setw(18)<<sinhvien[i].hoten<<setw(6)<<sinhvien[i].mssv<<setw(25);
            for(int j = 0; j < soMonHoc; j++) {
                sinhvien[i].dtk[j] = (((sinhvien[i].diem_tx1[j] + sinhvien[i].diem_tx2[j]) / 4) + (sinhvien[i].diem_kt[j] / 2));
                quyDoiDiem(sinhvien, soMonHoc, soSinhVien);
                cout<<setw(8)<<sinhvien[i].dtk[j]<<setw(2)<<sinhvien[i].diem_he_4[j]<<setw(3)<<sinhvien[i].diem_chu[j]<<setw(10); 
            }
            GPA(sinhvien, monhoc, soMonHoc, soSinhVien);
            cout<<setprecision(2)<<sinhvien[i].GPA;
            cout<<"\n";
        }
    cout<<setw(2)<<"+--------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    }
}

void xuatThongTinSinhVien(SinhVien sinhvien, Monhoc monhoc[], int soMonHoc) {
    cout<<"\n\t\tTHONG TIN SINH VIEN\n";
    cout<<"LOP"<<setw(15)<<"HO TEN"<<setw(15)<<"MSSV"<<setw(10);xuatThongTinMonHoc(monhoc, soMonHoc);
    cout<<setw(10)<<"GPA\n";
    cout<<setw(40);in(soMonHoc);cout<<endl;
    cout<<left<<sinhvien.lop<<setw(10)<<sinhvien.hoten<<right<<setw(10)<<sinhvien.mssv<<setw(8);
    for(int j = 0; j < soMonHoc; j++) {
        cout<<sinhvien.dtk[j]<<setw(3)<<sinhvien.diem_he_4[j]<<setw(3)<<sinhvien.diem_chu[j]<<setw(8);
    }
    cout<<setw(6)<<sinhvien.GPA;
}

void quyDoiDiem(SinhVien sinhvien[], int soMonHoc, int soSinhVien) {
    for(int i = 0; i < soSinhVien; i++) {
        for(int j = 0; j < soMonHoc; j++) {
            if(sinhvien[i].dtk[j] >= 8.5 && sinhvien[i].dtk[j] <= 10.0) {
                sinhvien[i].diem_he_4[j] = 4.0;
                sinhvien[i].diem_chu[j] = "A";
            }else if(sinhvien[i].dtk[j] >= 8.0 && sinhvien[i].dtk[j] <= 8.4) {
                sinhvien[i].diem_he_4[j] = 3.5;
                sinhvien[i].diem_chu[j] = "B+";
            }else if(sinhvien[i].dtk[j] >= 7.0 && sinhvien[i].dtk[j] <= 7.9) {
                sinhvien[i].diem_he_4[j] = 3.0;
                sinhvien[i].diem_chu[j] = "B";
            }else if(sinhvien[i].dtk[j] >= 6.5 && sinhvien[i].dtk[j] <= 6.9) {
                sinhvien[i].diem_he_4[j] = 2.5;
                sinhvien[i].diem_chu[j] = "C+";
            }else if(sinhvien[i].dtk[j] >= 5.5 && sinhvien[i].dtk[j] <= 6.4) {
                sinhvien[i].diem_he_4[j] = 2.0;
                sinhvien[i].diem_chu[j] = "C";
            }else if(sinhvien[i].dtk[j] >= 5.0 && sinhvien[i].dtk[j] <= 5.4) {
                sinhvien[i].diem_he_4[j] = 1.5;
                sinhvien[i].diem_chu[j] = "D+";
            }else if(sinhvien[i].dtk[j] >= 4.0 && sinhvien[i].dtk[j] <= 4.9) {
                sinhvien[i].diem_he_4[j] = 1.0;
                sinhvien[i].diem_chu[j] = "D";
            }else if(sinhvien[i].dtk[j] < 4.0) {
                sinhvien[i].diem_chu[j] = "F";
            }
        }
    }
}

void GPA(SinhVien sinhvien[], Monhoc monhoc[], int soMonHoc, int soSinhVien) {
    int temp = 0;
    for(int i = 0; i < soMonHoc; i++) {
        temp += monhoc[i].tinchi;
    }
    for(int i = 0; i < soSinhVien; i++) {
        float sum = 0.0;
        for(int j = 0; j < soMonHoc; j++) {
            sum += (sinhvien[i].diem_he_4[j] * monhoc[j].tinchi);  
        }
        sinhvien[i].GPA = sum / temp;
    }
}

void ThemSinhVien(SinhVien sinhvien[], int &soSinhVien, int soMonHoc) {
    SinhVien svm;
    cout<<"\nNhap ho ten sinh vien can them : ";
    svm.hoten = kiemTraTen();
    cout<<"\nNhap lop sinh vien : ";
    getline(cin, svm.lop);
    svm.lop = xoaKhoangTrang(svm.lop);
    cout<<"\nNhap ma so sinh vien : ";
    svm.mssv = kiemTraMaSinhVien(soSinhVien,sinhvien);
    for(int i = 0; i < 1; i++) {
        for(int j = 0; j < soMonHoc; j++) {
             cout<<"\nNhap diem thuong xuyen 1 : ";
            svm.diem_tx1[j] = kiemTraDiem();
            cout<<"\nNhap diem thuong xuyen 2: ";
            svm.diem_tx2[j] = kiemTraDiem();
            cout<<"\nNhap diem ket thuc : ";
            svm.diem_kt[j] = kiemTraDiem();
        }
    }
    sinhvien[soSinhVien] = svm;
    soSinhVien++;
    cout<<"\nThem sinh vien thanh cong!\n";
}

void SuaThongTinSinhVien(SinhVien sinhvien[], int &soSinhVien, Monhoc monhoc[], int soMonHoc) {
    cout<<"Nhap ma so sinh vien can sua : ";
    int vitri = timKiemSinhVien(sinhvien, soSinhVien);
    if(vitri == -1) {
        cout<<"\nMa so sinh vien khong ton tai! Kiem tra lai."<<endl;
    }
    else {
        xuatThongTinSinhVien(sinhvien[vitri], monhoc, soMonHoc);
        cout<<endl;
        cout<<"\nNhap ho ten sinh vien moi : ";
        sinhvien[vitri].hoten = kiemTraTen();
        cout<<"\nNhap lop sinh vien moi : ";
        getline(cin, sinhvien[vitri].lop);
        sinhvien[vitri].lop = xoaKhoangTrang(sinhvien[vitri].lop);
        cout<<"\nNhap ma so sinh vien moi : ";
        sinhvien[vitri].mssv = kiemTraMaSinhVien(soSinhVien, sinhvien);
        for(int j = 0; j < soMonHoc; j++) {
            cout<<"\nNhap diem thuong xuyen 1 : ";
            sinhvien[vitri].diem_tx1[j] = kiemTraDiem();
            cout<<"\nNhap diem thuong xuyen 2 : ";
            sinhvien[vitri].diem_tx2[j] = kiemTraDiem();
            cout<<"\nNhap diem ket thuc : ";
            sinhvien[vitri].diem_kt[j] = kiemTraDiem();
        }

    }
}

int timKiemSinhVien(SinhVien sinhvien[], int soSinhVien) {
    string Mssv;
    int vitri = -1;
    cin.ignore();
    getline(cin, Mssv);
    for(int i = 0; i < soSinhVien; i++) {
        if(sinhvien[i].mssv == Mssv) {
            return i;
            break;
        }
    }
    return vitri;
}

void xemTimKiem(SinhVien sinhvien[], int soSinhVien, Monhoc monhoc[], int soMonHoc) {
    cout<<"\nNhap vao MSSV tim kiem : ";
    int vitri = timKiemSinhVien(sinhvien, soSinhVien);
    if(vitri == -1) {
        cout<<"\nMa so sinh vien khong ton tai! Kiem tra lai."<<endl;
    }
    else {
        xuatThongTinSinhVien(sinhvien[vitri], monhoc, soMonHoc);
        cout<<endl;
    }
}  


void thong_Ke(SinhVien sinhvien[], int soSinhVien, Monhoc monhoc[], int soMonHoc) {
    // thông tin sinh viên có gpa cao nhất
    cout<<"\n\t\tTHONG KE SINH VIEN\n";
    float max_GPA = 0.0;
    for(int i = 0; i < soSinhVien; i++) {
        if(sinhvien[i].GPA > max_GPA) {
            max_GPA = sinhvien[i].GPA;
        }
    }
    // thông tin sinh viên có điểm tổng kết từng môn học cao nhất
    float max_dtk = 0.0;
    for(int i = 0; i < soMonHoc; i++) {
        for(int j = 0; j < soMonHoc; j++) {
            if(sinhvien[i].dtk[j] > max_dtk) {
                max_dtk = sinhvien[i].dtk[j];
            }
        }
    }
    cout<<"\n\tCo tat ca "<<soSinhVien<<" sinh vien trong danh sach.\n\tTrong do :\n";
    for(int i = 0; i < soSinhVien; i++) {
        if(max_GPA == sinhvien[i].GPA) {
            cout<<"Sinh vien co GPA cao nhat la sinh vien "<<sinhvien[i].hoten<<endl;
        }
    }
    cout<<endl;
    for(int i = 0; i < soSinhVien; i++) {
        for(int j = 0; j < soMonHoc; j++) {
            if(max_dtk == sinhvien[i].dtk[j]) {
                cout<<"Sinh vien co diem tong ket mon "<<monhoc[j].tenMonHoc<<" cao nhat là sinh vien "<<sinhvien[i].hoten<<endl;
            }
        }
        cout<<"\n";
    }
}

string xoaKhoangTrang(string &str) {
    while(str[0] == ' ') {
        str.erase(0,1);
    }
    while(str[str.length() - 1] == ' ') {
        str.erase((str.length() - 1), 1);
    }
    int i = 0;
    while(i < str.length()) {
        if(str[i] == ' ' && str[i+1] == ' ') {
            str.erase(i, 1);
        }else {
            i++;
        }
    }
    return str;
}

string inHoa(string &str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[0] >= 'a' && str[0] <= 'z') {
            str[0] -= 32;
        }
    }
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ' && str[i+1] >= 'a' && str[i+1] <= 'z') {
            str[i+1] -= 32;
        }
    }
    return str;
}

int kiemTraKyTu(string str) {
    bool check1 = false;
    bool check2 = false; 
    for (char c : str) {
        // isdigit kiểm tra số
        if (isdigit(c)) {
            check1 = true;
        }
        // isalpha kiểm tra kí tự đặc biệt isspace kiểm tra kí tự khoảng trắng
        else if (!isalpha(c) && !isspace(c)) {
            check2 = true;
        }
    }
    if (check1 && check2) {
        return 2;
    }
    else if (check1) {
        return 0;
    }
    else if (check2) {
        return -1;
    }
    return 1;
}

string kiemTraTen() {
    string str;
    while (true) {
        cin.ignore();
        getline(cin, str);
        if (kiemTraKyTu(str) == 0) {
            cout << "Ten khong duoc chua ky tu so! Vui long nhap lai\n";
        }
        else if (kiemTraKyTu(str) == -1) {
            cout << "Ten khong duoc chua ky dac biet! Vui long nhap lai\n";
        }
        else if (kiemTraKyTu(str) == 2) {
            cout << "Ten khong duoc chua ky so va ky tu dac biet! Vui long nhap lai\n";
        }
        else {
            str = xoaKhoangTrang(str);
            str = inHoa(str);
            return str;
        }
    }
}

string kiemTraTenMonHoc() {
    string str;
    while (true) {
        getline(cin, str);
        if (kiemTraKyTu(str) == -1) {
            cout << "Ten mon hoc khong duoc chua ky tu dac biet! Vui long nhap lai : ";
        }
        else {
            return inHoa(str);
        }
    }
}

double kiemTraDiem() {
    double diem;
    while(true) {
        cin>>diem;
        if(diem >= 0 && diem <= 10) {
            break;
        }
        else {
            cout<<"\nDiem khong hop le! Nhap lai : ";
        }
    }
    return diem;
}

string kiemTraMaSinhVien(int soSinhVien, SinhVien sinhvien[]) {
    regex rg("^[0]([0-9]){6}");
    string str;
    bool check = false;
    while (true) {
        cin >> str;
        if (regex_match(str, rg)) {
            check = true;
            if (soSinhVien == 0) {
                return str;
            }
            else {
                for (int i = 0; i < soSinhVien; i++) {
                    if (str == sinhvien[i].mssv) {
                        cout << "\nMa sinh vien da ton tai! Vui long nhap lai: ";
                        check = false;
                        break;
                    }
                }
            }
        }
        else cout << "Ma sinh vien khong dung dinh dang! Vui long nhap lai: ";
        if (check == true) {
            return str;
        }
    }
}
int kiemTraSo() {
    int soLuong;
    double check;
    while(true) {
        cin>>check;
        soLuong = check;
        if(check <= 0 || check != int(check)) {
            cout<<"\nGia tri khong hop le! Nhap lai : ";
        }
        else {
            break;
        }
    }
    return soLuong;
}

void ghiFile(SinhVien sinhvien[], int soSinhVien, int soMonHoc, Monhoc monhoc[]) {
    ofstream fileOut;
    fileOut.open("C:\\Users\\tiens\\Desktop\\data.txt",ios_base::out);
    if(fileOut.fail() == true) {
        cout<<"\nKhong the mo tep!";
        return;
    }
    fileOut<<soMonHoc<<endl;
    for(int j = 0; j < soMonHoc; j++) {
        fileOut<<monhoc[j].tenMonHoc<<endl;
        fileOut<<monhoc[j].tinchi<<endl;
    }
    for(int i = 0; i < soSinhVien; i++) {
        fileOut<<sinhvien[i].hoten<<endl<<sinhvien[i].lop<<endl<<sinhvien[i].mssv<<endl;
        for(int j = 0; j < soMonHoc; j++) {
            fileOut<<sinhvien[i].diem_tx1[j]<<" "<<sinhvien[i].diem_tx2[j]<<" "<<sinhvien[i].diem_kt[j]<<" "<<sinhvien[i].dtk[j]<<" "<<sinhvien[i].diem_he_4[j]<<" "<<sinhvien[i].diem_chu[j]<<endl;
        }
        fileOut<<setprecision(2)<<sinhvien[i].GPA<<endl;
    }
    fileOut.close();
    cout<<"\nDa lu vao file data.txt\n\n";
}

void loadFile(int &soSinhVien, int soMonHoc, SinhVien sinhvien[], Monhoc monhoc[]) {
    ifstream fileIn;
    fileIn.open("C:\\Users\\tiens\\Desktop\\data.txt", ios_base::in);
    if (fileIn.fail()) {
        cout << "khong the mo tep! kiem tra lai.";
        return;
    }
    int i = soSinhVien;
    fileIn>>soMonHoc;
    cout<<soMonHoc<<endl;
    for(int i = 0; i < soMonHoc; i++) {
        fileIn.ignore();
        getline(fileIn, monhoc[i].tenMonHoc);
        fileIn>>monhoc[i].tinchi;
        cout<<monhoc[i].tenMonHoc<<endl;
        cout<<monhoc[i].tinchi<<endl;
    }
    while (!fileIn.eof()) {
        fileIn.ignore();
        getline(fileIn, sinhvien[i].hoten);
        cout<<sinhvien[i].hoten<<endl;
        getline(fileIn, sinhvien[i].lop);
        cout<<sinhvien[i].lop<<endl;
        getline(fileIn, sinhvien[i].mssv);
        cout<<sinhvien[i].mssv<<endl;
        for(int j = 0; j < soMonHoc; j++) {
            fileIn>>sinhvien[i].diem_tx1[j]>>sinhvien[i].diem_tx2[j]>>sinhvien[i].diem_kt[j]>>sinhvien[i].dtk[j]>>sinhvien[i].diem_he_4[j]>>sinhvien[i].diem_chu[j];
            cout<<sinhvien[i].diem_tx1[j]<<" "<<sinhvien[i].diem_tx2[j]<<" "<<sinhvien[i].diem_kt[j]<<" "<<sinhvien[i].dtk[j]<<" "<<sinhvien[i].diem_he_4[j]<<" "<<sinhvien[i].diem_chu[j]<<endl;
        }
        fileIn>>sinhvien[i].GPA;
        cout<<sinhvien[i].GPA<<endl;
        i++;
        soSinhVien++;
    }
    cout << "Doc du lieu thanh cong." << endl;
    fileIn.close();
}
