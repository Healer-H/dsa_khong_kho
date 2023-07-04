#include <bits/stdc++.h>

using namespace std;

class Cong
{
protected:
    int point;

public:
    virtual void nhap() = 0;
    int getPoint()
    {
        return point;
    }
};

class CongTien : public Cong
{
private:
    int donGia;
    int slg;

public:
    void tinhPoint();
    void nhap();
};

class CongTriTue : public Cong
{
public:
    void nhap();
};

class CongSucManh : public Cong
{
public:
    void nhap();
};

class LauDai
{
private:
    vector<Cong *> dsCong;

public:
    void nhap();
    vector<Cong *> getDSCong();
};

class HoangTu
{
private:
    int soTien;
    int triTue;
    int sucManh;

public:
    void nhap();
    void xuat();
    bool tanCong(Cong *);
    bool tanCong(LauDai);

    bool coTheCuu(LauDai);
};
/* ------------------------------------------------------- */




int main()
{
    LauDai laudaitinhai;
    HoangTu dvh;

    laudaitinhai.nhap();
    dvh.nhap();
    dvh.coTheCuu(laudaitinhai);
    return 0;
}



/* ------------------------------------------------------- */
void CongTien::tinhPoint()
{
    point = donGia * slg;
}
void CongTien::nhap()
{
    cout << "Nhap Don gia: ";
    cin >> donGia;
    cout << "Nhap So luong: ";
    cin >> slg;
    CongTien::tinhPoint();
}
void CongTriTue::nhap()
{
    cout << "Nhap diem Tri tue: ";
    cin >> point;
}
void CongSucManh::nhap()
{
    cout << "Nhap diem Suc manh: ";
    cin >> point;
}
void LauDai::nhap()
{
    cout << "Nhap so luong Cong: ";
    int numGate;
    cin >> numGate;
    for (int i = 0; i < numGate; i++)
    {
        cout << "Chon loai cong: 1 (Cong Tien), 2 (Cong Tri tue), 3 (Cong Suc manh) \n";
        int type;
        cin >> type;
        if (type == 1)
        {
            CongTien *tmp = new CongTien;
            tmp->nhap();
            dsCong.push_back(tmp);
        }
        else if (type == 2)
        {
            CongTriTue *tmp = new CongTriTue;
            tmp->nhap();
            dsCong.push_back(tmp);
        }
        else if (type == 3)
        {
            CongSucManh *tmp = new CongSucManh;
            tmp->nhap();
            dsCong.push_back(tmp);
        }
        else
        {
            cout << "Khong hop le, moi nhap lai. \n";
            i--;
        }
    }
}

vector<Cong *> LauDai::getDSCong()
{
    return dsCong;
}

bool HoangTu::tanCong(Cong *cong)
{
    if (dynamic_cast<CongTien *>(cong))
    {
        soTien -= cong->getPoint();
        if (soTien >= 0)
            return true;
        else
            return false;
    }
    else if (dynamic_cast<CongTriTue *>(cong))
    {
        return triTue >= cong->getPoint();
    }
    else if (dynamic_cast<CongSucManh *>(cong))
    {
        sucManh -= cong->getPoint();
        if (sucManh >= 0)
            return true;
        else
            return false;
    }
}

bool HoangTu::tanCong(LauDai lauDai)
{
    vector<Cong *> dsCong = lauDai.getDSCong();
    for (int i = 0; i < dsCong.size(); i++)
    {
        if (HoangTu::tanCong(dsCong[i]) == false)
            return false;
    }
    return true;
}
void HoangTu::nhap()
{
    cout << "Nhap thong tin Hoang tu: \n";
    cout << "Nhap so tien: ";
    cin >> soTien;
    cout << "Nhap suc manh: ";
    cin >> sucManh;
    cout << "Nhap tri tue: ";
    cin >> triTue;
}
void HoangTu::xuat()
{
    cout << "So tien: " << soTien << endl;
    cout << "Suc manh: " << sucManh << endl;
    cout << "Tri tue: " << triTue << endl;
}

bool HoangTu::coTheCuu(LauDai lauDai)
{
    if (HoangTu::tanCong(lauDai))
    {
        cout << "Co the cuu Cong chua. \"૮₍  ˶•⤙•˶ ₎ა\n";
        cout << "Chi so con lai cua Hoang tu: \n";
        HoangTu::xuat();
        return true;
    }
    else
    {
        cout << "Luc bat tong tam (ᴗ_ ᴗ。)";
    }
}