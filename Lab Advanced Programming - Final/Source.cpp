#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Ship
{
public:
	Ship(string n, int sp, int pDmg, int sDmg)
	{
		name = n;
		structuralPoints = sp;
		primaryDmg = pDmg;
		secondaryDmg = sDmg;
	}

	void takeDamage(int amount) { structuralPoints -= amount; }
	int getPrimaryAttack() const { return primaryDmg; }
	int getSecondaryAttack() const { return secondaryDmg; }

	string getShipInfo()
	{
		stringstream s;
		s << "Ship name: " << name << "\t Structural Points: " << structuralPoints << endl;
		return s.str();

	}

private:
	string name;
	int structuralPoints;
	int primaryDmg;
	int secondaryDmg;
};

class Carrier
{
public:

	Carrier(string name, int maxShips) {
		this->name = name;
		this->maxShips = maxShips;
		numShips = 0;
		shipList = new Ship * [maxShips];


	}

	bool addShip(string name, int sp, int pDmg, int sDmg)
	{
		if (numShips < maxShips)
		{
			Ship* newShip = new Ship(name, sp, pDmg, sDmg);
			shipList[numShips] = newShip;
			numShips++;
			return true;
		}
		return false;
	}

	Ship* launchShip(int pos)
	{
		if (pos >= numShips)
		{
			return NULL;
		}
		Ship* temp = shipList[pos];
		shipList[pos] = shipList[numShips - 1];
		numShips--;
		return temp;

	}

	string getCarrierInfo()
	{
		stringstream s;
		s << "Carrier Name: " << name << "\n";
		s << "Ships Carried: \n";
		for (int x = 0; x < numShips; x++) {
			s << shipList[x]->getShipInfo() << endl;
		}
		return s.str();
	}

	int getNumShips() const
	{
		return numShips;
	}
	string getName() const
	{
		return name;
	}
private:

	string name;

	int numShips;
	int maxShips;

	Ship** shipList;

};

int main()
{
	Carrier c1("The Carry 5000", 10);
	c1.addShip("X-Wing", 350, 25, 180);
	c1.addShip("A-wing", 200, 20, 60);
	c1.addShip("Y-wing", 500, 15, 400);

	cout << c1.getCarrierInfo();

	return 0;

	/*Ship s1("X-Wing", 250, 30, 180);
	cout << s1.getShipInfo();*/
}