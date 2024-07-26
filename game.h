#include "player.h"

class game {
public:
	player p;
	vector<int> scores;
	map<int, pair<double, int>> m;


	// Method to run game
	void play() {
		// Loop for as many iterations set
		for (int i = 0; i < iterations; i++) {
			p.numDice = diceAmount; // Set numDice to global dice amount
			while (p.numDice != 0) {
				p.rollDice();
				score();
			}
			scores.push_back(p.score); // Push all scores into one vector
			p.score = 0; // Reset score to 0 for next iteration
		}

		calculateStats();
		printStats();
	}
	
private:
	// Method to score game
	void score() {
		int min = 7; // Set min variable to capture the min value if no 3's rolled
		int counter = 0; // Variable to keep track of how many 3's were rolled to delete the correct number of dice
		bool isThree = false; // Bool gate variable, if three is rolled

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
		p.d.clear(); // Clear dice for next iteration
	}

	// Method to calculate statistics
	void calculateStats() {
		double counter = 0;
		double percent = 0;
		
		// While scores still in vector
		while (scores.size() != 0) {
			int score = scores.back();
			for (int i = scores.size() - 1; i >= 0; i--) {
				if (score == scores[i]) {
					scores.erase(scores.begin() + i); // Erase instances of specific score
					counter++; // Keep count how many of that score
				}
			}

			percent = counter / iterations; // Calculate percentage based on number of times / iterations

			m.insert(make_pair(score, make_pair(percent, counter))); // Insert into map for easy print displaying and organization

			counter = 0; // Reset counter for next score
		}
	}

	// Method to print statistics
	void printStats() {
		cout << "Number of simulations was " << iterations << " using " << diceAmount << " dice." << endl;
		// Check for every possible score based on dice amount
		for (int i = 0; i <= diceAmount * 6; i++) {
			auto temp = m.find(i); // Find score
			// If find doesn't find anything it points to end, which will cause error so make sure it's not pointing to the end
			if (temp != m.end()) {
				cout << "Total " << temp->first << " occurs " << temp->second.first << " occurred " << temp->second.second << " times." << endl;
			}
		}
	}

};
