#include"header.h"

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
};

struct Monhoc
{
    string tenMonHoc;
    int tinchi;

};

void quy_Doi_He_4(SinhVien sv[], int m, int n);
void quy_Doi_Chu(SinhVien sv[], int n, int m);
float GPA(SinhVien sv[], Monhoc mh[], int m, int n);

void menu() {
    cout<<"\n\t\t\t\t\tCHUONG TRINH QUAN LI DIEM CUA SINH VIEN\n";
    cout<<"\t\t\t\t\t+--------------------------------------+\n";
    cout<<"\t\t\t\t\t| 1. Nhap danh sach sinh vien          |\n";
    cout<<"\t\t\t\t\t| 2. Xem danh sach thong tin sinh vien |\n";
    cout<<"\t\t\t\t\t| 3. Sua thong tin sinh vien           |\n";
    cout<<"\t\t\t\t\t| 4. tra cuu thong tin sinh vien       |\n";
    cout<<"\t\t\t\t\t| 5. Thong ke diem cua sinh vien       |\n";
    cout<<"\t\t\t\t\t| 6. Luu danh sach sinh vien ra file   |\n";
    cout<<"\t\t\t\t\t| 7. Load file da luu                  |\n";
    cout<<"\t\t\t\t\t| 0. Thoat khoi chuong trinh           |\n";
    cout<<"\t\t\t\t\t+--------------------------------------+\n";
    cout<<"\t\t\t\t\t -> Moi ban nhap vao lua chon\n";
}

void menu1() {
    cout<<"\n\t   Chon di ban oi";
    cout<<"\n\t+------------------+";
    cout<<"\n\t|1. Them sinh vien |";
    cout<<"\n\t|2. Sua sinh vien  |";
    cout<<"\n\t+------------------+";
    cout<<"\n\t-> lua chon cua ban\n ";

} 	
void Nhap_SL_SV(float &n) {
    cout<<"\nNhap vao so luong sinh vien : ";
    cin>>n;
}

void Nhap_SL_MH(int &m) {
    cout<<"\nNhap vao so luong mon hoc : ";
    cin>>m;
}

void Nhap_TT_MH(Monhoc mh[], int m) {
    for(int i = 0; i < m; i++) {
        cin.ignore();
        cout<<"\nNhap ten mon hoc thu "<<i+1<< " : ";
        getline(cin, mh[i].tenMonHoc);
        cout<<"\nNhap so tin chi mon "<<mh[i].tenMonHoc<< " : ";
        cin>>mh[i].tinchi; 
    } 
}

void Xuat_TT_Mh(Monhoc mh[], int m) {
    for(int j = 0; j < m; j++) {
        cout<<mh[j].tenMonHoc<<setw(14);
    }
}

void in(int m) {
    for(int j = 0; j < m; j++) {
        cout<<"DTK,"<<"TD4,"<<"DC"<<setw(8);
    }
}


void Tieu_De(Monhoc mh[], int m) {
    cout<<"\n\t\t\t\t\tTHONG TIN SINH VIEN\n";
    cout<<"+--------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    cout<<"|"<<setw(2)<<"STT"<<setw(6)<<"LOP"<<setw(9)<<"HO TEN"<<setw(15)<<"MSSV"<<setw(10);Xuat_TT_Mh(mh,m);cout<<setw(10)<<"GPA";
    cout<<"\n|"<<setw(40);in(m);
    cout<<"\n+------------------------------------------------------------------------------------------------------------------------------------------------+\n";

}

void Nhap(SinhVien &sv, int m, Monhoc mh[]) {
        cin.ignore();
        cout<<"\nNhap ten lop sinh vien : ";
        getline(cin, sv.lop);
        cout<<"\nNhap vao ho ten sinh vien : ";
        getline(cin, sv.hoten);
        cout<<"\nNhap MSSV cua sinh vien "<<sv.hoten<< " : ";
        getline(cin, sv.mssv);
        for(int j = 0; j < m; j++) {
            do {
            cout<<"\nNhap diem thuong xuyen 1 mon "<<mh[j].tenMonHoc<<" : ";
            cin>>sv.diem_tx1[j];
            if(sv.diem_tx1[j] < 0 || sv.diem_tx1[j] > 10) {
                cout<<"\nDiem khong hop le! Nhap lai.";
            }
            }while (sv.diem_tx1[j] < 0 || sv.diem_tx1[j] > 10);
            do {
            cout<<"\nNhap diem thuong xuyen 2 mon "<<mh[j].tenMonHoc<<" : ";
            cin>>sv.diem_tx2[j];
             if(sv.diem_tx2[j] < 0 || sv.diem_tx2[j] > 10) {
                cout<<"\nDiem khong hop le! Nhap lai.";
            }
            }while (sv.diem_tx2[j] < 0 || sv.diem_tx2[j] > 10);
            do {
            cout<<"\nNhap diem ket thuc mon "<<mh[j].tenMonHoc<<" : ";
            cin>>sv.diem_kt[j];
             if(sv.diem_kt[j] < 0 || sv.diem_kt[j] > 10) {
                cout<<"\nDiem khong hop le! Nhap lai.";
            }
            }while (sv.diem_tx2[j] < 0 || sv.diem_tx2[j] > 10);
        }
}

