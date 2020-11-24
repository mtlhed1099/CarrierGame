/*

	William Bryant
	11/14/2020
	Funciton prototypes

*/

#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include<cstdlib>
#include<ctime>
#include "Source.h"

using namespace std;
//ask user for their name
string askUser(string prompt)
{
	string user;	//declare user as a string
	cout << prompt;	//make the prompt a cout
	cin >> user;	//user input
	return user;	//return the user's name

};//end username function

  //set up some instructions
void instructions()
{
	cout << "You will be given a Carrier to fight with, Good Luck!.\n";
}

//roll for weapon hitting
int wepHit()//roll for weapon hit or miss
{
	srand(static_cast<unsigned int>(time(0))); //seed the random number generator

	int randomNumber = rand(); //generate random number

	int roll = (randomNumber % 10) + 1; //roll 1-10

	return roll;
}

//subtract 1 from weapons fired
void fireWeapon(int* car, int* y)
{
	cout << "You launch an aircraft to attack. ";
	*car = *car - *y;	//point to 2 values to use. 
	cout << *car << " Aircraft(s) remain...";	//output new value to user
}



