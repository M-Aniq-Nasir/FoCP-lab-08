//All the libraries used
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <chrono> 
#include <thread>

using namespace std;
//All the functions used.Details about their function is written above their definitions
void typetext(string, int x = 30 +rand()%10 );

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
bool exit_game();

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

	int murder_weapon = 0, loc = 0, murder_loc = 0, choice, energy = 100, choice_sus = 0, murderer = 0;
	while (true) {
		interface();
		game_start();
		murder_weapon = weapon();
		murder_loc = loc_weapon_link(murder_weapon);
		murderer = char_weapon_link(murder_weapon);
		while (energy >= 0) {
			typetext("\nEnergy = ");
			cout << energy << "\n\n";
			choice = choose();

			if (choice == 1 && energy >= 5) {
				loc = location_visit();
				clue_loc(loc, murder_loc, murder_weapon);
				energy_location(energy);
			}
			else if (choice == 2 && energy >= 5) {
				clue_sus(murderer, murder_weapon);
				energy_suspect(energy);
			}
			else if (choice == 3 || energy < 5) {
				if (energy < 5)typetext("Detective, it looks like you ran out of energy, now decide who the murderer is...\n\n");
				user_guess(murderer);
				energy = 0;
				if (exit_game()) {
					return 0;
				}
			}
			else cout << "Invalid input.Please enter correct values.\n";

		}
		
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
			typetext(intro, 30 + rand() % 20);
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
	typetext("The Mystery of Eldenwood Manor\n\nGame overview:\nThis is a detective mystery game where you take on the role of a Detective investigating \nthe suspicious murder of Evan Eledenwood, head of the wealthy Eldenwood family.\n"
		"During this game you will explore the manor, gather clues from different locations,interrogate the suspects with limited energy and finally identifying the real murderer.\n"
		"This game uses randomness for weapons, clues and murderer selection so manage your energy very carefully to gather maximum information.\n\nHow To Play : \n1.Starting the Game : \nFrom the main menu, choose one option.\n\nMain Menu Options : \n"
		"- How to play(Displays the basic instructions)\n"
		"- Start Game(Begins the story, shows suspects and locations and generates weapons)\n"
		"- About us(show information about game's developers)\n"
		"- Exit Game(Closes the program)\n\n"
		"2. Controls:\n"
		"Input numbers as instructed in the menu.\n"
		"All choices throughout the game are made by entering integer inputs.\n"
		"Use logic and deduction to solve the case.\n\n"
		"2. Energy Systems : \n"
		"You begin with 100 % energy.\n"
		"Investigating a location cost 5 % energy.\n"
		"Interrogating a suspect cost 10 % energy.\n"
		"If energy reaches 0 %, you will be forced to make a guess.\n\n"
		"3. Investigating the locations : \n"
		"You can explore seven different locations in the manor.\n"
		"Look for the murder weapon which is one of the most important clue in the game in these locations.\n\n"
		"4. Interrogating the suspects : \n"
		"There will be ten suspects each with a unique and strong motive to murder.\n"
		"You have to figure out who is trying to mislead you with lies.\n\n"
		"5. Gather clues : \n"
		"Use clues from both locations and suspects interrogation to make a strong guess.\n\n"
		"6. Final Accusation : \n"
		"In the end, you have to accuse one of the suspect as murderer based on your interrogation and other clues.\n\n"
		"Winning the Game : \n"
		"You win by correctly identifying the murderer using:\n"
		" - Weapon found\n"
		" - Location clues\n"
		" - Motives\n"
		" - Logical deduction\n\n"
		"Losing the Game : \n"
		"You lose if:\n"
		" - Your energy reaches 0 % before solving the case and you will be forced to guess the murderer.\n"
		" - You accuse the wrong suspect\n\n"
		"Tips : \n"
		" - Manage your energy level very carefully.\n"
		" - Use weapon clues to reduce the suspects list.\n"
		" - Think logically about every word of suspect during interrogation, there can be a connection which lead you to murderer.\n", 20);
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
		"8. Martha Eldenwood (Sister of victim) - Was continuosly deprived of her share in propety by Evan.\n"
		"9. Thomas (PA of victim) - Secretly loved Evan's sister and became furious due to Evan's wicked behaviour with her.\n"
		"10. Brad (Brother-in-Law of victim) - Had many fights with Evan due to Evan's bad behaviour with his wife Martha.\n";
	typetext(suspects, 40 + rand() % 10);
	cout<<"-----------------------------------------------\n\n";
}

