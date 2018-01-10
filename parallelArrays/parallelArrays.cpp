#include <iostream>
#include <string>

using namespace std;

void main() {
	const int MAXSTATES = 5;

	// Create parallel arrays, states and capitals
	string States[MAXSTATES];
	string Capitals[MAXSTATES];

	// POpulate the parallel arrays
	for (size_t i = 0; i < MAXSTATES; i++)
	{
		cout << "What is State " << i + 1 << "? ";
		getline(cin, States[i]);

		cout << "What is the Capital " << i + 1 << "? ";
		getline(cin, Capitals[i]);

	}

}
