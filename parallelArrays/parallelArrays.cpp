//parallel array example, states and capitals

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void main()
{
	const short MAXSTATES = 3;
	//Create parallel arrays, states and capitals
	string States[MAXSTATES];
	string Capitals[MAXSTATES];

	//Populate state and capital arrays
	for (int i = 0; i < MAXSTATES; i++)
	{
		cout << "What is state " << i + 1 << "? ";
		getline(cin, States[i]);
		cout << "What is the capital? ";
		getline(cin, Capitals[i]);
	}

	//Seed random number generator and clear screen
	system("CLS");
	srand(time(NULL));

	//Generate test questions:
	char Continue = 'y';
	while (Continue == 'y')
	{
		int StateIndex = rand() % MAXSTATES;
		cout << "What is the capital of " << States[StateIndex] << "? ";
		string Answer;
		getline(cin, Answer);

		if (Capitals[StateIndex] == Answer)
		{
			cout << "CORRECT" << endl;
		}
		else
		{
			cout << "INCORRECT, the capital of " << States[StateIndex] << " is " << Capitals[StateIndex] << endl;
		}

		cout << "Another question <y/Y>? ";
		cin >> Continue;
		cin.get();
		Continue = tolower(Continue);

	}

}
