#include "Tile.hpp"

namespace view
{
	Tile::Tile(QString title, QWidget* parent, int x, int y) :
		QPushButton(title, parent),
		timer_(this),
		x_(x),
		y_(y)
	{
		setGeometry(caseWidth * x_, caseHeight * y_, caseWidth, caseHeight);
		setDefaultColor();

		timer_.setSingleShot(true);
		QObject::connect(&timer_, &QTimer::timeout,
			this, &view::Tile::setDefaultColor);
	}


	void Tile::setImage(QIcon icon)
	{
		setIcon(icon);
		setIconSize(QSize(iconHeight, iconWidth));
	}


	void Tile::setDefaultColor()
	{
		const bool isPairColumn = (x_ % 2 == 0);
		const bool isPairRow = (y_ % 2 == 0);

		const bool isBlackTileCase1 = (isPairColumn && !isPairRow);
		const bool isBlackTileCase2 = (!isPairColumn && isPairRow);

		const bool isBlackTile = isBlackTileCase1 || isBlackTileCase2;
		if (isBlackTile)
			setStyleSheet(grey);
		else
			setStyleSheet(white);
	}

	
	void Tile::setInvalid()
	{
		setStyleSheet(red);
		timer_.start(invalidMoveColorTime);
	}
}