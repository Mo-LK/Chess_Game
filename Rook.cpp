/**
* Fichier contenant la classe Rook qui correspond � la tour.
* \file Rook.cpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#include "Rook.hpp"

namespace model
{
	Rook::Rook(int x, int y, const Color& color) : 
		AbsPiece(x, y, color, "Rook") 
	{
	}

	bool Rook::isValidPieceMove(int x, int y) const
	{
		const bool isHorizontalMove	= (x != x_) && (y == y_);
		const bool isVerticalMove	= (y != y_) && (x == x_);
		return isHorizontalMove ^ isVerticalMove;
	}
}