//function for 
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
		i = randomizer(0, 3);
		int locations[3] = { 1,3,5};
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
		else if (weapon == 2) string weapon_print = "Wrench";
		else if (weapon == 3) string weapon_print = "Crowbar";
		else if (weapon == 4) string weapon_print = "Gun";
		else if (weapon == 5) string weapon_print = "Torn rope";
		typetext(message);
		typetext(weapon_print);
		typetext(" on the ground,\nthe killer must have panicked,otherwise he would'nt have left it in the open.\nHe hid the body but couldn't hide the weapon in the time\n");
	}
	else {
		string no_clue = "You found no clue.\nHmm...You should go and check other locations,maybe there is something there.\n\n";
		typetext(no_clue);
	}
}

int sus_interrogate() {
	int user_input = 0;
	typetext( "Which one would you like to interrogate?\n");
	typetext("1. Henry(Butler) \n"
		"2. Regina (Maid)\n"
		"3. Arthur (Chef) \n"
		"4. Samuel (Driver)\n"
		"5. Edward (Gardener) \n"
		"6. Victor Eldenwood(Brother of victim) \n"
		"7. Felix (Guest) \n"
		"8. Martha Eldenwood (Sister of victim)\n"
		"9. Thomas (PA of victim)\n"
		"10. Brad (Brother-in-Law of victim) \n\n");
	cin >> user_input;
	return user_input;
}

