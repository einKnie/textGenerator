#include "text_generator.h"
#include "helper.h"
#include <unistd.h>

#define DEFAULT_TEXT "Hello, world!"

void print_help();

int main(int argc, char *argv[]) {

  char text[MAX_TEXT_LEN] = {'\0'};
  bool got_input = false;
  TextGenerator::genType_e type = TextGenerator::EGenRandom;

  // get command line arguments
  char opt;
  while ((opt = getopt(argc, argv, "s:hx")) != -1) {
    switch (opt) {
      case 's':
        (void)strncpy(text, optarg, sizeof(text));
        text[sizeof(text) - 1] = '\0';
        got_input = true;
        break;
      case 'x':
        type = TextGenerator::EGenStrfry;
        break;
      case 'h':
        print_help();
        return 0;
      default:
        print_help();
        return 1;
    }
  }

  if (!got_input) strncpy(text, DEFAULT_TEXT, sizeof(text));

  // start textGenerator && test utils functions
  TextGenerator *textGen = new TextGenerator((const char*)&text, type);
  textGen->generate();

  delete textGen;
  return 0;
}


void print_help() {
  printf("Text Generator v0.0.2\n");
  printf("Visual generation of a given text\n");
  printf(" -s str ... provide a string to generate [default: Hello, world!]\n");
  printf(" -x     ... activate strfry generation [experimental]\n");
  printf(" -h     ... show this help\n");
}
