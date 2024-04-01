#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1000];
bool visited[1000];
int parent[1000];
void dfs(int u)
{

    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            dfs(v);
        }
    }
}
void Path(int s, int t)
{
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    if (!visited[t])
    {
        cout << "no_path" << endl;
    }
    else
    {
        vector<int> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];

            path.push_back(s);
            reverse(path.begin(), path.end());
            for (int x : path)
                cout << x << " ";
        }
    }
}

main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    Path(s, t);
}
