#include "player.h"

class game {
public:
	player p;
	vector<int> scores;

	void play() {
		
		
		for (int i = 0; i < iterations; i++) {
			p.numDice = diceAmount;
			while (p.numDice != 0) {
				p.rollDice();
				score();
			
			}
			scores.push_back(p.score); // Push all scores into one vector
			p.score = 0;

			cout << "ITERATION COMPLETE!" << endl;
		}

		calculateStats();
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

	void calculateStats() {
		int counter = 0;


		while (scores.size() != 0) {
			for (int i = 0; i < scores.size(); i++) {
				cout << scores[i] << " ";
			}
			int temp = scores.back();
			for (int i = scores.size() - 1; i >= 0; i--) {
				if (temp == scores[i]) {
					scores.erase(scores.begin() + i);
					counter++;
				}
			}
			cout << "Count: " << counter << endl;
			cout << "Scores: ";

			counter = 0;
		}
	}

};
