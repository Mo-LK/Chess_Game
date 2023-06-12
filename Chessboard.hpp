/**
* Fichier impl�mentant l'�chiquier. C'est lui qui poss�de les pi�ces et la logique de l'application.
* \file Chessboard.hpp
* \author Erreur-404 et Mo-LK
* \date 19 avril 2022
* Cr�� le 10 avril 2022
*/

#pragma once
#include <QObject>
#include <memory>
#include <unordered_map>

#include <cppitertools/range.hpp>
#include <algorithm>
#include "StartupPositions.hpp"
#include "King.hpp"


namespace model 
{
	constexpr const int width = 8;
	constexpr const int height = 8;

	constexpr const std::pair defaultPosition(999, 999);

	class Chessboard : public QObject
	{
		Q_OBJECT;

	signals:
		/* 
		* Signal �mit lorsqu'un roi tombe en �chec
		* \param	x : La position en x du roi en �chec
		* \param	y : La position en y du roi en �chec
		*/
		void checkSignal(int x, int y) const;

		/* Signal �mit lorsque la partie est termin�e */
		void gameover();

		/*
		* Signal �mit lorsqu'une pi�ce est ajout�e pour que la vue puisse l'afficher
		* \param	x : La position en x de la nouvelle pi�ce
		* \param	y : La position en y de la nouvelle pi�ce
		* \param	type : Le type de la nouvelle pi�ce. (Par exemple, "King" ou "Bishop")
		* \param	pieceColor : La couleur de la nouvelle pi�ce
		*/
		void pieceAdded(int x, int y, std::string type, std::string pieceColor);

	public:
		/* Constructeur de Chessboard */
		Chessboard();


		/*
		* Indique si le mouvement est compl�tement valide.
		* \param	piece : La pi�ce sur laquelle on souhaite appliquer le mouvement
		* \param	x : Nouvelle position en x
		* \param	y : Nouvelle position en y
		* \return	La validit� du mouvement
		*/
		bool isValidMove(AbsPiece* piece, int x, int y);


		/*
		* D�place la pi�ce vers la nouvelle position
		* \param	piece : La pi�ce sur laquelle on souhaite appliquer le mouvement
		* \param	x : Nouvelle position en x
		* \param	y : Nouvelle position en y
		* \return	"true" si le mouvement s'est effectu� avec succ�s. "false" sinon
		*/
		bool movePiece(AbsPiece* piece, int x, int y);


		/*
		* Ajoute une pi�ce � l'�chiquier
		* \param	piece: La pi�ce � ajouter
		*/
		void addPiece(AbsPiece* piece);
		 

		/*
		* Obtient la pi�ce � la position demand�e
		* \param	x : La position sur l'axe des x
		* \param	y : La position sur l'axe des y
		* \return	La pi�ce demand�e. nullptr si ce n'est pas une pi�ce
		*/
		inline AbsPiece* getPiece(int x, int y) const { return board_[x][y].get(); };
		
		
		/*
		* Accesseur de la couleur du joueur qui a le droit de jouer
		* \return	La couleur du joueur 
		*/
		inline const Color& getColor() const { return currentPlayer_; };

		
		/* Place l'�chiquier pour que les joueurs puissent jouer */
		void startGame(class StartupPositions* strategy);

	private:

		/*
		* Place les pi�ces sur l'�chiquier selon la strat�gie de positionnement s�lectionn�e
		* \param	strategy : Pointeur vers la strat�gie de positionnement
		*/
		void initialize(class StartupPositions* strategy);


		/* D�truit toutes les pi�ces de l'�chiquier */
		void clear();


		/* 
		* Indique si le joueur tente de d�placer une pi�ce qui lui appartient ou non
		* \param	pieceColor : La couleur de la pi�ce que l'on souhaite d�placer
		* \return	"true" si la pi�ce appartient au joueur courant. "false" sinon
		*/
		bool isCorrectColor(const Color& pieceColor) const;


		/*
		* Indique si le mouvement est permit pour la pi�ce, sans se questionner 
		* � savoir s'il met le roi de la pi�ce en question en �chec
		* \param	pieceColor : La couleur de la pi�ce
		* \param	x : La prochaine position en x de la pi�ce
		* \param	y : La prochaine position en y de la pi�ce
		* \return	La validit� du mouvement
		*/
		bool isLegalMove(AbsPiece* piece, int x, int y) const;


