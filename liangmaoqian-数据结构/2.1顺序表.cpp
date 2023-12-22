#include<iostream>
using namespace std;

const int MaxSize = 100;
template <typename DataType>
class SeqList
{
public:
	//SeqList();//建立空的顺序表
	SeqList(DataType a[], int n);//建立长度为n的顺序表
	//~SeqList();//析构函数
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	//int Empty();
	void PrintList();//遍历操作
private:
	DataType data[MaxSize];
	int length;
};
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {//建立长度为n的顺序表 定义
	if (n > MaxSize)throw"参数非法";
	for (int i = 0;i < n;i++) {
		data[i] = a[i];
	}
	length = n;
}

template <typename DataType>
void SeqList<DataType>::PrintList() {//遍历操作
	for (int i = 0;i < length;i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}
template <typename DataType>
DataType SeqList<DataType>::Get(int i) {//按位查找
	if (i<1 || i>length)throw"查找位置非法";
	else return data[i - 1];
}

template <typename DataType>
int SeqList<DataType>::Locate(DataType x){//按值查找
	for (int i = 0;i < length;i++) 
		if (data[i] == x)return i + 1;
	return 0;
}
template <typename DataType>
int SeqList<DataType>::Length(){//求表长
	return length;
}
template <typename DataType>
void SeqList<DataType>::Insert(int i,DataType x) {//插入元素
	if (length == MaxSize)throw"上溢";
	if (i<1 || i>length)throw"插入位置错误";
	for (int j = length;j >= i;j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}
template<typename DataType>
DataType SeqList<DataType>::Delete(int i)//删除操作
{
	DataType x;
	if (length == 0)throw"下溢";
	if (i<1 || i>length)throw"删除位置错误";
	x = data[i - 1];//取出被删除的元素赋值给x
	for (int j = i;j < length;j++)
		data[j - 1] = data[j];
	length--;
	return x;
}


int main() {
	int r[5] = { 1,2,3,4,5 }, i, x;
	SeqList<int>L{ r,5 };
	cout << "当前线性表数据为:";
	L.PrintList();
	try 
	{
		L.Insert(2, 8);
		cout << "执行插入操作后数据为:";
		L.PrintList();
		cout <<"并且表长为" << L.Length()<<endl;
	}catch (char* str) { cout << str << endl; }
	cout << "请输入你要查找的位数(第几位):";
	cin >> i;
	cout << "第" << i << "位为"<< L.Get(i)<<endl;
	cout << "请输入你要查找的数值(是多少):";
	cin >> x;
	cout << "值" << x << "为第" << L.Locate(x) << "位"<<endl;
	cout << "请选择你要删除的位数(第几位):";
	cin >> i;
	cout << "删除 " << L.Delete(i) << "后的数据为:";
	L.PrintList();
	cout << endl;
	cout << "完成人：22网工李浩冉";
}
