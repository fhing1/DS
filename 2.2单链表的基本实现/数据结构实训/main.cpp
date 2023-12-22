#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -2

typedef int ElemType;  // �����������޸�Ϊ int

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
    printf("������Ԫ������:\n");
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
            printf("%d λ�ڵ� %d λ\n", elem, i);
        }
        L = L->next;
    }
    L = first;
    if (!flag) {
        printf("��Ǹ��û�и�Ԫ��\n");
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
        printf("�±겻�Ϸ�\n");
        L = first;
        return;
    }
    else {
        while (i < Location) {
            L = L->next;
            i++;
        }
        printf("�� %d λ�õ�Ԫ���� %d\n", Location, L->data);
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
        printf("�±겻�Ϸ�\n");
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
    printf("����ɹ�\n");
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
        printf("�±겻�Ϸ�\n");
        L = first;
        return;
    }
    while (i < location - 1) {
        L = L->next;
        i++;
    }
    L->next = L->next->next;
    printf("ɾ���ɹ�\n");
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
    printf("���óɹ�\n");
    print(L);
}

int main() {
    LinkList L = NULL;
    int operate = -1;
    int num = 0;
    int location = 0;
    printf("������Ҫ���еĲ���\n");
    printf("1---����������\n");
    printf("2---��������\n");
    printf("3---��ָ��Ԫ�ص�λ��\n");
    printf("4---�����±��ȡԪ��\n");
    printf("5---����Ԫ��\n");
    printf("6---ɾ��Ԫ��\n");
    printf("7---����\n");
    printf("8---���õ�����\n");
    printf("11---��ӡ������\n");
    printf("�����:22������ϲ��\n");
    while (operate != 0) {
        scanf_s("%d", &operate);
        switch (operate) {
        case 1:
            printf("������Ԫ�ظ���\n");
            scanf_s("%d", &num);
            L = InitLinkList();
            createLinkList(L, num);
            printf("�������Ž�����һ������\n");
            break;
        case 2:
            printf("������ĳ����� %d\n", listLength(L));
            printf("�������Ž�����һ������\n");
            break;
        case 3:
            printf("���������붨λ��Ԫ��\n");
            scanf_s("%d", &operate);
            LocationElem(L, operate);
            printf("�������Ž�����һ������\n");
            break;
        case 4:
            printf("������Ԫ���±�:\n");
            scanf_s("%d", &location);
            GetElem(L, location);
            printf("�������Ž�����һ������\n");
            break;
        case 5:
            printf("����������Ԫ�غͲ���λ��:\n");
            scanf_s("%d %d", &operate, &location);
            InsertList(L, operate, location);
            printf("�������Ž�����һ������\n");
            break;
        case 6:
            printf("����������ɾ����Ԫ�ص�λ��\n");
            scanf_s("%d", &location);
            deleteElem(L, location);
            printf("�������Ž�����һ������\n");
            break;
        case 7:
            sort(L);
            printf("�������Ž�����һ������\n");
            break;
        case 8:
            Invert(L);
            printf("�������Ž�����һ������\n");
            break;
        case 11:
            print(L);
            printf("�������Ž�����һ������\n");
            break;
        }
    }

    // �ͷ������ڴ�
    while (L != NULL) {
        LinkList temp = L;
        L = L->next;
        free(temp);
    }

    return 0;
}
