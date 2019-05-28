#include "GameLogic.h"
#include <iostream>

using namespace std;

void Game::printBoard(Game &game) {
	cout << game.getPieceAt(0, 0) << " | " << game.getPieceAt(0, 1) << " | " << game.getPieceAt(0, 2) << endl;
	cout << "---------" << endl;
	cout << game.getPieceAt(1, 0) << " | " << game.getPieceAt(1, 1) << " | " << game.getPieceAt(1, 2) << endl;
	cout << "---------" << endl;
	cout << game.getPieceAt(2, 0) << " | " << game.getPieceAt(2, 1) << " | " << game.getPieceAt(2, 2) << endl;
}
void Game::playerTurn(Game &game, Player &player) {
	int row;
	int column;
	while (true) {
		cout << "Please Enter Row: " << endl;
		cin >> row;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Please Enter Proper Integer: " << endl;
			continue;
		}
		cout << "Please Enter Column: " << endl;
		cin >> column;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Please Enter Proper Integer: " << endl;
			continue;
		}
		cout << "You Chose " << row << "," << column << "." << endl;
		if (row >=0 && row <= 2 && column >= 0 && column <= 2 && game.getPieceAt(row, column) == ' ' ) {
			game.setPieceAt(row, column, player.getPiece());
			break;
		}
		else {
			cout << "This Row & Column Were Already Selected, Please Enter New Row" << endl;
		}

	}
	
}
//{ '0,0','0,1','0,2'}
//{ '1,0','1,1','1,2'}
//{ '2,0','2,1','2,2'}
bool Game::checkBoard(Game &game) {
	if (game.getPieceAt(0, 0) != ' ' && game.getPieceAt(0, 0) == game.getPieceAt(0, 1) && game.getPieceAt(0, 1) == game.getPieceAt(0, 2)) {
		return true;
	}
	if (game.getPieceAt(1, 0) != ' ' && game.getPieceAt(1, 0) == game.getPieceAt(1, 1) && game.getPieceAt(1, 1) == game.getPieceAt(1, 2)) {
		return true;
	}
	if (game.getPieceAt(2, 0) != ' ' && game.getPieceAt(2, 0) == game.getPieceAt(2, 1) && game.getPieceAt(2, 1) == game.getPieceAt(2, 2)) {
		return true;
	}
	if (game.getPieceAt(0, 0) != ' ' && game.getPieceAt(1, 1) == game.getPieceAt(0, 0) && game.getPieceAt(2, 2) == game.getPieceAt(1, 1)) {
		return true;
	}
	if (game.getPieceAt(0, 2) != ' ' && game.getPieceAt(1, 1) == game.getPieceAt(0, 2) && game.getPieceAt(2, 0) == game.getPieceAt(1, 1)) {
		return true;
	}
	if (game.getPieceAt(0, 0) != ' ' && game.getPieceAt(0, 0) == game.getPieceAt(1, 0) && game.getPieceAt(2, 0) == game.getPieceAt(1, 0)) {
		return true;
	}
	if (game.getPieceAt(0, 1) != ' ' && game.getPieceAt(0, 1) == game.getPieceAt(1, 1) && game.getPieceAt(2, 1) == game.getPieceAt(1, 1)) {
		return true;
	}
	if (game.getPieceAt(0, 2) != ' ' && game.getPieceAt(0, 2) == game.getPieceAt(1, 2) && game.getPieceAt(2, 2) == game.getPieceAt(1, 2)) {
		return true;
	}
	return false;
}
void Game::startGame () {
	Player* currentPlayer;
	currentPlayer = player1;
	bool isGameOver=false;
	while (!isGameOver) {
		printBoard(*this);
		playerTurn(*this, *currentPlayer);
		isGameOver = checkBoard(*this);
		if (isGameOver) {
			endGame(*currentPlayer);
		}
		if (currentPlayer == player1) {
			currentPlayer = player2;
		}
		else {
			currentPlayer = player1;
		}
	}
}
void Game::endGame(Player &player) {
	cout << player.getName() << " Won!" << endl;
}
string Player::getName() {
	return name;
}
void Player::setName(string newName) {
	name = newName;
}
Player::Player(string inputName, char newPiece) {
	name = inputName; 
	piece = newPiece;

}

char Player::getPiece() {
	return piece;
}
void Player::setPiece(char newPiece) {
	piece = newPiece;
}
Game::Game(Player* setPlayer1, Player* setPlayer2) {
	player1 = setPlayer1;
	player2 = setPlayer2;
}
char Game::getPieceAt(int row, int column) {
	return board[row][column];
}
void Game::setPieceAt(int row, int column, char piece) {
	board[row][column] = piece;
}