#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iostream>

std::string intToStr(int n)
{
	std::stringstream s;
	s << n;
	return s.str();
}

sf::Color colors[7] = { sf::Color::Red,
sf::Color::Green,
sf::Color::Blue,
sf::Color::Magenta,
sf::Color::Cyan,
sf::Color::Yellow,
sf::Color(255, 128, 0) };

const int WIDTH = 6;
const int HEIGHT = 10;
const int SIZE = 20;

void drawQuad(sf::RenderWindow & window, float x, float y, sf::Color c)
{
	sf::RectangleShape rect(sf::Vector2f(SIZE - 2, SIZE - 2));
	rect.setPosition(x + 1, y + 1);
	rect.setFillColor(c);
	window.draw(rect);
}

enum ShapeIndexes { I = 0, O = 4, S = 8, Z = 12, T = 16, L = 20, J = 24 };
bool SHAPES[][4][4] = {
	// I
	{ { 1, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 0, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 1 } },

	{ { 1, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 0, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 1 } },
	// O
	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 1, 0, 0 } },
	// S
	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 1, 1, 0 },
	{ 1, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 1, 1, 0 },
	{ 1, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 0, 0 } },
	// Z
	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 1, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 0, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 1, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 0, 0, 0 } },
	// T
	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 1, 0 } },

	{ { 0, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 0, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 0 },
	{ 0, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 0, 0 } },
	// L
	{ { 0, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 0 },
	{ 1, 0, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 0, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 1, 0 },
	{ 1, 1, 1, 0 } },
	// J
	{ { 0, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 1, 1, 0 } },

	{ { 0, 0, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 1, 0, 0, 0 } },

	{ { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 0 },
	{ 0, 0, 1, 0 } },
};

class Part
{
private:
	int shapeIndex;
	int data[4][4], posX, posY, color;

	void fillData()
	{
		for (int i = 0; i < 4; i++)
		for (int m = 0; m < 4; m++)
			data[i][m] = SHAPES[shapeIndex][i][m];
	}

public:
	Part()
	{
		posX = 2;
		posY = -4;
		generate();
	}

	void generate()
	{
		int g = (rand() % 7) * 4;
		shapeIndex = (ShapeIndexes)g;
		color = g / 4;
		fillData();
	}

	void move(int x, int y)
	{
		if (isValid(x, y))
		{
			posX += x;
			posY += y;
		}

	}

	void rotate()
	{
		int coIndex = shapeIndex;
		shapeIndex = ((shapeIndex + 1) % 4 == 0 ? shapeIndex - 3 : shapeIndex + 1);
		fillData();
		if (!isValid())
		{
			shapeIndex = coIndex;
			fillData();
		}
	}

	bool isValid(int xOffset = 0, int yOffset = 0)
	{
		for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		if ((data[y][x] && (posX + x + xOffset >= WIDTH || posX + xOffset < 0)) || (data[y][x] && (posY + y + yOffset > HEIGHT)))
		{
			return false;
		}

		return true;
	}

	void draw(sf::RenderWindow & window)
	{
		for (int i = 0; i < 4; i++)
		for (int m = 0; m < 4; m++)
		if (data[i][m])
		{
			drawQuad(window, (m + posX) * SIZE, (i + posY) * SIZE, colors[color]);
		}
	}

	int getPosX()
	{
		return posX;
	}

	int getPosY()
	{
		return posY;
	}

	int getElement(int x, int y)
	{
		return data[y][x];
	}
};

class Map
{
private:
	int data[10][6];
	int score;

public:
	Map()
	{
		reset();
	}

	void reset()
	{
		score = 0;
		for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			data[y][x] = 0;
	}

	bool isCollision(Part part)
	{
		for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		if ((part.getPosY() + y >= 0) && ((data[part.getPosY() + y + 1][part.getPosX() + x] && part.getElement(x, y)) ||
			(part.getElement(x, y) && part.getPosY() + y >= HEIGHT - 1)))
			return true;

		return false;
	}

	void addPart(Part part)
	{
		for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		if (part.getElement(x, y))
			data[part.getPosY() + y][part.getPosX() + x] = 1;
	}

	void applyGravity(int h)
	{
		for (int y = h; y > -1; y--)
		for (int x = 0; x < WIDTH; x++)
		if (y < HEIGHT - 1 && data[y + 1][x] == 0 && data[y][x])
		{
			data[y][x] = 0;
			data[y + 1][x] = 1;
		}
	}

	void destroyLines()
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			bool good = true;
			for (int x = 0; x < WIDTH; x++)
			if (!data[y][x])
			{
				good = false;
				break;
			}
			if (good)
			{
				score++;
				for (int x = 0; x < WIDTH; x++)
					data[y][x] = 0;
				applyGravity(y);
				y = 0;
			}
		}
	}

	bool isFull()
	{
		for (int x = 0; x < WIDTH; x++)
		if (data[0][x])
			return true;
		return false;
	}

	void draw(sf::RenderWindow & window)
	{
		for (int i = 0; i < HEIGHT; i++)
		for (int m = 0; m < WIDTH; m++)
		if (data[i][m])
			drawQuad(window, m * SIZE, i * SIZE, sf::Color::White);
	}

	int getScore()
	{
		return score;
	}
};

int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(6 * SIZE, 10 * SIZE), "", sf::Style::None);
	window.setFramerateLimit(30);

	Map map;
	Part part;
	int tick = 0;
	bool gameOver = false;
	sf::Text text("Score: " + intToStr(map.getScore()));
	text.setPosition(20, 90);
	text.setCharacterSize(20);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				Part p = part;
				part.move(1, 0);
				if (map.isCollision(part))
					part = p;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				Part p = part;
				part.move(-1, 0);
				if (map.isCollision(part))
					part = p;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				while (!map.isCollision(part))
				{
					part.move(0, 1);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				Part p = part;
				part.rotate();
				if (map.isCollision(part))
					part = p;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
				gameOver = false;
		}
		window.clear();

		if (gameOver)
		{
			window.draw(text);
			window.display();
			continue;
		}

		if (tick % 30 == 0)
			part.move(0, 1);

		if (map.isCollision(part))
		{
			map.addPart(part);
			map.destroyLines();
			part = Part();
		}

		map.draw(window);
		part.draw(window);

		if (tick <= 30)
			tick++;
		else
			tick = 1;

		if (map.isFull())
		{
			text.setString("Score " + intToStr(map.getScore()) + "\n" + "Press enter");
			map.reset();
			gameOver = true;
		}

		window.display();
	}

	return 0;
}