void Nhap_DS_Sinh_Vien(SinhVien sv[], int m, Monhoc mh[], int &n) {
    Nhap_SL_SV(n);
    for(int i = 0; i < n; i++) {
        Nhap(sv[i], m, mh);
    }
}


void Xuat_DS_TT_SV(SinhVien sv[], int m, Monhoc mh[], int &n) {
    if(n > 0) {
        Tieu_De(mh, m);
        for(int i = 0; i < n; i++) {
            cout<<"|"<<setw(2)<<i+1<<setw(6)<<sv[i].lop<<setw(18)<<sv[i].hoten<<setw(6)<<sv[i].mssv<<setw(25);
            for(int j = 0; j < m; j++) {
                sv[i].dtk[j] = (((sv[i].diem_tx1[j] + sv[i].diem_tx2[j]) / 4) + (sv[i].diem_kt[j] / 2));
                quy_Doi_He_4(sv, m, n);
                quy_Doi_Chu(sv, n, m);
                cout<<setw(8)<<sv[i].dtk[j]<<setw(2)<<sv[i].diem_he_4[j]<<setw(3)<<sv[i].diem_chu[j]<<setw(10); 
            }
            GPA(sv, mh, m, n);
            cout<<setprecision(2)<<sv[i].GPA;
            cout<<"\n";
        }
    cout<<setw(2)<<"+--------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    }else {
        cout<<"\n\t Hien chua co sinh vien nao.";
    }
}

void Xuat_TT_SV(SinhVien &sv, Monhoc mh[], int m) {
    cout<<"\n\t\tTHONG TIN SINH VIEN\n";
    cout<<"LOP"<<setw(15)<<"HO TEN"<<setw(15)<<"MSSV"<<setw(10);Xuat_TT_Mh(mh, m);
    cout<<setw(10)<<"GPA\n";
    cout<<setw(40);in(m);cout<<endl;
    cout<<left<<sv.lop<<setw(10)<<sv.hoten<<right<<setw(10)<<sv.mssv<<setw(8);
    for(int j = 0; j < m; j++) {
        cout<<sv.dtk[j]<<setw(3)<<sv.diem_he_4[j]<<setw(3)<<sv.diem_chu[j]<<setw(8);
    }
    cout<<setw(6)<<sv.GPA;
}

void quy_Doi_He_4(SinhVien sv[], int m, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(sv[i].dtk[j] >= 8.5 && sv[i].dtk[j] <= 10.0) {
                sv[i].diem_he_4[j] = 4.0;
            }else if(sv[i].dtk[j] >= 8.0 && sv[i].dtk[j] <= 8.4) {
                sv[i].diem_he_4[j] = 3.5;
            }else if(sv[i].dtk[j] >= 7.0 && sv[i].dtk[j] <= 7.9) {
                sv[i].diem_he_4[j] = 3.0;
            }else if(sv[i].dtk[j] >= 6.5 && sv[i].dtk[j] <= 6.9) {
                sv[i].diem_he_4[j] = 2.5;
            }else if(sv[i].dtk[j] >= 5.5 && sv[i].dtk[j] <= 6.4) {
                sv[i].diem_he_4[j] = 2.0;
            }else if(sv[i].dtk[j] >= 5.0 && sv[i].dtk[j] <= 5.4) {
                sv[i].diem_he_4[j] = 1.5;
            }else if(sv[i].dtk[j] >= 4.0 && sv[i].dtk[j] <= 4.9) {
                sv[i].diem_he_4[j] = 1.0;
            }
        }
    }
}

void quy_Doi_Chu(SinhVien sv[], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(sv[i].diem_he_4[j] == 4.0) {
                sv[i].diem_chu[j] = "A";
            }else if(sv[i].diem_he_4[j] == 3.5) {
                sv[i].diem_chu[j] = "B+";
            }else if(sv[i].diem_he_4[j] == 3.0) {
                sv[i].diem_chu[j] = "B";
            }else if(sv[i].diem_he_4[j] == 2.5) {
                sv[i].diem_chu[j] = "C+";
            }else if(sv[i].diem_he_4[j] == 2.0) {
                sv[i].diem_chu[j] = "C";
            }else if(sv[i].diem_he_4[j] == 1.5) {
                sv[i].diem_chu[j] = "D+";
            }else if(sv[i].diem_he_4[j] == 1.0) {
                sv[i].diem_chu[j] = "D";
            }else if(sv[i].dtk[j] < 4.0) {
                sv[i].diem_chu[j] = "F";
            }
        }
    }
}

