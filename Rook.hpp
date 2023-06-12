/**
* Fichier contenant la classe Rook qui correspond � la tour.
* \file Rook.hpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#pragma once

#include "AbsPiece.hpp"

namespace model 
{

	class Rook : public AbsPiece
	{
	public:
		Rook() = default;
		Rook(int x, int y, const Color& color);
		virtual ~Rook() = default;

	protected:
		/*
		* Indique si le mouvement correspond � ceux permis par la Tour
		* \param x : Nouvelle position en x
		* \param y : Nouvelle position en y
		* \return La validit� du mouvement
		*/
		bool isValidPieceMove(int x, int y) const override;
	};

}