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

// Clears Input Buffer as to provent infinite loops on invalid input
void ClearInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function for displaying a choice and handling the choice the user makes fr
int GetChoice(string prompt, int number_of_choices) {
	int choice = -1;
	do
	{
		ClearInputBuffer();//Safeguard against infinite loops on invalid input

		std::cout << prompt << endl;
		cin >> choice;

	} while (choice < 1 || choice > number_of_choices);
	return choice;

}

void cls() {
	system("cls");

}

//Types out text input with a wait between characters as it looks better
void TypeOut(const std::string& Text, int delayMs = 50) {
	for (char c : Text)
	{
				std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % delayMs));
	}
	
}

int typingspeed = 50; //Global variable for typing speed
int main(){
	string Name;
	std::cout << "Hello welcome to Venessa, a Text based adventure game! \n Please enter your name User." << std::endl;
	getline(cin,Name);
	cls();
	TypeOut("Welcome " + Name + ", to the world of Venessa! \n\n", 20);
	
	Sleep(1000); //Allow User to read welcome message

	TypeOut("Your story starts as you awake with a splitting headache and little memory. As you look around you find yourself on a spaceship with dim lighting and an erie silence, as you look around you spot two diffrent hallways. The first appares to have a medical sign pointing to it, The other appares to be the direction to the cockpit of the ship\n\n\n", typingspeed);
	
	int first_choice = GetChoice("Which hallway do you choose? \n 1. Medical Bay \n 2. Cockpit", 2);
	cls();

	if (first_choice == 1) {
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

	TypeOut("You head towards the cockpit, as the door is locked and you must figure out the code. as you look at the four digit lock you notice a clock next to it showing the current time. Whats your guess?\n\n", typingspeed);
	
	int timeCode = 1000;
	int code_guess = 12;
	 do {
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
	//std::cout << "Debug: The correct code is " << timeCode << std::endl;
	
		
		if (code_guess == timeCode) {
			cls();
			break;
		}
		TypeOut("The lock lets out a buzzing sound and a faint red light. Try again.\n", 40);
	}while (code_guess != timeCode);
	TypeOut("The lock beeps and the door slides open, you enter the cockpit and find the controls of the ship. Suddenly, an alarm goes off indicating that the ship's systems are failing, the ship was constructed to be operated by a team of people 24/7 due to the lack of people operating and upkeeping systems they are failing!\n\n", typingspeed);

	std::cout << "To be continued...\n";

	return 0; 

}