#include <bits/stdc++.h>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0)
    {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC &operator=(const DONTHUC &rhs)
    {
        if (this == &rhs)
            return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};

struct Node
{
    DONTHUC *data;
    Node *next;

    Node(DONTHUC *_data = nullptr)
    {
        this->data = _data;
        this->next = nullptr;
    }
};

struct DATHUC
{
    Node *head;
    Node *tail;
    DATHUC()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

void Nhap(DATHUC &B, double heso, int somu)
{
    DONTHUC *donthuc = new DONTHUC(heso, somu);
    Node *node = new Node(donthuc);

    if (B.head == nullptr)
    {
        B.head = node;
        B.tail = node;
    }
    else
    {
        B.tail->next = node;
        B.tail = node;
    }
}

void Xuat(DATHUC &B)
{
    Node *p = B.head;
    bool first = true;
    bool allZero = true;
    while (p != nullptr)
    {
        if (p->data->heso != 0)
        {
            allZero = false;
            if (first)
            {
                if (p->data->heso < 0)
                    cout << "-";
                first = false;
            }
            else
            {
                if (p->data->heso > 0)
                    cout << "+";
                else
                    cout << "-";
            }

            if (abs(p->data->heso) != 1 || p->data->somu == 0)
                cout << abs(p->data->heso);

            if (p->data->somu > 0)
                cout << "x";
            if (p->data->somu > 1)
                cout << "^" << p->data->somu;
        }
        p = p->next;
    }
    if (allZero)
        cout << "0";
}

double TinhDaThuc(DATHUC &B, double x)
{
    double result = 0;
    Node *p = B.head;
    while (p != nullptr)
    {
        result += p->data->heso * pow(x, p->data->somu);
        p = p->next;
    }
    return result;
}

int main()
{
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++)
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }

    cout << "Da thuc vua nhap la: ";
    Xuat(B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
