#include "player.h"

class game {
public:
	player p;
	vector<int> scores;

	void play() {
		p.numDice = diceAmount;
		
		for (int i = 0; i < iterations; i++) {
			while (p.numDice != 0) {
				p.rollDice();
				score();
			
			}
			scores.push_back(p.score); // Push all scores into one vector
		}
	}
	
private:
	void score() {
		int min = 7;
		int counter = 0;
		bool isThree = false;

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

		cout << "Total score " << p.score << endl;
		p.d.clear();
	}

};
