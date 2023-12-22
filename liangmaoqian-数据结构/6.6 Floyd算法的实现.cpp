#include<iostream>
#include<climits>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];

void floydWarshall(int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int V = 4;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    graph[0][0] = 0;
    graph[0][1] = 5;
    graph[0][2] = INT_MAX;
    graph[0][3] = 10;
    graph[1][0] = INT_MAX;
    graph[1][1] = 0;
    graph[1][2] = 3;
    graph[1][3] = INT_MAX;
    graph[2][0] = INT_MAX;
    graph[2][1] = INT_MAX;
    graph[2][2] = 0;
    graph[2][3] = 1;
    graph[3][0] = INT_MAX;
    graph[3][1] = INT_MAX;
    graph[3][2] = INT_MAX;
    graph[3][3] = 0;

    floydWarshall(V);

    cout << "下面的矩阵显示了每对顶点之间的最短距离: \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INT_MAX)
                cout << "INF" << "     ";
            else
                cout << graph[i][j] << "     ";
        }
        cout << endl;
    }
    cout << "完成人：李浩冉";
    return 0;
}
