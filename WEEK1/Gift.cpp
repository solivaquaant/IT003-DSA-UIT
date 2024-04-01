#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Nhap(int a[], int n)
{
    for (int i=0;i<n;i++)
        cin>>a[i];
}

int main()
{
    int n,x;
    cin>>n;
    cin>>x;
    int a[n];
    Nhap(a,n);
    sort(a,a+n);
    int l=0, r=n-1, max_sum=0;
    while (l<r)
    {
        if (a[l]+a[r] <=x)
        {
            max_sum=max(max_sum,a[l]+a[r]);
            l++;
        }
        else r--;
    }
    cout<<max_sum;
    return 0;
}

