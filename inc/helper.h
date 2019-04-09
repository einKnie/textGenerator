#ifndef __HELPER_H_
#define __HELPER_H_

#include <stdint.h>

#define ASCII_LOWER_START 97
#define ASCII_LOWER_END   122
#define ASCII_UPPER_START 65
#define ASCII_UPPER_END   90

/// Change string to upper case
/// @param[in,out] buf string to upper-caseify
/// @param[in] len string length
/// @return pointer to buf
char *to_upper(char *buf, uint8_t len);

/// Change string to lower case
/// @param[in,out] buf string to lower-caseify
/// @param[in] len string length
/// @return pointer to buf
char *to_lower(char *buf, uint8_t len);

#endif // !__HELPER_H_
