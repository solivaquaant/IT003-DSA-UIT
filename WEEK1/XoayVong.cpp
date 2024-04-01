#include <iostream>
using namespace std;

void Nhap(int a[], int n)
{
    for (int i=0;i<n;i++)
        cin>>a[i];
}

void Xuat(int a[], int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

main()
{
    int n,k;
    cin>>n;cin>>k;
    int a[n];
    Nhap(a,n);
    k=k%n;
    for(int j=0;j<k;j++)
        for(int i=n-1;i>=1;i--)
        swap(a[i],a[i-1]);
    Xuat(a,n);

}
