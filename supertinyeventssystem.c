#define EVENT_REGISTER_MAX_NUMBER 32U

/*
 Add your event IDs here
 */
enum EVENTS
{
    // e.g. BLOB_DEATH
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
    if (EventRegisterCount >= EVENT_REGISTER_MAX_NUMBER)
    {
        //throw -1;
    }
    else
    {
        EventRegister[EventRegisterCount].m_eventID = eventID;
        EventRegister[EventRegisterCount].m_eventCallback = callback;

        EventRegisterCount++;
    }
}

void TriggerEvent(enum EVENTS eventID)
{
    for (uint32_t i = 0U; i < EventRegisterCount; i++)
    {
        if (EventRegister[i].m_eventID == eventID)
        {
			EventRegister[i].m_eventCallback();
		}
    }
}
