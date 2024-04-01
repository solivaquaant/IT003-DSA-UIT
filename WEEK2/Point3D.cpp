/*Tăng dần theo x,
nếu x bằng nhau thì sắp xếp các điểm giảm dần theo y,
nếu y bằng nhau thì sắp xếp các điểm tăng dần theo z.*/

#include <iostream>
using namespace std;

struct Point
{
    int x, y, z;
};

void Nhap(Point a[], int &n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
}

void Xuat(Point a[], int n)
{
    // cout << "kq" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i].x << " " << a[i].y << " " << a[i].z << endl;
}

bool cmp(Point a, Point b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    else if (a.y != b.y)
    {
        return a.y > b.y;
    }
    else
    {
        return a.z < b.z;
    }
}

int partition(Point a[], int l, int r)
{
    int pivot = a[r].x;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (cmp(a[j], a[r]))
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
void QuickSort(Point a[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(a, l, r);
        QuickSort(a, l, pi - 1);
        QuickSort(a, pi + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    Point a[n];
    Nhap(a, n);
    QuickSort(a, 0, n - 1);
    Xuat(a, n);
}