#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& visited, stack<int>& result) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            dfs(neighbor, graph, visited, result);
        }
        else if (visited[neighbor] == 1) {
            cout << "图中存在环，无法进行拓扑排序" << endl;
            exit(0);
        }
    }
    visited[node] = 2;
    result.push(node);
}

vector<int> topological_sort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    stack<int> result;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            dfs(i, graph, visited, result);
        }
    }
    vector<int> sorted_result;
    while (!result.empty()) {
        sorted_result.push_back(result.top());
        result.pop();
    }
    return sorted_result;
}

int main() {
    vector<vector<int>> graph = {
        {1},
        {2},
        {3},
        {}
    };
    vector<int> sorted_result = topological_sort(graph);
    cout << "拓扑序列为：";
    for (int node : sorted_result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
