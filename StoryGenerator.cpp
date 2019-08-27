// Story generator app
// Generates a story from a random selection, filling in pieces of it with user input
// Author: Meghan Dukes

#include <iostream>
#include <string>
using namespace std;

class StoryMaker
{
public:
	
	void getInput()
	{
		cout << "Type in a food, and then press Enter.\n";
		food = getAns(food);
		cout << "Type in a creature, then press Enter.\n";
		creature = getAns(creature);
		cout << "Enter the name of any item, like a lamp or a tree.\n";
		item = getAns(item);
		cout << "Enter an interjection, capitalized but without punctuation.\n";
		interjection = getAns(interjection);
		cout << "Enter a name, either normal or kooky.\n";
		name = getAns(name);
		cout << "Enter a place.\n";
		place = getAns(place);
		cout << "Enter an emotion (as in, I am feeling ___).\n";
		emotion = getAns(emotion);
		cout << "Enter a utensil.\n";
		utensil = getAns(utensil);
		cout << endl;
	}

	string randomStory()
	{
		//random number to determine story
		int randnum = rand() % 2 + 1;
		string story;

		switch (randnum)
		{
		case 2:
			story = "To become a successful " + creature + " herder,\n"
				+ "you have to be like the great " + name + " of " + place + ":\n"
				+ "he fed them plenty of " + food + ", he was skillful with a " + utensil + ",\n"
				+ "and he was always a " + emotion + " person who wasn't afraid to say \n"
				+ "\"" + interjection + ", get back here you " + creature + "\n"
				+ "will love you and give you lots of " + item + "s.\n";
			break;
		
		default:
			story = "One day, " + name + " was taking a walk. He said \"Boy, I'm hungry. \n"
				+ "I could really go for " + food + "s!\"" + "\n"
				+ "So he went to the nearby " + food + " stand and placed his order.\n"
				+ "The " + creature + " cashier said \"" + interjection + "! You had\n"
				+ "to ask for that. We don't sell " + food + "s anymore.\n"
				+ "But would you like a nice " + item + "? That's what we sell now.\"\n"
				+ name + " was " + emotion + ". \"What?! A " + food + " stand that only sells\n"
				+ item + "s? That's ridiculous! I'm going to the stand in " + place + ".\n"
				+ "They'll have better service.\" As he walked away, the " + creature + "\n"
				+ "said \"Hey, wait! I could sell you a " + utensil + " instead!\"\n";
			break;
		}
		return story;
	}

private:
	string food, creature, item, interjection,
		name, place, emotion, utensil; 

	string getAns(string ans)
	{
		do 
		{
			getline(cin, ans);
		} while (ans.length() < 2); //TODO: modify so that single-again answers are allowed
	return ans;
	}
};


void clearScreen();


int main()
{
	StoryMaker storymaker;
	char again;
	do
	{
		clearScreen();
		storymaker.getInput();
		cout << "Okay, here's your story:\n\n";
		cout << storymaker.randomStory();
		cout << endl;
		cout << "The End\n (applause please)\n";
		cout << "\nEnter 'Y' to fill in the story with different values\n" 
			<< "or enter 'N' to end program\n";
		cin >> again;
	} while (again == 'Y' || again == 'y');
    return 0;
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