/*   _______        _
 *  |__   __|      | |
 *     | | _____  _| |_
 *     | |/ _ \ \/ / __|
 *     | |  __/>  <| |_
 *    _|_|\___/_/\_\\__|              _
 *  / ____|                         | |
 * | |  __  ___ _ __   ___ _ __ __ _| |_ ___  _ __
 * | | |_ |/ _ \ '_ \ / _ \ '__/ _` | __/ _ \| '__|
 * | |__| |  __/ | | |  __/ | | (_| | || (_) | |
 * \_____|\___|_| |_|\___|_|  \__,_|\__\___/|_|  v0.3
 * <einKnie@gmx.at>
 */

#include "text_generator.h"
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

TextGenerator::TextGenerator(const char* text) : TextGenerator(text, TextGenerator::EGenRandom) { }
TextGenerator::TextGenerator(const char* text, genType_e type) {
  // seed random generator
  srand(time(0));
  init(text, type);
}

TextGenerator::~TextGenerator() {}

void TextGenerator::init(const char *text, genType_e type) {
  memset(m_tmp, '\0', sizeof(m_tmp));
  memset(m_text, '\0', sizeof(m_text));
  m_iterations = 0;
  m_found = 0;
  m_genType = type;

  // store new text
  strncpy(m_text, text, sizeof(m_text));
  m_text[sizeof(m_text) - 1] = '\0';
}

void TextGenerator::seedStart(const char *start) {
  strncpy(m_tmp, start, sizeof(m_tmp));
  m_tmp[sizeof(m_tmp) - 1] = '\0';
}

// generate random ascii symbols; skip over first 30 as they are non-printable
// 128 ascii characters total, 128 - 31 = 97
char *TextGenerator::generateRandom(char *var, size_t len) {
  for (uint8_t i = 0; i < len; i++) {
    var[i] = (rand() % 97) + 31;
  }
  return var;
}

int TextGenerator::delay(uint64_t msec) {
  struct timespec tm = {0};
  tm.tv_sec = 0;
  tm.tv_nsec = (uint64_t)msec * 1000000;
  if (nanosleep(&tm, NULL) == 0) {
    return 0;
  } else {
    return 1;
  }
}

int TextGenerator::generate(void) {

  if (m_genType == EGenStrfry) {
    strncpy(m_tmp, m_text, sizeof(m_tmp));
    strfry(m_tmp);
  } else if (m_genType == EGenRandom) {
    generateRandom(m_tmp, strlen(m_text));
  }
  quickPrint("\r%s", m_tmp);

  do {

    m_iterations++;

    quickPrint("\r");
    if (m_genType == EGenRandom) {
      for (uint8_t i = 0; i < strlen(m_tmp); i++) {
        if (m_tmp[i] == m_text[i]) {
          quickPrint("\033[35m%c\033[0m", m_tmp[i]);
          continue;
        } else {
          m_tmp[i] = (rand() % 97) + 31;
          quickPrint("%c", m_tmp[i]);
        }
      }
    }

    delay(50);

    if (strncmp(m_tmp, m_text, strlen(m_tmp)) == 0) {
      m_found = 1;
    } else if (m_genType == EGenStrfry) {
      for (uint8_t i = 0; i < strlen(m_tmp); i++) {
        if (m_tmp[i] == m_text[i]) {
          quickPrint("\033[35m%c\033[0m", m_tmp[i]);
        } else {
          quickPrint("%c", m_tmp[i]);
        }
      }
      strfry(m_tmp);
    }

  } while (!m_found);

  quickPrint("\r\033[35m%s\n\033[0m", m_tmp);
  delay(700);

  return m_iterations;
}

void TextGenerator::quickPrint(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  (void)vfprintf(stdout, fmt, args);
  va_end(args);
  (void)fflush(stdout);
}
