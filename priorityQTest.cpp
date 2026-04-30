#include "priorityQ.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
	priorityQ<string, int> marioKart;

	marioKart.push_back("Mario", 7);
	marioKart.push_back("Peach", 11);
	marioKart.push_back("KoopaTroopa", 8);
	marioKart.push_back("Luigi", 6);
	marioKart.push_back("Bowser", 5);
	marioKart.push_back("Wario", 3);

	marioKart.update_element("Mario", 2);
	marioKart.update_element("Wario", 15);
	marioKart.update_element("Peach", 1);

	while (!marioKart.isEmpty())
	{
		cout << marioKart.get_front_key() << " ";
		cout << marioKart.get_front_priority() << endl << endl;

		marioKart.pop_front();
	}

	return 0;
}
