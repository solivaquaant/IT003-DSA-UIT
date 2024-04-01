#include <iostream>
using namespace std;

void Nhap(int a[], int n)
{
    for (int i=0;i<n;i++)
        cin>>a[i];
}

int LinearSearch(int a[],int n, int x)
{
    int i=0; a[n]=x;
    while(a[i]!=x)
        i++;
    if(i==n)
        return 0; // Tìm không thấy x
    else
        return 1; // Tìm thấy

}

void Search(int q[], int m,int a[], int n)
{
    for (int i=0;i<m;i++)
      {
          if (LinearSearch(a,n,q[i])==1) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
      }
}

main()
{
    int n,m;
    //cout<<"Nhap n= ";
    cin>>n;
    //cout<<"Nhap m";
    cin>>m;
    int a[n], q[m];
    //cout<<"Nhap a:";
    Nhap(a,n);
    //cout<<"Nhap q:";
    Nhap(q,m);
    Search(q,m,a,n);


}
