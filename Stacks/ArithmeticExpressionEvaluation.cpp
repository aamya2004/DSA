/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where ‘N’ is the length of the given string ‘expression’.
*/

#include <stack>

bool isLowerPrecedence(char ops1, char ops2) 
{

    // Check whether ops1 has lower precedence than ops2.
    if ((ops1 == '+' || ops1 == '-') && (ops2 == '*' || ops2 == '/')) 
    {
        return true;
    }
    return false;
}

int evaluateArithmeticExpression(string & expression) 
{
    stack < char > stk;
    string postfixExp = "", operand = "";

    // Convert given infix expression to postfix/ Reverse Polish Notation.
    for (int i = 0; i < expression.length(); i++) 
    {
        if (expression[i] >= '0' && expression[i] <= '9') 
        {

            // Append digit to operand.
            operand += expression[i];
            continue;
        }

        if (operand != "") 
        {

            // Append operand in string 'postfix' 
            postfixExp += operand;
            postfixExp += ' ';
            operand = "";
        }

        if (expression[i] == '(') 
        {

            // Push opening bracket
            stk.push('(');
        } 
        
        else if (expression[i] == ')') 
        {

            // Append operators between current paranthesis pair in string postfixExp and discard paranthesis.
            while (stk.top() != '(') 
            {
                postfixExp += stk.top();
                stk.pop();
            }
            stk.pop();
        } 
        
        else 
        {
            while (stk.top() != '(' && isLowerPrecedence(expression[i], stk.top()) == false) 
            {

                // Pop operator with greater or equal precedence.
                postfixExp += stk.top();
                stk.pop();
            }

            // Add operator to top of stack.
            stk.push(expression[i]);
        }
    }

    stack < int > values;
    operand = "";

    // Evaluating equivalent postfix expression.
    for (int i = 0; i < postfixExp.length(); i++) 
    {
        if (postfixExp[i] >= '0' && postfixExp[i] <= '9') 
        {

            // Append digit to operand.
            operand += postfixExp[i];
        } 
        
        else if (postfixExp[i] == ' ') 
        {

            // Push operand in stack 'values'.
            values.push(stoi(operand));
            operand = "";
        } 
        
        else 
        {

            // Pop two operand and push their result after applying operator back to the stack 'values'.
            int operand2 = values.top();
            values.pop();
            int operand1 = values.top();
            values.pop();

            if (postfixExp[i] == '+') 
            {
                values.push(operand1 + operand2);
            }
            
            if (postfixExp[i] == '-') 
            {
                values.push(operand1 - operand2);
            }
            
            if (postfixExp[i] == '*') 
            {
                values.push(operand1 * operand2);
            }
            
            if (postfixExp[i] == '/') 
            {
                values.push(operand1 / operand2);
            }
        }
    }

    // Result of Expression
    return values.top();
}