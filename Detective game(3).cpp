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

//Interface
void interface();
void how_to_play();
void about_us();
int choose();
int location_visit();

//charcter selection and story start
void game_start();
void suspects_print();
void locations_print();
int weapon();

//storyline flow
int char_weapon_link(int);
int loc_weapon_link(int);
void clue_loc(int,int,int);
int sus_interrogate();
void clue_sus(int,int);
void user_guess(int);

//energy calculation
void energy_location(int &);
void energy_suspect(int &);

inline int randomizer(int start, int steps) { int random_int = start + rand() % steps; return random_int; }

//main function
int main() {
	srand(time(0));

	int murder_weapon = 0, loc=0, murder_loc=0, choice, energy=100, choice_sus=0, murderer = 0;

	interface();
	game_start();
	murder_weapon = weapon();
	murder_loc = loc_weapon_link(murder_weapon);
	murderer = char_weapon_link(murder_weapon);
	while (true) {
		choice = choose();
		if (choice == 1) {
			loc = location_visit();
			clue_loc(loc, murder_loc, murder_weapon);
			energy_location(energy);
		}
		else if (choice == 2) {
			clue_sus(murderer,murder_weapon);
		}
		else if (choice == 3) {
			user_guess(murderer);
			return 0;
		}
		else cout << "Invalid input.Please enter correct values.\n";
	}
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

int choose() {
	int choice = 0;
	typetext( "What would you like to investigate ?\n1.Locations\n2.Suspects\n3.Finish Investigation \n\n");
	cin >> choice;
	return choice;
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

//This function is used for user to select what they would like to do from the interface
void game_start() {
	int select;
	while (true) {
		cout << "For selection, Enter Integer(1-4) as numbered above.\nWhat would you like to do?\n";
		cin >> select;
		if (select == 1) {
			how_to_play();
		}
		else if (select == 2) {
			string intro = "Evan Eldenwood was found dead in his Manor.He was brutally murdered.\nWe recieved Evan's call just before his murder,but sadly he couldnt tell us anything else and was murdered.\nDetective! Investigate the following suspects.\n\n";
			typetext(intro, 50 + rand() % 10);
			suspects_print();
			break;
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
void suspects_print() {
	cout << "\n----------------------------------------------- \n";
	string suspects = "\nMurderer is among these ten suspects:\n"
		"1. Henry (Butler) -Served the family for 40 years, but the victim planned to dismiss him with no pension due to allegations of stealing.\n"
		"2. Regina (Maid) - Evan didn't give job to her husband who committed suicide.\n"
		"3. Arthur (Chef) - Evan always made racist remarks about his black colour.\n"
		"4. Samuel (Driver) - Was of idea that deserving lord of manor should be Brad.\n"
		"5. Edward (Gardener) - Was once forced by Evan to bury an unknown dead body.\n"
		"6. Victor Eldenwood (Brother of victim) - A drug addict who hates Evan because their parents always showed more care towards Evan and gave Evan all of their wealth.\n"
		"7. Felix (Guest) - An old rival invited to solve the past disputes by Evan.\n"
		"8. Martha Elderwood (Sister of victim) - Was continuosly deprived of her share in propety by Evan.\n"
		"9. Thomas (PA of victim) - Secretly loved Evan's sister and became furious due to Evan's wicked behaviour with her.\n"
		"10. Brad (Brother-in-Law of victim) - Had many fights with Evan due to his bad behaviour with wife Martha.\n";
	typetext(suspects, 40 + rand() % 10);
	cout<<"-----------------------------------------------\n\n";
}


int weapon(){
    int x = 1+rand() % 5;
    string weapon;

	switch (x) {
	case 1: {
		weapon = "Knife"; break;
	}
	case 2: {
		weapon = "Wrench"; break;
	}
	case 3: {
		weapon = "Crowbar"; break;
	}
	case 4: {
		weapon = "Gun"; break;
	}
	case 5: {
		weapon = "Torn Rope"; break;
	}
	default:
		cout << "value error";
		return 0;
	}
	/*string weapon_print = "The weapon found at the location of murder was: ";
	typetext(weapon_print);
	typetext(weapon);*/
	
	return x;
}


int char_weapon_link(int weapon) {
	int i, murderer;
	if (weapon == 1) {
		int murderers[4] = { 1,2,3,8 };
		i = randomizer(0, 4);
		murderer = murderers[i];
	}
	else if (weapon == 2) {
		i = randomizer(0, 3);
		int murderers[3] = {4,5,10};
		murderer = murderers[i];
	}
	else if (weapon == 3) {
		i = randomizer(0, 4);
		int murderers[4] = {1,6,4,5};
		murderer = murderers[i];
	}
	else if (weapon == 4) {
		i = randomizer(0, 2);
		int murderers[3] = { 6,9,7 };
		murderer = murderers[i];
	}
	else if (weapon == 5) {
		i = randomizer(0, 10);
		int murderers[10] = { 1,2,3,4,5,6,7,8,9, 10 };
		murderer = murderers[i];
	}
	else {
		cout << "Linkage Error.";
		return 0;
	}
	return murderer;
}

void locations_print() {
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
	else {
		cout << "You are out of energy, you have to make the guess";
		exit(0);
	} //Terminate the program immediately
}

void energy_suspect(int &x){
    x-=10;
    if(x>25)
    cout<<"Your Energy Left is: " << x<<"%\n";
    else if (x>0)
    cout<<"Beware, Low Energy!\t Your Energy Left is: " << x<<"%\n";
	else {
		cout << "You are out of energy, you have to make the guess";
		exit(0);
	}
}

//This function handles location selection and investigation
int location_visit() {

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
	locations_print();

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
		return 1;
		break;

	case 2:
		typetext(loc2);
		return 2;

	case 3:
		typetext(loc3);
		return 3;

	case 4:
		typetext(loc4);
		return 4;

	case 5:
		typetext( loc5);
		return 5;

	case 6:
		typetext( loc6);
		return 6;

	case 7:
		typetext( loc7);
		return 7;

	default:
		cout << "Invalid location number. Please enter a number between 1-7.\n";
		return -1;
	}
	return location_choice;
}


int loc_weapon_link(int weapon) {
	int i,loc=4;
	if (weapon == 1) {
		int locations[3] = { 1,3,5};
		i = randomizer(0, 4);
		loc = locations[i];
	}
	else if (weapon == 2) {
		
		loc = 4;
	}
	else if (weapon == 3) {
		i = randomizer(0, 2);
		int locations[2] = { 2,4 };
		loc = locations[i];
	}
	else if (weapon == 4) {
		i = randomizer(0, 4);
		int locations[4] = { 1,3,6,7};
		loc = locations[i];
	}
	else if (weapon == 5) {
		i = randomizer(0, 7);
		int locations[7] = { 1,2,3,4,5,6,7};
		loc = locations[i];
	}
	else {
		cout << "Linkage Error.";
		system("pause");
	}
	return loc;
}

void clue_loc(int location,int loc_murder,int weapon) {
	if (location == loc_murder) {
		string message = "This seems to be the murder location.....\n..here,look! there is a ";
		string weapon_print;
		if (weapon == 1) string weapon_print = "Knife";
		if (weapon == 2) string weapon_print = "Wrench";
		if (weapon == 2) string weapon_print = "Crowbar";
		if (weapon == 2) string weapon_print = "Gun";
		if (weapon == 2) string weapon_print = "Torn rope";
		typetext(message);
		typetext(weapon_print);
		typetext(" on the ground,\nthe killer must have panicked,otherwise he would'nt have left it in the open.\nHe hid the body but couldn't hide the weapon in the time");
	}
	else {
		string no_clue = "You found no clue.\nHmm...You should go and check other locations,maybe there is something there.\n\n";
		typetext(no_clue);
	}
}

int sus_interrogate() {
	int user_input = 0;
	typetext( "Which one would you like to interrogate first?\n");
	typetext("1. Henry(Butler) \n"
		"2. Regina (Maid)\n"
		"3. Arthur (Chef) \n"
		"4. Samuel (Driver)\n"
		"5. Edward (Gardener) \n"
		"6. Victor Eldenwood(Brother of victim) \n"
		"7. Felix (Guest) \n"
		"8. Martha Elderwood (Sister of victim)\n"
		"9. Thomas (PA of victim)\n"
		"10. Brad (Brother-in-Law of victim) \n\n");
	cin >> user_input;
	return user_input;
}

void clue_sus(int murderer,int weapon) {
	while (true) {
		int suspect = sus_interrogate();
		if (suspect == 1) {
			if (suspect == murderer) {
				if(weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			}
			else {
				typetext("");
			}

		}
		else if (suspect == 2) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			}
			
			else {
				typetext("");
			}
		}
		else if (suspect == 3) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			
			}
			else {
				typetext("");
			}
		}
		else if (suspect == 4) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			}
			
			else {
				typetext("");
			}
		}
		else if (suspect == 5) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			}
			
			else {
				typetext("");
			}
		}
		else if (suspect == 6) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			}
			
			else {
				typetext("");
			}
		}
		else if (suspect == 7) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			
			}
			else {
				typetext("");
			}
		}
		else if (suspect == 8) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			}
			
			else {
				typetext("");
			}
		}
		else if (suspect == 9) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			}
			
			else {
				typetext("");
			}
		}
		else if (suspect == 10) {
			if (suspect == murderer) {
				if (weapon == 1)typetext("");
				if (weapon == 3)typetext("");
				if (weapon == 5)typetext("");
			
			}
			else {
				typetext("");
			}
		}
		else {
			cout << "Invalid input.Please Enter correctly";
		}
	}
}

