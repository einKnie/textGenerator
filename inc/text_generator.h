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

#ifndef _TEXT_GEN_H_
#define _TEXT_GEN_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_TEXT_LEN 1000

class TextGenerator {
public:

  typedef enum {
    EGenRandom = 0,   ///< generate string through random generation
    EGenStrfry        ///< EXPERIMENTAL: may take forever
  } genType_e;

  /// Default constructor
  TextGenerator(const char *text);

  /// Default constructor
  TextGenerator(const char *text, genType_e type);

  /// Default destructor
  ~TextGenerator();

  /// Initialize TextGenerator with new text
  void init(const char *text, genType_e type = EGenRandom);

  /// Start generation with a specific string
  /// @param[in] start the string to start with
  void seedStart(const char *start);

  /// Generate the desired text in stdout
  /// @return number of iterations needed
  int generate(void);

private:

  char m_text[MAX_TEXT_LEN];  ///< the desired text
  char m_tmp[MAX_TEXT_LEN];   ///< the generated text
  int  m_iterations;          ///< number of iterations needed
  int  m_found;               ///< flag to inidicate if text has been generated
  genType_e m_genType;        ///< generation type
  bool m_color;               ///< flag to indicate colorful output

  /// Generate a random string
  /// @param[in,out] var pointer to fillable char array
  /// @param[in] len length of string
  /// @return pointer to random string, for ease of printing
  char *generateRandom(char *var, size_t len);

  /// Delay program flow for a specified time
  /// @param[in] msec time in milliseconds to wait
  /// @return 0 on success, 1 otherwise
  int  delay(uint64_t msec);

  /// Print a string to stdout && flush directly afterwards
  /// @param[in] fmt formatted string
  void quickPrint(const char *fmt, ...);

  void initCurses(void);
  void exitCurses(void);


};

#endif //_TEXT_GEN_H_
