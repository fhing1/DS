#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -2

typedef int ElemType;  // 将数据类型修改为 int

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, * LinkList;

LinkList InitLinkList() {
    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));
    if (L != NULL) {
        L->next = NULL;
    }
    return L;
}

void createLinkList(LinkList L, int num) {
    ElemType elem = 0;
    LinkList head = L;
    printf("请输入元素内容:\n");
    for (int i = 0; i < num; i++) {
        L->next = (LNode*)malloc(sizeof(LNode));
        scanf_s("%d", &elem);
        L->next->data = elem;
        L->next->next = NULL;
        L = L->next;
    }
    L = head;
}

int listLength(LinkList L) {
    LinkList first = L;
    int length = 0;
    while (L->next != NULL) {
        length++;
        L = L->next;
    }
    L = first;
    return length;
}

void LocationElem(LinkList L, ElemType elem) {
    int i = 0;
    bool flag = false;
    LinkList first = L;
    while (L->next != NULL) {
        i++;
        if (L->next->data == elem) {
            flag = true;
            printf("%d 位于第 %d 位\n", elem, i);
        }
        L = L->next;
    }
    L = first;
    if (!flag) {
        printf("抱歉，没有该元素\n");
    }
}

void GetElem(LinkList L, int Location) {
    LNode* first = L;
    int i = 0;
    int length = 0;
    while (L->next != NULL) {
        length++;
        L = L->next;
    }
    L = first;
    if (length < Location || Location < 1) {
        printf("下标不合法\n");
        L = first;
        return;
    }
    else {
        while (i < Location) {
            L = L->next;
            i++;
        }
        printf("第 %d 位置的元素是 %d\n", Location, L->data);
        L = first;
    }
}

void InsertList(LinkList L, ElemType elem, int location) {
    LNode* wait = NULL;
    LNode* wait_next = NULL;
    LNode* first = L;
    int i = 0;
    int length = 0;
    while (L->next != NULL) {
        length++;
        L = L->next;
    }
    L = first;
    if (location > length + 1 || location < 1) {
        printf("下标不合法\n");
        L = first;
        return;
    }
    while (i <= (location - 2)) {
        L = L->next;
        i++;
    }
    wait_next = L->next;
    wait = (LNode*)malloc(sizeof(LNode));
    wait->data = elem;
    L->next = wait;
    wait->next = wait_next;
    printf("插入成功\n");
    L = first;
}

void deleteElem(LinkList L, int location) {
    LNode* first = L;
    int i = 0;
    int length = 0;
    while (L->next != NULL) {
        length++;
        L = L->next;
    }
    L = first;
    if (location > length || location < 1) {
        printf("下标不合法\n");
        L = first;
        return;
    }
    while (i < location - 1) {
        L = L->next;
        i++;
    }
    L->next = L->next->next;
    printf("删除成功\n");
    L = first;
}

void print(LinkList L) {
    LNode* first = L;
    while (first->next != NULL) {
        printf("%d ", first->next->data);
        first = first->next;
    }
    printf("\n");
}

void sort(LinkList L) {
    ElemType temp;
    LNode* first = L;
    LNode* flag = L;
    int i = 0;
    int length = 0;
    while (L->next != NULL) {
        length++;
        L = L->next;
    }
    L = first;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (L->next->data > L->next->next->data) {
                temp = L->next->data;
                L->next->data = L->next->next->data;
                L->next->next->data = temp;
            }
            L = L->next;
        }
        L = first;
    }
    L = first;
    print(L);
}

void Invert(LinkList L) {
    LNode* first = L;
    LNode* last = L;
    ElemType temp;
    int i = 0;
    int length = 0;
    int length_temp;
    while (L->next != NULL) {
        length++;
        L = L->next;
    }
    length_temp = length;
    last = L;
    L = first;
    for (i = 0; i < length / 2; i++) {
        temp = L->next->data;
        L->next->data = last->data;
        last->data = temp;
        L = L->next;
        last = first;
        length_temp--;
        for (int j = 0; j < length_temp; j++) {
            last = last->next;
        }
    }
    L = first;
    printf("逆置成功\n");
    print(L);
}

int main() {
    LinkList L = NULL;
    int operate = -1;
    int num = 0;
    int location = 0;
    printf("请输入要进行的操作\n");
    printf("1---创建单链表\n");
    printf("2---单链表长度\n");
    printf("3---求指定元素的位置\n");
    printf("4---给定下标获取元素\n");
    printf("5---插入元素\n");
    printf("6---删除元素\n");
    printf("7---排序\n");
    printf("8---逆置单链表\n");
    printf("11---打印单链表\n");
    printf("完成人:22网工方喜健\n");
    while (operate != 0) {
        scanf_s("%d", &operate);
        switch (operate) {
        case 1:
            printf("请输入元素个数\n");
            scanf_s("%d", &num);
            L = InitLinkList();
            createLinkList(L, num);
            printf("请输入编号进行下一步操作\n");
            break;
        case 2:
            printf("单链表的长度是 %d\n", listLength(L));
            printf("请输入编号进行下一步操作\n");
            break;
        case 3:
            printf("请输入你想定位的元素\n");
            scanf_s("%d", &operate);
            LocationElem(L, operate);
            printf("请输入编号进行下一步操作\n");
            break;
        case 4:
            printf("请输入元素下标:\n");
            scanf_s("%d", &location);
            GetElem(L, location);
            printf("请输入编号进行下一步操作\n");
            break;
        case 5:
            printf("请输入插入的元素和插入位置:\n");
            scanf_s("%d %d", &operate, &location);
            InsertList(L, operate, location);
            printf("请输入编号进行下一步操作\n");
            break;
        case 6:
            printf("请输入你想删除的元素的位置\n");
            scanf_s("%d", &location);
            deleteElem(L, location);
            printf("请输入编号进行下一步操作\n");
            break;
        case 7:
            sort(L);
            printf("请输入编号进行下一步操作\n");
            break;
        case 8:
            Invert(L);
            printf("请输入编号进行下一步操作\n");
            break;
        case 11:
            print(L);
            printf("请输入编号进行下一步操作\n");
            break;
        }
    }

    // 释放链表内存
    while (L != NULL) {
        LinkList temp = L;
        L = L->next;
        free(temp);
    }

    return 0;
}
