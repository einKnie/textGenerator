#include "text_generator.h"
#include "helper.h"
#include <unistd.h>

#define SEARCH_WORD "Hello, world!"
#define MAX_LEN 100

void print_help();

int main(int argc, char *argv[]) {

  char text[MAX_LEN] = {'\0'};
  bool got_input = false;

  // get command line arguments
  char opt;
  while ((opt = getopt(argc, argv, "s:v:h")) != -1) {
    switch (opt) {
      case 's': (void)strcpy(text, optarg); got_input = true; break;
      case 'h': print_help(); return 0;
      default:  print_help(); return 1;
    }
  }

  if (!got_input) strncpy(text, SEARCH_WORD, sizeof(text));

  // start textGenerator && test utils functions
  TextGenerator *textGen = new TextGenerator((const char*)&text);
  textGen->generate();

  textGen->init(to_upper(text, strlen(text)));
  textGen->generate();

  // printf("Now trying strfry generation\n");
  // textGen->init(text, TextGenerator::EGenStrfry);
  // textGen->generate();


  delete textGen;

  return 0;
}


void print_help() {
  printf("Text Generator v0.0.2\n");
  printf("\t-s \"string\"\t... provide a string to generate\n");
  printf("\t-v [0...4]\t... set loglevel\n");
  printf("\t-h \t\t... print this help\n\n");
}
