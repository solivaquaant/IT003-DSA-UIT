#include <iostream>
using namespace std;

void Nhap(int a[], int n)
{
    for (int i=0;i<n;i++)
        cin>>a[i];
}
int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int a[n];
    Nhap(a,n);
    k%=n;
    for(int i=0;i<n;i++){
        cout<<a[(i-k+n)%n]<<" ";
    }
}
