/*
* Classe d�finissant la quatri�me strat�gie de positionnement des pi�ces
* \file StartupPositions4.cpp
* \author Erreur-404 et Mo-LK
* \date 26 avril 2022
* Cr�� le 26 avril 2022
*/

#include "StartupPositions4.hpp"

namespace model
{
	void StartupPositions4::set(class Chessboard* board)
	{
		board->addPiece(new King(0, 0, Color::black));
		board->addPiece(new Bishop(1, 1, Color::black));
		board->addPiece(new Bishop(2, 2, Color::black));
		board->addPiece(new Rook(1, 0, Color::black));
		board->addPiece(new Rook(0, 1, Color::black));

		board->addPiece(new King(7, 7, Color::white));
		board->addPiece(new Bishop(6, 6, Color::white));
		board->addPiece(new Bishop(5, 5, Color::white));
		board->addPiece(new Rook(6, 7, Color::white));
		board->addPiece(new Rook(7, 6, Color::white));
	}
}