#include "States/State.hpp"

#include <fstream>
#include <iostream>

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) {
	m_Window = window;
	m_States = states;
	m_SupportedKeys = supportedKeys;
}

State::~State() {
	
}

const bool& State::getQuit() const
{
	return m_Quit;
}

void State::endState() {
	m_Quit = true;
}

void State::updateMousePos() {
	m_MousePosScreen = sf::Mouse::getPosition();
	m_MousePosWindow = sf::Mouse::getPosition(*m_Window);
	m_MousePosView = m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_Window));
}

void State::initKeybinds(const std::string& configPath) {
	std::ifstream ifs(configPath);
	if (ifs.is_open()) {
		std::string name = "";
		std::string key = "";
		while (ifs >> name >> key) {
			m_Keybinds[name] = m_SupportedKeys->at(key);
		}
	}
	else {
		throw("ERROR::STATE::COULD NOT LOAD KEYBINDS (" + configPath + ")");
	}
}

void State::centerText(sf::Text& text, float offsetY) {
	sf::Vector2u windowSize = m_Window->getSize();
	sf::FloatRect textBounds = text.getLocalBounds();

	text.setOrigin(sf::Vector2f(textBounds.position.x + textBounds.size.x / 2.0f,
		textBounds.position.y + textBounds.size.y / 2.0f));

	text.setPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f));
}

