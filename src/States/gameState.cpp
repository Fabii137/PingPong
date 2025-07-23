#include "States/GameState.hpp"
#include "States/MainMenuState.hpp"

#include <fstream>
#include <iostream>

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states): State(window, supportedKeys, states) {
	initKeybinds(std::string(RESOURCES_PATH) + "configs/gamestate_keybinds.ini");
	m_Player1.setPosition(sf::Vector2f(100.f, 540.f));
	m_Player2.setPosition(sf::Vector2f(1820.f, 540.f));
	m_Ball.setPosition(sf::Vector2f(960.f, 540.f));
}

GameState::~GameState() {

}

void GameState::update(const float& dt) {
	updateMousePos();
	updateInput(dt);
}

void GameState::render(sf::RenderTarget* target) {
	if (!target) {
		target = m_Window;
	}

	m_Player1.render(target);
	m_Player2.render(target);
	m_Ball.render(target);

}

void GameState::updateInput(const float& dt) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P1_MOVE_UP"]))) {
		m_Player1.move(dt, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P1_MOVE_DOWN"]))) {
		m_Player1.move(dt, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P2_MOVE_UP"]))) {
		m_Player2.move(dt, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P2_MOVE_DOWN"]))) {
		m_Player2.move(dt, 1.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["CLOSE"]))) {
		endState();
	}

	
}
