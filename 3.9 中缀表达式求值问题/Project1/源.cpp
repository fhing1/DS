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

int evaluateExpression(string expression) {
    stack<int> numStack;
    stack<char> opStack;

    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            numStack.push(num);
            i--;
        }
        else if (expression[i] == '(') {
            opStack.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();
                char op = opStack.top();
                opStack.pop();

                int result;
                if (op == '+')
                    result = num1 + num2;
                else if (op == '-')
                    result = num1 - num2;
                else if (op == '*')
                    result = num1 * num2;
                else
                    result = num1 / num2;

                numStack.push(result);
            }
            opStack.pop();  // 弹出左括号
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(expression[i])) {
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();
                char op = opStack.top();
                opStack.pop();

                int result;
                if (op == '+')
                    result = num1 + num2;
                else if (op == '-')
                    result = num1 - num2;
                else if (op == '*')
                    result = num1 * num2;
                else
                    result = num1 / num2;

                numStack.push(result);
            }
            opStack.push(expression[i]);
        }
    }

    while (!opStack.empty()) {
        int num2 = numStack.top();
        numStack.pop();
        int num1 = numStack.top();
        numStack.pop();
        char op = opStack.top();
        opStack.pop();

        int result;
        if (op == '+')
            result = num1 + num2;
        else if (op == '-')
            result = num1 - num2;
        else if (op == '*')
            result = num1 * num2;
        else
            result = num1 / num2;

        numStack.push(result);
    }

    return numStack.top();
}

int main() {
    string expression;
    cin >> expression;
    int result = evaluateExpression(expression);
    cout << "表达式结果为: " << result << endl;
    cout << "完成人:22网工方喜健" << endl;


    return 0;
}
//(89-60)*(12-8)#