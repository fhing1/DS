#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
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
{//打印依次输出链表中的数据
    L = L->next;   
    cout << "两个集合中相同元素是:";
    while (L) {
        if (L->next != NULL) cout << L->data << " ";
        else cout << L->data;
        L = L->next;
    }

    cout << endl;
}
void Intersection(LinkList& LA, LinkList& LB)
{//求基于链表的两个集合的交集
/**************begin************/
    LinkList pa, pb, p;
    pa = LA->next;
    pb = LB->next;
    p = LA;
    while (pa && pb) {
        if (pa->data == pb->data) {
            p->next = pa;
            p = p->next;//p移动到新插入结点位置
            pa = pa->next;//pa和pb均向后移动
            pb = pb->next;
        }
        else if (pa->data > pb->data) {
            pb = pb->next;
        }
        else {
            pa = pa->next;
        }
    }
    p->next = NULL;//此时其一已结束,置空p结点的next
    /**************end************/
}
int main()
{
    int n, m,count=0;
    cout << "请输入两个集合中元素的个数，中间用空格分开："<<endl;
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
		cout<<endl<<"完成人：22网工李浩冉"<<endl;
    return 0;
}
