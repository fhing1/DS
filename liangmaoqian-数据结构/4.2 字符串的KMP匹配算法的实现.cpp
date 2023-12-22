//简单字符串匹配算法（时间复杂度O(mn))
#include <iostream>
#include <string.h>
using namespace std;

int Index(string S, string T) {
	int i = 1, j = 1;
	while (i <= S.length() && j <= T.length()) {
		if (S[i] == T[j]) {//继续比较后续字符 
			++i;
			++j;
		}
		else {
			i = i - j + 2;//指针回退重新开始匹配 
			j = 1;
		}
	}
	if (j > T.length())
		return i - T.length();
	else return 0;
}

int main() {
	string S = "ababcabcac";
	cout << "输入文本字符串："<<endl;
	cout << S << endl;
	string T = "abcac";
	cout << "要匹配的模式字符串：" << endl;
	cout << T<<endl;
	cout << Index(S, T);
 cout<<endl<<"完成人：22网工李浩冉"<<endl;
	return 0;
}
