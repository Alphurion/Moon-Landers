#include <string>
#include <iostream>
#include <iomanip>
#include "lander.h"
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

void outputLanderInfo(const lander&);

int main()
{
	cout << fixed << setprecision(2);

	double t1[] = { 0.1, 0.4, 1.5, 0.9, 0.8, -0.1, 1.2, 0.9, 0};
	double t2[] = { 0.7, 0, 0.9, 1.7, 0, -0.5, 0.4, 0.1, 1.0 };

	lander l1("GalacticGiggle", 200.0, 1000.0, 3.3, 25.0, 100.0);
	lander l2("MoonDance", 1500.0, 5500.0, 25.0, 25.0, 250.0);


	if (l1 < l2)
		cout << l1.get_name() << " is ahead" << endl << endl;
	else
		cout << l2.get_name() << " is ahead" << endl << endl;

	for (int i = 0; i < 9; i++)
	{
		l1.change_flow_rate(t1[i]);
		l2.change_flow_rate(t2[i]);

		l1.simulate();
		l2.simulate();

		outputLanderInfo(l1);
		outputLanderInfo(l2);

		if (l1 < l2)
			cout << l1.get_name() << " is ahead" << endl << endl;
		else
			cout << l2.get_name() << " is ahead" << endl << endl;
	}



	return 0;
}

void outputLanderInfo(const lander& l)
{
	cout << l.get_name () << " " << l.get_altitude() << "m ";
	cout << l.get_fuel_amount() << " gal " << l.get_velocity() << " m/s";
	cout << endl;
}
