#include"function.cpp"

int main() {
    int choice, soMonHoc;
    int soSinhVien = 0;
    while (true)
    {
        menu();
        cout<<"\nLua chon : ";
        choice = kiemTraSo();
        switch (choice) {
            case 0:
            cout<<"\nBan da thoat khoi chuong trinh BYE!!";
            return 0;
            case 1:
            nhapThongTinMonHoc(monhoc, soMonHoc);
            system("pause");
            system("cls");
            break;
            case 2:
            Nhap(sinhvien, soSinhVien, soMonHoc);
            system("pause");
            system("cls");
            break;
            case 3:
            danhSachThongTinSinhVien(sinhvien, soMonHoc, monhoc, soSinhVien);
            system("pause");
            system("cls");
            break;
            case 4:
            while(true) {
            menu1();
            int chon;
            cout<<"\nLua chon : ";
            cin>>chon; 
            switch (chon) {
                case 1:
                ThemSinhVien(sinhvien, soSinhVien, soMonHoc);
                system("pause");
                system("cls");
                break;
                case 2:
                SuaThongTinSinhVien(sinhvien, soSinhVien, monhoc, soMonHoc);
                system("pause");
                system("cls");
                break;
                default:
                cout<<"\nBan chi chon (1-2)";
                break;
            }
            break;
            }
            break;
            case 5:
            xemTimKiem(sinhvien, soSinhVien, monhoc, soMonHoc);
            system("pause");
            system("cls");
            break;
            case 6:
            thong_Ke(sinhvien, soSinhVien, monhoc, soMonHoc);
            system("pause");
            system("cls");
            break;
            case 7:
            ghiFile(sinhvien, soSinhVien, soMonHoc, monhoc);
            system("pause");
            system("cls");
            break;
            case 8:
            loadFile(soSinhVien, soMonHoc, sinhvien, monhoc);
            system("pause");
            system("cls");
            break;
            default:
            cout<<"\nAnh zai chi duoc chon tu (0-7) nha. Nhap lai di!!!"<<endl;
            break;
        }
    }
    return 0;
}
