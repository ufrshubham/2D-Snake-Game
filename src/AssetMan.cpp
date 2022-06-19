#include "AssetMan.hpp"

Engine::AssetMan::AssetMan()
{
}

Engine::AssetMan::~AssetMan()
{
}

void Engine::AssetMan::AddTexture(int id, const std::string &filePath, bool wantRepeated)
{
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(filePath))
    {
        texture->setRepeated(wantRepeated);
        m_textures[id] = std::move(texture);
    }
}

void Engine::AssetMan::AddFont(int id, const std::string &filePath)
{
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filePath))
    {
        m_fonts[id] = std::move(font);
    }
}

void Engine::AssetMan::AddSoundTrack(int id, const std::string &filePath, bool wantLooping)
{
    auto soundTrack = std::make_unique<sf::Music>();

    if (soundTrack->openFromFile(filePath))
    {
        soundTrack->setLoop(wantLooping);
        m_soundTracks[id] = std::move(soundTrack);
    }
}

void Engine::AssetMan::AddSoundEffect(int id, const std::string &filePath)
{
    auto soundBuffer = std::make_unique<sf::SoundBuffer>();

    if (soundBuffer->loadFromFile(filePath))
    {
        m_soundEffects[id] = std::move(soundBuffer);
    }
}

const sf::Texture &Engine::AssetMan::GetTexture(int id) const
{
    return *(m_textures.at(id).get());
}

const sf::Font &Engine::AssetMan::GetFont(int id) const
{
    return *(m_fonts.at(id).get());
}

sf::Music &Engine::AssetMan::GetSoundTrack(int id)
{
    return *(m_soundTracks.at(id).get());
}

const sf::SoundBuffer &Engine::AssetMan::GetSoundEffect(int id) const
{
    return *(m_soundEffects.at(id).get());
}
