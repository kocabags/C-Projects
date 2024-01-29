#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcome() {
    cout << "Welcome to Sarp's Casino. Where you make money, not friends!\n" << endl;
}

void players() {
    cout << "How many players do you have? (1-4)\n" << endl;
}

int main() {
    srand(time(NULL));
    int np;
    int i;
    bool playerbust = false;

    welcome();

    players();
    cin >> np;

    while (np <= 0 || np >= 5) {
        cout << "How many players do you have? (1-4)\n";
        cin >> np;
    }

    float money[np];
    float sum = 0;

    for (i = 0; i < np; i++) {
        cout << "Player " << i + 1 << ", how much money are you starting with?\n";
        cin >> money[i];

        while (money[i] <= 0) {
            cout << "Player " << i + 1 << ", how much money are you starting with?\n";
            cin >> money[i];
        }

        sum += money[i];
    }

    int pscore, dscore, player_play_again = 1, dealer_play_again = 1, bet, cashout = 0;

    while (sum != 0 && cashout == 0) {
        sum = 0;
        for (i = 0; i < np; i++) {
            player_play_again = 1;
            dealer_play_again = 1;
            pscore = 0;
            dscore = 0;

            if (money[i] != 0) {
                playerbust = false;
                cout << "Player " << i + 1 << ", how much do you want to bet?\n";
                cin >> bet;

                while (bet <= 0 || bet > money[i]) {
                    cout << "Player " << i + 1 << ", how much do you want to bet?\n";
                    cin >> bet;
                }

                // Player's turn
                while (true) {
                    int k = rand() % 11 + 1;
                    pscore += k;
                    cout << "Player " << i + 1 << ", you got " << k << ". Your total points are " << pscore << ".\n";

                    if (pscore > 21) {
                        cout << "Player " << i + 1 << ", you bust! Dealer wins.\n";
                        money[i] -= bet;
                        cout << "The player has $" << money[i] << ".\n";
                        break;
                    }

                    cout << "Do you want to go again? (0-no or 1-yes)\n";
                    cin >> player_play_again;

                    if (player_play_again != 1) {
                        break;
                    }
                }

                // Dealer's turn
                while (dscore <= 17 && dealer_play_again == 1 && player_play_again == 0) {
                    int k = rand() % 11 + 1;
                    dscore += k;
                    cout << "Dealer gets " << k << ". Dealer's total points are " << dscore << ".\n";
                }

                // Determine the winner
                if (!playerbust) {
                    if (dscore > 21 || pscore > dscore) {
                        cout << "Player " << i + 1 << ", you win!\n";
                        money[i] += bet;
                    } else if (pscore == dscore) {
                        cout << "It's a tie.\n";
                    } else {
                        cout << "Dealer wins.\n";
                        money[i] -= bet;
                    }
                }

                cout << "The player has $" << money[i] << ".\n";
                sum += money[i];
            }
        }

        if (sum == 0) {
            cout << "Game over!\n";
            break;
        }

        cout << "Do players want to cash out? (0-no 1-yes)\n";
        cin >> cashout;

        while (cashout < 0 || cashout > 1) {
            cout << "Do players want to cash out? (0-no 1-yes)\n";
            cin >> cashout;
        }

        if (cashout == 1) {
            cout << "Game over!\n";
            break;
        }
    }

    return 0;
}
