/**
* Fichier contenant la classe AbsPiece qui est une classe de laquelle chaque pi�ce doit 
* h�riter
* \file AbsPiece.hpp
* \author Erreur-404 et Mo-LK 
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#pragma once
#include <utility>
#include <stdexcept>

namespace model 
{
	enum class Color {
		white,
		black
	};


	class AbsPiece
	{
	public:
		AbsPiece(int x, int y, const Color& color, const std::string& type);
		virtual ~AbsPiece() = default;

		/*
		* D�place la pi�ce
		* \param	x :	Nouvelle position sur l'axe des x
		* \param	y :	Nouvelle position sur l'axe des y
		*/
		void move(int x, int y);

		/*
		* Acc�de � la position de la piece
		* \return	La position courante de la piece
		*/
		inline std::pair<int, int> getPosition() const { return std::pair(x_, y_); };

		/*
		* Indique si le mouvement est valide, sans tenir compte de la position des autres pi�ces
		* \param	x :	Nouvelle position sur l'axe des x
		* \param	y :	Nouvelle position sur l'axe des y
		* \return	La validit� du mouvement
		*/
		bool isValidMove(int x, int y) const; // Publique parce que la fonction sera peut �tre appel�e par la vue

		/*
		* Obtient la couleur de la pi�ce.
		* \return	La couleur de la pi�ce
		*/
		inline const Color& getColor() const { return color_; };

		/*
		* Obtient le type de la pi�ce.
		* \return	Le type. Ex: "King"
		*/
		inline const std::string& getType() { return type_; };

	protected:
		/*
		* Indique si le mouvement correspond � ceux permis par la piece
		* \param x : Nouvelle position en x
		* \param y : Nouvelle position en y
		* \return La validit� du mouvement
		*/
		virtual bool isValidPieceMove(int x, int y) const = 0;

		/* La position en x de la pi�ce */
		int x_;
		/* La position en y de la pi�ce */
		int y_;
		/* La couleur de la pi�ce */
		Color color_;
		/* Le type de la pi�ce */
		std::string type_;
	};
}