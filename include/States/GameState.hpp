#ifndef GAMESTATE_HPP
#define	GAMESTATE_HPP

#include "States/State.hpp"
#include "Entities/Player.hpp"
#include "Entities/Ball.hpp"
#include <format>

class GameState : public State {
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	void update(const float& dt);
	void render(sf::RenderTarget* target);
private:
	bool m_GameOver = false;

	std::unique_ptr<Player> m_Player1;
	std::unique_ptr<Player> m_Player2;
	std::unique_ptr<Ball> m_Ball;

	int m_ScorePlayer1 = 0;
	int m_ScorePlayer2 = 0;
	const int m_MaxScore = 2;

	sf::Font m_Font;
	std::unique_ptr<sf::Text> m_ScoreText1;
	std::unique_ptr<sf::Text> m_ScoreText2;
	std::unique_ptr<sf::Text> m_WonText;
	std::unique_ptr<sf::Text> m_RestartText;
private:
	void initFont();
	void initText();
	void initGameObjects();
	void handleGameplayInput(const float& dt);
	void handleGameOverInput();
	void updateInput(const float& dt);
	void checkWin();
	void resetRound();
};

#endif /* GAMESTATE_HPP */