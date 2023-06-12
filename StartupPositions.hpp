/*
* Classe de base d�finissant l'interface d'une classe permettant d'ajouter
* les pi�ces sur l'�chiquier � des positions pr�cises
* \file StartupPositions.hpp
* \author Erreur-404 et Mo-LK
* \date 26 avril 2022
* Cr�� le 26 avril 2022
*/

#pragma once

#include <iostream>

#include "Chessboard.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"

namespace model
{
	class StartupPositions
	{
	public:
		StartupPositions() = default;
		virtual ~StartupPositions() = default;

		/*
		* Add the pieces to the correct initial positions
		* \param	board : The board on which the pieces should be added
		*/
		virtual void set(class Chessboard* board) = 0;
	};
}