#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>

double evaluate(const std::string& infix);
void addInput(const std::string& input);
void clearExpression();
void deleteLast();
void displayExpression();
bool precedence(const std::string& topOfStack, const std::string& current);
bool isAlpha(const char a);
bool isOperator(const char c);
double solveFunc(std::string f, double op);
double solve(std::string c, double op1, double op2);

extern std::string expression;
#endif