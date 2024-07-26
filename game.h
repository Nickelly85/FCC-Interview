#include "player.h"

class game {
public:
	player p;
	vector<int> scores;

	void play() {
		p.numDice = diceAmount;
		int min = 7;
		int counter = 0;
		bool isThree = false;
		

		while (p.numDice != 0) {
			p.rollDice();
			
			for (int i = 0; i < p.numDice; i++) {
				if (p.d[i].value == 3) {
					isThree = true;
					counter++;
				}
				else if (min > p.d[i].value) {
					min = p.d[i].value;
				}
			}
			if (isThree) {
				p.score += 0;
				p.numDice -= counter;
			}
			else {
				p.score += min;
				p.numDice--;
			}
			p.d.clear();
		}
	}
};
