#define _USE_MATH_DEFINES
#include "Evaluator.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;
string expression = "";

// Add input
void addInput(const string& input) 
{
    expression += input;
}

// Clear expression
void clearExpression() 
{
    expression = "";
}

// Delete last character
void deleteLast() 
{
    if (!expression.empty()) expression.pop_back();
}

// Display expression
void displayExpression() 
{
    cout << "Current Expression: " << (expression.empty() ? "0" : expression) << endl;
}

// Operator precedence
bool precedence(const string& topOfStack, const string& current) {
    if (topOfStack == "sin" || topOfStack == "cos" || topOfStack == "tan" ||
        topOfStack == "log" || topOfStack == "ln" || topOfStack == "sqrt")
        return true;

    if (current == "sin" || current == "cos" || current == "tan" ||
        current == "log" || current == "ln" || current == "sqrt")
        return false;

    if (topOfStack == "(" && current == ")") return false;
    if (current == ")" && topOfStack != "(") return true;
    if (current == "(") return false;
    if (topOfStack == "(" && current != ")") return false;

    int topPrec = 0, currPrec = 0;
    if (topOfStack == "^") topPrec = 11;
    else if (topOfStack == "*" || topOfStack == "/" || topOfStack == "mod") topPrec = 10;
    else if (topOfStack == "+" || topOfStack == "-") topPrec = 9;
    else if (topOfStack == "=") topPrec = 3;

    if (current == "^") currPrec = 11;
    else if (current == "*" || current == "/" || current == "mod") currPrec = 10;
    else if (current == "+" || current == "-") currPrec = 9;
    else if (current == "=") currPrec = 3;

    if (topPrec > currPrec) return true;
    else if (topPrec == currPrec) return (current == "^") ? false : true;
    else return false;
}

bool isAlpha(const char a) { return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')); }
bool isOperator(const char c) { return (c == '-' || c == '+' || c == '*' || c == '/' || c == '^'); }

// Solve functions
double solveFunc(string f, double op) {
    if (f == "sin") return sin(op * M_PI / 180.0);
    else if (f == "cos") return cos(op * M_PI / 180.0);
    else if (f == "tan") return tan(op * M_PI / 180.0);
    else if (f == "asin") return asin(op) * 180.0 / M_PI;
    else if (f == "acos") return acos(op) * 180.0 / M_PI;
    else if (f == "atan") return atan(op) * 180.0 / M_PI;
    else if (f == "log10") return log10(op);
    else if (f == "abs") return abs(op);
    else if (f == "exp") return exp(op);
    else if (f == "ln") return log(op);
    else return sqrt(op);
}

double solve(string c, double op1, double op2) {
    if (c == "+") return op1 + op2;
    else if (c == "-") return op1 - op2;
    else if (c == "*") return op1 * op2;
    else if (c == "/") return op2 == 0 ? 0 : op1 / op2;
    else if (c == "^") return pow(op1, op2);
    else return fmod(op1, op2);
}

// Evaluate expression
double evaluate(const string& infix)
{
    string x = infix;
    stack<double> operand;
    stack<string> operators;
    int i = 0;

    while (i < x.length()) {
        if (isspace(x[i])) { i++; continue; }

        if (isdigit(x[i]) || x[i] == '.') {
            string num;
            while (i < x.length() && (isdigit(x[i]) || x[i] == '.'))
                num += x[i++];
            operand.push(stod(num));
            continue;
        }

        if (isAlpha(x[i])) {
            string func;
            while (i < x.length() && isAlpha(x[i]))
                func += x[i++];
            operators.push(func);
            continue;
        }

        if (isOperator(x[i]) || (x[i] == 'm' && x.substr(i, 3) == "mod")) {
            string op;
            if (x[i] == 'm' && x.substr(i, 3) == "mod") { op = "mod"; i += 3; }
            else { op = string(1, x[i]); i++; }

            if (op == "-" && (i == 1 || x[i - 2] == '(' || isOperator(x[i - 2]))) operand.push(0);

            while (!operators.empty() && precedence(operators.top(), op)) {
                string topOp = operators.top(); operators.pop();
                if (topOp == "sin" || topOp == "cos" || topOp == "tan" || topOp == "asin" || topOp == "acos" ||
                    topOp == "atan" || topOp == "log10" || topOp == "ln" || topOp == "abs" || topOp == "exp" || topOp == "sqrt") {
                    double val = operand.top(); operand.pop();
                    operand.push(solveFunc(topOp, val));
                }
                else {
                    double b = operand.top(); operand.pop();
                    double a = operand.top(); operand.pop();
                    operand.push(solve(topOp, a, b));
                }
            }
            operators.push(op);
            continue;
        }

        if (x[i] == '(') { operators.push("("); i++; continue; }

        if (x[i] == ')') {
            while (!operators.empty() && operators.top() != "(") {
                string topOp = operators.top(); operators.pop();
                if (topOp == "sin" || topOp == "cos" || topOp == "tan" || topOp == "asin" || topOp == "acos" ||
                    topOp == "atan" || topOp == "log10" || topOp == "ln" || topOp == "sqrt" || topOp == "abs" || topOp == "exp") {
                    double val = operand.top(); operand.pop();
                    operand.push(solveFunc(topOp, val));
                }
                else {
                    double b = operand.top(); operand.pop();
                    double a = operand.top(); operand.pop();
                    operand.push(solve(topOp, a, b));
                }
            }
            if (!operators.empty()) operators.pop();
            if (!operators.empty()) {
                string topOp = operators.top();
                if (topOp == "sin" || topOp == "cos" || topOp == "tan" || topOp == "asin" || topOp == "acos" ||
                    topOp == "atan" || topOp == "log10" || topOp == "ln" || topOp == "abs" || topOp == "exp" || topOp == "sqrt") {
                    operators.pop();
                    double val = operand.top(); operand.pop();
                    operand.push(solveFunc(topOp, val));
                }
            }
            i++;
            continue;
        }

        i++;
    }

    while (!operators.empty()) {
        string topOp = operators.top(); operators.pop();
        if (topOp == "sin" || topOp == "cos" || topOp == "tan" || topOp == "asin" || topOp == "acos" ||
            topOp == "atan" || topOp == "log10" || topOp == "ln" || topOp == "sqrt" || topOp == "abs" || topOp == "exp") {
            double val = operand.top(); operand.pop();
            operand.push(solveFunc(topOp, val));
        }
        else {
            double b = operand.top(); operand.pop();
            double a = operand.top(); operand.pop();
            operand.push(solve(topOp, a, b));
        }
        // return operand.empty() ? 0 : operand.top();
    }
}
