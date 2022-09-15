/* 
 * Functions to handle intersystem communications in a B&R environment.
 * The term 'system' is used as synonym for a operating system.
 */

/* 
 * Interlock data access - API
 * Atomic compare and exchange of a 4-byte value without interruption by another CPU.
 * Compares the value pointed to by 'pData' with the 'compareValue'. If the two values are equal,
 * the 'newValue' will be written to the location pointed to by 'pData' and the 'compareValue' is
 * returned. If they are not equal, the content of 'pData' is left unchanged and returned.
 * Returns: 'compareValue' if the exchange was carried out,
 *          or the unchanged value pointed to by pData if the exchange was not carried out.
 */

#ifndef _BRISC_ATOMIC_H_
#define _BRISC_ATOMIC_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BRISC_EXPORTS
	#define BRISCATOMIC_API __declspec(dllexport)
#else
	#define BRISCATOMIC_API __declspec(dllimport)
#endif

BRISCATOMIC_API unsigned int briscInterlockedCompareExchange(unsigned int newValue, unsigned int compareValue, unsigned int* pData);

#ifdef __cplusplus
}
#endif

#endif
