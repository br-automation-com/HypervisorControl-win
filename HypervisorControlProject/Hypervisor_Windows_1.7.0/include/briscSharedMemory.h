/* 
 * Functions to handle intersystem communications in a B&R environment.
 * The term 'system' is used as synonym for a operating system.
 */

/* 
 * Shared memory API
 * The default shared memory partition for usage by a user is preconfigured.
 */

#ifndef _BRISC_SHARED_MEMORY_H_
#define _BRISC_SHARED_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BRISC_EXPORTS
	#define BRISCSHAREDMEMORY_API __declspec(dllexport)
#else
	#define BRISCSHAREDMEMORY_API __declspec(dllimport)
#endif

typedef struct BRISC_SHM* BRISC_SHM_H;

/* 
 * Opens the default shared memory partition.
 * A shared memory partition cannot be opened twice on the same system.
 * Returns the handle of the opened shared memory partition or NULL in case of error.
 */
BRISCSHAREDMEMORY_API BRISC_SHM_H briscShmOpen();

/* 
 * Opens the shared memory partition with the given name which has to be configured 
 * in the hypervisor configuration file.
 * The shared memory partition cannot be opened twice on the same system.
 * Returns the handle of the opened shared memory partition or NULL in case of error.
 */
BRISCSHAREDMEMORY_API BRISC_SHM_H briscShmOpenByName(const char* pName);

/* 
 * Determine the size of the opened shared memory partition with the given handle 'hShm'.
 * Returns the size in bytes of the shared memory partition or -1 in case of error.
 */
BRISCSHAREDMEMORY_API int briscShmGetSize(BRISC_SHM_H hShm);

/* 
 * Determine the address of the opened shared memory partition with the given handle 'hShm'.
 * When accessing shared memory, the application is itself responsible for making sure
 * it does not access memory outside of the allocated shared memory partition.
 * Returns the pointer to the shared memory partition or NULL in case of error.
 */
BRISCSHAREDMEMORY_API volatile void* briscShmGetAddress(BRISC_SHM_H hShm);

/* 
 * Closes the shared memory partition with the given handle 'hShm'.
 */
BRISCSHAREDMEMORY_API void briscShmClose(BRISC_SHM_H hShm);

#ifdef __cplusplus
}
#endif

#endif
