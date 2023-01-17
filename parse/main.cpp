#include <iostream>
#include <cstring>
#include "constants.h"
#include "Stack.h"
#include "Express.h"

using namespace std;

int main()
{
	char ans;
	char string[LEN];
	cout << "Enter an arithmetic expression in the form 2+3*4/3-2"
		"\nNumbers must be one digit"
		"\nDo not use spaces or brackets";

	do
	{
		cout << "\nExpression: ";
		cin >> string;

		Express* eptr = new Express(string);

		eptr->parse();

		cout << "\nResult: " << eptr->solve();

		delete eptr;

		cout << "\nAnother expression (y/n)? ";
		cin >> ans;
	} while (ans == 'y');

	system("pause");
	return 0;
}