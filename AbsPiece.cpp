/**
* Fichier contenant la classe AbsPiece qui est une classe de laquelle chaque pi�ce doit
* h�riter
* \file AbsPiece.cpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#include "AbsPiece.hpp"

namespace model
{
	AbsPiece::AbsPiece(
		int x, 
		int y, 
		const Color& color, 
		const std::string& type
	) : x_(x), y_(y), color_(color), type_(type)
	{}

	void AbsPiece::move(int x, int y)
	{
		x_ = x;
		y_ = y;
	}

	bool AbsPiece::isValidMove(int x, int y) const
	{
		const bool isSamePosition = (x == x_) && (y == y_);

		return !isSamePosition && isValidPieceMove(x, y);
	}

}