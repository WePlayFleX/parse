#pragma once

using namespace std;

class Express
{
private:
	Stack s;
	char* pStr;
	int len;

public:
	Express(char* ptr)
	{
		pStr = ptr;
		len = strlen(pStr);
	}

	void parse();
	int solve();
};

void Express::parse()
{
	char ch;
	char lastval;
	char lastop;

	for (int i = 0; i < len; i++)
	{
		ch = pStr[i];

		if (ch >= '0' && ch <= '9')
		{
			s.push(ch - '0');
		}
		else
		{
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				if (s.gettop() == 1)
				{
					s.push(ch);
				}
				else
				{
					lastval = s.pop();
					lastop = s.pop();

					if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
					{
						s.push(lastop);
						s.push(lastval);
					}
					else
					{
						switch (lastop)
						{
						case '+':
							s.push(s.pop() + lastval);
							break;

						case '-':
							s.push(s.pop() - lastval);
							break;

						case '*':
							s.push(s.pop() * lastval);
							break;

						case '/':
							s.push(s.pop() / lastval);
							break;

						default:
							cout << "\nUnknown operator";
							exit(1);
						}
					}
					s.push(ch);
				}
			}
			else
			{
				cout << "\nUnknown character";
				exit(1);
			}
		}
	}
}

int Express::solve()
{
	char lastval;

	while (s.gettop() > 1)
	{
		lastval = s.pop();
		switch (s.pop())
		{
		case '+':
			s.push(s.pop() + lastval);
			break;

		case '-':
			s.push(s.pop() - lastval);
			break;

		case '*':
			s.push(s.pop() * lastval);
			break;

		case '/':
			s.push(s.pop() / lastval);
			break;

		default:
			cout << "\nUnknown operator";
			exit(1);
		}
	}

	return int(s.pop());
}