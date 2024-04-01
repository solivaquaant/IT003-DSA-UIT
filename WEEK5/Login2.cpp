#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    unordered_map<string, vector<string>> List;

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        List[s].push_back(t);
    }

    string str[q];
    for (int i = 0; i < q; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < q; i++)
    {
        if (List.count(str[i]) > 0)
        {
            for (string password : List[str[i]])
            {
                cout << password << " ";
            }
            cout << endl;
        }
        else
            cout << "Chua Dang Ky!" << endl;
    }
}
