#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class ALGraph {
public:
    ALGraph(int n) : adjList(n) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void DFS(int start) {
        vector<bool> visited(adjList.size(), false);
        DFSUtil(start, visited);
    }

    void BFS(int start) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

private:
    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    vector<vector<T>> adjList;
};

int main() {
    ALGraph<int> graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);

    cout << "深度优先遍历（从顶点0开始）：";
    graph.DFS(0);
    cout << endl;

    cout << "广度优先遍历（从顶点0开始）：";
    graph.BFS(0);
    cout << endl;
    cout << "完成人：李浩冉";

    return 0;
}
