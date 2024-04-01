#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, bool>> list(n);
    vector<int> results;
    cout << "Nhap den";
    for (int i = 0; i < n; ++i)
    {
        cin >> list[i].first;
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < n; ++i)
    {
        if (list[i].first == list[i - 1].first && i != 0)
            list[i].second = false;
        else
            list[i].second = true;
    }

    int i = 0;
    while (k > 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (list[i].second == true)
            {
                results.push_back(list[i].first);
                --k;
                list[i].second = false;
                if (list[i].first == list[i + 1].first)
                {
                    list[i + 1].second = true;
                    ++i;
                }
            }
            if (k < 1)
                break;
        }
    }

        for (int &x : results)
        cout << x << " ";
}