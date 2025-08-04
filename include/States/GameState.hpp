#ifndef GAMESTATE_HPP
#define	GAMESTATE_HPP

#include "States/State.hpp"
#include "Entities/Player.hpp"
#include "Entities/Ball.hpp"

class GameState : public State {
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	void update(const float& dt);
	void render(sf::RenderTarget* target);
private:
	std::unique_ptr<Player> m_Player1;
	std::unique_ptr<Player> m_Player2;
	std::unique_ptr<Ball> m_Ball;
private:
	void updateInput(const float& dt);

};

#endif /* GAMESTATE_HPP */