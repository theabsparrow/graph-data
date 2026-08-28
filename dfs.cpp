#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src) {
    cout << src << " ";
    vis[src] = true;
    for(int child : adj_list[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}


int main () {
    int n, e;
    cin >> n >> e;
    while(e--) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    memset(vis, false, sizeof(vis));
    dfs(0);
    return 0;
}