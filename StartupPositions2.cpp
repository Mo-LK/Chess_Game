/*
* Classe d�finissant la seconde strat�gie de positionnement des pi�ces
* \file StartupPositions2.cpp
* \author Erreur-404 et Mo-LK
* \date 26 avril 2022
* Cr�� le 26 avril 2022
*/

#include "StartupPositions2.hpp"

namespace model
{
	void StartupPositions2::set(class Chessboard* board)
	{
		board->addPiece(new King(3, 0, Color::black));
		board->addPiece(new Bishop(0, 0, Color::black));

		board->addPiece(new King(3, 7, Color::white));
		board->addPiece(new Rook(7, 7, Color::white));
	}
}