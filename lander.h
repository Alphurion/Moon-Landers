#include <string>

#ifndef LANDER_H
#define LANDER_H

class lander
{
public:
	lander(std::string = "", double = 0, double = 0,
		double = 0, double = 0, double = 0);

	double get_velocity() const { return velocity; }
	double get_altitude() const { return altitude; }
	double get_fuel_amount() const { return fuel_amount; }
	std::string get_name() const { return name; }

	double get_mass() const { return lander_mass; }
	double get_max_thrust() const { return max_thrust; }

	char get_status() const;
	bool change_flow_rate(double);
	void simulate();

	bool operator<(const lander&) const;
private:
	std::string name;
	double flow_rate;
	double velocity;
	double altitude;
	double fuel_amount;
	bool stillLanding;
	double lander_mass;
	double max_fuel_consumption_rate;
	double max_thrust;
};

#endif
