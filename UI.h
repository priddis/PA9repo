#include <SFML/Graphics.hpp>

class UI : public sf::Drawable
{
private:
	sf::Vector2<int> position;
	sf::Vector2<int> size;
	sf::Color color;

public:
	
	~UI();

	// Set
	void setPosition(int x, int y) { position.x = x; position.y = y; }
	void setSize(int width, int height) { size.x = width; size.y = height; }
	void setColor(sf::Color newColor) { color = newColor; }

	// Get
	sf::Vector2<int> getPosition() { return position; }
	sf::Vector2<int> getSize() { return size; }
	sf::Color getColor() { return color; }
};