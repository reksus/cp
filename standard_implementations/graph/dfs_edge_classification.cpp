#include<bits/stdc++.h>
using namespace std;
void dfs_visit (int u);
/*
DFS Notes:

TIME COMPLEXITY - O(V+E)
O(V) - each vertex color is visted exactly once in dfs_visit
O(E) - adj list of any vertex is traverserd exactly once


1. nesting of intervals
v is proper descendant of u iff d[u] < d[v] < f[v] < f[u]

2. White-Path theorem
if v is a descendant of u iff at the time of d[u], v can be reached from u along a path consisting entirely of white vertices.

3 Edge Classification
directed graph:
WHITE -> tree edge
GRAY -> back edge
BLACK -> 
    forward (d[u] < d[v]) or 
    cross (d[u] > d[v]) edge

undirected graph: 
forward and cross edges don't exist

*/

// undirected graph example
// int N = 5;
// vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1}, {2}};

// directed graph example
int N = 6;
vector<vector<int>> adj = {{1, 4}, {2, 3}, {0, 4}, {}, {}, {4}};

vector<int> color(N); // 0 = 'white'
vector<int> d(N, INT_MAX); // discovery time
vector<int> f(N, INT_MAX); // finishing time
vector<int> p(N, -1); // parent (no parent for any node in the beginning)
int TIME = 0;
vector<pair<int,int>> treeedges, backedges, forwardedges, crossedges;

// required to keep a track of reverse egde in a undirected graph to not get counted
// not required in a directed graph
set<pair<int,int>> s;

void dfs() {
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            dfs_visit(i);
        }
    }
}

void dfs_visit (int u) {
    color[u] = 1; // 'gray'
    d[u] = TIME++;
    for (auto& v: adj[u]) {

        // this tactic is required for undirected graphs
        // since we don't an edge to be considered twice
        // if the graph is directed the check will always fail, hence not required for directed graphs
        if (s.find({u, v}) != s.end()) continue;
        s.insert({v, u});
        
        if (color[v] == 0) {
            p[v] = u;
            treeedges.push_back({u, v});
            dfs_visit(v);
        } 
        else {
            if (color[v] == 1) {
                backedges.push_back({u, v});
            }
            else if (color[v] == 2){
                if (d[u] < d[v]) forwardedges.push_back({u, v});
                else if (d[u] > d[v]) crossedges.push_back({u, v});
            }
        }
    }
    color[u] = 2; // 'black'
    f[u] = TIME++;
    // do something else with v
}


int main() {
    // DFS
    dfs();
    for (int i = 0; i < N; i++) {
        cout << i << " " << d[i] << " " << f[i] << " " << p[i] << endl;
    } 

    // printing tree edges.
    cout << "dfs tree edges" << endl;
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
