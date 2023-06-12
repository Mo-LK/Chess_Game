/**
* Fichier la classe Tile. Celle ci correspond aux tuiles qui composent l'�chiquier.
* \file Tile.hpp
* \author Erreur-404 et Mo-LK
* \date 2 mai 2022
* Cr�� le 2 mai 2022
*/
#pragma once
#include <QPushButton>
#include <QString>
#include <QTimer>

namespace view
{
	constexpr const int defaultPosition = 999;

	constexpr const int caseWidth = 100;
	constexpr const int caseHeight = 100;

	constexpr const int iconHeight = 150;
	constexpr const int iconWidth = 150;

	constexpr const int invalidMoveColorTime = 100; // milliseconds

	const QString red = "QPushButton {background-color: red; color: white}";
	const QString white = "QPushButton {background-color: white; color: black}";
	const QString grey = "QPushButton {background-color: grey; color: white}";
	const QString blue = "QPushButton {background-color: blue; color: white}";

	class Tile : public QPushButton
	{
	public slots:
		/* Slot permettant d'attribuer la couleur de d�faut � une tuile */
		void setDefaultColor();

	public:
		Tile(QString title = "", 
			 QWidget* parent = nullptr, 
			 int x = defaultPosition, 
			 int y = defaultPosition
		);

		void setImage(QIcon icon);

		/* Affiche un mouvement invalide sur la tuile */
		void setInvalid();

		/* Indique si la tuile pr�sente un �chec */
		inline bool isCheck() { return styleSheet() == red; }

		/* Affiche que la tuile pr�sente un �chec */
		inline void setCheck() { setStyleSheet(red); }

		/* Affiche que la tuile est s�lectionn�e */
		inline void setSelected() { setStyleSheet(blue); }

		/*
		* Indique la position de la pi�ce
		* \return	std::pair contenant la position en x et en y
		*/
		inline std::pair<int, int> getPosition() { return std::pair<int, int>(x_, y_); }

	private:
		/* La minuterie permettant d'effectuer une action pour un certain temps */
		QTimer timer_;

		/* La position en x de la tuile */
		int x_;
		/* La position en y de la tuile */
		int y_;
	};
}