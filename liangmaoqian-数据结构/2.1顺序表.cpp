#include<iostream>
using namespace std;

const int MaxSize = 100;
template <typename DataType>
class SeqList
{
public:
	//SeqList();//�����յ�˳���
	SeqList(DataType a[], int n);//��������Ϊn��˳���
	//~SeqList();//��������
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	//int Empty();
	void PrintList();//��������
private:
	DataType data[MaxSize];
	int length;
};
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {//��������Ϊn��˳��� ����
	if (n > MaxSize)throw"�����Ƿ�";
	for (int i = 0;i < n;i++) {
		data[i] = a[i];
	}
	length = n;
}

template <typename DataType>
void SeqList<DataType>::PrintList() {//��������
	for (int i = 0;i < length;i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}
template <typename DataType>
DataType SeqList<DataType>::Get(int i) {//��λ����
	if (i<1 || i>length)throw"����λ�÷Ƿ�";
	else return data[i - 1];
}

template <typename DataType>
int SeqList<DataType>::Locate(DataType x){//��ֵ����
	for (int i = 0;i < length;i++) 
		if (data[i] == x)return i + 1;
	return 0;
}
template <typename DataType>
int SeqList<DataType>::Length(){//���
	return length;
}
template <typename DataType>
void SeqList<DataType>::Insert(int i,DataType x) {//����Ԫ��
	if (length == MaxSize)throw"����";
	if (i<1 || i>length)throw"����λ�ô���";
	for (int j = length;j >= i;j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}
template<typename DataType>
DataType SeqList<DataType>::Delete(int i)//ɾ������
{
	DataType x;
	if (length == 0)throw"����";
	if (i<1 || i>length)throw"ɾ��λ�ô���";
	x = data[i - 1];//ȡ����ɾ����Ԫ�ظ�ֵ��x
	for (int j = i;j < length;j++)
		data[j - 1] = data[j];
	length--;
	return x;
}


int main() {
	int r[5] = { 1,2,3,4,5 }, i, x;
	SeqList<int>L{ r,5 };
	cout << "��ǰ���Ա�����Ϊ:";
	L.PrintList();
	try 
	{
		L.Insert(2, 8);
		cout << "ִ�в������������Ϊ:";
		L.PrintList();
		cout <<"���ұ�Ϊ" << L.Length()<<endl;
	}catch (char* str) { cout << str << endl; }
	cout << "��������Ҫ���ҵ�λ��(�ڼ�λ):";
	cin >> i;
	cout << "��" << i << "λΪ"<< L.Get(i)<<endl;
	cout << "��������Ҫ���ҵ���ֵ(�Ƕ���):";
	cin >> x;
	cout << "ֵ" << x << "Ϊ��" << L.Locate(x) << "λ"<<endl;
	cout << "��ѡ����Ҫɾ����λ��(�ڼ�λ):";
	cin >> i;
	cout << "ɾ�� " << L.Delete(i) << "�������Ϊ:";
	L.PrintList();
	cout << endl;
	cout << "����ˣ�22�������Ƚ";
}
