/**
* Fichier impl�mentant le contr�leur. La vue doit contacter le contr�leur pour interagir avec le mod�le.
* \file Controller.hpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 12 avril 2022
*/

#pragma once
#include "QObject"

#include "Chessboard.hpp"

#include "StartupPositions1.hpp"
#include "StartupPositions2.hpp"
#include "StartupPositions3.hpp"
#include "StartupPositions4.hpp"

namespace control
{
	class Controller : public QObject
	{
		Q_OBJECT

	public slots:
		/*
		* Slot permettant d'attraper le signal d'�chec du mod�le et de le r��mettre 
		* \param	x : position en x de la pi�ce en �chec
		* \param	y : position en y de la pi�ce en �chec
		*/
		void forwardCheck(int x, int y);

		/* Slot permettant d'attraper le signal de fin de jeu du mod�le et de le r��mettre */
		void forwardGameover();

		/*
		* Slot permettant d'attraper le signal de pi�ce ajout�e �mit par le mod�le et de le r��mettre
		* \param	x : La position en x de la pi�ce ajout�e
		* \param	y : La position en y de la pi�ce ajout�e
		* \param	type : Le type de la pi�ce ajout�e
		* \param	pieceColor : La couleur  de la pi�ce ajout�e
		*/
		void forwardPieceAdded(int x, int y, std::string type, std::string pieceColor);

	signals:
		/*
		* Signal �mit pour indiquer que le mouvement est invalide
		* \param	x : La position en x de la destination souhait�e
		* \param	y : La position en y de la destination souhait�e
		*/
		void invalidMove(int x, int y);

		/*
		* Signal �mit pour indiquer qu'il y a �chec 
		* \param	x : La position en x de la pi�ce en �chec
		* \param	y : La position en y de la pi�ce en �chec
		*/
		void notifyCheck(int x, int y);

		/* 
		* Signal �mit pour indiquer qu'une pi�ce a �t� ajout�e
		* \param	x : La position en x de la pi�ce
		* \param	y : La position en y de la pi�ce
		* \param	type : Le type de la pi�ce
		* \param	pieceColor : La couleur de la pi�ce
		*/
		void notifyPieceAdded(int x, int y, std::string type, std::string pieceColor);

		/* Signal �mit pour indiquer que le jeu est termin� */
		void notifyGameover();

	public:
		Controller();
		~Controller();

		/*
		* Demande � l'�chiquier de d�marrer la partie avec la strat�gie de positionnement demand�e
		* \param	strategyNumber : Le num�ro de la strat�gie demand�e
		*/
		void startGame(int strategyNumber);

		/*
		* Tente de d�placer la pi�ce en demandant poliment � l'�chiquier
		* \param	sourceX : La position en x initiale
		* \param	sourceY : La position en y initiale
		* \param	destinationX : La position en x finale
		* \param	destinationY : La position en y finale
		* \return	La validit� du mouvement 
		*/
		bool move(int sourceX, int sourceY, int destinationX, int destinationY);

		/*
		* Obtient la couleur du joueur qui a le droit de jouer
		* \return	La couleur du joueur
		*/
		inline const model::Color& getColor() const { return board_->getColor(); };

		/*
		* Obtient un pointeur sur la pi�ce � la position demand�e
		* \param	x : Position en x de la case o� on cherche � obtenir la pi�ce
		* \param	y : Position en y de la case o� on cherche � obtenir la pi�ce
		* \return	Pointeur sur la pi�ce. nullptr si la case est vide.
		*/
		inline model::AbsPiece* getPiece(int x, int y) const { return board_->getPiece(x, y); }

		/*
		* Indique si la tuile contient une pi�ce que le joueur a le droit de d�placer
		* \param	x : La position en x de la tuile
		* \param	y : La position en y de la tuile
		* \return	La validit� de la s�lection de la pi�ce
		*/
		bool isValidTile(int x, int y) const;

	private:
		/*
		* Obtient un pointeur vers la strat�gie de positionnement correspondant au param�tre
		* \param	strategyNumber : Le num�ro de la strat�gie
		* \return	Un pointeur vers la strat�gie de positionnement correspondante
		*/
		model::StartupPositions* getStrategy(int strategyNumber);

		/* L'�chiquier vers lequel le controlleur achemine les demandes */
		model::Chessboard* board_;
	};
}