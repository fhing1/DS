#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

int find(vector<int>& parent, int x) {
    if (parent[x] == -1) {
        return x;
    }
    return parent[x] = find(parent, parent[x]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

vector<Edge> kruscal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n, -1);
    vector<Edge> mst;
    for (const Edge& e : edges) {
        int rootU = find(parent, e.u);
        int rootV = find(parent, e.v);
        if (rootU != rootV) {
            mst.push_back(e);
            unionSets(parent, rootU, rootV);
        }
    }
    return mst;
}

int main() {
    int n, m;
    cout << "请输入顶点数和边数：";
    cin >> n >> m;
    vector<Edge> edges(m);
    cout << "请输入每条边的起始顶点、结束顶点和权重：" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    vector<Edge> mst = kruscal(edges, n);
    cout << "最小生成树中的各边为：" << endl;
    for (const Edge& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    cout << "完成人：李浩冉";
    return 0;
}
