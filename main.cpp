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
void greetings();
void interface();
void how_to_play();
void about_us();
int murderer();
void selection();
void weapon();
void energy_location(int &);
void energy_suspect(int &);

int main() {
    int Murderer,Guess,Energy;
	srand(time(0));
	Murderer = murderer();
	selection();
    while(Energy>0)
    {  
        //Ali add the suspect names here and use conditional to verify is user entered correct guess
    }
	return 0;
}

//This Function is for just the initial interface.
void greetings(){
    cout << setw(80) << "- ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~     WELCOME - TO - THE - ELDENWOOD - MANSION     ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ -\n\n\n";
}

//This function is for menu display
void interface() {
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
		cout << "Error. No Murderer selected.";
	}
	return sus_select;
}

//This function will be used with every text after the start of the game to make it look like typing animation
void typeText(const string message, int delay_ms) {
	int length = message.length();
	for (int i = 0; i < length; i++) {
		cout << message[i];
		this_thread::sleep_for(chrono::milliseconds(delay_ms));
	}
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

//This function is used for user to select what they would like to do from the interface
void selection() {
	int select=0;
    do{
        interface();
		cout << "For selection, Enter Integer(1-4) as numbered above.\nWhat would you like to do?\n";
		cin >> select;
		if (select == 1) {
			how_to_play();
		}
		else if (select == 2) {
            int initial_energy = 100;
            cout<<"\nYour Starting Energy is: "<<initial_energy<<"%\n\n";
            weapon();
            select++;//exit loop and continue game

		}
		else if (select == 3) {
			about_us();
		}
		else if (select == 4) {
			cout << "You have chosen to exit program.\nExiting Program....";
			this_thread::sleep_for(chrono::milliseconds(100));
			break;
		}
		else {
			cout << "\nInvalid input. Please input correct integer as according to numbering.";
		}
    }
	while (select<=5);
}

//used to display basic about us
void about_us() {
	cout << "\nThis game (The Mystery of Elderwood Manor.) has been developed by us(group of 3).This game is a \nmurder mystery game revolving around murder of Evan Eldenwood.";
	cout << "\nThrough this game,we challenge your wits and your ability to piece together clues which ultimately \nleads to a the mastermind behind this murder.";
	cout << "\nDetective! We wish you luck in finding the true mastermind.\nNow lets dive into The Mystery of The Eldenwood Manor.\n\n";
}

//used for guiding the player how to play
void how_to_play() {
	cout << "\nTo play this game, whenever you are asked something write the command's index you want to execute.\nTry to find the murderer ASAP. It's that simple. Now have fun.\n";
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
