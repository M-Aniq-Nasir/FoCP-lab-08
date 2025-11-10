//All the libraries used
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <chrono> 
#include <thread>

using namespace std;
//All the functions used.Details about their function is written above their definitions
void typeText(string, int );
void interface();
void how_to_play();
void about_us();
int murderer();
void selection();

int main() {
	srand(time(0));
	murderer();
	interface();
	selection();
	
	return 0;
}

//This Function is for just thr initial interface.
void interface() {
	cout << setw(80) << "---------Welcome to The Eldenwood Mansion--------\n\n\n";
	cout << setw(60) << "1. How to play?\n\n";
	cout << setw(59) << "2. Start Game.\n\n";
	cout << setw(57) << "3. About us.\n\n";
	cout << setw(59) << "4. Exit Game.\n\n\n";
}

//This function selects the murderer.
int murderer() {
	int sus_select = 1 + rand() % 10;
	switch (sus_select) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	default:
		cout << "Error.No Murderer selected.";
	}
	return sus_select;
}

//This function will be used with every text after the start of the game to make it look like typing animation
//Please Enter Everything as Strings and keep in mind the width of string
void typeText(const string message, int delay_ms) {
	int length = message.length();
	for (int i = 0; i < length; i++) {
		cout << message[i];
		this_thread::sleep_for(chrono::milliseconds(delay_ms));
	}
}
void selection() {
	int select;
	while (true) {
		cout << "For selection, Enter Integer(1-4) as numbered above.\nWhat would you like to do?\n";
		cin >> select;
		if (select == 1) {
			how_to_play();
		}
		else if (select == 2) {

		}
		else if (select == 3) {
			about_us();
		}
		else if (select == 4) {
			cout << "Exiting Program....";
			this_thread::sleep_for(chrono::milliseconds(100));
			exit(0);
		}
		else {
			cout << "\nInvalid input. Please input correct integer as according to numbering.";
		}
	
	}
}
void about_us() {
	cout << "\nThis game (The Mystery of Elderwood Manor.) has been developed by us(group of 3).This game is a \nmurder mystery game revolving around murder of Evan Eldenwood.";
	cout << "\nThrough this game,we challenge your wits and your ability to piece together clues which ultimately \nleads to a the mastermind behind this murder.";
	cout << "\nDetective! We wish you luck in finding the true mastermind.\nNow lets dive into The Mystery of The Eldenwood Manor.\n\n";
}
void how_to_play() {
	cout << "\nTo play this game, whenever you are asked something write the number of the command you want to \nexecute, as will be given with every command.It's this simple.Now have fun.\n";
}