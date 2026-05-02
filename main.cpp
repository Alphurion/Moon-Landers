#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "priorityQ.h"
#include "lander.h"

/*
1. Prompt simulation txt name
2. Parse the file
3. Create a simulation Loop

*/
int main()
{
	/*
	Racetothemoon: Holds all landers
	infile: For reading in the lander names and defaults
	Double list: All aspects of lander that will be simulated
	Name: Name of the lander
	*lander: Holds data for the lander to be created when read in 
	*/
  priorityQ<std::string, lander> raceToTheMoon;
  std::ifstream infile("LanderInput.txt");
  double mass, max_thrust, max_fuel, alt, fuel, max_fuel_consumption_rate;
  std::string name;
  lander *ship;

  while (!infile.eof())
  {
    infile >> name >> mass >> max_thrust >> max_fuel >> max_fuel_consumption_rate >> alt >> fuel;
    ship = new lander(name, mass, max_thrust, max_fuel, alt, fuel);
    raceToTheMoon.push_back(name, *ship);
  }

  infile.close();

	/*
	THE SIMULATION
	1. Read in the ship name >> thrust of the ship
	2. Update the element
	3. Check if the ship is still alive
	4. Pop ship if landed/crashed
	5. Keep simulating loop until there are no more landers
	
	throttle: Holds the current thrust of read in ship
	iteration: Keeps track of 
	*/
  double throttle = 0.0;
	int iteration = 0; 
  while (!raceToTheMoon.isEmpty())
  {
		/*
			Enter lander name and throttle amount:
		*/
    std::cin >> name >> throttle;
		
		if(raceToTheMoon.isEmpty())
		{
			break;
		}
		if(raceToTheMoon.get_element(name).get_altitude() <= 0)
		{
			raceToTheMoon.pop_front();
		}
		raceToTheMoon.get_element(name).simulate();
		std::cout 
		<< "Name " << name << raceToTheMoon.get_element(name).get_altitude() << " meters from the moon surface"
		<< "Traveling at " << raceToTheMoon.get_element(name).get_velocity() << " m/s"
		<< "Fuel: " << raceToTheMoon.get_element(name).get_fuel_amount() << std::endl;

		/*
		(ship number) Name: shipname (number) meters from moon surface
		Traveling at (number) m/s
		Fuel: (number)

		Name crashed :(
		*/
	}
  return 0;
}
