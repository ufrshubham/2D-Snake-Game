#pragma once

#include <memory>
#include <array>

#include <SFML/Graphics/Sprite.hpp>

#include "Game.hpp"
#include "State.hpp"

class GamePlay : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Sprite m_grass;
    sf::Sprite m_food;
    std::array<sf::Sprite, 4> m_walls;

    // Todo:
    // Added Snake

public:
    GamePlay(std::shared_ptr<Context> &context);
    ~GamePlay();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    void Pause() override;
    void Start() override;
};