float GPA(SinhVien sv[], Monhoc mh[], int m, int n) {
    int temp = 0;
    for(int i = 0; i < m; i++) {
        temp += mh[i].tinchi;
    }
    for(int i = 0; i < n; i++) {
        float sum = 0.0;
        for(int j = 0; j < m; j++) {
            sum += (sv[i].diem_he_4[j] * mh[j].tinchi);  
        }
        sv[i].GPA = sum / temp;
    }
}

void Them_SinhVien(SinhVien sv[], int &n, Monhoc mh[], int m) {
    SinhVien svm;
    int count = 0;
    cin.ignore();
    cout<<"\nNhap lop sinh vien can them : ";
    getline(cin, svm.lop);
    cout<<"\nNhap ho ten sinh vien can them : ";
    getline(cin, svm.hoten);
    do {
        count = 0;
        cout<<"\nNhap mssv can them : ";
        getline(cin, svm.mssv);
        for(int i = 0; i < n; i++) {
            if(sv[i].mssv == svm.mssv) {
            cout<<"\nMSSV khong duoc trung! Moi ban nhap lai"<<endl;
            count++;

        }
    }
    }while(count > 0);

    for(int i = 0; i < 1; i++) {
        for(int j = 0; j < m; j++) {
            cout<<"\nNhap diem thuong xuyen 1 mon "<<mh[j].tenMonHoc<<" : ";
            cin>>svm.diem_tx1[j];
            cout<<"\nNhap diem thuong xuyen 2 mon "<<mh[j].tenMonHoc<<" : ";
            cin>>svm.diem_tx2[j];
            cout<<"\nNhap diem ket thuc mon "<<mh[j].tenMonHoc<<" : ";
            cin>>svm.diem_kt[j];
            }
        }
    sv[n] = svm;
    n++;
    cout<<"\nThem sinh vien thanh cong!";
}

void Sua_TT_SinhVien(SinhVien sv[], int &n, Monhoc mh[], int m) {
    SinhVien svm;
    string Mssv;
    int count = 0;
    cout<<"\nNhap vao MSSV can sua : ";
    cin.ignore();
    getline(cin, Mssv);
    for(int i = 0; i < n; i++) {
        if(sv[i].mssv == Mssv) {
        Xuat_TT_SV(sv[i], mh, m);
        }
        cout<<"\nNhap ten lop sinh vien : ";
        getline(cin, sv[i].lop);
        cout<<"\nNhap ho ten sinh vien : ";
        getline(cin,sv[i].hoten);
        do {
        count = 0;
        cout<<"\nNhap mssv : ";
        getline(cin, sv[i].mssv);
        for(int i = 0; i < n; i++) {
            if(sv[i].mssv == svm.mssv) {
            cout<<"\nMSSV khong duoc trung! Moi ban nhap lai"<<endl;
            count++;

        }
    }
    }while(count > 0);
       for(int i = 0; i < 1; i++) {
        for(int j = 0; j < m; j++) {
            cout<<"\nNhap diem thuong xuyen 1 mon "<<mh[j].tenMonHoc<<" : ";
            cin>>svm.diem_tx1[j];
            cout<<"\nNhap diem thuong xuyen 2 mon "<<mh[j].tenMonHoc<<" : ";
            cin>>svm.diem_tx2[j];
            cout<<"\nNhap diem ket thuc mon "<<mh[j].tenMonHoc<<" : ";
            cin>>svm.diem_kt[j];
            }
        }
        cin.ignore();
        break;
    }
    cout<<"\nSua sinh vien thanh cong."; 
}

void Tra_Cuu_SV(SinhVien sv[], int n, int m, Monhoc mh[]) {
    string Mssv;
    cout<<"\nNhap vao MSSV tim kiem : ";
    cin.ignore();
    getline(cin, Mssv);
    for(int i = 0; i < n; i++) {
        if(sv[i].mssv == Mssv) {
            Xuat_TT_SV(sv[i], mh, m);
            break;
        }
    }
}

