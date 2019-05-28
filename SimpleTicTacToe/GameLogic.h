#pragma once

#include <string>
using namespace std;

class Player {
private:
	string name;
	char piece;
public:
	Player(string inputName, char newPiece);

	string getName();
	void setName(string newName);
	char getPiece();
	void setPiece(char newPiece);

};

class Game {
private:
	Player* player1;
	Player* player2;
	char board[3][3] = {
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '} };
	void endGame(Player& player);
	char getPieceAt(int row, int column);
	void setPieceAt(int row, int column, char piece);
	void printBoard(Game& game);
	void playerTurn(Game& game, Player& player);
	bool checkBoard(Game& game);
public:
	Game(Player* setPlayer1, Player* setPlayer2);
	void startGame();
	
};
