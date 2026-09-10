#include <bits/stdc++.h>
using namespace std;
int num;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src)
{
    vis[src] = true;
    num++;
    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    vector<int> num_node;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            num = 0;
            dfs(i);
            num_node.push_back(num);
        }
    }
    sort(num_node.begin(), num_node.end());
    for (int x : num_node)
    {
        cout << x << " ";
    }

    return 0;
}