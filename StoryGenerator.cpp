// Programming_for_fun.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string getAns(string ans);

int main()
{
	string food, creature, item, interjection;
	string name, place, emotion, utensil;
	char letter;
	do
	{
		system("cls");
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
		cout << "Okay, here's your story:\n";
		cout << endl;
		cout << "One day, " << name << " was taking a walk. He said \"Boy, I'm hungry. \n"
			<< "I could really go for " << food << "s!\"" << endl
			<< "So he went to the nearby " << food << " stand and placed his order.\n"
			<< "The " << creature << " cashier said \"" << interjection << "! You had\n"
			<< "to ask for that. We don't sell " << food << "s anymore.\n"
			<< "But would you like a nice " << item << "? That's what we sell now.\"\n"
			<< name << " was " << emotion << ". \"What?! A " << food << " stand that only sells\n"
			<< item << "s? That's ridiculous! I'm going to the stand in " << place << ".\n"
			<< "They'll have better service.\" As he walked away, the " << creature << endl
			<< "said \"Hey, wait! I could sell you a " << utensil << " instead!\"\n";
		cout << endl;
		cout << "The End\n (applause please)\n";
		cout << "\nEnter 'Y' to fill in the story with different values\n" 
			<< "or enter 'N' to end program\n";
		cin >> letter;
	} while (letter == 'Y' || letter == 'y');
    return 0;
}

string getAns(string ans)
{
	do 
	{
		getline(cin, ans);
	} while (ans.length() < 2);
return ans;
}