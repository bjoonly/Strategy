#include"Game.h"

Strategy* SetStrategyMenu() {
	int number = 0;
	do {
		cout << "Enter number of strategy:\n1.+7\n2.+4\n3.+2\n4.-1\n5.-3\n6.-6\n";
		cin >> number;
		switch (number) {
		case 1:
			return new StrategyPlus7;
		case 2:
			return new StrategyPlus4;
		case 3:
			return new StrategyPlus2;
		case 4:
			return new StrategyMinus1;
		case 5:
			return new StrategyMinus3;
		case 6:
			return new StrategyMinus6;
		default:
			cout << "Invalid number.";
			break;
		}
	} while (number < 1 || number>6);

	throw exception("Error");
}


int main() {

	srand(unsigned(time(0)));
	Game game;
	int action=0;
	bool res = true;

	do {

		if (game.GetMoveNumber() == 0 || game.GetMoveNumber() % 5 == 0)
			game.FillField();

		do {
			system("cls");
			game.Show();
			cout << "Choose action:\n1.Move\n2.Set strategy\n3.Exit from game\n";
			cin >> action;
			switch (action) {
			case 1:
				res = game.MovingOnTheField();
				break;
			case 2:
				game.SetStrategy(SetStrategyMenu());
				break;
			case 3:
				break;
			default:
				cout << "Invalid action.";
				Sleep(1500);
				system("cls");
				break;
			}
		} while (action != 1 && action != 3);

	} while (res);
	cout << "\nYou passed " << game.GetMoveNumber() / 5 << " stages.\n";
	if (res == false) {
		cout << "\nYou lose.\n";
	}
	return 0;
}