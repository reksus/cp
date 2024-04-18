#include<bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=ZeDNSeilf-Y

/*
Tarjans algorithm:
SCC (strongly connected components)
data to keep
- discovery time
- low time (earliest time reachable from the current vertex)

when visiting a BackEdge 
low[u] = min(low[u], d[v])
why d[v] ?

when backtracking 
low[u] = min(low[u], low[v])

whenever a node is completely visited (black color) and if the d[u] == low[u] then 
u is the head of the SCC

stack is required to keep track of the nodes in the current SCC
if an edge is pointing to a visited node already in stack then it is a back edge
else it is a cross edge

why cross edge is not processed?
SCC1 -> SCC2
no point in covering already completed SCC2

printing component when backtracking:
whenever d[u] = low[u]
keep popping and printing from the stack till the current node is reached. 


Conditions for Articulation Points:
- Simple approach 
repeat for all nodes
    Delete each node and its edges and run dfs on any other node. 
        - if entire graph is traversed then the deleted node is not an articulation point

Time Complexity: O(V*(V+E))

Condition for an articulation point:
- if the node is a root node of a dfs tree and has more than 1 components as its child
- if the node is not a root node and if any of its children subgraph does NOT have a back edge to any of the ancestor of the node.

of course edge from child to parent is not a back edge. (cuz it is assumed to be removed for AP checking)


Conditions for Bridges:
if there is no back edge from a subgraph to any of the nodes ancestors or itself (across the edge being checked) then the edge (being checked) will be a bridge
why we don't consider child to parent edge?
cuz we assume this edge to be removed for bridge checking
- A back edge can never be bridge. (As there is already another path)

*/




int N = 7;
vector<vector<int>> adj = {{1}, {2, 3}, {}, {4}, {0, 5, 6}, {2, 6}, {5}};


void dfs(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& inStack) {
    static int time = 0;
    disc[u] = low[u] = time++;
    st.push(u);
    inStack[u] = true;

    for (int v: adj[u]) {
        if (disc[v] == -1) { // not yet discovered
            dfs(v, disc, low, st, inStack); // visit this
            low[u] = min(low[u], low[v]); // update the low[u]
        }
        else if (inStack[v]) { // back-edge (skip the cross edge as it can't make the low[u] any lower)
            low[u] = min(low[u], disc[v]);
        }
    }
    if (disc[u] == low[u]) { // root of the scc
        while (st.top() != u) {
            int top = st.top();
            st.pop();
            cout << top << ' ';
            inStack[top] = false;
        }
        int top = st.top();
        st.pop();
        cout << top << endl;
        inStack[top] = false;
    }
}

void find_sccs_tarjan() {
    vector<int> disc(N, -1), low(N, -1);
    vector<bool> inStack(N, false);
    stack<int> st;

    for (int i = 0; i < N; i++) {
        if (disc[i] == -1) {
            dfs(i, disc, low, st, inStack);
        }
    }
}

int main() {
    find_sccs_tarjan();
    return 0;
}