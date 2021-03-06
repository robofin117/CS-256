// SFML_Test.cpp : Defines the entry point for the console application.
//

// 1.) Change image of food with another sprite that is 16x16
// 2.) Change speed of snake as it grows
// 3.) Add a second player

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;
using namespace std;

//globals
int num_vertBox = 41, num_horzBox = 41;
int pixelSize = 16;// number of pixels
int w = pixelSize * num_horzBox;//Background number of pixels in width
int h = pixelSize * num_vertBox;//Background number of pixels in height

int direction1, direction2, snake_length = 4 , snake2_length = 4;

//Maximum size of Snake
struct Snake {
	int x, y;
	
}s[100], s2[100];


struct Fruit {
	int x, y;
}food;

int Tick() {
	int hasEaten = 0;
	//Move remaining pieces of snake s[1] - s[99]
	for (int i = snake_length; i >0; i--)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}


	//Head of snake depends on direction of user s[0]
	//User Up
	if (direction1 == 3) {
		s[0].y -= 1;
	}
	//User Down
	if (direction1 == 0) {
		s[0].y += 1;
	}
	//User Left
	if (direction1 == 1) {
		s[0].x -= 1;
	}
	//User Right
	if (direction1 == 2) {
		s[0].x += 1;
	}



	//If Snake 1 eats food it should grow
	if ((s[0].x) == food.x && (s[0].y) == food.y) {
		//Increment snake
		cout << "Food eaten by Snake 1." << endl;
		snake_length++;
		hasEaten = 1;


		//Randomly place food somewhere else
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;


	}



	//Boundary Checking screen loop back on other side for Player 1
	if (s[0].x > num_horzBox) {
		s[0].x = 0;
	}
	if (s[0].x < 0) {
		s[0].x = num_horzBox;
	}

	if (s[0].y > num_vertBox) {
		s[0].y = 0;
	}
	if (s[0].y < 0) {
		s[0].y = num_vertBox;
	}


	//Check if go over snake
	for (int i = 1; i < snake_length; i++) {
		//Cut snake 1 in half from place eaten
		if (s[0].x == s[i].x && s[0].y == s[i].y) {
			cout << "snake1 collision with itself" << endl;
			snake_length = i;
			hasEaten = 2;
		}

		//Cut snake 1 in half if collides with snake 2.
		else if (s[0].x == s2[i].x && s[0].y == s2[i].y) {
			cout << "snake1 collides with snake2" << endl;
			snake_length = i;
			hasEaten = 2;
		}


		else if (s[0].x == s2[0].x && s[0].y == s2[0].y) {
			cout << "snake1 head collision with snake2 head" << endl;
			snake_length = i;
			hasEaten = 2;
		}

	}
	return hasEaten;
}

int Tick2() {
	int hasEaten = 0;
	//Move remaining pieces of snake s2[1] - s2[99]
	for (int i = snake2_length; i > 0; i--) {
		s2[i].x = s2[i - 1].x;
		s2[i].y = s2[i - 1].y;
	}
	//Head of snake depends on direction of user s2[0]
	//User Up
	if (direction2 == 3) {
		s2[0].y -= 1;
	}
	//User Down
	if (direction2 == 0) {
		s2[0].y += 1;
	}
	//User Left
	if (direction2 == 1) {
		s2[0].x -= 1;
	}
	//User Right
	if (direction2 == 2) {
		s2[0].x += 1;
	}

	//If Snake 2 eats food it should grow
	if ((s2[0].x) == food.x && (s2[0].y) == food.y) {
		//Increment snake
		cout << "Food eaten by Snake 2." << endl;
		snake2_length++;
		hasEaten = 1;

		//Randomly place food somewhere else
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;


	}
	//Boundary Checking screen loop back on other side for Player 1
	if (s2[0].x > num_horzBox) {
		s2[0].x = 0;
	}
	if (s2[0].x < 0) {
		s2[0].x = num_horzBox;
	}

	if (s2[0].y > num_vertBox) {
		s2[0].y = 0;
	}
	if (s2[0].y < 0) {
		s2[0].y = num_vertBox;
	}

	//Check if go over snake
	for (int i = 1; i < snake2_length; i++) {
		//Cut snake 2 in half from place eaten
		if (s2[0].x == s2[i].x && s2[0].y == s2[i].y) {
			cout << "snake2 collision with itself" << endl;
			snake2_length = i;
			hasEaten = 2;
		}
		//Cut in half if snake2 hits snake1
		else if (s2[0].x == s[i].x && s2[0].y == s[i].y) {
			cout << "snake2 collides with snake1" << endl;
			snake2_length = i;
			hasEaten = 2;
		}


		else if (s2[0].x == s[0].x && s2[0].y == s[0].y) {
			cout << "snake2 head collision with snake1 head" << endl;
			snake2_length = i;
			hasEaten = 2;
		}
	}
	return hasEaten;
}

int main()
{
	srand(time(0));


	RenderWindow window(VideoMode(w, h), "Snake Game");

	//Textures
	//Load an image
	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");
	t3.loadFromFile("images/fruit.png");
	t4.loadFromFile("images/blue.png");

	//Sprite
	//Has physical dimensions
	Sprite sprite1(t1); //white
	Sprite sprite2(t2); //red
	Sprite sprite3(t3); //green apple
	Sprite sprite4(t4); //blue

	food.x = 20;
	food.y = 20;

	Clock clock;
	float timer1 = 0.0f, timer2 = 0.0f, delay1 = .1f, delay2 = .1f;


	//Starting position for snake 1.
	s[0].x = 9;
	s[0].y = 20;
	//Starting position for snake 2.
	s2[0].x = 31;
	s2[0].y = 20;

	while (window.isOpen()) {
		
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer1 += time;
		timer2 += time;

		//Allow us to check when a user does something
		Event e;

		//Check when window is closed
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		//Controls for Snake 1 Movement by User
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			direction1 = 3;
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			direction1 = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			direction1 = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			direction1 = 2;
		}

		//Controls for Snake 2 Movement by User
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			direction2 = 3;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			direction2 = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			direction2 = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			direction2 = 2;
		}

		if (timer1 > delay1) {
			timer1 = 0; //reset timer
			int check = Tick(); //Move Snake 1 one sprite forward

			if (check == 1) {
				delay1 = delay1 - .005f;
			}
			if (check == 2) {
				delay1 = .1f;
			}

		}

		if (timer2 > delay2) {
			timer2 = 0; //reset timer
			int check = Tick2(); //Move Snake 2 one sprite forward
			if (check == 1) {
				delay2 = delay2 - .005f;
			}
			if (check == 2) {
				delay2 = .1f;
			}
 
		}


		//Draw
		window.clear();

		//Draw Background
		for (int i = 0; i < num_horzBox; i++) {
			for (int j = 0; j < num_vertBox; j++) {
				sprite1.setPosition(i*pixelSize, j*pixelSize);
				window.draw(sprite1);
			}
		
		}

		//Draw Snake 1 
		for (int i = 0; i < snake_length; i++) {
			sprite2.setPosition((s[i].x*pixelSize), s[i].y*pixelSize);
			window.draw(sprite2);

		}

		//Draw Snake 2
		for (int i = 0; i < snake2_length; i++) {
			sprite4.setPosition((s2[i].x *pixelSize), s2[i].y*pixelSize);
			window.draw(sprite4);
		}

		//Draw Fruit
		sprite3.setPosition(food.x*pixelSize, food.y*pixelSize);
		window.draw(sprite3);

		window.display();

	}

	return 0;
}

