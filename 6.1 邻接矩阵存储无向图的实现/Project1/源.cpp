#include <iostream>
#include <queue>
using namespace std;

template<class T, int MAX_SIZE>
class MGraph {
private:
    T vertices[MAX_SIZE];
    bool matrix[MAX_SIZE][MAX_SIZE];
    int vertexNum;

public:
    MGraph() : vertexNum(0) {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                matrix[i][j] = false;
            }
        }
    }

    void create_graph() {
        cout << "�����붥�������" << endl;
        cin >> vertexNum;

        cout << "�����붥��ֵ��" << endl;
        for (int i = 0; i < vertexNum; i++) {
            cin >> vertices[i];
        }

        cout << "������ߵĸ�����" << endl;
        int edgeNum;
        cin >> edgeNum;

        cout << "������ÿ���ߵ����������±꣺" << endl;
        for (int i = 0; i < edgeNum; i++) {
            int v1, v2;
            cin >> v1 >> v2;

            if (v1 >= 0 && v1 < vertexNum && v2 >= 0 && v2 < vertexNum) {
                matrix[v1][v2] = true;
                matrix[v2][v1] = true;
            }
            else {
                cout << "�����±�Խ�磬�ߴ���ʧ�ܣ�" << endl;
            }
        }

        cout << "����ͼ�����ɹ���" << endl;
    }

    void dfs_traverse() {
        bool visited[MAX_SIZE];
        for (int i = 0; i < vertexNum; i++) {
            visited[i] = false;
        }

        cout << "������ȱ��������" << endl;
        for (int i = 0; i < vertexNum; i++) {
            if (!visited[i]) {
                dfs(i, visited);
            }
        }
        cout << endl;
    }

    void bfs_traverse() {
        bool visited[MAX_SIZE];
        for (int i = 0; i < vertexNum; i++) {
            visited[i] = false;
        }

        cout << "������ȱ��������" << endl;
        for (int i = 0; i < vertexNum; i++) {
            if (!visited[i]) {
                bfs(i, visited);
            }
        }
        cout << endl;
    }

private:
    void dfs(int v, bool visited[]) {
        visited[v] = true;
        cout << vertices[v] << " ";

        for (int i = 0; i < vertexNum; i++) {
            if (matrix[v][i] && !visited[i]) {
                dfs(i, visited);
            }
        }
    }

    void bfs(int v, bool visited[]) {
        queue<int> q;
        q.push(v);
        visited[v] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << vertices[curr] << " ";

            for (int i = 0; i < vertexNum; i++) {
                if (matrix[curr][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    MGraph<char, 10> graph;
    graph.create_graph();

    graph.dfs_traverse();
    graph.bfs_traverse();

    return 0;
}
