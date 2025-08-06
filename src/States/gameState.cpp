#include "States/GameState.hpp"
#include "States/MainMenuState.hpp"

#include <fstream>
#include <iostream>

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states): State(window, supportedKeys, states) {
	initKeybinds(std::string(RESOURCES_PATH) + "configs/gamestate_keybinds.ini");
	initFont();
	initText();
	initGameObjects();

	m_Ball->start(); // start moving ball
}

GameState::~GameState() {

}

void GameState::update(const float& dt) {
	updateMousePos();
	updateInput(dt);

	m_Ball->update(dt);
	checkWin();
}

void GameState::render(sf::RenderTarget* target) {
	if (!target) {
		target = m_Window;
	}

	m_Player1->render(target);
	m_Player2->render(target);
	m_Ball->render(target);

	target->draw(*m_ScoreText1);
	target->draw(*m_ScoreText2);

	if (m_GameOver) {
		target->draw(*m_WonText);
		target->draw(*m_RestartText);
	}
	

}

void GameState::initFont() {
	if (!m_Font.openFromFile(std::string(RESOURCES_PATH) + "fonts/Dosis-Light.ttf")) {
		throw("ERROR::GAMESTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initText() {
	sf::Vector2u windowSize = m_Window->getSize();

	m_ScoreText1 = std::make_unique<sf::Text>(m_Font, "0", 50);
	m_ScoreText1->setPosition(sf::Vector2f(windowSize.x * 0.2f, windowSize.y * 0.1f));
	m_ScoreText1->setFillColor(sf::Color::White);

	m_ScoreText2 = std::make_unique<sf::Text>(m_Font, "0", 50);
	m_ScoreText2->setPosition(sf::Vector2f(windowSize.x * 0.8f, windowSize.y * 0.1f));
	m_ScoreText2->setFillColor(sf::Color::White);

	m_WonText = std::make_unique<sf::Text>(m_Font, "Player x won", 50);
	sf::FloatRect wonTextBounds = m_WonText->getLocalBounds();
	// center with -50.0 y offset
	m_WonText->setPosition(sf::Vector2f(windowSize.x / 2.f - wonTextBounds.size.x / 2.f, windowSize.y / 2.f - wonTextBounds.size.y / 2.f - 50.f));
	m_WonText->setFillColor(sf::Color::White);

	m_RestartText = std::make_unique<sf::Text>(m_Font, "Press Space to play again...", 40);
	sf::FloatRect restartTextBounds = m_RestartText->getLocalBounds();
	// center with +50.0 y offset
	m_RestartText->setPosition(sf::Vector2f(windowSize.x / 2.f - restartTextBounds.size.x / 2.f, windowSize.y / 2.f - restartTextBounds.size.y / 2.f + 50.f));
	m_RestartText->setFillColor(sf::Color::White);
}

void GameState::initGameObjects() {
	m_Player1 = std::make_unique<Player>(*m_Window);
	m_Player1->setPosition(sf::Vector2f(100.f, 540.f));

	m_Player2 = std::make_unique<Player>(*m_Window);
	m_Player2->setPosition(sf::Vector2f(1820.f, 540.f));

	m_Ball = std::make_unique<Ball>(*m_Player1->getShape(), *m_Player2->getShape(), *m_Window);
	m_Ball->setPosition(sf::Vector2f(960.f, 540.f));
}

void GameState::handleGameplayInput(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P1_MOVE_UP"]))) {
		m_Player1->move(dt, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P1_MOVE_DOWN"]))) {
		m_Player1->move(dt, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P2_MOVE_UP"]))) {
		m_Player2->move(dt, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["P2_MOVE_DOWN"]))) {
		m_Player2->move(dt, 1.f);
	}
}

void GameState::handleGameOverInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(sf::Keyboard::Key::Space))) {
		m_ScorePlayer1 = 0;
		m_ScoreText1->setString("0");

		m_ScorePlayer2 = 0;
		m_ScoreText2->setString("0");

		m_WonText->setString("");
		m_RestartText->setString("");
		m_GameOver = false;
		resetRound();
	}
}

void GameState::updateInput(const float& dt) {
	
	if (!m_GameOver) {
		handleGameplayInput(dt);
	}
	else {
		handleGameOverInput();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_Keybinds["CLOSE"]))) {
		endState();
	}
}

void GameState::checkWin() {
	sf::Vector2f ballPos = m_Ball->getShape()->getPosition();
	sf::Vector2u windowSize = m_Window->getSize();

	if (ballPos.x < 0) {
		m_ScorePlayer2++;
		m_ScoreText2->setString(std::to_string(m_ScorePlayer2));
		resetRound();
	}
	else if (ballPos.x > windowSize.x) {
		m_ScorePlayer1++;
		m_ScoreText1->setString(std::to_string(m_ScorePlayer1));
		resetRound();
	}

	if (m_ScorePlayer1 >= m_MaxScore || m_ScorePlayer2 >= m_MaxScore) {
		std::string wonText = std::format("Player {} won!", (m_ScorePlayer1 >= m_MaxScore ? "1" : "2"));
		m_WonText->setString(wonText);
		m_GameOver = true;
		m_Ball->stop();
	}
}

void GameState::resetRound() {
	m_Player1->setPosition(sf::Vector2f(100.f, 540.f));
	m_Player2->setPosition(sf::Vector2f(1820.f, 540.f));

	m_Ball->setPosition(sf::Vector2f(960.f, 540.f));
	m_Ball->start();
}
