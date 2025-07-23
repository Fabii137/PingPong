#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"

#include <fstream>

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states) {
    initKeybinds(std::string(RESOURCES_PATH) + "configs/mainmenustate_keybinds.ini");
    initFont();
    initButtons();
}

MainMenuState::~MainMenuState() {
    for(auto it = m_Buttons.begin(); it != m_Buttons.end(); it++) {
        delete it->second;
	}
}

void MainMenuState::update(const float& dt) {
    updateMousePos();
	updateInput(dt);
    updateButtons();
}

void MainMenuState::render(sf::RenderTarget* target) {
    if (!target) {
        target = m_Window;
    }
    
    // render buttons
    for (auto& it : m_Buttons) {
        it.second->render(target);
    }
}

void MainMenuState::initButtons() {
    m_Buttons["NEW_GAME"] = new Button(300, 480, 250, 50,
        &m_Font, "New Game", 50,
        sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
        sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    m_Buttons["SETTINGS"] = new Button(300, 580, 250, 50,
        &m_Font, "Settings", 50,
        sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
        sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    m_Buttons["EXIT"] = new Button(300, 880, 250, 50,
        &m_Font, "Quit", 50,
        sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
        sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void MainMenuState::initFont() {
    if (!m_Font.openFromFile(std::string(RESOURCES_PATH) + "fonts/Dosis-Light.ttf")) {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::updateInput(const float& dt) {
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["CLOSE"]))) {
        endState();
	}*/
}

void MainMenuState::updateButtons() {
	for (auto& it : m_Buttons) {
		it.second->update(m_MousePosView);
	}

    if (m_Buttons["NEW_GAME"]->isPressed()) {
        m_States->push(new GameState(m_Window, m_SupportedKeys, m_States));
    }

    if (m_Buttons["SETTINGS"]->isPressed()) {
        //TODO: push settings state
    }

	if (m_Buttons["EXIT"]->isPressed()) {
        endState();
	}
}

