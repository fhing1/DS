//���ַ���ƥ���㷨��ʱ�临�Ӷ�O(mn))
#include <iostream>
#include <string.h>
using namespace std;

int Index(string S, string T) {
	int i = 1, j = 1;
	while (i <= S.length() && j <= T.length()) {
		if (S[i] == T[j]) {//�����ȽϺ����ַ� 
			++i;
			++j;
		}
		else {
			i = i - j + 2;//ָ��������¿�ʼƥ�� 
			j = 1;
		}
	}
	if (j > T.length())
		return i - T.length();
	else return 0;
}

int main() {
	string S = "ababcabcac";
	cout << "�����ı��ַ�����"<<endl;
	cout << S << endl;
	string T = "abcac";
	cout << "Ҫƥ���ģʽ�ַ�����" << endl;
	cout << T<<endl;
	cout << Index(S, T);
 cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
	return 0;
}
