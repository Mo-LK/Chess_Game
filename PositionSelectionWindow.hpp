/**
* Fichier contenant la classe SelectStartupWindow qui g�n�re une fen�tre servant � s�lectionner le d�but de partie voulue.
* \file SelectStartupWindow.hpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 8 avril 2022
*/

#pragma once
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "Tile.hpp"
#include "MainWindow.hpp"

namespace view
{
	const int xPosition = 450;
	const int yPosition = 450;
	const int widthDimension = 400;
	const int heightDimension = 400;
	const int numberOfPresets = 4;

	class PositionSelectionWindow : public QWidget
	{
		Q_OBJECT

	public:
		PositionSelectionWindow() = default;
		~PositionSelectionWindow() = default;

		/*
		* Cr�e une fen�tre permettant de s�lectionner la position de d�part des pi�ces
		* \param	mainWindow : La fen�tre principale qui recevra la position s�lectionn�e
		*/
		void createWindow(class MainWindow& mainWindow);
	};
}