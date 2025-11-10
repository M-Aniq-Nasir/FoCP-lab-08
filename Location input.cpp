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
void suspects();
void locations();
int murder_location(int);

int main() {
	srand(time(0));
	murderer();
	interface();
	selection();
	
	return 0;
}

//This Function is for just the initial interface.
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

//This function is used for user to select what they would like to do from the interface
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

//used to display basic about us
void about_us() {
	cout << "\nThis game (The Mystery of Elderwood Manor.) has been developed by us(group of 3).This game is a \nmurder mystery game revolving around murder of Evan Eldenwood.";
	cout << "\nThrough this game,we challenge your wits and your ability to piece together clues which ultimately \nleads to a the mastermind behind this murder.";
	cout << "\nDetective! We wish you luck in finding the true mastermind.\nNow lets dive into The Mystery of The Eldenwood Manor.\n\n";
}

//used for guiding the player how to play
void how_to_play() {
	cout << "\nTo play this game, whenever you are asked something write the number of the command you want to \nexecute, as will be given with every command.It's this simple.Now have fun.\n";
}

//used for displaying brief introduction of suspects
void suspects() {
	cout << "\nMurderer is among these ten suspects:\n";
	cout << "-----------------------------------------------\n";
	cout << "1. Henry (Butler) -Served the family for 40 years, but the victim planned to dismiss him with no pension due to allegations of stealing.\n";
	cout << "2. Regina (Maid) - Evan didn't gave any job to her husband who committed suicide.\n";
	cout << "3. Arthur (Chef) - Evan always made racist remarks about his black colour.\n";
	cout << "5. Victor Eldenwood (Brother of victim) - A drug addict who hates Evan because their parents always showed more care towards Evan.\n";
	cout << "7. Felix (Guest) - An old rival invited to solve the past disputes by Evan.\n";
	cout << "8. Edward (Gardener) - Was once forced by Evan to bury an unknown dead body.\n";
	cout << "9. Martha Elderwood (Sister of victim) - Was continuosly deprived of her share in propety by Evan.\n";
	cout << "10. Brad (Brother-in-Law of victim) - Had many fights with Evan due to his bad behaviour with wife Martha.\n";
	cout << "6. Thomas (PA of victim) - Secretly loved Evan's sister and became furious due to Evan's wicked behaviour with her.\n";
	cout << "4. Samuel (Driver) - Was of idea that deserving lord of manor should be Brad.\n";
	cout << "-----------------------------------------------\n\n";
}

//Displays available locations for investigation
void locations() {
	cout << "\nInvestigate in the following locations:\n";
	cout << "------------------------------------------------------------\n";
	cout << "1.Dining Room\n";
	cout << "2.Hall\n";
	cout << "3.Bedroom\n";
	cout << "4.Garage\n";
	cout << "5.Kitchen\n";
	cout << "6.Library\n";
	cout << "7.Lounge\n";
	cout << "------------------------------------------------------------\n\n";
}

//This function handles location selection and investigation
int murder_location(int murder_num) {

	//Variables for all locations in sequence
	string dining_room = "Dining Room";
	string hall = "Hall";
	string bedroom = "Bedroom";
	string garage = "Garage";
	string kitchen = "Kitchen";
	string library = "Library";
	string lounge = "Lounge";

	int location_choice;

	//Display available locations to user in sequence
	locations();

	//Get user input
	cout << "Enter the location number you want to investigate (1-7): ";
	cin >> location_choice;
	cout << endl;

	switch(location_choice) {
		case 1:
		cout << "You are investigating the " << dining_room << "...\n";
		break;

		case 2:
		cout << "You are investigating the " << hall << "...\n";
		break;

		case 3:
		cout << "You are investigating the " << bedroom << "...\n";
		break;

		case 4:
		cout << "You are investigating the " << garage << "...\n";
		break;

		case 5:
		cout << "You are investigating the " << kitchen << "...\n";
		break;

		case 6:
		cout << "You are investigating the " << library << "...\n";
		break;

		case 7:
		cout << "You are investigating the " << lounge << "...\n";
		break;

		default:
		cout << "Invalid location number. Please enter a number between 1-7.\n";
		return -1;
	}
	return location_choice;
}