#include <iostream>
#include <string>
#include "GameLogic.h"

using namespace std;

string player1Name;
char player1Piece;
string player2Name;
char player2Piece;
int main() {
	cout << "Please Enter Player 1's Name: ";
	cin >> player1Name;
	cout << "Player 1s Name Is " << player1Name << endl;
	cout << "Please Enter Player 2's Name: ";
	cin >> player2Name;
	cout << "Player 2s Name Is " << player2Name << endl;
	while(true){
		
		cout << "Player 1 Please Enter Your Desired Piece: ";
		cin >> player1Piece;
		cout << "Player 1s Chosen Piece Is: " << player1Piece << endl;
	
		
		cout << "Player 2 Please Enter Your Desired Piece: ";
		cin >> player2Piece;
		cout << "Player 2s Chosen Piece Is: " << player2Piece << endl;
		if (player2Piece != player1Piece && player2Piece != ' ') {
			break;
		}
		else {
			cout << "Both Players Cannot Have Same Pieces: " << endl;
		}
	}
	Player player1(player1Name, player1Piece);
	Player player2(player2Name, player2Piece);

	Game game(&player1, &player2);
	game.startGame();


}

