#include <stdio.h>
#include <stdbool.h>

#define N 7

int color[N] = { 0 };           // �洢ÿ��������ɫ
int adjacency[N][N] = { 0 };    // �洢���ɰ�������֮������ڹ�ϵ

// ��ʼ�����ɰ�����ڹ�ϵ
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
            adjacency[i][j] = 0;  // ��ʼ��Ϊ������
        }
    }

    for (i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        adjacency[edges[i][0]][edges[i][1]] = edges[i][2];
    }
}

// ��ȡ��ָ��������ڵ���Ϳɫ����ɫ����
void getAdjacentColors(int block, int adjacentColors[N]) {
    int i, colorIndex = 0;

    for (i = 0; i < N; i++) {
        if (adjacency[block][i] == 1 && color[i] != 0) {
            adjacentColors[color[i] - 1] = 1;
        }
    }
}

// ̰��Ϳɫ�㷨
void greedyColoring() {
    int i, j, c;
    int adjacentColors[N] = { 0 };

    for (i = 0; i < N; i++) {
        // ��ȡ�뵱ǰ������ڵ���Ϳɫ����ɫ����
        getAdjacentColors(i, adjacentColors);

        // ѡ����С��δ��ʹ�õ���ɫͿɫ
        for (c = 0; c < N; c++) {
            if (adjacentColors[c] == 0) {
                color[i] = c + 1;
                break;
            }
        }

        // ����������ɫ����
        for (j = 0; j < N; j++) {
            adjacentColors[j] = 0;
        }
    }
}

int main() {
    initAdjacency();  // ��ʼ�����ɰ�����ڹ�ϵ

    greedyColoring();  // ����̰��Ϳɫ�㷨

    printf("Ϳɫ����Ϊ: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
    printf("�����:22������ϲ��");
    return 0;
}
