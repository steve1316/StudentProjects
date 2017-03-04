/////////////////////////////////////////
//                                     //
// Name: Steve Tu                      //
// Partner Name: Peter Shin            //
// Date: 02/18/17                      //
//                                     //
//                                     //
/////////////////////////////////////////

#include <iostream>
#include <string>
#include "Stack.h"
#include "Node.h"

int main()
{
	std::string infix = "";
	std::string postfix = "";
	std::cout << "-------------------------------------------------------------------\n";
	std::cout << "\n\t\tInfix to Postfix Evaluation Program\n";
	std::cout << "\n-------------------------------------------------------------------";
	std::cout << "\nPlease enter infix expression and any whitespaces you need: ";
	getline(std::cin, infix);

	Stack<char> opStack(new Node<char>());
	Stack<int> valStack(new Node<int>());

	// clears out the stacks in order to get them ready for operations.
	opStack.clear();
	valStack.clear();

	// Parsing out the operands and operators into valStack and opStack.
	for (int i = 0; i < infix.length(); i++)
	{
		switch (infix[i]) // look through each char in the string to parse out each number and operator.
		{
		case ' ': // skips whitespace and if whitespace was at end of expression, append remaining operators to postfix string.
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '0':
			// If char i is number 0
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '1':
			// If char i is number 1
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '2':
			// If char i is number 2
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '3':
			// If char i is number 3
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '4':
			// If char i is number 4
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '5':
			// If char i is number 5
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '6':
			// If char i is number 6
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '7':
			// If char i is number 7
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '8':
			// If char i is number 8
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '9':
			// If char i is number 9
			valStack.push(infix[i] - '0');
			postfix += infix[i];
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '(':
			// If char i is operator (
			if (opStack.isEmpty())
			{
				opStack.push(infix[i]);
			}
			else if (opStack.precedence(opStack.peek()) > opStack.precedence(infix[i]))
			{
				// if operator at top of stack has higher precedence than i.
				opStack.push(infix[i]); // push ( onto stack.
			}
			else if (opStack.precedence(opStack.peek()) < opStack.precedence(infix[i]))
			{
				// if operator at top of stack has lower precedence than i...
				// append the the operator at top of stack to postfix string and then pop it out of stack.
				postfix += opStack.peek();
				opStack.pop();
				// and then push ( to stack.
				opStack.push(infix[i]);
			}
			break;
		case ')':
			// If char i is operator )
			while (opStack.peek() != '(')
			{
				postfix += opStack.peek();
				opStack.pop(); // pop out all operators until we reach beginning of parentheses
			}
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				if (opStack.peek() == '(')
				{
					opStack.pop(); // removes ( from top of stack and proceed to finalize appending remaining operators to postfix string.
				}
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			else if (opStack.peek() == '(')
			{
				opStack.pop(); // takes care of any remaining ( in stack.
			}
			break;
		case '+':
			// If char i is operator +
			if (opStack.isEmpty())
			{
				opStack.push(infix[i]);
			}
			else if (opStack.precedence(opStack.peek()) > opStack.precedence(infix[i]))
			{
				// if operator at top of stack has higher precedence than i.
				postfix += opStack.peek(); //append the operator at top of stack into postfix string...
				opStack.pop(); //... and then pop it off stack.
				opStack.push(infix[i]); // push new operator onto stack.
			}
			else if (opStack.precedence(opStack.peek()) < opStack.precedence(infix[i]))
			{
				// if operator at top of stack has lower precedence than i.
				opStack.push(infix[i]);
			}
			else
			{
				opStack.push(infix[i]); // push new operator onto stack.
			}
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '-':
			// If char i is operator -
			if (opStack.isEmpty())
			{
				opStack.push(infix[i]);
			}
			else if (opStack.precedence(opStack.peek()) > opStack.precedence(infix[i]))
			{
				// if operator at top of stack has higher precedence than i.
				postfix += opStack.peek(); //append the operator at top of stack into postfix string...
				opStack.pop(); //... and then pop it off stack.
				opStack.push(infix[i]); // push new operator onto stack.
			}
			else if (opStack.precedence(opStack.peek()) < opStack.precedence(infix[i]))
			{
				// if operator at top of stack has lower precedence than i.
				opStack.push(infix[i]);
			}
			else
			{
				opStack.push(infix[i]); // push new operator onto stack.
			}
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '*':
			// If char i is operator *
			if (opStack.isEmpty())
			{
				opStack.push(infix[i]);
			}
			else if (opStack.precedence(opStack.peek()) > opStack.precedence(infix[i]))
			{
				// if operator at top of stack has higher precedence than i.
				postfix += opStack.peek(); //append the operator at top of stack into postfix string...
				opStack.pop(); //... and then pop it off stack.
				opStack.push(infix[i]); // push new operator onto stack.
			}
			else if (opStack.precedence(opStack.peek()) < opStack.precedence(infix[i]))
			{
				// if operator at top of stack has lower precedence than i.
				opStack.push(infix[i]);
			}
			else
			{
				opStack.push(infix[i]); // push new operator onto stack.
			}
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		case '/':
			// If char i is operator /
			if (opStack.isEmpty())
			{
				opStack.push(infix[i]);
			}
			else if (opStack.precedence(opStack.peek()) > opStack.precedence(infix[i]))
			{
				// if operator at top of stack has higher precedence than i.
				postfix += opStack.peek(); //append the operator at top of stack into postfix string...
				opStack.pop(); //... and then pop it off stack.
				opStack.push(infix[i]); // push new operator onto stack.
			}
			else if (opStack.precedence(opStack.peek()) < opStack.precedence(infix[i]))
			{
				// if operator at top of stack has lower precedence than i.
				opStack.push(infix[i]);
			}
			else
			{
				opStack.push(infix[i]); // push new operator onto stack.
			}
			if (i + 1 == infix.length()) // if we reached the end of the expression...
			{
				while (!opStack.isEmpty()) // while the operator stack is not empty...
				{
					postfix += opStack.peek(); // append postfix string with operator at top of stack and then...
					opStack.pop(); // pop it off stack until all remaining operators are appended to postfix string.
				}
			}
			break;
		}
	}
	std::cout << "\nPostfix from stacks is: " << postfix << std::endl;

	int answer = 0;
	int num1 = 0;
	int num2 = 0;

	// Evaluating the expression in postfix form.
	valStack.clear();
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isdigit(postfix[i]))
		{
			// if i is a digit, push to valStack as a int.
			valStack.push(postfix[i] - '0');
		}
		if (!isdigit(postfix[i]))
		{
			// if i is a operator, take out the top 2 operands and evaluate using i.
			num2 = valStack.peek();
			valStack.pop();
			num1 = valStack.peek();
			valStack.pop();
			answer = valStack.evaluatepostfix(num1, num2, postfix[i]);
			valStack.push(answer); // This insures that the last evaluation can be used in succession for the next evaluation.
		}
	}

	std::cout << "\nExpression result is: " << answer << std::endl << std::endl;
	system("PAUSE");
	return 0;
}