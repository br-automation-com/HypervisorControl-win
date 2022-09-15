/* 
 * Functions to handle intersystem communications in a B&R environment.
 * The term 'system' is used as synonym for a operating system.
 */

/* 
 * Event API
 * An Event is a type of notification between systems.
 * It's possible to send an event from system to system or to the own system.
 * The functions for triggering the event and waiting for the event work in either direction.
 * The maximum allowed length of the event name is 256 characters.
 * The maximum allowed amount of events is 32.
 *
 * There is no caching of events on receivers side. If the event receiver is not 
 * in receiving state, a triggered event is lost.
 * 
 * Best practice: The system that opens the event (briscEventOpen()) triggers 
 * it (briscEventTrigger()). The system that creates the event (briscEventCreate()) 
 * waits for the event (briscEventWait()).
 */


#ifndef _BRISC_EVENT_H_
#define _BRISC_EVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BRISC_EXPORTS
	#define BRISCEVENT_API __declspec(dllexport)
#else
	#define BRISCEVENT_API __declspec(dllimport)
#endif

typedef struct BRISC_EVENT* BRISC_EVENT_H;

/* 
 * Creates an event with the given name 'pName'.
 * If the event already exists an error is returned.
 * Returns: handle of an event or NULL in case of error.
 */
BRISCEVENT_API BRISC_EVENT_H briscEventCreate(const char * pName);

/* 
 * Opens an existing event with the given name 'pName'.
 * Returns: handle of an event or NULL in case of error.
 */
BRISCEVENT_API BRISC_EVENT_H briscEventOpen(const char * pName);

/* 
 * Triggers an event.
 * Triggers an event for all operating systems, if the event was not already
 * triggered before. If the event is already triggered the function returns
 * still true.
 * Returns: true if triggering was successful or false in case of error.
 */
BRISCEVENT_API bool briscEventTrigger(BRISC_EVENT_H hEvent);

/* 
 * Waits for an event.
 * When the event is triggered the waiting thread will continue executing.
 * This function will return immediately with return value 'true' if the specified event has already been
 * signaled and the event has not been cleared by a preceeding xxxEvWait() call within this OS.
 * The timeout is given in milliseconds, 0xFFFFFFFF waits infinite time.
 * Returns: true if successful or false in case of error.
 */
BRISCEVENT_API bool briscEventWait(BRISC_EVENT_H hEvent, unsigned long timeout);

/* 
 * Closes an event.
 * If the last handle of an event is closed, the event will be destroyed from the system.
 */
BRISCEVENT_API void briscEventClose(BRISC_EVENT_H hEvent);

#ifdef __cplusplus
}
#endif

#endif
