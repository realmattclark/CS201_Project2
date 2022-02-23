#include <iostream>
using namespace std;

int liveCards[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
int deadCards[16] = {};
int score = 0;
int through() {
	int total = 0;
	for (int i = 0; i < 16; i++) {
		if (deadCards[i] > 0) total++;
	}
	return total;
}

void showDeadCards() {
	for (int i = 0; i < 16; i++) {
		if (deadCards[i] > 0)
		cout << right << deadCards[i];
	}
	cout << endl;
}

void showLiveCards() {
	for (int i = 0; i < 16; i++) {
		if (liveCards[i] > 0)
			cout << std::right << liveCards[i];
	};
	cout << endl;
}


int isDead(int num) {

	for (int i = 0; i < 16; i++) {

		if (deadCards[i] == num)

			return 1;

	}

	return 0;

}



int nextCard() {

	int num = rand() % 16 + 1;

	if (isDead(num)) {

		cout << num << "Dead" << endl;

		return 0;

	}
	else {

		cout << num << endl;

		return num;

	}

}

void takeIt(int card) {

	score += card;

	for (int i = 0; i < card; i++) {

		deadCards[i] = i + 1;

		liveCards[i] = 0;

	}

}

void leave(int card) {

	deadCards[card - 1] = card;

	liveCards[card - 1] = 0;

}

int main() {
	cout << "Hey twitta worl" << endl;
}