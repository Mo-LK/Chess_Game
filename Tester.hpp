/*
* Fichier contenant la d�finition et l'impl�mentation de la classe Tester permettant 
* d'acc�der � la m�thode isCheckMate � des fins de tests unitaires sans devoir rendre
* cette m�thode publique et briser l'encapsulation. La classe Tester est friend de 
* la classe Chessboard. Cette technique a �t� recommand�e par Fran�ois-Raymond Boyer.
* \file Tester.hpp
* \author Erreur-404 et Mo-LK
* \date 2 mai 2022
* Cr�� le 2 mai 2022
*/

#pragma once
#include "Chessboard.hpp"

namespace model
{
	class Tester
	{
	public:
		Tester() = default;

		/*
		* Method to test the board isCheckMate method in the gtests
		* \param	board : The board to which the method should be tested
		*/
		inline bool testIsCheckMate(Chessboard& board) { return board.isCheckMate(); }
	};
}