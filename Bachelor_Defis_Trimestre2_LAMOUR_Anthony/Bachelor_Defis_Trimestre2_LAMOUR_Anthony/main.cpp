#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

	//constantes
		const float PLAYERSPEED = 10;

	//cr�ation de la fen�tre
		sf::RenderWindow window(sf::VideoMode(1000, 1000), "Space shooter", sf::Style::Close);

	//cr�ation du Background du jeu
		sf::Texture BackgroundTexture;
		sf::Sprite Background;
		if (BackgroundTexture.loadFromFile("Background.png")) {
			Background.setPosition(0, 0);
			Background.setTexture(BackgroundTexture);
		}
		else {
			std::cout << "Erreur de chargement du Background." << std::endl;
		}

	//cr�ation du joueur
		sf::Texture PlayerTexture;
		sf::Sprite Player;
		if (PlayerTexture.loadFromFile("Player.png")) {
			Player.setPosition(window.getSize().x / 2, window.getSize().y - PlayerTexture.getSize().y);
			Player.setTexture(PlayerTexture);
		}
		else {
			std::cout << "Erreur de chargement du Player." << std::endl;
		}

	//cr�ation des textures de ennemis
		//Ennemi1
			sf::Texture Ennemi1Texture;
			if (Ennemi1Texture.loadFromFile("Ennemi1.png")) {
				std::cout << "Texture de l'ennmi 1 chager." << std::endl;
			}
			else {
				std::cout << "Erreur de chargement de la texture de l'ennemi 1." << std::endl;
			}
		//Ennemi2
			sf::Texture Ennemi2Texture;
			if (Ennemi2Texture.loadFromFile("Ennemi2.png")) {
				std::cout << "Texture de l'ennmi 2 chager." << std::endl;
			}
			else {
				std::cout << "Erreur de chargement de la texture de l'ennemi 2." << std::endl;
			}
		//Boss
			sf::Texture BossTexture;
			if (BossTexture.loadFromFile("Boss.png")) {
				std::cout << "Texture du boss chager." << std::endl;
			}
			else {
				std::cout << "Erreur de chargement de la texture du boss." << std::endl;
			}

	//cr�ation de la texture des bullets
		//BulletPlayer
			sf::Texture BulletPlayerTexture;
			if (BulletPlayerTexture.loadFromFile("BulletPlayer.png")) {
				std::cout << "Texture des bullets du joueur chager." << std::endl;
			}
			else {
				std::cout << "Erreur de chargement de la texture des bullets du joueur." << std::endl;
			}
		//BulletEnnemi
			sf::Texture BulletEnnemiTexture;
			if (BulletPlayerTexture.loadFromFile("BulletEnnemi.png")) {
				std::cout << "Texture des bullets des ennemis chager." << std::endl;
			}
			else {
				std::cout << "Erreur de chargement de la texture des bullets des ennemis." << std::endl;
			}

	//cr�ation du tableau d'ennemis
		int NumEnnemi=0;
		sf::Sprite * TabEnnemi=new sf::Sprite[NumEnnemi];

	//cr�ation du tableau de balle du joueur
		int NumBallePlayer = 0;
		sf::Sprite * TabBallePlayer = new sf::Sprite[NumBallePlayer];

	//cr�ation du tableau de balle du joueur
		int NumBalleEnnemi = 0;
		sf::Sprite * TabBalleEnnemi = new sf::Sprite[NumBalleEnnemi];

	//boucle de jeu
		while (window.isOpen())
		{

			//r�cup�ration d'�v�nements
			sf::Event event;
			while (window.pollEvent(event))
			{
				//permet de fermer la fen�tre
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}

				//permet de fermer la fen�tre en appuyant sur �chap
					if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window.close();
					}

				//d�placement du personnage
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					{
						if (Player.getPosition().y - PLAYERSPEED > 0) {
							Player.move(0, -PLAYERSPEED);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						if (Player.getPosition().y + PLAYERSPEED < window.getSize().y-Player.getTexture()->getSize().y) {
							Player.move(0, PLAYERSPEED);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
						if (Player.getPosition().x - PLAYERSPEED > 0) {
							Player.move(-PLAYERSPEED, 0);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						if (Player.getPosition().x + PLAYERSPEED < window.getSize().x - Player.getTexture()->getSize().x) {
							Player.move(PLAYERSPEED, 0);
						}
					}

			}

			//affichage du jeu
			window.clear();
			window.draw(Background);
			window.draw(Player);
			window.display();
		}

	return 0;
}