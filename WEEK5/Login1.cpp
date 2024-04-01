#include <iostream>
#include <bits/stdc++.h>

using namespace std;

main()
{
    int n, q;
    cin >> n >> q;

    unordered_map<string, string> List;

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        List[s] = t;
    }
    string str[q];
    for (int i = 0; i < q; i++)
    {
        cin>>str[i];
    }
    for (int i=0;i<q;i++)
    {
        if (List.count(str[i]) > 0) // co xuat hien
        {
            cout << List[str[i]] << endl;
        }
        else
            cout << "Chua Dang Ky!"<<endl;
    }
}
