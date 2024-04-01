#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
const int MAX = 26 + 5;
int n, m, pa[MAX];
char ch[MAX];
vector<int> e[MAX];

void BFS(char s, char t)
{
    int ids, idt;
    queue<int> qu;
    for (int i = 1; i <= n; i++)
    {
        pa[i] = -1;
        if (ch[i] == s)
        {
            ids = i;
            qu.push(ids);
        }
        if (ch[i] == t)
            idt = i;
    }
    while (qu.size() > 0)
    {
        int u = qu.front();
        qu.pop();
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            if (pa[v] == -1)
            {
                pa[v] = u;
                qu.push(v);
            }
        }
    }
    if (pa[idt] == -1)
    {
        cout << "no_path\n";
        return;
    }
    vector<char> ans;
    int u = idt;
    while (true)
    {
        ans.push_back(ch[u]);
        u = pa[u];
        if (u == ids)
            break;
    }
    ans.push_back(ch[ids]);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> ch[i];
    char u, v;
    int idu, idv;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        for (int j = 1; j <= n; j++)
        {
            if (ch[j] == u)
                idu = j;
            if (ch[j] == v)
                idv = j;
        }
        e[idu].push_back(idv);
    }
    int q;
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        BFS(u, v);
    }
}
