#include <bits/stdc++.h>

using namespace std;

class NhomMau
{
protected:
    bool Rh;

public:
    NhomMau(bool Rh = true) : Rh(Rh) {}
    virtual void nhap();
    virtual void xuat() = 0;

    bool getRh()
    {
        return Rh;
    }

    virtual int convert() = 0;
};

class O : public NhomMau
{
public:
    int convert()
    {
        return 3;
    }
    void xuat()
    {
        cout << "Nhom mau O";
        if(Rh)  
            cout << "+\n";
        else
            cout << "-\n";
    }
};

class A : public NhomMau
{
public:
    int convert()
    {
        return 0;
    }
    void xuat()
    {
        cout << "Nhom mau A";
        if(Rh)  
            cout << "+\n";
        else
            cout << "-\n";
    }
};

class B : public NhomMau
{
public:
    int convert()
    {
        return 1;
    }
    void xuat()
    {
        cout << "Nhom mau B";
        if(Rh)  
            cout << "+\n";
        else
            cout << "-\n";
    }
};

class AB : public NhomMau
{
public:
    int convert()
    {
        return 2;
    }
    void xuat()
    {
        cout << "Nhom mau AB";
        if(Rh)  
            cout << "+\n";
        else
            cout << "-\n";
    }
};

class DanhSachNhomMau
{
private:
    vector<NhomMau *> danhSach;

public:
    void nhap();
    static bool kiemTra(NhomMau *, NhomMau *, NhomMau *);
    vector<int> coTheChoMau(int);
};

int main()
{

    DanhSachNhomMau lst;
    // lst.nhap();
    // lst.coTheChoMau(0);
    NhomMau* bo = new A;
    NhomMau* me = new O;
    NhomMau* con = new A;
    cout << DanhSachNhomMau::kiemTra(bo, me, con);

    return 0;
}

void NhomMau::nhap()
{
    cout << "Nhap phan loai Rhesus (0: Rh- || other: Rh+): \n";
    int type;
    cin >> type;
    if (type == 0)
        Rh = false;
    else
        Rh = true;
}

void DanhSachNhomMau::nhap()
{
    cout << "Nhap so luong mau mau: \n";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Chon loai mau: \n";
        cout << "0 --- A\n";
        cout << "1 --- B\n";
        cout << "2 --- AB\n";
        cout << "3 --- O\n";
        int type;
        cin >> type;
        switch (type)
        {
        case 0:
        {
            A *a = new A;
            a->nhap();
            danhSach.push_back(a);
            break;
        }
        case 1:
        {
            B *b = new B;
            b->nhap();
            danhSach.push_back(b);
            break;
        }
        case 3:
        {
            O *o = new O;
            o->nhap();
            danhSach.push_back(o);
            break;
        }
        case 2:
        {
            AB *ab = new AB;
            ab->nhap();
            danhSach.push_back(ab);
            break;
        }
        default:
        {
            cout << "Khong hop le, moi nhap lai. \n";
            i--;
            break;
        }
        }
    }
}

bool DanhSachNhomMau::kiemTra(NhomMau *bo, NhomMau *me, NhomMau *con)
{
    vector<int> diTruyen[4][4];
    // vector lưu thông tin di truyền với quy ước: 0 = A, 1 = B, 2 = AB, 3 = O
    // ví dụ diTruyen[1][2] là danh sách các nhóm máu có thể là con của B (1) và AB (2)
    diTruyen[0][0] = vector<int>{0, 3};
    diTruyen[1][1] = vector<int>{1, 3};
    diTruyen[2][2] = vector<int>{0, 1, 2};
    diTruyen[3][3] = vector<int>{3};
    diTruyen[0][1] = diTruyen[1][0] = vector<int>{0, 1, 2, 3};
    diTruyen[0][2] = diTruyen[2][0] = vector<int>{0, 1, 2};
    diTruyen[0][3] = diTruyen[3][0] = vector<int>{0, 3};
    diTruyen[1][2] = diTruyen[2][1] = vector<int>{0, 1, 2};
    diTruyen[1][3] = diTruyen[3][1] = vector<int>{1, 3};
    diTruyen[2][3] = diTruyen[3][2] = vector<int>{0, 1};

    int father = bo->convert();
    int mother = me->convert();
    int child = con->convert();

    for (int i = 0; i < (int)diTruyen[father][mother].size(); i++)
    {
        if (diTruyen[father][mother][i] == child)
            return true;
    }
    return false;
}

vector<int> DanhSachNhomMau::coTheChoMau(int id)
{
    vector<int> ans;
    int type = danhSach[id]->convert();

    // những loại máu phù hợp
    vector<int> coTheChoMau;
    if(type == 0)
    {
        coTheChoMau = vector<int>{0, 3};
    }
    else if(type == 1)
    {
        coTheChoMau = vector<int>{1, 3};
    }
    else if(type == 2)
    {
        coTheChoMau = vector<int>{0, 1, 2, 3};
    }
    else 
    {
        coTheChoMau = vector<int>{3};
    }
    
    // duyệt qua danh sách máu
    for(int i = 0; i < danhSach.size(); i++)
    {
        if(i == id)
            continue;
        bool rh = danhSach[id]->getRh();

        for(int j = 0; j < coTheChoMau.size(); j++)
        {
            if(danhSach[i]->convert() == coTheChoMau[j] && (rh == true || rh == danhSach[i]->getRh()))
            {
                ans.push_back(i);
            }
        }     
    }

    for(int i = 0; i < ans.size(); i++)
    {
        danhSach[i]->xuat();
    }
}
