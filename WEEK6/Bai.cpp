#include <bits/stdc++.h>
using namespace std;

int n, e, pair_num;
vector<int> adj[1001];
bool visited[1001];
vector<pair<int, int>> m;
vector<int> dsDinh;
int parent[1001];

bool search(vector<int> a, int x)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == x)
            return 1;
    }
    return 0;
}

void input()
{
    cin >> n >> e;
    // nhap ds cac dinh
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        cin.ignore();
        dsDinh.push_back((int)a);
    }
    // transfer ds canh -> ds ke
    for (int i = 0; i < e; i++)
    {
        char x, y;
        cin >> x >> y;
        if (search(dsDinh, x) && search(dsDinh, x))
        {
            adj[(int)x].push_back((int)y);
        }
    }
    // nhap m cap canh cam tim duong di
    cin >> pair_num;
    cin.ignore();
    for (int i = 0; i < pair_num; i++)
    {
        string s;
        char a, b;
        cin >> a;
        cin.ignore();
        cin >> b;
        cin.ignore();
        m.push_back({(int)a, (int)b});
    }
    // Sao chep gtri false
    memset(visited, false, sizeof(visited));
}
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}

void find_path_by_dfs(int s, int t)
{
    memset(visited, false, sizeof(visited));
    bfs(s);
    if (!visited[t])
    {
        cout << "no_path" << endl;
        return;
    }
    else
    {
        queue<vector<int>> stk;
        stk.push({s});
        while (!stk.empty())
        {
            vector<int> cur = stk.front();
            for (int i = 0; i < adj[cur[cur.size() - 1]].size(); i++)
            {
                vector<int> tmp = stk.front();
                tmp.push_back(adj[cur[cur.size() - 1]][i]);
                stk.push(tmp);
                if (tmp[tmp.size() - 1] == t)
                {
                    for (int j = 0; j < tmp.size(); j++)
                    {
                        cout << char(tmp[j]) << " ";
                    }
                    cout << endl;
                    return;
                }
            }
            stk.pop();
        }
    }
}

int main()
{
    input();
    if (pair_num > 0)
    {
        for (auto it : m)
        {
            find_path_by_dfs(it.first, it.second);
        }
    }
    return 0;
}