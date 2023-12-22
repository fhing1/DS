#include<iostream>
using namespace std;

template<typename DataType>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template<typename DataType>
class LinkStack {
public:
	LinkStack();
	~LinkStack();
	void Push(DataType x);//��ջ
	DataType Pop();//��ջ����ջ��Ԫ�س�ջ
	DataType GetTop();//ȡջ��Ԫ�أ�����ɾ����
	int empty();
private:
	Node<DataType>* top;
}; 
template<typename DataType>
void LinkStack<DataType>::Push(DataType x) {//��ջ
	Node<DataType>* s = nullptr;
	s = new Node<DataType>;s->data = x;
	s->next = top;top = s;//��s����ջ��
}
template<typename DataType>
DataType LinkStack<DataType>::Pop() {//��ջ
	Node<DataType>* p = nullptr;
	DataType x;
	if (top == nullptr)throw "����";
	x = top->data;p = top;
	top = top->next;
	delete p;
	return x;
}
template<typename DataType>
DataType LinkStack<DataType>::GetTop() {//ȡջ
	return top->data;
}
template<typename DataType>
int LinkStack<DataType>::empty() {
	if (top == nullptr)
		cout << "ջ����";
}
template<typename DataType>
LinkStack<DataType>::LinkStack() {//���캯��
	top = new Node<DataType>;
	top->next = nullptr;
}
template<typename DataType>
LinkStack<DataType>::~LinkStack() {//��������
	Node<DataType>* q = nullptr;
	while (top != nullptr) {
		q = top;
		top = top->next;
		delete q;
	}
}
int main() {
	int x;
	LinkStack<int> s{};
	cout << "��ջ�����ݣ�"<<endl;
	cout << "6" << "��ջ" << endl;
	s.Push(6);
	cout << "7" << "��ջ" << endl;
	s.Push(7);
	cout << "4" << "��ջ" << endl;
	s.Push(4);
	cout << "9" << "��ջ" << endl;
	s.Push(9);
	cout << "5" << "��ջ" << endl;
	s.Push(5);
	cout << "ջ��Ԫ��Ϊ:" <<endl;
	cout << s.GetTop() << endl;
	cout << "ջ����ջ���µ�ջ��Ԫ��Ϊ:"<<endl;
	s.Pop();
	cout << s.GetTop();
 cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
}
