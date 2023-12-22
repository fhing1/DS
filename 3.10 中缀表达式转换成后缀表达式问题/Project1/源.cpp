#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string expression) {
    stack<char> opStack;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            while (i < expression.length() && isdigit(expression[i])) {
                postfix += expression[i];
                i++;
            }
            postfix += " ";
            i--;
        }
        else if (expression[i] == '(') {
            opStack.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.pop();  // ����������
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(expression[i])) {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.push(expression[i]);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += " ";
        opStack.pop();
    }

    return postfix;
}

int main() {
    string expression; //"(89-60)*(12-8)";
    cout << "��������׺���ʽ:" << endl;
    cin >> expression;
    string postfix = infixToPostfix(expression);
    cout << "��׺���ʽ��Ӧ�ĺ�׺���ʽΪ: " << postfix << endl;
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
