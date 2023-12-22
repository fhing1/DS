#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 无穷大值

// 定义边结构体
struct Edge {
    int src, dest, weight;
};

// 实现Prim算法
void primMST(vector<vector<int>>& graph, int numVertices) {
    vector<int> parent(numVertices); // 存储最小生成树中各点的父节点
    vector<int> key(numVertices, INF); // 存储每个点到最小生成树的距离
    vector<bool> inMST(numVertices, false); // 存储每个点是否已被加入最小生成树

    // 初始化起始点
    key[0] = 0;
    parent[0] = -1;

    // 依次加入剩余的点
    for (int count = 0; count < numVertices - 1; ++count) {
        int u = -1;
        // 找到距离最小的点
        for (int v = 0; v < numVertices; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true; // 将该点加入最小生成树

        // 更新相关边的距离
        for (int v = 0; v < numVertices; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // 输出最小生成树的边
    for (int i = 1; i < numVertices; ++i) {
        cout << "边: " << parent[i] << " - " << i << "    权值: " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int numVertices = 5; // 顶点个数
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    cout << "graph:" << endl;
    for(const auto&row:graph)
    {
	    for(int value:row)
	    {
            cout << value << " ";
	    }
        cout << endl;
    }
    primMST(graph, numVertices);
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}