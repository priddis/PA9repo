
#include <SFML/Graphics.hpp>

class UI : public sf::Drawable
{
private:
	sf::Vector2<int> position;
	sf::Vector2<int> size;
	sf::Texture texture;
	sf::Sprite uiSprite;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	
	UI();

	~UI();

	// Set
	void UI::setPosition(int x, int y) { position.x = x; position.y = y; }
	void UI::setSize(int width, int height) { size.x = width; size.y = height; }
	void UI::setTexture(sf::Texture newTexture) { texture = newTexture; }

	// Get
	sf::Vector2<int> UI::getPosition() { return position; }
	sf::Vector2<int> UI::getSize() { return size; }
	sf::Texture UI::getTexture() { return texture; }
};