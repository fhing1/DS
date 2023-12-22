#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int dist[N];        // dist[i]��ʾ���i�����ľ���
int g[N][N];        // g[i][j]��ʾ���i�����j�ıߵĳ���
bool st[N];         // st[i]��ʾ�ý���Ƿ�ȷ������С���룬1��ȷ����0��δȷ��
int n, m;

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);   // �Ѿ����ʼ��Ϊ������
    dist[1] = 0;

    int iter = n;
    while (iter--) {    // n���㣬ѭ��n��
        int t = -1;
        for (int i = 1; i <= n; i++) {
            if (!st[i] && (t == -1 || dist[t] > dist[i]))
                t = i;
        }
        st[t] = true;   // ����st[t] = 1�����������distȥ����ʣ�����dist

        for (int i = 1; i <= n; i++) {
            if (!st[i])
                dist[i] = min(dist[i], dist[t] + g[t][i]);
        }
    }
}

int main() {
    cout << "������ڵ�����ͱ������ո�ָ�����" << endl;
    // ����n���㣬m����
    cin >> n >> m;

    // ��ʼ��g�����б�Ϊ�����
    memset(g, 0x3f, sizeof g);

    cout << "������ÿ���ߵ���㡢�յ��Ȩֵ���ո�ָ�����" << endl;
    // ����m���ߵ���Ϣ
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);  // ע��������ܳ����رߵ����
    }

    // ����Dijkstra�㷨
    dijkstra();

    cout << "ÿ����㵽������̾���Ϊ��" << endl;
    // ���ÿ����㵽������̾���
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x3f3f3f3f)   // ���ĳ����㵽������̾�����Ȼ������󣬱�ʾ�޷�����
            cout << "�ڵ� " << i << " �޷�����" << endl;
        else
            cout << "�ڵ� " << i << " ��������̾���Ϊ " << dist[i] << endl;
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