void thong_Ke(SinhVien sv[], int n, Monhoc mh[], int m) {
    // thông tin sinh viên có gpa cao nhất
    cout<<"\n\t\tTHONG KE SINH VIEN\n";
    float max_GPA = 0.0;
    for(int i = 0; i < n; i++) {
        if(sv[i].GPA > max_GPA) {
            max_GPA = sv[i].GPA;
        }
    }
    // thông tin sinh viên có điểm tổng kết từng môn học cao nhất
    float max_dtk = 0.0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(sv[i].dtk[j] > max_dtk) {
                max_dtk = sv[i].dtk[j];
            }
        }
    }
    cout<<"\n\tCo tat ca "<<n<<" sinh vien trong danh sach.\n\tTrong do :\n";
    for(int i = 0; i < n; i++) {
        if(max_GPA == sv[i].GPA) {
            cout<<"Sinh vien co GPA cao nhat la sinh vien "<<sv[i].hoten<<endl;
        }
    }
    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(max_dtk == sv[i].dtk[j]) {
                cout<<"Sinh vien co diem tong ket mon "<<mh[j].tenMonHoc<<" cao nhat là sinh vien "<<sv[i].hoten<<endl;
            }
        }
        cout<<"\n";
    }
}

void luu_File(SinhVien sv[], int n, int m, Monhoc mh[]) {
    ofstream fileOut;
    fileOut.open("C:\\Users\\tiens\\Desktop\\data.txt",ios_base::out);
    if(fileOut.fail() == true) {
        cout<<"\nKhong the mo tep!";
        return;
    }
    // in ra số lượng môn học
    fileOut<<m<<endl;
    // in ra tên các môn học và tín chỉ các môn
    for(int j = 0; j < m; j++) {
        fileOut<<mh[j].tenMonHoc<<endl;
        fileOut<<mh[j].tinchi<<endl;
    }
    // in ra tên sinh viên
    for(int i = 0; i < n; i++) {
        fileOut<<sv[i].lop<<sv[i].hoten<<endl<<sv[i].mssv<<endl;
        for(int j = 0; j < m; j++) {
            // in ra điểm các môn
            fileOut<<sv[i].diem_tx1[j]<<" "<<sv[i].diem_tx2[j]<<" "<<sv[i].diem_kt[j]<<" "<<sv[i].dtk[j]<<" "<<sv[i].diem_he_4[j]<<" "<<sv[i].diem_chu[j]<<endl;
        }
        fileOut<<setprecision(2)<<sv[i].GPA<<endl;
    }
    fileOut.close();
    cout<<"\nDa lu vao file data.txt\n\n";
}

void load_File(SinhVien sv[], int n, int m) {
    ifstream fileIn;
    fileIn.open("C:\\Users\\tiens\\Desktop\\data.txt", ios::in);
    if (fileIn.fail()) {
        cout << "Loi mo tep.";
        return;
    }
    while (!fileIn.eof()) {
        for (int i = 0; i < n; i++) {
            fileIn.ignore();
            getline(fileIn, sv[i].hoten);
            fileIn >> sv[i].mssv >> sv[i].lop;
            for (int j = 0; j < m; j++ ) {
                fileIn >> sv[i].diem_tx1[j] >> sv[i].diem_tx2[j] >> sv[i].diem_kt[j] >> sv[i].diem_kt[j] >> sv[i].diem_he_4[j] >> sv[i].diem_chu[j];
            }
            fileIn >> sv[i].GPA;
        }
    cout << "Doc file thanh cong." << endl;
    fileIn.close();
   }
}
    
int main() {
    int n,luachon;
    float m;
    Nhap_SL_MH(m);
    SinhVien sv[max];
    Monhoc mh[max];
    Nhap_TT_MH(mh, m);
    while (true)
    {
        menu();
        cout<<"Lua chon : ";
        cin>>luachon;

        switch (luachon) {
            case 0:
            cout<<"\nBan da thoat khoi chuong trinh BYE!!";
            return 0;
            case 1:
            Nhap_DS_Sinh_Vien(sv, m, mh, n);
            break;
            case 2:
            Xuat_DS_TT_SV(sv, m, mh, n);
            break;
            case 3:
            while(true) {
            menu1();
            int chon;
            cout<<"\nLua chon : ";
            cin>>chon; 
            switch (chon) {
                case 1:
                Them_SinhVien(sv, n, mh, m);
                break;
                case 2:
                Sua_TT_SinhVien(sv, n, mh, m);
                break;
                default:
                cout<<"\nBan chi chon (1-2)";
                break;
            }
            break;
            }
            break;
            case 4:
            Tra_Cuu_SV(sv, n, m, mh);
            break;
            case 5:
            thong_Ke(sv, n, mh, m);
            break;
            case 6:
            luu_File(sv, n, m, mh);
            break;
            case 7:
            load_File(sv, n, m);
            break;
            default:
            cout<<"\nAnh zai chi duoc chon tu (0-7) nha. Nhap lai di!!!";
            break;
        }
    }
    return 0;
}
