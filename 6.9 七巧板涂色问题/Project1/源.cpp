#include <stdio.h>
#include <stdbool.h>

#define N 7

int color[N] = { 0 };           // 存储每个板块的颜色
int adjacency[N][N] = { 0 };    // 存储七巧板各个板块之间的相邻关系

// 初始化七巧板的相邻关系
void initAdjacency() {
    int i, j;
    int edges[][3] = { {0, 1, 1}, {0, 4, 1}, {0, 6, 1},
                      {1, 0, 1}, {1, 3, 1}, {1, 5, 1},
                      {2, 4, 1}, {2, 6, 1},
                      {3, 1, 1}, {3, 6, 1}, {3, 7, 1},
                      {4, 0, 1}, {4, 2, 1}, {4, 7, 1},
                      {5, 1, 1}, {5, 6, 1},
                      {6, 0, 1}, {6, 2, 1}, {6, 3, 1}, {6, 5, 1} };

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            adjacency[i][j] = 0;  // 初始化为不相邻
        }
    }

    for (i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        adjacency[edges[i][0]][edges[i][1]] = edges[i][2];
    }
}

// 获取与指定板块相邻的已涂色的颜色集合
void getAdjacentColors(int block, int adjacentColors[N]) {
    int i, colorIndex = 0;

    for (i = 0; i < N; i++) {
        if (adjacency[block][i] == 1 && color[i] != 0) {
            adjacentColors[color[i] - 1] = 1;
        }
    }
}

// 贪心涂色算法
void greedyColoring() {
    int i, j, c;
    int adjacentColors[N] = { 0 };

    for (i = 0; i < N; i++) {
        // 获取与当前板块相邻的已涂色的颜色集合
        getAdjacentColors(i, adjacentColors);

        // 选择最小的未被使用的颜色涂色
        for (c = 0; c < N; c++) {
            if (adjacentColors[c] == 0) {
                color[i] = c + 1;
                break;
            }
        }

        // 重置相邻颜色数组
        for (j = 0; j < N; j++) {
            adjacentColors[j] = 0;
        }
    }
}

int main() {
    initAdjacency();  // 初始化七巧板的相邻关系

    greedyColoring();  // 调用贪心涂色算法

    printf("涂色方案为: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
    printf("完成人:22网工方喜健");
    return 0;
}
