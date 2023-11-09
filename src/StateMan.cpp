#include "StateMan.hpp"

Engine::StateMan::StateMan() : m_add(false), m_replace(false), m_remove(false), m_removeAll(false)
{
}

Engine::StateMan::~StateMan()
{
}

void Engine::StateMan::Add(std::unique_ptr<State> toAdd, bool replace)
{
    m_add = true;
    m_newState = std::move(toAdd);

    m_replace = replace;
}

void Engine::StateMan::PopCurrent()
{
    m_remove = true;
}

void Engine::StateMan::PopAll()
{
    m_removeAll = true;
    m_remove = false;
}

void Engine::StateMan::ProcessStateChange()
{
    if (m_removeAll)
    {
        while (!m_stateStack.empty())
        {
            m_stateStack.pop();
        }
        m_removeAll = false;
    }
    else if (m_remove && (!m_stateStack.empty()))
    {
        m_stateStack.pop();

        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Start();
        }

        m_remove = false;
    }

    if (m_add)
    {
        if (m_replace && (!m_stateStack.empty()))
        {
            m_stateStack.pop();
            m_replace = false;
        }

        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Pause();
        }

        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->Init();
        m_stateStack.top()->Start();
        m_add = false;
    }
}

std::unique_ptr<Engine::State> &Engine::StateMan::GetCurrent()
{
    return m_stateStack.top();
}

bool Engine::StateMan::IsEmpty() const
{
    return m_stateStack.empty();
}
