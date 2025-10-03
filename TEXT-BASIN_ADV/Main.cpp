#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function for displaying a choice and handling the choice the user makes fr
int GetChoice(string prompt, int number_of_choices) {
	int choice = -1;
	do
	{
		cout << prompt << endl;
		cin >> choice;

	} while (choice < 1 || choice > number_of_choices);
	return choice;

}




int main(){
	string Name;
	cout << "Hello welcome to Venessa, a Text based adventure game! \n Please enter your name User." << std::endl;
	cin >> Name;
	cout << "Welcome, " << Name << " to the world of Venessa! \n\n Your story starts as you awake with a splitting headache and little memory. As you look around you find yourself on a spaceship with dim lighting and an erie silence, as you look around you spot two diffrent hallways. The first appares to have a medical sign pointing to it, The other appares to be the direction to the cockpit of the ship\n\n\n";

}