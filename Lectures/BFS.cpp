#include <bits/stdc++.h>
using namespace std;

bool *visited;
int *truoc;

class Graph {
    public:
    int V;
    list<int> *adj;

    public:
    int numVertex();
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    bool isBigPartitie(int s);
};

Graph::Graph(int V) {
    this -> V = V;
    adj = new list<int>[V];
}

int Graph::numVertex() {
    return V;
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    //adj[v].push_back(u); //If graph has direction
}

void Graph::BFS(int s) {
    visited[s] = NULL;
    queue<int> Q;
    list<int>::iterator it;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front();
        cout << u << " ";
        Q.pop();
        for(it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = *it;
            if(!visited[v]) {
                visited[v] = true;
                truoc[v] = u;
                Q.push(v);
            }
        }
    }
    cout << endl;
}

void Graph::DFS(int s) {
    visited[s] = true;
    truoc[s] = NULL;
    list<int>::iterator it;
    stack<int> S;
    S.push(s);
    while(!S.empty()) {
        int u = S.top(); S.pop();
        cout << u << " ";
        for(it = adj[u].begin(); it != adj[u].end(); it ++) {
            int v = *it;
            if(!visited[v]) {
                visited[v] = true;
                S.push(v);
                truoc[v] = u;
            }
        }

    }
    cout << endl;

}

bool Graph::isBigPartitie(int s) {
    vector<int> colors(this -> numVertex());
    int V = this -> numVertex();
    for(int i = 0; i < V; i ++) {
        colors[i] = -1;
    }
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
            int v  =*it;
            if(u == v) return false;
            else if(colors[v] != -1) {
                colors[v] = 0;
                Q.push(v);
            }
            else if(colors[u] == colors[v]) return false;
        }
    }
    return true;
}

int main() {
    Graph g(5);
    g.addEdge(1, 2); g.addEdge(1, 3);
    g.addEdge(2, 4); g.addEdge(4, 0);
    g.addEdge(3, 0); g.addEdge(0, 2);

    int numV = g.numVertex();
    visited = new bool[numV];
    truoc = new int[numV];
    for(int i = 0; i < numV; i++) {
        visited[i] = false;
        truoc[i] = NULL;
    }
    cout << "BFS(1): " ;
    g.BFS(1);
    for(int i = 0; i < numV; i++) visited[i] = false;
    cout << "DFS(1): ";
    g.DFS(1);
    cout << g.isBigPartitie(1)<<endl;
    
    // int t = 4;
    // while(truoc[t] != NULL) {
    //     cout << t << "<-";
    //     t = truoc[t];
    // }
    return 0;
}