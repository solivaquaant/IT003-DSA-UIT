#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> DanhSachKet(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        DanhSachKet[u - 1].push_back(v - 1);
        DanhSachKet[v - 1].push_back(u - 1);
    }
    int s;
    cin >> s;
    s--;

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : DanhSachKet[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> dsTanCong;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            dsTanCong.push_back(i + 1);
    }

    cout << dsTanCong.size() << endl;
    for (int u : dsTanCong)
        cout << u << " ";
    cout << endl;

    return 0;
}
