#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <ctime> 
#include <cstdlib> 
#include <sstream> 
#include <iostream> 


const int WIDTH = 10;
const int HEIGHT = 20;
const int SIZE = 32;

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
};//Фигурки тетриса

class Part
{
private:
	int shapeIndex;
	int data[4][4], posX, posY;

	void fillData()
	{
		for (int i = 0; i < 4; i++)
		for (int m = 0; m < 4; m++)
			data[i][m] = SHAPES[shapeIndex][i][m];
	}

public:
	Part()
	{
		posX = 4;
		posY = -3;
		generate();
	}

	int color;
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


	bool isValid(int xOffset = 0, int yOffset = 0)
	{
		for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		if ((data[y][x] && (posX + x + xOffset >= WIDTH || posX + xOffset < 0)) || (data[y][x] && (posY + y + yOffset > HEIGHT - 1)))
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
			drawQuad(window, (m + posX) * SIZE, (i + posY) * SIZE, sf::Color(255, 0, 0));
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
	int data[HEIGHT][WIDTH];

public:
	Map()
	{
		reset();
	}

	void reset()
	{
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

	void draw(sf::RenderWindow & window)
	{
		for (int i = 0; i < HEIGHT; i++)
		for (int m = 0; m < WIDTH; m++)
		if (data[i][m])
			drawQuad(window, m * SIZE, i * SIZE, sf::Color(255,0,0));
	}

};

int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(WIDTH * SIZE, HEIGHT * SIZE), "Tetris", sf::Style::None);
	int speed = 120;
	window.setFramerateLimit(speed);

	Map map;
	Part part;
	int tick = 0;
	bool gameOver = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))//отработка нажатий 
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				Part p = part; //отработка коллизий 
				part.move(1, 0);//движение вправо 
				if (map.isCollision(part))
					part = p;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				Part p = part;
				part.move(-1, 0);//движение влево 
				if (map.isCollision(part))
					part = p;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				Part p = part;
				part.move(0, 1);//движение вниз(ускоренное) 
				if (map.isCollision(part))
					part = p;
			}



		} //Использование клавиатуры 

		window.clear(sf::Color(0, 0, 0));

		window.setFramerateLimit(speed);


		if (tick % 30 == 0) part.move(0, 1);

		if (map.isCollision(part))
		{
			map.addPart(part);
			part = Part();
		}

		map.draw(window);

		part.draw(window);

		if (tick <= 30) tick++; else tick = 1;



		window.display();
	}

	return 0;
}
