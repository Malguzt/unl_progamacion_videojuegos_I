#include "Modal.h"

Modal::Modal()
{
	modal.setOutlineColor(Color::Cyan);
	modal.setOutlineThickness(4);

	font.loadFromFile("ApleTime.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setColor(Color::Black);
}


Modal::~Modal()
{
}

void Modal::setRect(FloatRect rect)
{
	modal.setSize(Vector2f(rect.width, rect.height));
	modal.setOrigin(Vector2f(rect.width/2, rect.height/2));
	modal.setPosition(rect.left, rect.top);
	text.setPosition(rect.left - rect.width / 4, rect.top - rect.height / 4);
}

void Modal::draw(RenderWindow & gm, String message)
{
	gm.draw(modal);
	text.setString(message);
	gm.draw(text);
}
