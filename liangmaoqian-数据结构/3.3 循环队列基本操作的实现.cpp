#include<iostream>
using namespace std;

const int queuesize = 100;
template<typename datatype>
class cirqueue {
public:
	cirqueue();
	~cirqueue();
	void enqueue(datatype x);//���
	datatype dequeue();//����
	datatype gethead();//ȡ��ͷ����ɾ��
	int countnum();//����
	int empty();
	int count=0;
private:
	datatype data[queuesize];
	int front, rear;
};
template<typename datatype>
cirqueue<datatype>::cirqueue() {//���캯��
	rear = front = queuesize - 1;
}
template<typename datatype>
cirqueue<datatype>::~cirqueue() {}//���е���������Ϊ��

template<typename datatype>
void cirqueue<datatype>::enqueue(datatype x){//���
	if ((rear + 1) % queuesize == front)throw"����";
	rear = (rear + 1) % queuesize;
	data[rear] = x;//��λ����Ԫ��
	count++;
}

template<typename datatype>
datatype cirqueue<datatype>::dequeue() {//����
	if (rear == front)throw"����";
	front = (front + 1) % queuesize;
	count--;
	return data[(front + 1) % queuesize];
	
}
template<typename datatype>
datatype cirqueue<datatype>::gethead() {
	if (rear == front)throw"����";
	return data[(front + 1) % queuesize];
}
template<typename datatype>
int cirqueue<datatype>::empty() {
	if (front == rear)return 0;
}
template<typename datatype>
int cirqueue<datatype>::countnum() {
	return count;
}
int main()
{
	int x;
	cirqueue<int>q{};
	cout << "��ʼ����Ϊ��"<<endl;
	cout << 5 << "���" << endl;
	q.enqueue(5);
	cout << 4 << "���" << endl;
	q.enqueue(4);
	cout << 7 << "���" << endl;
	q.enqueue(7);
	cout << 9 << "���" << endl;
	q.enqueue(9);
	cout << 11 << "���" << endl;
	q.enqueue(11);
	cout << 6 << "���" << endl;
	q.enqueue(6);
	cout << "��ͷԪ��Ϊ:" << endl;
	cout<<q.gethead() << endl;
	x=q.gethead();
	q.dequeue();
	cout << "����Ԫ��Ϊ"<<x<<endl;
	cout << "����Ԫ�ظ���Ϊ��" <<q.countnum()<< endl;
	cout << "��ͷ���к��µĶ�ͷԪ��Ϊ:" <<endl;
	cout << q.gethead() << endl;
	cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
}
