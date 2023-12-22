#include<iostream>
using namespace std;

const int queuesize = 100;
template<typename datatype>
class cirqueue {
public:
	cirqueue();
	~cirqueue();
	void enqueue(datatype x);//入队
	datatype dequeue();//出队
	datatype gethead();//取队头但不删除
	int countnum();//计数
	int empty();
	int count=0;
private:
	datatype data[queuesize];
	int front, rear;
};
template<typename datatype>
cirqueue<datatype>::cirqueue() {//构造函数
	rear = front = queuesize - 1;
}
template<typename datatype>
cirqueue<datatype>::~cirqueue() {}//队列的析构函数为空

template<typename datatype>
void cirqueue<datatype>::enqueue(datatype x){//入队
	if ((rear + 1) % queuesize == front)throw"上溢";
	rear = (rear + 1) % queuesize;
	data[rear] = x;//队位插入元素
	count++;
}

template<typename datatype>
datatype cirqueue<datatype>::dequeue() {//出队
	if (rear == front)throw"下溢";
	front = (front + 1) % queuesize;
	count--;
	return data[(front + 1) % queuesize];
	
}
template<typename datatype>
datatype cirqueue<datatype>::gethead() {
	if (rear == front)throw"下溢";
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
	cout << "初始队列为空"<<endl;
	cout << 5 << "入队" << endl;
	q.enqueue(5);
	cout << 4 << "入队" << endl;
	q.enqueue(4);
	cout << 7 << "入队" << endl;
	q.enqueue(7);
	cout << 9 << "入队" << endl;
	q.enqueue(9);
	cout << 11 << "入队" << endl;
	q.enqueue(11);
	cout << 6 << "入队" << endl;
	q.enqueue(6);
	cout << "队头元素为:" << endl;
	cout<<q.gethead() << endl;
	x=q.gethead();
	q.dequeue();
	cout << "出队元素为"<<x<<endl;
	cout << "现在元素个数为：" <<q.countnum()<< endl;
	cout << "队头出列后新的队头元素为:" <<endl;
	cout << q.gethead() << endl;
	cout<<endl<<"完成人：22网工李浩冉"<<endl;
}
