#include<stdio.h>
#include <stdlib.h>
//����������ṹ
typedef struct Node {
    int data;
    struct Node* next;
}Node;

//���嵥����
typedef Node* LinkList;
//β�巨����������
void CreatList(LinkList* L, int n) {
    LinkList p, r;
    *L = (LinkList)malloc(sizeof(Node)); //ͷ���
    r = *L;                     //rָ������β���,��ʱr�ǵ�һ��Ҳ�����һ��
    printf("����������Ԫ��:\n");
    for (int i = 0; i < n; i++) {
        p = (Node*)malloc(sizeof(Node));          //Ϊ�½�������ڴ�
        scanf_s("%d", &p->data);
        r->next = p;
        r = p;
    }
    r->next = nullptr;
}
//�������
void Printlist(LinkList L)
{
    LinkList p;
    p = L->next;  //pָ��L�ĵ�һ�����
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

//�͵�����

void Reverselist(LinkList* L) {

    Node* p, * q;
    if ((*L)->next && (*L)->next->next) {              //������ջ�����ֻ��һ����㣬����Ҫ��ת
        p = (*L)->next;           //�������Ϊ������һ����ͷ����һ������������ʣ�� �����ɵ�����
        q = p->next;
        p->next = NULL;
        while (q) {             //��ͷ�巨���ν��ڶ��������еĽ������һ������
            p = q;
            q = q->next;
            p->next = (*L)->next;
            (*L)->next = p;
        }
    }
}

int main(void) {
    LinkList L;
    int len;
    printf("������������");
    scanf_s("%d", &len);
    CreatList(&L, len);
    Reverselist(&L);
    printf("��ת��\n");
    Printlist(L);
    printf("\n����ˣ�22�������Ƚ");
    return 0;
}
