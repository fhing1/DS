#include<iostream>
#include<cmath>
using namespace std;


class Sort
{
public:
    Sort(int r[], int n);                     //构造函数，生成待排序序列
    ~Sort();                                  //析构函数
    void InsertSort();                        //直接插入排序
    void ShellSort();                         //希尔排序
    void BubbleSort();                        //起泡排序
    void QuickSort(int first, int last);      //快速排序
    void SelectSort();                        //简单选择排序
    void HeapSort();                          //堆排序
    void MergeSort2();                        //二路归并非递归排序
    void Print();                             //输出排序
private:
    int Partition(int first, int last);       //快速排序，一次划分
    void Sift(int k, int last);               //堆排序，堆调整
    void Merge(int first1, int last1, int last2);    //归并排序，合并相邻有序序列
    void MergePass(int h);                    //归并排序，一趟归并
    int* data;                                //待排序序列
    int length;
};

Sort::Sort(int r[], int n)
{
    data = new int[n];
    for (int i = 0;i < n;i++)
        data[i] = r[i];
    length = n;
}

Sort::~Sort()
{
    delete[] data;
}

void Sort::Print()
{
    for (int i = 0;i < length;i++)
    {
        cout << data[i] << "\t";
        cout << endl;
    }
}


void Sort::InsertSort()                         //直接插入排序
{
    int i, j, temp;
    for (i = 1;i < length;i++)                       //排序进行length-1趟
    {
        temp = data[i];                           //暂存待插记录
        for (j = i - 1;j >= 0 && temp < data[j];j--)       //寻找插入位置
            data[j + 1] = data[j];
        data[j + 1] = temp;
    }
}


void Sort::ShellSort()                           //希尔排序
{
    int d, i, j, temp;
    for (d = length / 2;d >= 1;d = d / 2)                   //增量为d进行直接插入排序
    {
        for (i = d;i < length;i++)                    //进行一趟希尔排序
        {
            temp = data[i];                    //暂存待插入排序
            for (j = i - d;j >= 0 && temp < data[j];j = j - d)
                data[j + d] == data[j];          //记录后移d个位置
            data[j + d] = temp;
        }
    }
}


void Sort::BubbleSort()                           //起泡排序
{
    int j, exchange, bound, temp;
    exchange = length - 1;                            //第一趟起泡排序的区间是[0~length-1]
    while (exchange != 0)
    {
        bound = exchange;exchange = 0;
        for (j = 0;j < bound;j++)                      //一趟起泡排序的区间是[0~bound]
            if (data[j] > data[j + 1])
            {
                temp = data[j];data[j] = data[j + 1];data[j + 1] = temp;
                exchange = j;                           //记录每一次记录交换的位置
            }
    }
}


int Sort::Partition(int first, int last)           //快速排序，一次划分
{
    int i = first, j = last, temp;                      //初始化一次划分的区间
    while (i < j)
    {
        while (i < j && data[i] <= data[j])j--;         //右侧扫描
        if (i < j)
        {
            temp = data[i];data[i] = data[j];data[j] = temp;
            i++;
        }
        while (i < j && data[i] <= data[j])i++;          //左侧扫描
        if (i < j)
        {
            temp = data[i];data[i] = data[j];data[j] = temp;
            j--;
        }
    }
    return i;                                      //i为轴值记录的最终位置
}


void Sort::QuickSort(int first, int last)           //快速排序
{
    if (first >= last)return;                         //区间长度为1，递归结束
    else
    {
        int pivot = Partition(first, last);            //一次划分
        QuickSort(first, pivot - 1);                   //对左侧字序列进行快速排序
        QuickSort(pivot + 1, last);                    //对右侧子序列进行快速排序
    }
}


void Sort::SelectSort()                              //简单选择排序
{
    int i, j, index, temp;
    for (i = 0;i < length - 1;i++)                          //进行length-1趟简单选择排序
    {
        index = i;
        for (j = i + 1;j < length;j++)                      //在无序区中选取最小记录
            if (data[j] < data[index])index = j;
        if (index != i)
        {
            temp = data[i];data[i] = data[index];data[index] = temp;
        }
    }
}


void Sort::Sift(int k, int last)                     //堆排序，堆调整
{
    int i, j, temp;
    i = k;j = 2 * i + 1;                                    //i是被调整节点，j是i的左孩子
    while (j <= last)                                 //还没有进行到叶子
    {
        if (j < last && data[i] < data[j + 1])j++;           //j指向左右孩子的较大者
        if (data[i] > data[j])break;                  //已经是堆
        else
        {
            temp = data[i];data[i] = data[j];data[j] = temp;
            i = j;j = 2 * i + 1;                            //被调整结点位于结点j的位置
        }
    }
}


void Sort::HeapSort()                               //堆排序
{
    int i, temp;
    for (i = ceil(length / 2) - 1;i >= 0;i--)                //从最后一个分支节点至根节点调整
        Sift(i, length - 1);
    for (i = 1;i < length;i++)
    {
        temp = data[0];data[0] = data[length - i];data[length - i] = temp;
        Sift(0, length - i - 1);                          //重建堆
    }
}


void Sort::Merge(int first1, int last1, int last2)    //归并排序，合并相邻有序序列
{
    int* temp = new int[length];                      //数组temp作为合并的辅助空间
    int i = first1, j = last1 + 1, k = first1;
    while (i <= last1 && j <= last2)
    {
        if (data[i] <= data[j])temp[k++] = data[i++];
        else temp[k++] = data[j++];
    }
}


void Sort::MergePass(int h)                         //归并排序，一趟归并
{
    int i = 0;
    while (i + 2 * h <= length)                            //有两个长度为h的子序列
    {
        Merge(i, i + h - 1, i + 2 * h - 1);
        i = i + 2 * h;
    }
    if (i + h < length)                                  //两个子序列一个长度小于h
        Merge(i, i + h - 1, length - 1);
}


void Sort::MergeSort2()                            //二路归并非递归排序
{
    int h = 1;                                       //初始时子序列长度为1
    while (h < length)
    {
        MergePass(h);                              //一趟并归排序
        h = 2 * h;
    }
}


int main()
{
    int select, r[10] = { 2,5,1,7,9,4,3,6,5,8, };
    Sort L{ r,10 };
    cout << "原有数据为:" << endl;
    for (int i = 0;i<10;i++) {
        cout << r[i]<<"  ";
        if (i == 9)cout << endl;
    }
    cout << "1.直接插入排序          2.希尔排序" << endl;
    cout << "3.起泡排序              4.快速排序" << endl;
    cout << "5.简单选择排序          6.堆排序" << endl;
    cout << "7.二路归并非递归排序" << endl;
    cout << "请输入使用的排序技术编号：";
    cin >> select;
    switch (select)
    {
    case 1:
        L.InsertSort();
        break;
    case 2:
        L.ShellSort();
        break;
    case 3:
        L.BubbleSort();
        break;
    case 4:
        L.QuickSort(0, 9);
        break;
    case 5:
        L.SelectSort();
        break;
    case 6:
        L.HeapSort();
        break;
    case 7:
        L.MergeSort2();
        break;
    default:cout << "输入排序编号错误" << endl;break;
    }
    L.Print();
	  cout <<endl<< "完成人：李浩冉"<<endl;
    return 0;
}
