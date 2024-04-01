#include <iostream>
#include <bits/stdc++.h>

using namespace std;

main()
{
    int n, q;
    cin >> n >> q;

    unordered_map<string, string> List;
    // map<string, string>::iterator it = List.begin();

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        List[s] = t;
    }

    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        if (List.count(str) > 0) // co xuat hien
        {
            cout << List[str] << endl;
        }
        else
            cout << "Chua Dang Ky!";
    }
}