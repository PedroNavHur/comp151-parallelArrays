#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Sends title and clears screen
void titleAndClear() {
	system("CLS");
	cout << "State - Capital Trivia Game\n\n";
}

// Generates a random number from 0 - 4
int getRandomN() {
	srand(time(NULL));
	int randomNumber = (rand() % 10) / 2;
	return randomNumber;
}

// Ask the user a trivia question
// Returns true if user wants to continue playing
// Returns false if he doesn't
bool askQuestion(string States[], string Capitals[], bool &isCorrect) {
	titleAndClear();
	bool isStillPlaying = true;
	bool changeQuestion = false;
	int randN = getRandomN();
	string state = States[randN];
	string trueCapital = Capitals[randN];
	string capital;


	while (!changeQuestion) {
		cout << "What is the Capital of " << state << "?";
		getline(cin, capital);

		
		if (trueCapital == capital) {
			changeQuestion = true;
			cout << "Correct\n";
			cout << "Do you want to keep playing?\n";
			cout << "Press \"Y\" to continue playing\n";
			cout << "Press \"N\" to exit\n";
			string keepPlaying;
			getline(cin, keepPlaying);

			if (keepPlaying == "N") {
				isStillPlaying = false;
			}
		}
		else {
			isCorrect = false;
			cout << "Incorrect\n";
			cout << "Do you want to try again?\n";
			cout << "Press \"Y\" to try again\n";
			cout << "Press \"N\" to exit\n";
			string keepPlaying;
			getline(cin, keepPlaying);

			if (keepPlaying == "N") {
				isStillPlaying = false;
				changeQuestion = true;
			}
	}

	
	}

	return isStillPlaying;
}

void populateArrays(string States[], string Capitals[], int MAXSTATES) {
	for (size_t i = 0; i < MAXSTATES; i++)
	{
		cout << "What is State " << i + 1 << "? ";
		getline(cin, States[i]);

		cout << "What is the Capital " << i + 1 << "? ";
		getline(cin, Capitals[i]);

	}
}

void main() {
	const int MAXSTATES = 5;

	// Create parallel arrays, states and capitals
	string States[MAXSTATES];
	string Capitals[MAXSTATES];

	titleAndClear();

	// Populate the parallel arrays
	populateArrays(States, Capitals, MAXSTATES);

	// Let the user play
	bool isPlaying = true;
	bool isCorrect = true;
	int correctCount = 0;
	int wrongCount = 0;
	while (isPlaying) {
		isPlaying = askQuestion(States, Capitals, isCorrect);
		if (isCorrect){
			correctCount++;
		} else {
			wrongCount++;
		}
	}

	cout << "You plaid " << correctCount + wrongCount << " times \n";
	cout << "You had " << correctCount << " correct answers \n";
	cout << "You had " << wrongCount << " wrong answers \n";




}
