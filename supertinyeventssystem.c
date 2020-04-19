#define EVENT_REGISTER_MAX_NUMBER 32U

/*
 Add your event IDs here
 */
enum EVENTS
{
    BLOB_DEATH
};

typedef void(*EventFunc)(void); // function callback

struct EventSubscription
{
    enum EVENTS m_eventID;
    EventFunc m_eventCallback;
};

static uint32_t EventRegisterCount = 0;
static EventSubscription EventRegister[EVENT_REGISTER_MAX_NUMBER];

void SubscribeToEvent(enum EVENTS eventID, EventFunc callback)
{
    EventRegister[EventRegisterCount].m_eventID = eventID;
    EventRegister[EventRegisterCount].m_eventCallback = callback;
    
    EventRegisterCount++;
    
    if (EventRegisterCount >= EVENT_REGISTER_MAX_NUMBER)
    {
        throw -1;
    }
}

void TriggerEvent(enum EVENTS eventID)
{
    for (uint32_t i = 0U; i < EventRegisterCount; i++)
    {
        EventRegister[i].m_eventCallback();
    }
}
