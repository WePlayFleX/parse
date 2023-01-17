#pragma once
class Stack
{
private:
	char st[MAX];
	int top;

public:
	Stack()
	{
		top = 0;
	}

	void push(char var)
	{
		st[++top] = var;
	}

	char pop()
	{
		return st[top--];
	}

	int gettop()
	{
		return top;
	}
};