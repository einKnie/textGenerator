#include "helper.h"

char *to_upper(char *buf, uint8_t len) {

  for (uint8_t i = 0; i < len; i++) {
    if ((buf[i] < ASCII_LOWER_START) || (buf[i] > ASCII_LOWER_END)) continue;
    buf[i] -= 32;
  }
  return buf;
}

char *to_lower(char *buf, uint8_t len) {

  for (uint8_t i = 0; i < len; i++) {
    if ((buf[i] < ASCII_UPPER_START) || (buf[i] > ASCII_UPPER_END)) continue;
    buf[i] += 32;
  }
  return buf;
}
