#include <SFML/Graphics/CircleShape.hpp>

#include "Game.hpp"
#include "MainMenu.hpp"

#include <filesystem>

Game::Game() : m_context(std::make_shared<Context>())
{
    ModifyCurrentWorkingDirectory();

    auto cwd = std::filesystem::current_path();
    m_context->m_window->create(sf::VideoMode(640, 352), "Snake Game", sf::Style::Close);
    m_context->m_assets->AddSoundTrack(MAIN_SOUND_TRACK, "assets/audio/Spinning out.ogg", true);
    m_context->m_assets->AddSoundEffect(COIN_SFX, "assets/audio/Simple Coin 006.wav");
    m_context->m_assets->AddSoundEffect(DEATH_SFX, "assets/audio/Death 002.wav");
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

Game::~Game()
{
}

void Game::Run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();
        }
    }
}

void Game::ModifyCurrentWorkingDirectory() const
{
    while (!std::filesystem::exists("assets"))
    {
        std::filesystem::current_path(std::filesystem::current_path().parent_path());
    }
}
