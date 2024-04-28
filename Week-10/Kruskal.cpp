#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int start, end, weight;
};

struct graph {
    int n;
    vector<Edge> edge;
};

bool operator<(const Edge &a, const Edge &b){
    return a.weight > b.weight;
}

int group(vector<int> &disjoint, int n){
    while(disjoint[n] != n)
        n = disjoint[n];
    return disjoint[n];
}

int Kruskal_min (graph g){

    vector<int> disjoint(g.n);
    priority_queue<Edge> pq;
    int times = g.n-1, min_cost = 0;
    for(int i = 0; i < g.n; i++)
        disjoint[i] = i; // init, gruop only self.

    for(vector<Edge>::iterator it = g.edge.begin(); it != g.edge.end(); it++)
        pq.push(*it);

    while(times-- > 0 && !pq.empty()){
        Edge e = pq.top();
        pq.pop();

        int  g1 = group(disjoint, e.start), g2 = group(disjoint, e.end); // which group.

        if(g1 != g2){
            disjoint[g1] = g2;
            min_cost += e.weight;
        }
    }
    return min_cost;
}

int main() {
    graph G;
    
    int a, b, r;
    cout << "Input Number of Nodes." << endl; 
    cin >> G.n;
    cout << "Input node.1, node.2 and Cost of two nodes." << endl;
    while(cin >> a >> b >> r){
        Edge push  = {a, b, r};
        G.edge.push_back(push);
    }
    cout << "Minimum cost to each point = " << Kruskal_min(G) << endl;
    return 0;
}