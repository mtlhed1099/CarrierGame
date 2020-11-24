//William Bryant
//11-14-2020
//Main source code

#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Source.h"

using namespace std; //uses standard namespace so i don't ahve to type std:: all the time

//parent class
class warShip
{

	//attributes that the user can apply to either the submarine or carrier
protected:
	string coName;
	string hullName;
	int hullNumber;

	//methods
public:
	//blank constructor to set aside memory
	warShip()
	{}
	//constructor
	warShip(string A, string B, int H)
	{
		coName = A;
		hullName = B;
		hullNumber = H;
	}
	//set methods
	void setcoName(string A)
	{
		coName = A;
	}
	void sethullName(string B)
	{
		hullName = B;
	}
	void sethullNumber(int H)
	{
		hullNumber = H;
	}
	//get methods
	string getcoName()
	{
		return coName;
	}
	string gethullName()
	{
		return hullName;
	}
	int gethullNumber()
	{
		return hullNumber;
	};
	//display methods
	void Display()
	{
		cout << "CO's Name = " << coName << endl;
		cout << "Ship Name = " << hullName << endl;
		cout << "Hull Number = " << hullNumber << endl;
	}
};//end of class warship class

//make a child submarine class with torpedoes
class Submarine : public warShip
{
	//attributes
private:
	string SubWeapon;
	int Torpedo;

public:
	//blank constructor to set aside memory
	Submarine()
	{}
	//constructor calling from warShip
	Submarine(string A, string B, int H, string E, int F) : warShip(A, B, H)
	{
		warShip(A, B, H);
		SubWeapon = E;
		Torpedo = F;

	}
	//set method, encapsulate, pass in hull number to set
	void setCarrierWeapon(string E)
	{
		SubWeapon = E;
	}
	void setAircrafts(int F)
	{
		Torpedo = F;
	}

	//get method
	string getSubWeapon()
	{
		return SubWeapon;
	}
	int getTorpedo()
	{
		return Torpedo;
	}

	//display method
	void Display()
	{
		warShip::Display();
		cout << "Submarine has = " << Torpedo << " " << SubWeapon << endl;
	}

};//End of Submarine  Class

//make a child carrier class with airplanes
class Carrier : public warShip
{
	//attributes
private:
	string CarrierWeapon;
	int airCrafts;

public:
	//blank constructor to set aside memory
	Carrier()
	{}
	//constructor calling from warShip
	Carrier(string A, string B, int H, string C, int D) : warShip(A, B, H)
	{
		warShip(A, B, H);
		CarrierWeapon = C;
		airCrafts = D;

	}
	//set method, encapsulate, pass in hull number to set
	void setCarrierWeapon(string C)
	{
		CarrierWeapon = C;
	}
	void setAircrafts(int D)
	{
		airCrafts = D;
	}

	//get method
	string getCarrierWeapon()
	{
		return CarrierWeapon;
	}
	int getAircrafts()
	{
		return airCrafts;
	}

	//display method
	void Display()
	{
		warShip::Display();
		cout << "Carrier has = " << airCrafts << " " << CarrierWeapon << endl;
	}

};//End of Carrier Class


int main()//begin main function
{
	//set the class values of carrier and submarine
	Carrier Car("Larry Snively", "Essex", 47, "Aircrafts", 5);
	
	//Submarine Sub("Bob", "OKC", 723, "Torpedoes", 10);
	Submarine Sub("Davy Jones", "Flying Dutchman", 1641, "Torpedoes", 15);
	
	//declare variables from class values to edit as the program flows
	int carWep = Car.getAircrafts();

	//ask user for their name
	string user = askUser("What is your name? ");	//call username function			

	cout << "Welcome " << user << endl;
	//tell user what they're going to be doing
		instructions();																										//Function instructions

	//welcome the player, dispay carrier stats
	cout << "Welcome to the combat simulator, we have a great carrier for you:\n" << endl;
	Car.Display();	//displays carrier's base stats
	cout << endl;
	//Sub.Display();	//displays submarine's base stats
	
	//enter main game loop
	char again;
	int sunk = 0;

	do//begin game loop
	{
		cout << "An enemy battleship arrives\n" << endl;
		int firedWep = 1;//only 1 weapon fied at a time
		fireWeapon(&carWep, &firedWep);//reference the carrier's weapon and fire value to run the function
		
		int roll = wepHit();	//roll

		cout << "You roll a " << roll << "." << endl;	//tell user what they rolled

		if (roll <= 5)
		{
			cout << "\nYou missed! BRACE FOR ENEMY COUNTERFIRE" << endl;
		}
		else if (roll > 5)
		{
			cout << "\nDirect hit!" << endl;
			sunk = sunk + 1;	//count sunk battleships
		};

		
		cout << "Continue the fight? (y/n)";	//give user the chance to stop
		
		cin >> again;

		if (again == 'n')
		{
			break;
		}
		else
			continue;
	} while (carWep >=1);

	cout << endl;
	cout <<user<<" you ran out of aircrafts to fight with!";
	cout << "\n" << sunk << " Battleships sunk.\n\n";

	cout << "***New class coming in 2025***\n\n";//give them another class to look forward to next time!
	Sub.Display();
	cout << "\n\nHave a great day!";


									

							






	char c;								//pause code
	cout << " " << endl;
	cin >> c;

	return 0;
} //end main function