		/*
		* Indique si le mouvement est � l'int�rieur de l'�chiquier
		* \param	x : Nouvelle position en x
		* \param	y : Nouvelle position en y
		* \return	La validit� du mouvement
		*/
		bool isInsideBoard(int x, int y) const;


		/*
		* Indique si le mouvement est invalide puisque bloqu� par une autre pi�ce.
		* \param	piece : La pi�ce � d�placer
		* \param	x : Nouvelle position en x
		* \param	y : Nouvelle position en y
		* \return	"true" si le d�placement est bloqu�, "false" s'il ne l'est pas.
		* On consid�re que le d�placement vers une case occup�e par une pi�ce de la
		* m�me �quipe est un mouvement bloqu� alors que sur une case occup�e par une
		* pi�ce de l'�quipe adverse est permi
		*/
		bool isBlockedMove(AbsPiece* piece, int x, int y) const;


		/*
		* Retire une pi�ce de l'�chiquier
		* \param	x : La position en x de la pi�ce � retirer
		* \param	y : La position en y de la pi�ce � retirer
		*/
		void removePiece(int x, int y);


		/* Met � jour l'�chiquier, ce qui inclu les d�placements possibles des pi�ces, mais aussi
		l'�tat de la mise en �chec des rois. Cette op�ration devrait �tre ex�cut�e � chaque tour,
		au moment o� le joueur r�fl�chi de pr�f�rence */
		void update();


		/*
		* Met � jour les d�placements possibles pour une pi�ce
		* \param	piece : La pi�ce sur laquelle on fait la mise � jour
		*/
		void updatePossibleMoves(AbsPiece* piece);


		/* Donne le droit de jouer au joueur suivant */
		void togglePlayerTurn();


		/* Passe au tour suivant, ce qui implique une mise � jour de l'�chiquier et un changement de joueurs */
		void nextTurn();


		/* V�rifie si la pi�ce peut atteindre le roi rival. 
		* Si il y a �chec, la m�thode �met le signal checkSignal
		* \param	piece : La pi�ce sur laquelle on souhaite faire la v�rification
		* \return	"true" si le roi adverse est en �chec, "false" sinon
		*/
		bool isRivalKingCheck(AbsPiece* piece) const;


		// Note au correcteur: Je ne retourne pas par r�f�rence puisque autrement je re�ois
		// l'erreur "auto doesn't deduce references. A possible unintended copy is being made."
		/*
		* Obtient la position du roi adverse
		* \param	pieceColor : La couleur de la pi�ce qui fait la demande
		* \return	La position du roi adverse
		*/
		const std::pair<int, int> getRivalKingPosition(const Color& pieceColor) const;


		/*
		* Indique si le d�placement d'une pi�ce rendra le roi de cette pi�ce en �chec
		* \param	pieceColor : La couleur de la pi�ce
		* \param	x : La prochaine position en x de la pi�ce
		* \param	y : La prochaine position en y de la pi�ce
		* \return	"true" si le roi alli� sera en �chec apr�s le d�placement. "false" sinon
		*/
		bool alliedKingBecomesChecked(AbsPiece* piece, int x, int y);


		/*
		* Obtient la position du roi alli�
		* \param	pieceColor : La couleur de la pi�ce qui fait la demande
		* \return	La position du roi alli�
		*/
		const std::pair<int, int> getAlliedKingPosition(const Color& pieceColor) const;


		/*
		* Modifie la position du roi retourn�e stock�e dans XXXXKingPosition_. 
		* \param	king : Le roi dont on souhaite modifier la position.
		*/
		void setKingPosition(const AbsPiece* king);


		/*
		* Indique s'il y a �chec et mat
		* \return	"true" si �chec et mat, "false" sinon
		*/
		bool isCheckMate();


		/*
		* Indique si il y a �chec et pat
		* \return	"true" si �chec et pat, "false" sinon
		*/
		bool isStaleMate();


		/* Contient les d�placements permis pour chaque pi�ce */
		std::unordered_map<AbsPiece*, std::vector<std::pair<int, int>>> possibleMoves_;


		/* L'�chiquier lui-m�me. C'est lui qui contient les pi�ces */
		std::unique_ptr<AbsPiece> board_[width][height];


		/* La position du roi blanc */
		std::pair<int, int> whiteKingPosition_;
		/* La position du roi noir */
		std::pair<int, int> blackKingPosition_;


		/* La couleur du joueur qui a le droit de jouer */
		Color currentPlayer_;

		friend class Tester;
	};
}