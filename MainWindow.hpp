/**
* Fichier contenant la fen�tre principale. C'est elle qui affiche le jeu et qui re�oit les demandes de l'utilisateur.
* \file MainWindow.hpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 13 avril 2022
*/

#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTextFormat>
#include <QMenu>
#include <QMenuBar>
#include <QIcon>
#include <QPixmap>
#include <QGraphicsView>
#include <QLabel>
#include <QFont>
#include <QMessageBox>

#include <iostream>
#include <string>
#include <cppitertools/range.hpp>

#include "Tile.hpp"
#include "Controller.hpp"
#include "PositionSelectionWindow.hpp"

namespace view
{	
	constexpr const int margin = 100;
	
	constexpr const int chessboardWidth = 8;
	constexpr const int chessboardHeigth = 8;

	const std::string startupPositionString = "Startup Position ";
	constexpr const int startupPositionStringLength = 17;
	
	constexpr const int playerTurnDisplayerHeight = 70;
	constexpr const int playerTurnDisplayerWidth = 70;
	constexpr const int playerTurnDisplayerX = 30;
	constexpr const int playerTurnDisplayerY = 30;

	constexpr const int gameoverMessageWidth = 200;
	constexpr const int gameoverMessageHeight = 50;
	constexpr const int gameoverMessageX = 415;
	constexpr const int gameoverMessageY = 40;
	constexpr const int gameoverMessageSize = 20;


	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public slots:

		/* Slot qui g�re la s�lection d'une tuile */
		void buttonClicked();

		/* 
		* Affiche l'invalidit� d'un mouvement
		* \param	x : Position en x de la destination voulue
		* \param	y : Position en y de la destination voulue
		*/
		void invalidMove(int x, int y);
		
		/*
		* Assigne la valeur de la tuile en �chec � checkedTile_ 
		* \param	x : Position en x de la pi�ce en �chec
		* \param	y : Position en y de la pi�ce en �chec
		*/
		void assignCheckTile(int x, int y);

		/*
		* Ajoute une pi�ce sur l'�chiquier graphique
		* \param	x : La position en x de la nouvelle pi�ce
		* \param	y : La position en y de la nouvelle pi�ce
		* \param	type : Le type de la nouvelle pi�ce
		* \param	pieceColor : La couleur de la nouvelle pi�ce
		*/
		void addPiece(int x, int y, std::string type, std::string pieceColor);

		/* Affiche au joueur que la partie est termin�e */
		void gameover();

		/* D�marre une nouvelle partie avec la strat�gie de positionnement appelante */
		void selectStartupPosition();

		/* Affiche la fen�tre de s�lection des positions de d�part */
		void displayPositionSelectionWindow();

	public:
		MainWindow();
		~MainWindow();

		/* Initialise l'interface graphique */
		void setUi();

	private:
		/* Cr�e la fen�tre principale */
		void initializeMainWindow();

		/* Cr�e l'�chiquier avec les cases, sans tenir compte des pi�ces */
		void initializeBoard();

		/* Cr�e le cercle indiquant le joueur qui a le droit de jouer */
		void initializePlayerTurnDisplayer();

		/* Cr�e la bar de menu */
		void initializeMenuBar();

		/* 
		* Affiche la fen�tre de confirmation
		* \param	positionNumber : Le num�ro de la position � confirmer
		*/
		void displayPrompt(int positionNumber);

		/* 
		* D�marre une nouvelle partie avec la strat�gie de positionnement demand�e 
		* \param	piecesPositionNumber : Le num�ro de la position initiale des pi�ces
		*/
		void startGame(int piecesPositionNumber);

		/*
		* Assigne le tour au joueur dont la couleur correspond au param�tre
		* \param	color : La couleur du joueur qui obtiendra le tour
		*/
		void switchColor(const model::Color& color);

		/* Nettoie la fen�tre principale pour accueillir une nouvelle partie */
		void clear();

		/* Retire toutes les pi�ces de l'�chiquier */
		void clearBoard();

		/* 
		* Fonction qui s'occupe d'appeler le contr�leur si une demande de d�placement est confirm�e 
		* \param	destinationX : La destination en X
		* \param	destinationY : La destination en Y
		*/
		void movePiece(int destinationX, int destinationY);

		/*
		* D�place l'ic�ne de la pi�ce vers la tuile o� on souhaite l'amener
		* \param	destinationTile : La tuile destination
		*/
		void moveIcon(Tile* destinationTile);

		/* Redonne la couleur de d�faut � la tuile source */
		void setSourceTileDefaultColor();

		/* Assigne la bonne couleur � la tuile pr�sentant un �chec */
		void setCheckedTileColor();
		
		/* Tile o� se trouve la pi�ce que l'on souhaite d�placer */
		Tile* sourceTile_;

		/* Permet de retrouver la case mise en �chec pour quelle reprenne sa couleur par d�faut */
		Tile* checkedTile_;

		/* Les 64 tuiles de l'�chiquier */
		QList<Tile*> tiles_;

		/* Le contr�leur que l'on appelle pour contacter l'�chiquier (le mod�le) */
		control::Controller* controller_;

		/* Le voyant indiquant le joueur ayant le droit de jouer */
		QLabel* playerTurnDisplayer_;
		
		/* Message inquant que la partie est termin�e */
		QLabel* gameoverMessage_;

		/* Fen�tre secondaire permettant de s�lectionner la position de d�part */
		class PositionSelectionWindow* positionSelectionWindow_;
	};
}