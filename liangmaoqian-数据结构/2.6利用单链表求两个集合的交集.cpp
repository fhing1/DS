#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//��巨����������
    L = new LNode;
    L->next = NULL;
    LinkList r = L;
    for (int i = 0;i < n;i++)
    {
        LinkList p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
void PrintList(LinkList& L)
{//��ӡ������������е�����
    L = L->next;   
    cout << "������������ͬԪ����:";
    while (L) {
        if (L->next != NULL) cout << L->data << " ";
        else cout << L->data;
        L = L->next;
    }

    cout << endl;
}
void Intersection(LinkList& LA, LinkList& LB)
{//�����������������ϵĽ���
/**************begin************/
    LinkList pa, pb, p;
    pa = LA->next;
    pb = LB->next;
    p = LA;
    while (pa && pb) {
        if (pa->data == pb->data) {
            p->next = pa;
            p = p->next;//p�ƶ����²�����λ��
            pa = pa->next;//pa��pb������ƶ�
            pb = pb->next;
        }
        else if (pa->data > pb->data) {
            pb = pb->next;
        }
        else {
            pa = pa->next;
        }
    }
    p->next = NULL;//��ʱ��һ�ѽ���,�ÿ�p����next
    /**************end************/
}
int main()
{
    int n, m,count=0;
    cout << "����������������Ԫ�صĸ������м��ÿո�ֿ���"<<endl;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        LinkList LA, LB;
        CreateList_R(LA, n);
        CreateList_R(LB, m);
        Intersection(LA, LB);
        PrintList(LA);
        count++;
        if (count == 2) {
            break;
        }
    }
		cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
    return 0;
}
