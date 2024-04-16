#include<bits/stdc++.h>
using namespace std;

void dfs_visit (int u);

/*
TOPOLOGICAL SORT notes:

TIME COMPLEXITY - O(V+E)
O(V) - each vertex color is visted exactly once in dfs_visit
    - each vertex is added to the linked list exactly once in O(1)
O(E) - adj list of any vertex is traverserd exactly once

CYCLICITY:
A graph is acylic iff dfs of G yields no back edges
*/


class Node {
public:
    int val;
    Node* next;

    Node (int val) {
        this->val = val;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }
    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << endl;
    }
};

int N = 5;
vector<vector<int>> adj = {{1, 2}, {2, 3}, {4}, {4}, {}}; // adjacency list
vector<int> color(N); // 0 = 'white'
vector<int> d(N, INT_MAX); // discovery time
vector<int> f(N, INT_MAX); // finishing time
vector<int> p(N, -1); // parent (no parent for any node in the beginning)
int TIME = 0;
LinkedList l;

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
        if (color[v] == 0) {
            p[v] = u;
            dfs_visit(v);
        }
    }
    color[u] = 2; // 'black'
    f[u] = TIME++;
    l.insert(u); // <<--- this is added to the linked list in reverse order (only change for toposort)
    // do something else with v
}

int main() {
    dfs();
    l.print();
    return 0;
}
