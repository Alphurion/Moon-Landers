#include "lander.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

const int TIME = 1; // 1 second of time for the simulation function

lander::lander(string name, double mass, double thrust, double max_fuel, double alt, double fuel)
{
  lander_mass = mass;
  max_thrust = thrust;
  max_fuel_consumption_rate = max_fuel;

  stillLanding = true;
  flow_rate = 0.0;
  velocity = 0.0;
  altitude = alt;
  fuel_amount = fuel;
  this->name = name;
}
/*
Returns 'a' if airborne, 'c' if not airborne and velocity <= -2, and 'T' if not airborne and velocity is within reason
> -2
*/
char lander::get_status() const
{
  if (this->altitude > 0.0)
  {
    return 'a'; // Airborne.
  }
  else if ((this->altitude == 0) && (this->velocity <= -2))
  {
    return 'c'; // Crashed.
  }
  else
  {
    return 'T'; // Landed, yay!
  }
}
/*
Changes the flow rate and updates fuel amount if == 0. Does nothing if flow rate is invalid.
*/
bool lander::change_flow_rate(double r)
{
	if((r <= 1) && (r >= 0))
	{
		this->flow_rate = r;
		if(this->fuel_amount == 0)
		{
			this->flow_rate = 0;
		}
		return true;
	}
	else
	{
		return false; //Invalid flow rate.
	}
}

void lander::simulate()
{
  /*
  1. Calculate V_ins by (TIME * (flow_rate * max thrust)/(lander_mass *
  fuel_Amount)) - 1.62
  2. Increment velocity field by v
  3. Update velocity by TIME * velocity f ield
  4. Update StillLanding
  5. Decrement Fuel_Amount by TIME * max_fuel_rate * | v|
  6. Set fuel amount to 0 if the amount results to negative for fuel amount
  */


}
/*
Compares values and decides which lander is prioritized.
*/
bool lander::operator<(const lander &rhs) const
{
	if(this->altitude != rhs.altitude)
	{
		return this->altitude < rhs.altitude;
	}
	if(this->fuel_amount != rhs.fuel_amount)
	{
		return this->fuel_amount < rhs.fuel_amount;
	}
	if(this->lander_mass != rhs.get_mass())
	{
		return this->lander_mass < rhs.get_mass();
	}
	if(this->get_name() != rhs.get_name())
	{
		return this->get_name() < rhs.get_name();
	}
	return false;
}
