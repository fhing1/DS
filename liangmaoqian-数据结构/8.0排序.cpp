#include<iostream>
#include<cmath>
using namespace std;


class Sort
{
public:
    Sort(int r[], int n);                     //���캯�������ɴ���������
    ~Sort();                                  //��������
    void InsertSort();                        //ֱ�Ӳ�������
    void ShellSort();                         //ϣ������
    void BubbleSort();                        //��������
    void QuickSort(int first, int last);      //��������
    void SelectSort();                        //��ѡ������
    void HeapSort();                          //������
    void MergeSort2();                        //��·�鲢�ǵݹ�����
    void Print();                             //�������
private:
    int Partition(int first, int last);       //��������һ�λ���
    void Sift(int k, int last);               //�����򣬶ѵ���
    void Merge(int first1, int last1, int last2);    //�鲢���򣬺ϲ�������������
    void MergePass(int h);                    //�鲢����һ�˹鲢
    int* data;                                //����������
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


void Sort::InsertSort()                         //ֱ�Ӳ�������
{
    int i, j, temp;
    for (i = 1;i < length;i++)                       //�������length-1��
    {
        temp = data[i];                           //�ݴ�����¼
        for (j = i - 1;j >= 0 && temp < data[j];j--)       //Ѱ�Ҳ���λ��
            data[j + 1] = data[j];
        data[j + 1] = temp;
    }
}


void Sort::ShellSort()                           //ϣ������
{
    int d, i, j, temp;
    for (d = length / 2;d >= 1;d = d / 2)                   //����Ϊd����ֱ�Ӳ�������
    {
        for (i = d;i < length;i++)                    //����һ��ϣ������
        {
            temp = data[i];                    //�ݴ����������
            for (j = i - d;j >= 0 && temp < data[j];j = j - d)
                data[j + d] == data[j];          //��¼����d��λ��
            data[j + d] = temp;
        }
    }
}


void Sort::BubbleSort()                           //��������
{
    int j, exchange, bound, temp;
    exchange = length - 1;                            //��һ�����������������[0~length-1]
    while (exchange != 0)
    {
        bound = exchange;exchange = 0;
        for (j = 0;j < bound;j++)                      //һ�����������������[0~bound]
            if (data[j] > data[j + 1])
            {
                temp = data[j];data[j] = data[j + 1];data[j + 1] = temp;
                exchange = j;                           //��¼ÿһ�μ�¼������λ��
            }
    }
}


int Sort::Partition(int first, int last)           //��������һ�λ���
{
    int i = first, j = last, temp;                      //��ʼ��һ�λ��ֵ�����
    while (i < j)
    {
        while (i < j && data[i] <= data[j])j--;         //�Ҳ�ɨ��
        if (i < j)
        {
            temp = data[i];data[i] = data[j];data[j] = temp;
            i++;
        }
        while (i < j && data[i] <= data[j])i++;          //���ɨ��
        if (i < j)
        {
            temp = data[i];data[i] = data[j];data[j] = temp;
            j--;
        }
    }
    return i;                                      //iΪ��ֵ��¼������λ��
}


void Sort::QuickSort(int first, int last)           //��������
{
    if (first >= last)return;                         //���䳤��Ϊ1���ݹ����
    else
    {
        int pivot = Partition(first, last);            //һ�λ���
        QuickSort(first, pivot - 1);                   //����������н��п�������
        QuickSort(pivot + 1, last);                    //���Ҳ������н��п�������
    }
}


void Sort::SelectSort()                              //��ѡ������
{
    int i, j, index, temp;
    for (i = 0;i < length - 1;i++)                          //����length-1�˼�ѡ������
    {
        index = i;
        for (j = i + 1;j < length;j++)                      //����������ѡȡ��С��¼
            if (data[j] < data[index])index = j;
        if (index != i)
        {
            temp = data[i];data[i] = data[index];data[index] = temp;
        }
    }
}


void Sort::Sift(int k, int last)                     //�����򣬶ѵ���
{
    int i, j, temp;
    i = k;j = 2 * i + 1;                                    //i�Ǳ������ڵ㣬j��i������
    while (j <= last)                                 //��û�н��е�Ҷ��
    {
        if (j < last && data[i] < data[j + 1])j++;           //jָ�����Һ��ӵĽϴ���
        if (data[i] > data[j])break;                  //�Ѿ��Ƕ�
        else
        {
            temp = data[i];data[i] = data[j];data[j] = temp;
            i = j;j = 2 * i + 1;                            //���������λ�ڽ��j��λ��
        }
    }
}


void Sort::HeapSort()                               //������
{
    int i, temp;
    for (i = ceil(length / 2) - 1;i >= 0;i--)                //�����һ����֧�ڵ������ڵ����
        Sift(i, length - 1);
    for (i = 1;i < length;i++)
    {
        temp = data[0];data[0] = data[length - i];data[length - i] = temp;
        Sift(0, length - i - 1);                          //�ؽ���
    }
}


void Sort::Merge(int first1, int last1, int last2)    //�鲢���򣬺ϲ�������������
{
    int* temp = new int[length];                      //����temp��Ϊ�ϲ��ĸ����ռ�
    int i = first1, j = last1 + 1, k = first1;
    while (i <= last1 && j <= last2)
    {
        if (data[i] <= data[j])temp[k++] = data[i++];
        else temp[k++] = data[j++];
    }
}


void Sort::MergePass(int h)                         //�鲢����һ�˹鲢
{
    int i = 0;
    while (i + 2 * h <= length)                            //����������Ϊh��������
    {
        Merge(i, i + h - 1, i + 2 * h - 1);
        i = i + 2 * h;
    }
    if (i + h < length)                                  //����������һ������С��h
        Merge(i, i + h - 1, length - 1);
}


void Sort::MergeSort2()                            //��·�鲢�ǵݹ�����
{
    int h = 1;                                       //��ʼʱ�����г���Ϊ1
    while (h < length)
    {
        MergePass(h);                              //һ�˲�������
        h = 2 * h;
    }
}


int main()
{
    int select, r[10] = { 2,5,1,7,9,4,3,6,5,8, };
    Sort L{ r,10 };
    cout << "ԭ������Ϊ:" << endl;
    for (int i = 0;i<10;i++) {
        cout << r[i]<<"  ";
        if (i == 9)cout << endl;
    }
    cout << "1.ֱ�Ӳ�������          2.ϣ������" << endl;
    cout << "3.��������              4.��������" << endl;
    cout << "5.��ѡ������          6.������" << endl;
    cout << "7.��·�鲢�ǵݹ�����" << endl;
    cout << "������ʹ�õ���������ţ�";
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
    default:cout << "���������Ŵ���" << endl;break;
    }
    L.Print();
	  cout <<endl<< "����ˣ����Ƚ"<<endl;
    return 0;
}
