#include <stdio.h>

// 表示状态的结构体
typedef struct {
    int farmer;   // 农夫所在的岸，0 表示南岸，1 表示北岸
    int wolf;     // 狼所在的岸，0 表示南岸，1 表示北岸
    int goat;     // 羊所在的岸，0 表示南岸，1 表示北岸
    int cabbage;  // 白菜所在的岸，0 表示南岸，1 表示北岸
} State;

// 判断两个状态是否相同
int is_same(State state1, State state2) {
    return (state1.farmer == state2.farmer &&
        state1.wolf == state2.wolf &&
        state1.goat == state2.goat &&
        state1.cabbage == state2.cabbage);
}

// 判断当前状态是否合法
int is_valid(State state) {
    // 如果狼和羊在同一岸，而农夫不在，或者羊和白菜在同一岸，而农夫不在，状态不合法
    if ((state.wolf == state.goat && state.farmer != state.wolf) ||
        (state.goat == state.cabbage && state.farmer != state.goat)) {
        return 0;
    }
    return 1;
}

// 打印当前状态
void print_state(State state) {
    printf("农夫: %s, 狼: %s, 羊: %s, 白菜: %s\n",
        state.farmer == 0 ? "南岸" : "北岸",
        state.wolf == 0 ? "南岸" : "北岸",
        state.goat == 0 ? "南岸" : "北岸",
        state.cabbage == 0 ? "南岸" : "北岸");
}

// 搜索函数
void search(State initial, State goal) {
    // 创建一个存储状态的数组，用于模拟栈
    State stack[1000];
    int top = 0; // 栈顶指针

    // 将初始状态入栈
    stack[top++] = initial;

    // 当栈不为空时，继续搜索
    while (top > 0) {
        // 出栈
        State current = stack[--top];

        // 判断是否达到目标状态
        if (is_same(current, goal)) {
            print_state(current);
            return;
        }

        // 尝试每一种可能的动作
        for (int i = 0; i < 16; i++) {
            State next = current;

            // 农夫移动
            if (i & 1) next.farmer = 1 - next.farmer;

            // 狼移动
            if (i & 2) next.wolf = 1 - next.wolf;

            // 羊移动
            if (i & 4) next.goat = 1 - next.goat;

            // 白菜移动
            if (i & 8) next.cabbage = 1 - next.cabbage;

            // 判断移动后的状态是否合法
            if (is_valid(next)) {
                // 将新状态入栈
                stack[top++] = next;
            }
        }
    }
}

int main() {
    State initial = { 0, 0, 0, 0 };  // 初始状态
    State goal = { 1, 1, 1, 1 };     // 目标状态

    printf("过河方案:\n");
    search(initial, goal);

    return 0;
}