void user_guess(int murderer) {
	int guess = 0;
	typetext("So Detective,You have found out the murderer. Who do you think is the murderer? \n");
	typetext("1. Henry(Butler) \n"
		"2. Regina (Maid)\n"
		"3. Arthur (Chef) \n"
		"4. Samuel (Driver)\n"
		"5. Edward (Gardener) \n"
		"6. Victor Eldenwood(Brother of victim) \n"
		"7. Felix (Guest) \n"
		"8. Martha Elderwood (Sister of victim)\n"
		"9. Thomas (PA of victim)\n"
		"10. Brad (Brother-in-Law of victim) \n\n");
	cin >> guess;
	if (guess == murderer) {
		typetext("Head Detective: As i thought, you are an excellent detective, you managed to figured out the true murderer.\n                Congratulations You passed our test.You didnt disappoint me.\n");
		typetext("You: What are you saying......this was ...a test.\n");
		typetext("Head Detective: Yes, This was a test, we are elite detectives.We are always in desperate need of people with your skills.\n");
		typetext("You: So... All of this was fake....is Evan even dead.\n");
		typetext("Head Detective: Yes, Evan did die... but 5 months ago. We staged this scene exactly as it was.\n               Just so you know Before you, five people failed this.So, from now on you are one of us.");
		typetext("\n                By the way,just so you know you cannot refuse, you are already too deep into it.");
	}
	else if (guess >= 1 && guess <= 10) {
		typetext("You were wrong.");
	}

}