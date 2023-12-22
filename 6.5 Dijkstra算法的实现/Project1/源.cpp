#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int dist[N];        // dist[i]表示结点i到起点的距离
int g[N][N];        // g[i][j]表示结点i到结点j的边的长度
bool st[N];         // st[i]表示该结点是否确定了最小距离，1是确定，0是未确定
int n, m;

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);   // 把距离初始化为正无穷
    dist[1] = 0;

    int iter = n;
    while (iter--) {    // n个点，循环n次
        int t = -1;
        for (int i = 1; i <= n; i++) {
            if (!st[i] && (t == -1 || dist[t] > dist[i]))
                t = i;
        }
        st[t] = true;   // 设置st[t] = 1，用这个结点的dist去更新剩余结点的dist

        for (int i = 1; i <= n; i++) {
            if (!st[i])
                dist[i] = min(dist[i], dist[t] + g[t][i]);
        }
    }
}

int main() {
    cout << "请输入节点个数和边数（空格分隔）：" << endl;
    // 输入n个点，m条边
    cin >> n >> m;

    // 初始化g的所有边为无穷大
    memset(g, 0x3f, sizeof g);

    cout << "请输入每条边的起点、终点和权值（空格分隔）：" << endl;
    // 输入m条边的信息
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);  // 注意这里可能出现重边的情况
    }

    // 调用Dijkstra算法
    dijkstra();

    cout << "每个结点到起点的最短距离为：" << endl;
    // 输出每个结点到起点的最短距离
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x3f3f3f3f)   // 如果某个结点到起点的最短距离仍然是无穷大，表示无法到达
            cout << "节点 " << i << " 无法到达" << endl;
        else
            cout << "节点 " << i << " 到起点的最短距离为 " << dist[i] << endl;
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
