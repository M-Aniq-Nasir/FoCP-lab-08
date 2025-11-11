//All the libraries used
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <chrono> 
#include <thread>

using namespace std;
//All the functions used.Details about their function is written above their definitions
void typetext(string, int x = 50 +rand()%10 );
void interface();
void how_to_play();
void about_us();
int murderer();
void selection();
void suspects();
void locations();
void weapon();
void energy_location(int &);
void energy_suspect(int &);

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
void typetext(const string message, int delay_ms ) {
	int length = message.length();
	for (int i = 0; i < length; i++) {
		cout << message[i];
		this_thread::sleep_for(chrono::milliseconds(delay_ms));
	}
}

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
		cout << "Error. No Murderer selected.";
	}
	return sus_select;
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
			string intro = "Evan Eldenwood was found dead in his Manor.He was brutally murdered.""Detective! Investigate the following suspects.";
			typetext(intro, 50 + rand() % 10);
			suspects();
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
	cout << "\n----------------------------------------------- \n";
	string suspects = "\nMurderer is among these ten suspects:\n"
		"1. Henry (Butler) -Served the family for 40 years, but the victim planned to dismiss him with no pension due to allegations of stealing.\n"
		"2. Regina (Maid) - Evan didn't gave any job to her husband who committed suicide.\n"
		"3. Arthur (Chef) - Evan always made racist remarks about his black colour.\n"
		"4. Samuel (Driver) - Was of idea that deserving lord of manor should be Brad.\n"
		"5. Victor Eldenwood (Brother of victim) - A drug addict who hates Evan because their parents always showed more care towards Evan.\n"
		"6. Thomas (PA of victim) - Secretly loved Evan's sister and became furious due to Evan's wicked behaviour with her.\n"
		"7. Felix (Guest) - An old rival invited to solve the past disputes by Evan.\n"
		"8. Edward (Gardener) - Was once forced by Evan to bury an unknown dead body.\n"
		"9. Martha Elderwood (Sister of victim) - Was continuosly deprived of her share in propety by Evan.\n"
		"10. Brad (Brother-in-Law of victim) - Had many fights with Evan due to his bad behaviour with wife Martha.\n";
	typetext(suspects, 60 + rand() % 10);
	cout<<"-----------------------------------------------\n\n";
}
//Displays available locations for investigation
void locations() {
	string loc = "\nInvestigate in the following locations:\n";
	typetext(loc);
	cout << "------------------------------------------------------------\n";
	string loc1 = "1.Dining Room\n"
		"2.Hall\n"
		"3.Bedroom\n"
		"4.Garage\n"
		"5.Kitchen\n"
		"6.Library\n"
		"7.Lounge\n";
	typetext(loc1);
	cout<<"------------------------------------------------------------\n\n";
}

void energy_location(int &x){
    x-=5;
    if(x>25)
    cout<<"Your Energy Left is: " << x<<"%\n";
    else if (x>0)
    cout<<"Beware, Low Energy!\t Your Energy Left is: " << x<<"%\n";
    else
    exit(0); //Terminate the program immediately
}

void energy_suspect(int &x){
    x-=10;
    if(x>25)
    cout<<"Your Energy Left is: " << x<<"%\n";
    else if (x>0)
    cout<<"Beware, Low Energy!\t Your Energy Left is: " << x<<"%\n";
    else
    exit(0);
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
	string loc1 = "You are investigating the " + dining_room + "...\n";
	string loc2 = "You are investigating the " + hall + "...\n";
	string loc3 = "You are investigating the " + bedroom + "...\n";
	string loc4 = "You are investigating the " + garage + "...\n";
	string loc5 = "You are investigating the " + kitchen + "...\n";
	string loc6 = "You are investigating the " + library + "...\n";
	string loc7 = "You are investigating the " + lounge + "...\n";
	
	switch(location_choice) {
	case 1:
		typetext(loc1);
		break;

	case 2:
		typetext(loc2);
		break;

	case 3:
		typetext(loc3);
		break;

	case 4:
		typetext(loc4);
		break;

	case 5:
		typetext( loc5);
		break;

	case 6:
		typetext( loc6);
		break;

	case 7:
		typetext( loc7);
		break;

	default:
		cout << "Invalid location number. Please enter a number between 1-7.\n";
		return -1;
	}
	return location_choice;
}

void weapon(){
    int x = 1+rand() % 5;
    string y;
    switch(x){
        case 1 :{
            y="Torn Rope";break;
        }
        case 2 :{
            y="Wrench";break;
        }
        case 3 :{
            y="Gun";break;
        }
        case 4 :{
            y="Knife";break;
        }
        case 5 :{
            y="Crowbar";break;
        }

    }
    cout<<"The weapon found at the location of murder was: "<<y<<endl;
}