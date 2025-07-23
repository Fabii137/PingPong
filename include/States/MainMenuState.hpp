#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include <map>

#include "States/State.hpp"
#include "Resources/Button.hpp"

class MainMenuState: public State {
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	void update(const float& dt) override;
	void render(sf::RenderTarget* target) override;
private:
	sf::Font m_Font;
	std::map<std::string, Button*> m_Buttons;

private:
	void initButtons();
	void initFont();
	void updateInput(const float& dt);
	void updateButtons();
};

#endif /* MAINMENUSTATE_HPP */