void bfs(int vex, vector<bool>&vis, vector<vector<int>>&adj, int a[]) {
    queue<int>q;
    q.push(vex);
    vis[vex] = true;
    int mn = a[vex];

    while (!q.empty()) {
        int cur_v = q.front();
        q.pop();
        mn = min(mn, a[cur_v]);
        for (auto child : adj[cur_v]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
    ans += mn;
}