void clue_sus(int murderer,int weapon) {
	int suspect = sus_interrogate();
	
	if (suspect == 1) {
		if (suspect == murderer) {
			if (weapon == 1)typetext("You:Where were you at the time of murder?\nHenry: I was just helping Arthur cut onions as he was busy bringing the groceries, when i heard loud screams.");
			else if (weapon == 3)typetext("You:Where were you at the time of murder? \nHenry: I went to the cellar to turn on the heater but the cellar door jammed again \nand I was locked inside, so I grabbed the crowbar from the shed to pry it open that is when i heard loud screams.");
			else if (weapon == 5)typetext("You:Where were you at the time of murder?\nHenry: I went to put pile of documents into the attic. The rope i was tying it with was torn so it took me a lot of time, and \njust when i was coming back i heard screams");
		}
		else {		
			typetext("You:Where were you at the time of murder?\nHenry:I was in the attic rearranging boxes and it took me a lot of time,but i heard no screams,you can't hear much in the attic.");
			}

	}
	else if (suspect == 2) {
		if (suspect == murderer) {
			if (weapon == 1)typetext("You:Where were you at the time of murder?\nRegina: Arthur asked me to help slice onions, as I was cutting with the small kitchen knife he handed me so it was taking me a lot of time");
			else if (weapon == 5)typetext("You:Where were you at the time of murder?\nRegina: The laundry line snapped in the wind, so I was busy retying it with the rope I keep for emergencies.");
		}
			
		else {
			typetext("");
		}
		}
	else if (suspect == 3) {
		if (suspect == murderer) {
			if (weapon == 1)typetext("You:Where were you at the time of murder?\nArthur: I went to buy a new knife, i lost it this morning, I must have dropped it somewhere.");
			else if (weapon == 5)typetext("You:Where were you at the time of murder?\nArthur: Well! i was cutting the rope i used to bring the meat with my beloved knife.That's when i heard the scream");
		
		}
		else {
			if(weapon == 1) typetext("You:Where were you at the time of murder?\nArthur: I was trying to find my knife, someone must have stolen it.To think they murdered Evan with my beloved knife.\n");
			else typetext("You:Where were you at the time of murder ? \nArthur: I went to buy some groceries from the supermarket.\n");
		}
	}
	else if (suspect == 4) {
		if (suspect == murderer) {
			if (weapon == 2)typetext("You:Where were you at the time of murder ? \nSamuel: The jeep started rattling again, so I was tightening the bolts.It was making so much noise that i didn't hear Boss's Scream.\n");
			else if (weapon == 3)typetext("You:Where were you at the time of murder ? \nSamuel: I was busy prying open the jeep's Engine,it is an antique piece.You need to use crowbar to even open it's hood.\n");
			else if (weapon == 5)typetext("You:Where were you at the time of murder ? \nSamuel: The luggage was slipping as only an old torn rope was used to tie it so i had to go to store to grab more rope.\n");
		}
			
		else {
			typetext("You:Where were you at the time of murder ? \nSamuel: I was loading the luggage onto the truck but I didnt have rope so I asked Edward to bring it.\n");
		}
	}
	else if (suspect == 5) {
		if (suspect == murderer) {
			if (weapon == 2)typetext("You:Where were you at the time of murder ? \nEdward: The greenhouse pump got broken, i was opening it, but it turned it it's bolts were pretty tight so it took me a lot of time \nand i heard nothing,probably because i was in the garden,\n");
			else if (weapon == 3)typetext("You:Where were you at the time of murder ? \nEdward: I was trying to uproot a wild plant, it could'nt even be done by a the crowbar.\n");
			else if (weapon == 5)typetext("You:Where were you at the time of murder ? \nEdward: I went to pick up a new rope from the store for Samuel,as the rope I had was torn.\n");
		}
		
		else {
			typetext("You:Where were you at the time of murder ? \nEdward: Samuel needed my rope for something so i was bringing that.While i was going there i heard screaming.\n");
		}
	}
	else if (suspect == 6) {
		if (suspect == murderer) {
			if (weapon == 3)typetext("You:Where were you at the time of murder ? \nVictor: I wanted to open a crate but I could'nt open it no matter what so I was opening it with a crowbar.");
			else if (weapon == 4)typetext("You:Where were you at the time of murder ? \nVictor: I was just watching movies so I heard nothing.Besides brother keeps his gun in the room in his closet.\nHe could have easily defended himself if only he wasn't so careless all the time");
			else if (weapon == 5)typetext("You:Where were you at the time of murder ? \nVictor: I used a rope to pull some crates into my room, but it tore right in my hands, so I was going towards garden to ask Edward for a rope.");
		}
			
		else {
			typetext("You:Where were you at the time of murder ? \nVictor: I was watching movies in my room.Then suddenly I heard screaming.I rushed but found nothing.Well to be fair,Evan did deserve it.");
		}
	}
	else if (suspect == 7) {
		if (suspect == murderer) {
			if (weapon == 4)typetext("You:Where were you at the time of murder ? \nFelix: I  was invited to solve previous conflicts.\nI got so angry that he made me wait for so much time in his guest room, i was about to take my gun out....but then i found out that Evan was murdered.");
			else if (weapon == 5)typetext("You:Where were you at the time of murder ? \nFelix: I was invited bu Evan to solve our past conflicts.I even brought him presents, though the rope binding the presents broke and some crates also got destroyed");
			
		}
		else {
			typetext("You:Where were you at the time of murder ? \nFelix: I was waiting outside. Thankfully he died, I hated him so much.He was very shrewd,so much so that I always keep my gun with me when he is around.\n");
		}
	}
	else if (suspect == 8) {
		if (suspect == murderer) {
			if (weapon == 1)typetext("You:Where were you at the time of murder ? \nMartha: I was in the kitchen cutting vegetables for preparing my food.I don't trust the chef so I even bring my own vegetables and also cut it myself.\n");
			if (weapon == 5)typetext("You:Where were you at the time of murder ? \nMartha: I was tying up some presents for the kids at the orphanage with a decorative small rope in my room .then I heard some screams from upstairs.\n" );
		}
		
		else {
			typetext("You:Where were you at the time of murder ? \nMartha: I was just preparing presents for the kids at the orphanage in my room");
		}
	}
	else if (suspect == 9) {
		if (suspect == murderer) {
			if (weapon == 4)typetext("You:Where were you at the time of murder ? \nThomas: I was busy finding Evan's gun. He was saying he lost it in my office but I could'nt find it.");
			else if (weapon == 5)typetext("You:Where were you at the time of murder ? \nThomas: I was busy preparing for event I was trying to hang up the backdrop \nbut the rope broke and we didnt have anymore so i went to store to buy it");
		}
			
		else {
			typetext("You:Where were you at the time of murder? \nThomas: I was busy preparing for the event,I was managing some paperwork related to event in my office.");
		}	
	}
	else if (suspect == 10) {
		if (suspect == murderer) {
			if (weapon == 2)typetext("You:Where were you at the time of murder? \nBrad: I was fixing the bathroom tap,It was very hard to open with the wrentch i borrowed from Samuel.");
			else if (weapon == 5)typetext("You:Where were you at the time of murder? \nBrad: I was trying to bring a shelf from the attic but the rope broke and the furniture fell and broke.\nI was taking throwing furnitue out");
		
		}
		else {
			typetext("You:Where were you at the time of murder? \nBrad: I was rearranging my bedroom.I didn't hear anything probably due to the noise of dragging furniture");
		}
	}
	else {
		cout << "Invalid input.Please Enter correctly.";
	}

		
}

void user_guess(int murderer) {
	int guess = 0;
	typetext("So Detective,You have found out who the murderer is. Who do you think is the murderer? \n");
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
	typetext("Enter your guess: ");
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

bool exit_game() {
	int choice = 0;
	while (true) {
		cout << "\n----------------------------------------------- \n";
		cout << setw(30) << "1. Play again.\n\n";
		cout << setw(29) << "2. Exit Game.\n";
		cout << "\n----------------------------------------------- \n";
		cin >> choice;
		if (choice == 2) {
			return true;
		}
		else if (choice != 1) {
			cout << "\nInvalid input.Please input correctly.\n";
		}
	}
	return false;
}