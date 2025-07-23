#include "game.hpp"
#include "States/MainMenuState.hpp"

#include <fstream>
#include <iostream>

Game::Game() {
	applyConfig();
	initSupportedKeys();
	initStates();
}

Game::~Game() {
	if (m_Window) {
		delete m_Window;
		m_Window = nullptr;
	}

	while (!m_States.empty()) {
		delete m_States.top();
		m_States.pop();
	}
}

void Game::initStates() {
	m_States.push(new MainMenuState(m_Window, &m_SupportedKeys, &m_States));
}

void Game::initSupportedKeys() {
	std::ifstream ifs(std::string(RESOURCES_PATH) + "configs/supported_keys.ini");

	if (ifs.is_open()) {
		std::string key = "";
		int value = 0;
		while (ifs >> key >> value) {
			m_SupportedKeys[key] = value;
		}
	}
	else {
		throw("ERROR::GAME::COULD NOT LOAD SUPPORTED KEYS");
	}
}

void Game::applyConfig()
{	
	std::ifstream ifs(std::string(RESOURCES_PATH) + "configs/window.ini");

	sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
	std::string title = "None";
	int framerateLimit = 120;
	bool vSyncEnabled = false;
	int antialiasingLevel = 0;

	// read config file
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> windowBounds.size.x >> windowBounds.size.y;
		ifs >> m_Fullscreen;
		ifs >> framerateLimit;
		ifs >> vSyncEnabled;
		ifs >> antialiasingLevel;
	} else {
		throw ("ERROR::GAME::COULD NOT LOAD CONFIG");
	}
	ifs.close();

	// set window settings and create window
	m_WindowSettings.antiAliasingLevel = antialiasingLevel;
	if (m_Fullscreen) {
		m_Window = new sf::RenderWindow(windowBounds, title, sf::State::Fullscreen, m_WindowSettings);
	}
	else {
		m_Window = new sf::RenderWindow(windowBounds, title, sf::Style::Close, sf::State::Windowed, m_WindowSettings);
	}
	m_Window->setFramerateLimit(framerateLimit);
	m_Window->setVerticalSyncEnabled(vSyncEnabled);
}

void Game::updateDt() {
	m_Dt = m_DtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
	while (const std::optional event = m_Window->pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			m_Window->close();
		}
	}
}

void Game::update() {
	updateSFMLEvents();

	if (!m_States.empty()) {
		m_States.top()->update(m_Dt);
		if (m_States.top()->getQuit()) {
			std::cout << "State ended: " << typeid(*m_States.top()).name() << std::endl;
			std::cout << "States remaining: " << m_States.size() - 1 << std::endl;
			m_States.top()->endState();
			delete m_States.top();
			m_States.pop();
		}
	}
	else {
		m_Window->close();
	}
}

void Game::render() {
	m_Window->clear();

	// render current state
	if (!m_States.empty()) {
		m_States.top()->render(m_Window);
	}

	m_Window->display();
}

void Game::run() {
	while (m_Window->isOpen()) {
		updateDt();
		update();
		render();
	}
}


