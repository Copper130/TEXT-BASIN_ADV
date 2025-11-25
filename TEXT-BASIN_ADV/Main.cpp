#define _CRT_SECURE_NO_WARNINGS 
#define NOMINMAX
#include <iostream>
#include <vector>
#include <windows.h>
#include <random>
#include <string>
#include <limits>
#include <thread>// For sleep_for
#include <chrono>// For milliseconds
#include <ctime>//These are included as to let me pull the current time from the system
#include <iomanip>// Ditto
#include <sstream>// Ditto

using namespace std;

void cls() {
	system("cls");

}

// Clears Input Buffer as to provent infinite loops on invalid input
void ClearInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Types out text input with a wait between characters as it looks better
void TypeOut(const std::string& Text, int delayMs = 50) {
	for (char c : Text)
	{
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % delayMs));
	}

}
bool Crashed = false;
// Function for displaying a choice and handling the choice the user makes fr
int GetChoice(string prompt, int number_of_choices) {
	int choice = -1;
	while (choice < 1 || choice > number_of_choices){

		ClearInputBuffer();//Safeguard against infinite loops on invalid input

		std::cout << prompt << endl;
		cin >> choice;
		if(choice < 1 || choice > number_of_choices){
			cls();
			std::cout << "Are you sure. You can not take this back. Enter one for yes. Enter anything else for no.\n";
			std::string PlayerDOOM;
			std::cin >> PlayerDOOM;
			if (PlayerDOOM == "1" || PlayerDOOM == "one"|| PlayerDOOM == "One") {
				
					if (Crashed == false){
					cls();
					system("color 56");
					TypeOut("An astroid suddenly flies through the wall and vaporizes you for indecision. Game Over.\n\n", 25);
					Sleep(5000);
					}
					else {
					cls();
					system("color 56");
					TypeOut("As you hesitate a huge fly trap grabs you from behind and goobles your buns. Game Over :p\n\n", 25);
					Sleep(5000);
					}
				exit(80085);
			}
		}
	} 
	
	
	cls();
	return choice;

}

string Name;

