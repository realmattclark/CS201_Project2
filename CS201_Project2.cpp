#include <iostream>
using namespace std;


int liveCards[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
int deadCards[16] = {};
int score = 0;

int isOver() {
	int total = 0;
	for (int i = 0; i < 16; i++) {
		if (deadCards[i] > 0) total++;
	}
	return total == 16 ? 0 : 1;
}

void showDeadCards() {

	for (int i = 0; i < 16; i++) {
		if (deadCards[i] > 0)
			cout << deadCards[i];
	}

	cout << endl;

}

void showLiveCards() {

	for (int i = 0; i < 16; i++) {
		if (liveCards[i] > 0)
			cout << liveCards[i];
	}
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

		cout << num << "Dead: " << endl;

		return 0;

	}
	else {

		cout << num << endl;

		return num;

	}

}

void takeit(int card) {

	score += card;

	for (int i = 0; i < card; i++) {

		deadCards[i] = i + 1;

		liveCards[i] = 0;

	}

}

void leaveit(int card) {

	deadCards[card - 1] = card;

	liveCards[card - 1] = 0;

}

int main() {

	char choice[10];

	int card;

	while (true) {

		while (isOver()) {

			cout << "Current Score: " << score << endl;

			cout << "Dead cards:";

			showDeadCards();

			cout << "Live cards: ";

			showLiveCards();

			cout << "Next cards: ";

			card = nextCard();

			if (card != 0) {

				cout << "Take it [T] or Leave it [L]?";

				cin >> choice;

				if (choice[0] == 'T' || choice[0] == 't') {

					takeit(card);

				}
				else {

					leaveit(card);
				}
			}
		}
		cout << "Want to play Again - Yes [Y] No [N] ?";

		cin >> choice;

		if (choice[0] == 'N' || choice[0] == 'n') {
			break;

		}
	}
	return 0;
}