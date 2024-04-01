#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> MaTranKe(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MaTranKe[i][j];
        }
    }

    vector<vector<int>> DanhSachKet(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (MaTranKe[i][j] == 1)
            {
                DanhSachKet[i].push_back(j + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (DanhSachKet[i].empty() != true)
        {
            cout << i + 1 << "->";
            for (int j = 0; j < DanhSachKet[i].size(); j++)
            {
                cout << DanhSachKet[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