int typingspeed = 50; //Global variable for typing speed default is 50ms per character
int main() {


	std::cout << "Hello welcome to Venessa, a Text based adventure game! \n Please enter your name User." << std::endl;

	getline(cin, Name);
	
	cls();
	TypeOut("Welcome " + Name + ", to the world of Venessa! \n\n", 20);

	Sleep(1000); //Allow User to read welcome message

	TypeOut("Your story starts as you awake with a splitting headache and little memory. As you look around you find yourself on a spaceship with dim lighting and an erie silence, as you look around you spot two diffrent hallways. The first appares to have a medical sign pointing to it, The other appares to be the direction to the cockpit of the ship\n\n", typingspeed);
	cout << "Press Enter to Begin\n";

	int first_choice = GetChoice("Which hallway do you choose? \n 1. Medical Bay \n 2. Cockpit", 2);
	cls();
	bool Went_to_medbay{};
	if (first_choice == 1) {
		 Went_to_medbay = true;
		TypeOut("You head towards the medical bay, as you enter you see a few medical pods, one of them is open and appears to have some medical supplies inside. Do you want to take the supplies? \n\n", typingspeed);
		int med_choice = GetChoice(" 1. Take them \n 2. Leave them", 2);
		if (med_choice == 1) {
			TypeOut("You take the medical supplies and feel a bit better. Suddenly, an alarm goes off indicating that the ship's systems are failing, the ship was constructed to be operated by a team of people 24/7 due to the lack of people operating and upkeeping systems they are failing.\n\n", typingspeed);
			bool TookMeds = true;
		}
		else {
			TypeOut("You decide not to take the supplies despite having a crippling migrane and pain making it hard to think. \n\n", typingspeed);
			bool TookMeds = false;
		}


	}
	else {
		 Went_to_medbay = false;
	}
		if (!Went_to_medbay){
			TypeOut("You head towards the cockpit, as the door is locked and you must figure out the code. as you look at the four digit lock you notice a clock next to it showing the current time. Whats your guess?\n\n", typingspeed);

		int timeCode = 1000;
		int code_guess = 12;
		while (code_guess != timeCode) {
			int code_guess = 6000;
			std::cout << "Enter the 4-digit code: ";
			ClearInputBuffer();
			cin >> code_guess;

			// Get the current time
			time_t now = time(0);
			tm* localTime = localtime(&now);

			int hour = localTime->tm_hour;
			int minute = localTime->tm_min;

			// Combine into HHMM format (e.g., 1437 for 2:37 PM)
			int timeCode = hour * 100 + minute;
		
			if (code_guess == timeCode|| code_guess == (timeCode-1)) {
				cls();
				break;
			}
			TypeOut("The lock lets out a buzzing sound and a faint red light. Try again.\n", 40);
		}
		
		TypeOut("The lock beeps and the door slides open, you enter the cockpit and find the controls of the ship. Suddenly, an alarm goes off indicating that the ship's systems are failing, the ship was constructed to be operated by a team of people 24/7 due to the lack of people operating and upkeeping systems they are failing!\n\n", typingspeed);
		}

	Sleep(1000);
	cls();
	int i = 8;
	if (Went_to_medbay == false) {
		for (i; i > 0; i--) {
			system("color 4");//Set text color to red
			TypeOut("You see a planet getting closer.\n", 3);
			TypeOut("Impact in " + to_string(i) + " seconds!\n", 3);
		}
	}
	else {
		for (i; i > 0; i--) {
			system("color 4");//Set text color to red
			TypeOut("You are thrown around as the ship barrels to the ground.\n", 3);
			TypeOut("Impact in " + to_string(i) + " seconds!\n", 3);
		}
	}

	cls();
	int IncreaseAmt = 1;
	int fontSize = 16;
	CONSOLE_FONT_INFOEX cfi;  // declare once
	cfi.cbSize = sizeof(cfi); // initialize
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Declare console handle here so it's in scope for everything below
	for (int i = 0; i < 30; i++) {
		system("color 7");//Reset to default color
		TypeOut("CRASH!\n", 10);
		system("color 4");//Set text color to red
		cout << "CRASH!\n";
	
	}
	Sleep(1500);
	system ("color 7");//Reset to default color
	cls();
	Crashed = true;// Set crashed to true to indicate the player has crashed
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Make text bright cyan for the planet
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	// Simple ASCII planet frames (rotating illusion)
	const string frames[] = {
		R"(
         .------.
       .'        `.
      /   o    o   \
     |      ()      |
      \    ----    /
       `.        .'
         `------'
        )",
		R"(
         .------.
       .'        `.
      /   o    o   \
     |    ----()    |
      \      o     /
       `.        .'
         `------'
        )",
		R"(
         .------.
       .'        `.
      /   ()----   \
     |   o    o     |
      \    o       /
       `.        .'
         `------'
        )",
		R"(
         .------.
       .'        `.
      /   o      o \
     |   ()----     |
      \   o    o   /
       `.        .'
         `------'
        )"
	};

	int frameCount = sizeof(frames) / sizeof(frames[0]);
	int CurrentFrame = 0;
	int CrashDuration = 15; // Duration of crash animation in number of frames shown.
	while (CrashDuration >= 0) {
		cls();
		std::cout << "You have crash landed on an unknown planet...\n\n";
		std::cout << frames[CurrentFrame] <<endl;
		std::cout << "You are stuck." << endl;
		this_thread::sleep_for(chrono::milliseconds(200));
		CurrentFrame = (CurrentFrame + 1) % frameCount;
		CrashDuration--;
	}
	cls();
	system("color e0");
	TypeOut("As you regain consciousness, you find yourself lying on the surface of an alien planet. The sky above is a strange hue, and unfamiliar flora surrounds you. Your ship lies in ruins nearby, smoke still rising from its wreckage. You realize that survival is your immediate concern.\n\n", 70);
	Sleep(500);// used for dramatic effect
	TypeOut("What will you do next? \n\n", 70); // Just making the next choice clear.


	int after_wreck_choice = GetChoice(" 1. Explore the surroundings \n 2. Search the wreckage for supplies \n 3. Call for help using the ship's radio", 3);
	//cout << after_wreck_choice; //for testing purposes only
	
	int supply_choice;// decared here to be used in the switch case later
	int radio_choice; // decared here to be used in the switch case later
	int explore_choice;// decared here to be used in the switch case later

	switch (after_wreck_choice) {
	
	case 1:
		// Explore the surroundings
		TypeOut("You decide to explore the alien landscape, hoping to find resources or signs of life. As you venture further from the wreckage, you notice strange plants with bioluminescent properties and hear distant, unidentifiable sounds. The environment is both fascinating and intimidating, reminding you of the importance of caution in this unknown world.\n\n", typingspeed);
		TypeOut("As you push deeper into the glowing forest, the air hums with a strange vibration. The plants pulse softly, almost like they're breathing. In the distance, you spot three things that immediately catch your attention:\n\n", typingspeed);

		explore_choice = GetChoice(" 1. A pulsating plant that reacts when you step closer\n 2. Footprints in the dirt that definitely aren't yours\n 3. A narrow cave entrance blowing out warm air",3);

		switch (explore_choice) {
			case 1:
				// Investigate the pulsating plant
				TypeOut("You approach the pulsating plant cautiously. As you get closer, it reacts to your presence, its glow intensifying. Suddenly, a small, luminescent creature emerges from behind it, staring at you it almost feels as if it can see inside your mind.\n\n", typingspeed);
				Sleep(1000);
				break;
			case 2:
				// Follow the footprints
				TypeOut("You follow the strange footprints through the soft, glowing soil. They lead you to a super small alien structure, partially hidden among the glowing flora. The footprints stop abruptly—someone or something was here recently.\n\n", typingspeed);
				Sleep(1000);
				break;
			case 3:
				// Enter the cave
				TypeOut("The cave entrance emits a warm, inviting air. As you step inside, your footsteps echo off the walls. Bioluminescent moss lights the way, and you notice strange markings etched into the stone. Something about this cave feels alive, almost watching you.\n\n", typingspeed);
				Sleep(500);
				TypeOut("you feel a sense of doom and instinctually turn to leave the cave. Finding the exit gone.\n\n", typingspeed);
				Sleep(1000);
				break;
		}
		
		break;
	case 2:
		// Search the wreckage for supplies
		TypeOut("You cautiously approach the wreckage of your ship, searching for any usable supplies that might aid in your survival. Amidst the twisted metal you see 3 essential items however a fire is quickly approching them and you only have time to grab one. \n\n", typingspeed);
		
		supply_choice = GetChoice(" Which item do you choose to take? \n 1. A first aid kit \n 2. A multi-tool \n 3. A portable water purifier", 3);
		break;
	case 3:
		// Call for help using the ship's radio
		TypeOut("You decide to use the ship's radio to call for help, hoping that someone might be able to pick up your distress signal. You take the radio and find its got no power\n\n", typingspeed);
		TypeOut("You press the radio’s power switch again, but nothing happens. The device is completely dead—not even a flicker of light. The crash must have drained or destroyed its power source. If you want to call for help, you’ll need to find some way to bring it back to life.\n\n", typingspeed);

		radio_choice = GetChoice(" 1. Search the wreckage for anything that could act as a battery\n 2. Try to repair the radio’s internal wiring using scrap tools\n 3. Attempt to build a crude power source from broken components", 3);
		switch (radio_choice) {

		case 1:
		//Search the wreckage for anything that could act as a battery
			TypeOut("You dig through the wreckage, tossing aside burnt panels and broken wiring. Eventually you find a half-melted emergency battery. It's damaged beyond functioning.\n\n", typingspeed);
			Sleep(1000);
			break;

		case 2: 
		//Try to repair the radio’s internal wiring using scrap tools
			TypeOut("You crack open the radio casing and start rearranging the torn wires. Sparks jump once or twice, but after a few minutes it's clear the internal board is fried beyond simple repair.\n\n", typingspeed);
			Sleep(1000);
			break;

		case 3: 
		//Attempt to build a crude power source from broken components
			TypeOut("You gather scraps of copper, wiring, and metal shards. With some patience you manage to jury-rig a tiny makeshift power cell. It's unstable and weak, but it produces a faint current. Not enough to broadcast the signal farther than 10 kilometers let alone another planet or ship.\n\n", typingspeed);
			Sleep(1000);
			break;

		}

		
		break;
	default:
		cout << "this case should be impossible to fufill. If you did then congratulations you broke my code...\n\n";
		//Blah just because I am sure Conner will manage it.
		return 41;
	}
	Sleep(1500);
	cls();
	system("color 53"); //Set text color to purple and background blue if i recall correctly
	TypeOut("alr thats all ive got for now thanks \n\n", typingspeed);
	return 69; 
	 
}