#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include <map>

class State {
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();
	
	const bool& getQuit() const;
	void endState();

	void updateMousePos();
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target) = 0;
protected:
	std::stack<State*>* m_States = nullptr;
	sf::RenderWindow* m_Window = nullptr;
	std::map<std::string, int>* m_SupportedKeys = nullptr;
	std::map<std::string, int> m_Keybinds;
	bool m_Quit = false;

	sf::Vector2i m_MousePosScreen;
	sf::Vector2i m_MousePosWindow;
	sf::Vector2f m_MousePosView;
protected:
	void initKeybinds(std::string& configPath);
};

#endif /* STATE_HPP */