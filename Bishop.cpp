/**
* Fichier contenant la classe Bishop qui correspond au Fou. 
* \file Bishop.cpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#include "Bishop.hpp"

namespace model 
{
	Bishop::Bishop(int x, int y, const Color& color) : 
		AbsPiece(x, y, color, "Bishop") 
	{ 
	}

	bool Bishop::isValidPieceMove(int x, int y) const
	{
		return abs(y - y_) == abs(x - x_);
	}
}