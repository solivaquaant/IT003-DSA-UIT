#include<bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
};

void Nhap(point a[], int n)
{
    for (int i=0;i<n;i++)
    {
        cin>>a[i].x;
        cin>>a[i].y;
    }
}

void Xuat(point a[], int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i].x<<" "<<a[i].y<<"\n";
}

bool cmp(point a, point b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}


int partition(point a[], int l, int r) {
    int pivot = a[r].x;
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (cmp(a[j], a[r])) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
void quick_sort(point a[], int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}

int main(){
    int n;
    cin>>n;
    point a[n];
    Nhap(a,n);
    quick_sort(a,0,n-1);
    Xuat(a,n);
}
