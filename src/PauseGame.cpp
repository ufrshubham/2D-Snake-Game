#include "PauseGame.hpp"

#include <SFML/Window/Event.hpp>

PauseGame::PauseGame(std::shared_ptr<Context> &context)
    : m_context(context)
{
}

PauseGame::~PauseGame()
{
}

void PauseGame::Init()
{
    // Title
    m_pauseTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_pauseTitle.setString("Paused");
    m_pauseTitle.setOrigin(m_pauseTitle.getLocalBounds().width / 2,
                           m_pauseTitle.getLocalBounds().height / 2);
    m_pauseTitle.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2);
}

void PauseGame::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_states->PopAll();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
            {
                m_context->m_states->PopCurrent();
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void PauseGame::Update(const sf::Time &deltaTime)
{
}

void PauseGame::Draw()
{
    m_context->m_window->draw(m_pauseTitle);
    m_context->m_window->display();
}
