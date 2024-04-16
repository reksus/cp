#include<bits/stdc++.h>

#define pii pair<int,int> 

using namespace std;

/*
BFS NOTES:

TIME COMPLEXITY - O(V+E)
O(V) - each vertex is enqueued/dequeued only once
O(E) - adj list of any vertex is traverserd exactly once

Edge Classification

directed graph:
- no Forward
WHITE -> tree edge
GRAY -> back edge
BLACK -> 
    cross (d[u] > d[v]) edge

undirected graph: 
- no Forward edge
- no Back edge

*/

// int N = 5;
// vector<vector<int>> adj = {{1, 2, 3}, {0, 2, 3}, {0, 1, 4}, {0, 1}, {2}}; // adjacency list

int N = 4;
vector<vector<int>> adj = {{1, 2}, {3}, {}, {0, 2}};

vector<int> color(N); // 0 = 'white'
vector<int> d(N, INT_MAX); // discovery time
vector<int> f(N, INT_MAX); // finishing time
vector<int> p(N, -1); // parent (no parent for any node in the beginning)
int TIME = 0;
vector<pii> treeedges, backedges, forwardedges, crossedges;

// required to keep a track of reverse egde in a undirected graph to not get counted
// not required in a directed graph
set<pii> edge_set;

void bfs(int s) {
    for (int i = 0; i < N; i++) {
        color[i] = 0;
        d[i] = INT_MAX;
        p[i] = -1;
    }
    queue<int> q;
    color[s] = 1;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) { // loop invariant: when this condition is checked q only has gray nodes
        int u = q.front();
        q.pop();
        for (auto& v: adj[u]) {
            
            // this tactic is required for undirected graphs
            // since we don't an edge to be considered twice
            // if the graph is directed the check will always fail, hence not required for directed graphs
            // if (edge_set.find({u, v}) != edge_set.end()) continue;
            // edge_set.insert({v, u});

            if (color[v] == 0) {
                color[v] = 1;
                p[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
                treeedges.push_back({u, v});
            } else {
                int pu = u;
                int pv = v;
                while (pv != -1 && d[pv] > d[pu]) pv = p[pv];
                while (pu != -1 && d[pu] > d[pv]) pu = p[pu];
                if (pu == pv) 
                    backedges.push_back({u, v});
                else 
                    crossedges.push_back({u, v});
            }
        }
        color[u] = 2;
    }
}


void print_path(int s, int v) {
    // print vertices of shortest path from s to v;
    if (v == s) {
        cout << s << endl;
    } 
    else {
        if (p[v] == -1) {
            cout << "path doesn't exist from " << s << " to " << v << endl;
        } 
        else {
            print_path(s, p[v]);
            cout << v << endl;
        }
    }
}

int main() {
    // BFS
    bfs(0);
    // print_path(0, 4);
    cout << "tree edges" << endl;
    for (auto& [u, v]: treeedges){
        cout << u << ',' << v << ' ';
    }
    cout << endl;
    cout << "back edges" << endl;
    for (auto& [u, v]: backedges){
        cout << u << ',' << v << ' ';
    }
    cout << endl;
    cout << "forward edges" << endl;
    for (auto& [u, v]: forwardedges){
        cout << u << ',' << v << ' ';
    }
    cout << endl;
    cout << "cross edges" << endl;
    for (auto& [u, v]: crossedges){
        cout << u << ',' << v << ' ';
    }
    cout << endl;
    
    return 0;
}
