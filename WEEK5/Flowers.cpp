#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> Hash;
    int n = A.size();
    vector<pair<int, bool>> list(n);
    for (int i = 0; i < n; ++i)
    {
        list[i] = make_pair(A[i], true);
    }

    priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;
    for (int i = 0; i < n; ++i)
    {
        pq.push(list[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        list[i] = pq.top();
        pq.pop();
    }

    for (int i = 0; i < n; ++i)
    {
        if (list[i].first == list[i - 1].first && i != 0)
            list[i].second = false;
        else
            list[i].second = true;
    }

    int i = 0;
    vector<int> results;
    while (K > 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (list[i].second == true)
            {
                results.push_back(list[i].first);
                --K;
                list[i].second = false;
                if (list[i].first == list[i + 1].first)
                {
                    list[i + 1].second = true;
                    ++i;
                }
            }
            if (K < 1)
                break;
        }
    }
    return results;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans = get_ans(a, k);
    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
