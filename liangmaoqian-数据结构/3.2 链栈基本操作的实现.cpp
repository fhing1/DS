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
	void Push(DataType x);//入栈
	DataType Pop();//出栈，将栈顶元素出栈
	DataType GetTop();//取栈顶元素（并不删除）
	int empty();
private:
	Node<DataType>* top;
}; 
template<typename DataType>
void LinkStack<DataType>::Push(DataType x) {//入栈
	Node<DataType>* s = nullptr;
	s = new Node<DataType>;s->data = x;
	s->next = top;top = s;//将s插在栈顶
}
template<typename DataType>
DataType LinkStack<DataType>::Pop() {//出栈
	Node<DataType>* p = nullptr;
	DataType x;
	if (top == nullptr)throw "下溢";
	x = top->data;p = top;
	top = top->next;
	delete p;
	return x;
}
template<typename DataType>
DataType LinkStack<DataType>::GetTop() {//取栈
	return top->data;
}
template<typename DataType>
int LinkStack<DataType>::empty() {
	if (top == nullptr)
		cout << "栈空了";
}
template<typename DataType>
LinkStack<DataType>::LinkStack() {//构造函数
	top = new Node<DataType>;
	top->next = nullptr;
}
template<typename DataType>
LinkStack<DataType>::~LinkStack() {//析构函数
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
	cout << "入栈的数据："<<endl;
	cout << "6" << "入栈" << endl;
	s.Push(6);
	cout << "7" << "入栈" << endl;
	s.Push(7);
	cout << "4" << "入栈" << endl;
	s.Push(4);
	cout << "9" << "入栈" << endl;
	s.Push(9);
	cout << "5" << "入栈" << endl;
	s.Push(5);
	cout << "栈顶元素为:" <<endl;
	cout << s.GetTop() << endl;
	cout << "栈顶出栈后新的栈顶元素为:"<<endl;
	s.Pop();
	cout << s.GetTop();
 cout<<endl<<"完成人：22网工李浩冉"<<endl;
}
