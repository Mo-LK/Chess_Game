/*
* Classe d�finissant la quatri�me strat�gie de positionnement des pi�ces
* \file StartupPositions4.hpp
* \author Erreur-404 et Mo-LK
* \date 26 avril 2022
* Cr�� le 26 avril 2022
*/

#pragma once

#include "StartupPositions.hpp"

namespace model
{
	class StartupPositions4 : public StartupPositions
	{
	public:
		StartupPositions4() = default;

		/*
		* Add the pieces to the correct initial positions
		* \param	board : The board on which the pieces should be added
		*/
		void set(class Chessboard* board) override;
	};
}