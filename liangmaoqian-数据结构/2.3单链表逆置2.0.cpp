#include<stdio.h>
#include <stdlib.h>
//定义链表结点结构
typedef struct Node {
    int data;
    struct Node* next;
}Node;

//定义单链表
typedef Node* LinkList;
//尾插法创建单链表
void CreatList(LinkList* L, int n) {
    LinkList p, r;
    *L = (LinkList)malloc(sizeof(Node)); //头结点
    r = *L;                     //r指向链表尾结点,这时r是第一个也是最后一个
    printf("请输入链表元素:\n");
    for (int i = 0; i < n; i++) {
        p = (Node*)malloc(sizeof(Node));          //为新结点申请内存
        scanf_s("%d", &p->data);
        r->next = p;
        r = p;
    }
    r->next = nullptr;
}
//输出链表
void Printlist(LinkList L)
{
    LinkList p;
    p = L->next;  //p指向L的第一个结点
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

//就地逆置

void Reverselist(LinkList* L) {

    Node* p, * q;
    if ((*L)->next && (*L)->next->next) {              //如果链空或链表只有一个结点，则不需要翻转
        p = (*L)->next;           //将链表分为两个，一个带头结点和一个结点的链表，和剩余 结点组成的链表
        q = p->next;
        p->next = NULL;
        while (q) {             //用头插法依次将第二个链表中的结点插入第一个链表
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
    printf("请输入链表长度");
    scanf_s("%d", &len);
    CreatList(&L, len);
    Reverselist(&L);
    printf("翻转后：\n");
    Printlist(L);
    printf("\n完成人：22网工李浩冉");
    return 0;
}
