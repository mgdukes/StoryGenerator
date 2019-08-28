// Story generator app
// Generates a story from a random selection, filling in pieces of it with user input
// Author: Meghan Dukes

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class StoryMaker
{
public:
	
	// prompts user to fill in variables
	void getInput()
	{
		cout << "Enter a food.\n>";
		food = getAns(food);
		cout << "Enter a creature (real or mythical).\n>";
		creature = getAns(creature);
		cout << "Enter an item (e.g. lamp, tree).\n>";
		item = getAns(item);
		cout << "Enter an interjection, without punctuation.\n>";
		interjection = getAns(interjection);
		cout << "Enter a name.\n>";
		name = getAns(name);
		cout << "Enter a place.\n>";
		place = getAns(place);
		cout << "Enter an emotion (as in, I am feeling ___).\n>";
		emotion = getAns(emotion);
		cout << "Enter a utensil or tool.\n>";
		tool = getAns(tool);
		cout << endl;
	}

	// randomly chooses a story from a given set and returns it filled in with
	// 	input values
	string randomStory()
	{
		//be sure name and interjection are capitalized
		name[0] = toupper(name[0]); 
		interjection[0] = toupper(interjection[0]);

		//random number to determine story
		int randnum = rand() % 5 + 1;
		string story; 

		switch (randnum)
		{
		case 5:
			story = "If you're going to " + name + "'s Diner,\n"
				+ "here's some things to know: \n"
				+ "1. The roast " + creature + " doesn't come with a " + tool + ".\n"
				+ "\tYou have to bring your own.\n"
				+ "2. The " + food + " is so good, you'll say \"" + interjection + "!\"\n"
				+ "3. The " + place + " special now comes with a free " + item + "\n"
				+ "4. Everyone who goes to " + name + "'s comes out feeling " + emotion + "\n"
				+ "Try " + name + "'s today!\n";
			break;
		case 4:
			item[0] = toupper(item[0]);
			story = "There once was a girl named " + name + ", but her friends\n" 
				+ "called her " + item + " (it's a long story). Well one day " + item + "\n"
				+ "was walking by the woods when she saw a " + creature + ". She was so\n"
				+ emotion + " to see it there that she yelled out \"" + interjection + "!\n"
				+ "\"A " + creature + "!\". She tried to convince it to come out by giving\n"
				+ "it " + food + ". She even made it a little house out of a " + tool + " she\n"
				+ "happened to have with her. But the " + creature + " went back in the woods.\n"
				+ "\"Oh well,\" " + item + " said, \"I guess it's better off in " + place + "\n"
				+ "in its natural habitat.\"\n";
			break;
		case 3:
			story = "There once was a guy named " + name + ".\n"
				+ "He liked " + food + ". One day, " + name + " was taking a walk\n"
				+ "in " + place + ", when suddenly he saw a " + creature + "!\n"
				+ "He watched as it was walking by, until it turned around and said\n\""
				+ interjection + "! What, you ain't never seen a " + creature + " before?\"\n"
				+ "It tossed a " + item + " at him in disgust and left. " + name + "\n"
				+ "was left feeling " + emotion + " and quietly went back to using his " + tool + ".\n";
			break;
		case 2:
			story = "To become a successful " + creature + " herder,\n"
				+ "you have to be like the great " + name + " of " + place + ":\n"
				+ "he fed them plenty of " + food + ", he was skillful with a " + tool + ",\n"
				+ "and he was always a " + emotion + " person who wasn't afraid to say \n"
				+ "\"" + interjection + ", get back here you " + creature + "!\"\n"
				+ "If you treat your " + creature + "s right just like " + name + ", they\n"
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
				+ "said \"Hey, wait! I could sell you a " + tool + " instead!\"\n";
			break;
		}
		return story;
	}

private:
	string food, creature, item, interjection,
		name, place, emotion, tool; 

	string getAns(string ans)
	{
		do 
		{
			getline(cin, ans);
		} while (ans.length() < 1);
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
		cout << "\t*******************\n"
			<< "\t| Story Generator |\n"
			<< "\t*******************\n";
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


//clear screen regardless of platform
void clearScreen()
{
	#ifdef WINDOWS
		system("cls");
	#else
		// Assume POSIX
		system ("clear");
	#endif
}