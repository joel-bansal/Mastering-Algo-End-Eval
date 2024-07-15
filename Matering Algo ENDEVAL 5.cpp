//
// Created by Dell on 15-07-2024.
//
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void dijkstra(int n, vector<vector<pair<int, int>>>& adj, vector<long long>& dist) {

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> mxH;
    dist[1] = 0;
    mxH.push({0, 1});

    while (!mxH.empty()) {
        long long d = mxH.top().first;
        int u = mxH.top().second;
        mxH.pop();

        if (d != dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int len = edge.second;

            if (dist[u] + len < dist[v]) {
                dist[v] = dist[u] + len;
                mxH.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i=0;i<m;i++) {
        int a,b,q;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    vector<long long> dist(n + 1,INF);

    dijkstra(n,adj,dist);

    for (int i=1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }

    return 0;
}
