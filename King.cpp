/**
* Fichier contenant la classe King qui correspond au roi.
* \file King.cpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#include "King.hpp"

namespace model 
{
	int King::numberOfKings_ = 0;

	King::King(int x, int y, const Color& color) : 
		AbsPiece(x, y, color, "King")
	{ 
		if (King::numberOfKings_ < 2)
			King::numberOfKings_++;
		else
			throw TooManyKingsException("Two kings already exist");
	}

	King::~King()
	{
		King::numberOfKings_--;
	}

	bool King::isValidPieceMove(int x, int y) const
	{
		const bool isValidX = (x_ - 1 <= x) && (x <= x_ + 1);
		const bool isValidY = (y_ - 1 <= y) && (y <= y_ + 1);
		return isValidX && isValidY;
	}

}