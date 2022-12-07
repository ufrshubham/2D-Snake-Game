#include "GameOver.hpp"
#include "GamePlay.hpp"

#include <SFML/Window/Event.hpp>

GameOver::GameOver(std::shared_ptr<Context> &context)
    : m_context(context), m_option(Option::Retry)
{
}

GameOver::~GameOver()
{
}

void GameOver::Init()
{
    // Title
    m_gameOverTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameOverTitle.setString("Game Over");
    m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width / 2,
                              m_gameOverTitle.getLocalBounds().height / 2);
    m_gameOverTitle.setPosition(m_context->m_window->getSize().x / 2,
                                m_context->m_window->getSize().y / 2 - 150.f);

    // Play Button
    m_retryButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_retryButton.setString("Retry");
    m_retryButton.setOrigin(m_retryButton.getLocalBounds().width / 2,
                            m_retryButton.getLocalBounds().height / 2);
    m_retryButton.setPosition(m_context->m_window->getSize().x / 2,
                              m_context->m_window->getSize().y / 2 - 25.f);
    m_retryButton.setCharacterSize(20);

    // Exit Button
    m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 + 25.f);
    m_exitButton.setCharacterSize(20);

    m_deathSfx.setBuffer(m_context->m_assets->GetSoundEffect(DEATH_SFX));
}

void GameOver::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            {
                m_option = (Option)(std::clamp(m_option - 1, 0, (int)Option::Count - 1));
                break;
            }
            case sf::Keyboard::Down:
            {
                m_option = (Option)(std::clamp(m_option + 1, 0, (int)Option::Count - 1));
                break;
            }
            case sf::Keyboard::Return:
            {
                switch (m_option)
                {
                case Option::Retry:
                    m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
                    break;

                case Option::Exit:
                    m_context->m_window->close();
                    break;
                }

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

void GameOver::Update(const sf::Time &deltaTime)
{
    switch (m_option)
    {
    case Option::Retry:
        m_retryButton.setFillColor(sf::Color::Black);
        m_exitButton.setFillColor(sf::Color::White);
        break;

    case Option::Exit:
        m_exitButton.setFillColor(sf::Color::Black);
        m_retryButton.setFillColor(sf::Color::White);
        break;
    }
}

void GameOver::Draw() const
{
    m_context->m_window->clear(sf::Color::Blue);
    m_context->m_window->draw(m_gameOverTitle);
    m_context->m_window->draw(m_retryButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}

void GameOver::Start()
{
    m_deathSfx.play();
}