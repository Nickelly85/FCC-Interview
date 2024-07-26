#include "dice.h"

class player {
public:
	vector<dice> d;
	int numDice;
	int score;

	// Constructor
	player() {
		numDice = 0;
		score = 0;
	}
	
	// Method to roll dice (Generates random number)
	void rollDice() {
		dice temp;
		for (int i = 0; i < numDice; i++) {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6); // distribution in range [1, 6]

			temp.value = dist6(rng);

			d.push_back(temp);
		}
	}
};
