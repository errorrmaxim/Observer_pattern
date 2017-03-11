#include <iostream>
#include <string>
#include <memory>

#include "event.h"
#include "event_listener.h"
#include "event_manager.h"

using namespace std;


struct FileLogger : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

struct ConnectionMgr : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


struct EventHandler : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


int main(int argc, char *argv[])
{
   EventManager *Mng = EventManager::getInstance();
   Event start("start");
   Event status("status");
   Event stop("stop");


    shared_ptr<EventListener> evListener1 = make_shared<FileLogger>();
    shared_ptr<EventListener> evListener2 = make_shared<ConnectionMgr>();
    shared_ptr<EventListener> evListener3 = make_shared<EventHandler>();

    Mng->addListener(evListener1);
    Mng->addListener(evListener2);
    Mng->addListener(evListener3);

    Mng->publishEvent(start);
    cout << "==============" << endl;

    Mng->removeListener(evListener3);


    Mng->publishEvent(stop);



    //...

    return 0;
}
