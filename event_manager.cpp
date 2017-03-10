#include "event_manager.h"
#include <algorithm>

using namespace std;

EventManager* EventManager::getInstance()
{
    static EventManager inst;
    return &inst;
}

void EventManager::publishEvent(const Event& ev)
{
    //...
  for(auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
  {
     (*(it)->lock()).notify(ev);
  }
}

void EventManager::addListener(shared_ptr<EventListener>& listener)
{
    //...
    auto it = find_if(m_listeners.begin(), m_listeners.end(), [&](std::weak_ptr<EventListener> const& p) {
        return p.lock() == listener;
    });

    if(it == m_listeners.end())
    {
        m_listeners.push_back(listener);

    }


}

void EventManager::removeListener(shared_ptr<EventListener>& listener)
{

    auto it = find_if(m_listeners.begin(), m_listeners.end(), [&](std::weak_ptr<EventListener> const& p) {
        return p.lock() == listener;
    });
    if(it != m_listeners.end())
    {
    m_listeners.erase(it);
    }

}
