#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // �����ֵ

// ����߽ṹ��
struct Edge {
    int src, dest, weight;
};

// ʵ��Prim�㷨
void primMST(vector<vector<int>>& graph, int numVertices) {
    vector<int> parent(numVertices); // �洢��С�������и���ĸ��ڵ�
    vector<int> key(numVertices, INF); // �洢ÿ���㵽��С�������ľ���
    vector<bool> inMST(numVertices, false); // �洢ÿ�����Ƿ��ѱ�������С������

    // ��ʼ����ʼ��
    key[0] = 0;
    parent[0] = -1;

    // ���μ���ʣ��ĵ�
    for (int count = 0; count < numVertices - 1; ++count) {
        int u = -1;
        // �ҵ�������С�ĵ�
        for (int v = 0; v < numVertices; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true; // ���õ������С������

        // ������رߵľ���
        for (int v = 0; v < numVertices; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // �����С�������ı�
    for (int i = 1; i < numVertices; ++i) {
        cout << "��: " << parent[i] << " - " << i << "    Ȩֵ: " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int numVertices = 5; // �������
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
    cout << "�����:22������ϲ��" << endl;
    return 0;
}