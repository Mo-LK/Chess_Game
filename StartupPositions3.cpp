/*
* Classe d�finissant la troisi�me strat�gie de positionnement des pi�ces
* \file StartupPositions3.cpp
* \author Erreur-404 et Mo-LK
* \date 26 avril 2022
* Cr�� le 26 avril 2022
*/

#include "StartupPositions3.hpp"

namespace model
{
	void StartupPositions3::set(class Chessboard* board)
	{
		board->addPiece(new King(4, 4, Color::black));
		board->addPiece(new Bishop(4, 5, Color::black));
		board->addPiece(new Bishop(4, 3, Color::black));
		board->addPiece(new Rook(3, 4, Color::black));
		board->addPiece(new Rook(5, 4, Color::black));

		board->addPiece(new King(7, 7, Color::white));
		board->addPiece(new Bishop(4, 0, Color::white));
		board->addPiece(new Bishop(4, 7, Color::white));
		board->addPiece(new Rook(0, 4, Color::white));
		board->addPiece(new Rook(7, 4, Color::white));
	}
}