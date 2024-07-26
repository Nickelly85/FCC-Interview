#include "player.h"

class game {
public:
	player p;
	vector<int> scores;
	map<int, pair<double, int>> m;

	void play() {
		
		
		for (int i = 0; i < iterations; i++) {
			p.numDice = diceAmount;
			while (p.numDice != 0) {
				p.rollDice();
				score();
			
			}
			scores.push_back(p.score); // Push all scores into one vector
			p.score = 0;
		}

		calculateStats();
		printStats();
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

		p.d.clear();
	}

	void calculateStats() {
		double counter = 0;
		double percent = 0;
		

		while (scores.size() != 0) {
			int temp = scores.back();
			for (int i = scores.size() - 1; i >= 0; i--) {
				if (temp == scores[i]) {
					scores.erase(scores.begin() + i);
					counter++;
				}
			}

			percent = counter / iterations;

			m.insert(make_pair(temp, make_pair(percent, counter)));

			counter = 0;
		}
	}

	void printStats() {
		cout << "Number of simulations was " << iterations << " using " << diceAmount << " dice." << endl;
		for (int i = 0; i <= diceAmount * 6; i++) {
			auto temp = m.find(i);

			if (temp != m.end()) {
				cout << "Total " << temp->first << " occurs " << temp->second.first << " occurred " << temp->second.second << " times." << endl;
			}
		}
	}

};
