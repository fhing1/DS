#include<iostream>
#include <iomanip>//这个头文件是声明一些 “流操作符”的
//比较常用的有:setw(int);//设置显示宽度，left//right//设置左右对齐。 setprecision(int);//设置浮点数的精确度。
using namespace std;
// 哈夫曼树的结点结构
struct element
{
    int weight;        // 权值域
    int lchild, rchild, parent;  // 该结点的左、右、双亲结点在数组中的下标
};
// 选取权值最小的两个结点
void selectMin(element a[], int n, int& s1, int& s2)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].parent == -1)// 初始化s1,s1的双亲为-1
        {
            s1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)// s1为权值最小的下标
    {
        if (a[i].parent == -1 && a[s1].weight > a[i].weight)
            s1 = i;
    }
    for (int j = 0; j < n; j++)
    {
        if (a[j].parent == -1 && j != s1)// 初始化s2,s2的双亲为-1
        {
            s2 = j;
            break;
        }
    }
    for (int j = 0; j < n; j++)// s2为另一个权值最小的结点
    {
        if (a[j].parent == -1 && a[s2].weight > a[j].weight && j != s1)
            s2 = j;
    }
}
// 哈夫曼算法
// n个叶子结点的权值保存在数组w中
void HuffmanTree(element huftree[], int w[], int n)
{
    for (int i = 0; i < 2 * n - 1; i++)    // 初始化，所有结点均没有双亲和孩子
    {
        huftree[i].parent = -1;
        huftree[i].lchild = -1;
        huftree[i].rchild = -1;
    }
    for (int i = 0; i < n; i++)    // 构造只有根节点的n棵二叉树
    {
        huftree[i].weight = w[i];
    }
    for (int k = n; k < 2 * n - 1; k++) // n-1次合并
    {
        int i1, i2;
        selectMin(huftree, k, i1, i2); // 查找权值最小的俩个根节点，下标为i1,i2
        // 将i1，i2合并，且i1和i2的双亲为k
        huftree[i1].parent = k;
        huftree[i2].parent = k;
        huftree[k].lchild = i1;
        huftree[k].rchild = i2;
        huftree[k].weight = huftree[i1].weight + huftree[i2].weight;
    }

}// 打印哈夫曼树
void print(element hT[], int n)
{
    cout << "index weight parent lChild rChild" << endl;
    cout << left;    // 左对齐输出
    for (int i = 0; i < n; ++i)
    {
        cout << setw(5) << i << " ";
        cout << setw(6) << hT[i].weight << " ";
        cout << setw(6) << hT[i].parent << " ";
        cout << setw(6) << hT[i].lchild << " ";
        cout << setw(6) << hT[i].rchild << endl;
    }
}
int main()
{
    int x[] = { 5,29,7,8,14,23,3,11 };        // 权值集合
    element* hufftree = new element[2 * 8 - 1];    // 动态创建数组
    HuffmanTree(hufftree, x, 8);
    print(hufftree, 15);
	cout << "完成人:22网工方喜健" << endl;
    system("pause");
	
    return 0;
    
}