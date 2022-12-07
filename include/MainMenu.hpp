#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine::State
{
private:
    enum Option
    {
        Play,
        Exit,
        Count
    };

    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;

    Option m_option;

public:
    MainMenu(std::shared_ptr<Context> &context);
    ~MainMenu();

    void Init() override;
    void ProcessInput() override;
    void Update(const sf::Time &deltaTime) override;
    void Draw() const override;
};