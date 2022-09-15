/* 
 * Functions to handle intersystem communications in a B&R environment.
 * The term 'system' is used as synonym for a operating system.
 */

/* 
 * Shared memory API
 * The default shared memory partition for usage by a user is preconfigured.
 */

#ifndef _BRHYPSRV_H_
#define _BRHYPSRV_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BRHYPSRV_EXPORTS
	#define BRHYPSRV_API __declspec(dllexport)
#else
	#define BRHYPSRV_API __declspec(dllimport)
#endif

/* 
 * Performs a System Reboot ("Deep Reboot") of the B&R Hypervisor system.
 * In detail, it sends shutdown commands to GPOS and ARemb. After both OSes are shutdown, the system is rebooted.
 */
BRHYPSRV_API void brhypsrvSystemReboot();

/* 
 * Performs a System Shutdown ("Deep Shutdown") of the B&R Hypervisor system.
 * In detail, it sends shutdown commands to GPOS and ARemb. After both OSes are shutdown, the system is powered off.
 */
BRHYPSRV_API void brhypsrvSystemShutdown();

/* 
 * Returns true if B&R Hypervisor is running, false otherwise (i.e.: Windows or Linux was started stand alone).
 */
BRHYPSRV_API bool brhypsrvIsHypervisorRunning();


#ifdef __cplusplus
}
#endif

#endif
