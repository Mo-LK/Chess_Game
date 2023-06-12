/*
* Classe d�finissant la premi�re strat�gie de positionnement des pi�ces
* \file StartupPositions1.cpp
* \author Erreur-404 et Mo-LK
* \date 26 avril 2022
* Cr�� le 26 avril 2022
*/

#include "StartupPositions1.hpp"

namespace model
{
	void StartupPositions1::set(class Chessboard* board)
	{
		board->addPiece(new Rook(0, 0, Color::black));
		board->addPiece(new Bishop(2, 0, Color::black));
		board->addPiece(new King(3, 0, Color::black));
		board->addPiece(new Bishop(5, 0, Color::black));
		board->addPiece(new Rook(7, 0, Color::black));

		board->addPiece(new Rook(0, 7, Color::white));
		board->addPiece(new Bishop(2, 7, Color::white));
		board->addPiece(new King(3, 7, Color::white));
		board->addPiece(new Bishop(5, 7, Color::white));
		board->addPiece(new Rook(7, 7, Color::white));
	}
}