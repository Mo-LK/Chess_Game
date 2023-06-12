/**
* Fichier contenant la classe Bishop qui correspond au Fou.
* \file Bishop.hpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#pragma once

#include <cstdlib>
#include "AbsPiece.hpp"

namespace model 
{

	class Bishop : public AbsPiece
	{
	public:
		Bishop() = default;
		Bishop(int x, int y, const Color& color);
		virtual ~Bishop() = default;
	
	protected:
		/*
		* Indique si le mouvement correspond � ceux permis par le Fou
		* \param x : Nouvelle position en x
		* \param y : Nouvelle position en y
		* \return La validit� du mouvement
		*/
		bool isValidPieceMove(int x, int y) const override;
	};

}