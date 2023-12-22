#include <stdio.h>

// ��ʾ״̬�Ľṹ��
typedef struct {
    int farmer;   // ũ�����ڵİ���0 ��ʾ�ϰ���1 ��ʾ����
    int wolf;     // �����ڵİ���0 ��ʾ�ϰ���1 ��ʾ����
    int goat;     // �����ڵİ���0 ��ʾ�ϰ���1 ��ʾ����
    int cabbage;  // �ײ����ڵİ���0 ��ʾ�ϰ���1 ��ʾ����
} State;

// �ж�����״̬�Ƿ���ͬ
int is_same(State state1, State state2) {
    return (state1.farmer == state2.farmer &&
        state1.wolf == state2.wolf &&
        state1.goat == state2.goat &&
        state1.cabbage == state2.cabbage);
}

// �жϵ�ǰ״̬�Ƿ�Ϸ�
int is_valid(State state) {
    // ����Ǻ�����ͬһ������ũ���ڣ�������Ͱײ���ͬһ������ũ���ڣ�״̬���Ϸ�
    if ((state.wolf == state.goat && state.farmer != state.wolf) ||
        (state.goat == state.cabbage && state.farmer != state.goat)) {
        return 0;
    }
    return 1;
}

// ��ӡ��ǰ״̬
void print_state(State state) {
    printf("ũ��: %s, ��: %s, ��: %s, �ײ�: %s\n",
        state.farmer == 0 ? "�ϰ�" : "����",
        state.wolf == 0 ? "�ϰ�" : "����",
        state.goat == 0 ? "�ϰ�" : "����",
        state.cabbage == 0 ? "�ϰ�" : "����");
}

// ��������
void search(State initial, State goal) {
    // ����һ���洢״̬�����飬����ģ��ջ
    State stack[1000];
    int top = 0; // ջ��ָ��

    // ����ʼ״̬��ջ
    stack[top++] = initial;

    // ��ջ��Ϊ��ʱ����������
    while (top > 0) {
        // ��ջ
        State current = stack[--top];

        // �ж��Ƿ�ﵽĿ��״̬
        if (is_same(current, goal)) {
            print_state(current);
            return;
        }

        // ����ÿһ�ֿ��ܵĶ���
        for (int i = 0; i < 16; i++) {
            State next = current;

            // ũ���ƶ�
            if (i & 1) next.farmer = 1 - next.farmer;

            // ���ƶ�
            if (i & 2) next.wolf = 1 - next.wolf;

            // ���ƶ�
            if (i & 4) next.goat = 1 - next.goat;

            // �ײ��ƶ�
            if (i & 8) next.cabbage = 1 - next.cabbage;

            // �ж��ƶ����״̬�Ƿ�Ϸ�
            if (is_valid(next)) {
                // ����״̬��ջ
                stack[top++] = next;
            }
        }
    }
}

int main() {
    State initial = { 0, 0, 0, 0 };  // ��ʼ״̬
    State goal = { 1, 1, 1, 1 };     // Ŀ��״̬

    printf("���ӷ���:\n");
    search(initial, goal);

    return 0;
}
