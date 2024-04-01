#include <bits/stdc++.h>
#include <iostream>
using namespace std;

main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    int min_sum=INT_MAX;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            int sum=0;
            for(int k=i;k<i+3;k++)
            {
                for(int l=j;l<j+3;l++)
                {
                    sum+=a[k][l];}
            }
            min_sum=min(min_sum,sum);
        }
    }

    cout<<min_sum<<endl;
    return 0;
}
