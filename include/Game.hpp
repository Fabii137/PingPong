#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <States/State.hpp>
#include <stack>
#include <map>


class Game {
public:
	Game();
	virtual ~Game();

	void run();
private:
	sf::RenderWindow* m_Window = nullptr;
	sf::ContextSettings m_WindowSettings;
	std::stack<State*> m_States;
	std::map<std::string, int> m_SupportedKeys;
	sf::Clock m_DtClock;
	float m_Dt = 0.f;
	bool m_Fullscreen = false;

private:
	void initStates();
	void initSupportedKeys();
	void applyConfig();
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
};

#endif /* GAME_HPP */