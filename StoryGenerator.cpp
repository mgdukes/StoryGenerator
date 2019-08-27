// Story generator app
// Generates a story from a random selection, filling in pieces of it with user input
// Author: Meghan Dukes

#include <iostream>
#include <string>
using namespace std;

class UserInput
{
	public:
	string food, creature, item, interjection,
		name, place, emotion, utensil;
};

string getAns(string ans);
void clearScreen();
void getInput(UserInput& userInput);
string randomStory(UserInput& userInput);


int main()
{
	UserInput inputFromUser;
	char again;
	do
	{
		clearScreen();
		getInput(inputFromUser);
		cout << "Okay, here's your story:\n\n";
		cout << randomStory(inputFromUser);
		cout << endl;
		cout << "The End\n (applause please)\n";
		cout << "\nEnter 'Y' to fill in the story with different values\n" 
			<< "or enter 'N' to end program\n";
		cin >> again;
	} while (again == 'Y' || again == 'y');
    return 0;
}

string getAns(string ans)
{
	do 
	{
		getline(cin, ans);
	} while (ans.length() < 2); //TODO: modify so that single-again answers are allowed
return ans;
}

void getInput(UserInput& userInput)
{

	cout << "Type in a food, and then press Enter.\n";
	userInput.food = getAns(userInput.food);
	cout << "Type in a creature, then press Enter.\n";
	userInput.creature = getAns(userInput.creature);
	cout << "Enter the name of any item, like a lamp or a tree.\n";
	userInput.item = getAns(userInput.item);
	cout << "Enter an interjection, capitalized but without punctuation.\n";
	userInput.interjection = getAns(userInput.interjection);
	cout << "Enter a name, either normal or kooky.\n";
	userInput.name = getAns(userInput.name);
	cout << "Enter a place.\n";
	userInput.place = getAns(userInput.place);
	cout << "Enter an emotion (as in, I am feeling ___).\n";
	userInput.emotion = getAns(userInput.emotion);
	cout << "Enter a utensil.\n";
	userInput.utensil = getAns(userInput.utensil);
	cout << endl;
}

string randomStory(UserInput& userInput)
{
	//random number
	string story = "One day, " + userInput.name + " was taking a walk. He said \"Boy, I'm hungry. \n"
			+ "I could really go for " + userInput.food + "s!\"" + "\n"
			+ "So he went to the nearby " + userInput.food + " stand and placed his order.\n"
			+ "The " + userInput.creature + " cashier said \"" + userInput.interjection + "! You had\n"
			+ "to ask for that. We don't sell " + userInput.food + "s anymore.\n"
			+ "But would you like a nice " + userInput.item + "? That's what we sell now.\"\n"
			+ userInput.name + " was " + userInput.emotion + ". \"What?! A " + userInput.food + " stand that only sells\n"
			+ userInput.item + "s? That's ridiculous! I'm going to the stand in " + userInput.place + ".\n"
			+ "They'll have better service.\" As he walked away, the " + userInput.creature + "\n"
			+ "said \"Hey, wait! I could sell you a " + userInput.utensil + " instead!\"\n";
	return story;
}

void clearScreen()
{
	#ifdef WINDOWS
		system("cls");
	#else
		// Assume POSIX
		system ("clear");
	#endif
}