#ifndef ITUENGINE_INTERFACETEMPLATEEVENTMANAGER_H
#define ITUENGINE_INTERFACETEMPLATEEVENTMANAGER_H

////////////////////////////////////////////////////////////////
// Generic event manager for native C++.
//

#include <list>
using namespace std;

//////////////////
// Generic event manager. Holds list of client objects. Template class
// parameterized by the event interface.
//
// - Instantiate in event source class.
//
// - Source calls Raise to raise an event, passing functor object 
// initialized with event params.
//
// - Clients derive from event interface and override event handlers. 
// Clients call Register/Unregister to add/remove themselves.
//

template <typename I> //Interface type
class InterfaceTemplateEventManager
{
protected:
    list<I*> m_clients; // list of registered client objects
public:
    InterfaceTemplateEventManager() { }
    ~InterfaceTemplateEventManager() { }

    // Register: Add client to list.
    void Register(I* client)
    {
        m_clients.push_back(client);
    }

    // Unregister: Remove client from list.
    void Unregister(I* client)
    {
        m_clients.remove(client);
    }

    // Nested template member function! This fn calls the function object 
    // F for each registered client. It merely passes F to for_each. Use 
    // the DEFINE_EVENT macros to generate the functors. See IPrimeEvents 
    // in Prime.h for example. 
    template <typename F> //Function class type
    void Raise(F fn)
    {
        for_each(m_clients.begin(), m_clients.end(), fn);
    }
};

#endif
