# Text Generator

This generates a given string by randomly trying different characters.<br>
Once a correct character is found, it is locked in place.<br>
(Minimal) visual representation with colored output.

### Modes

Regular mode uses regular random character generation, one character at a time.<br>
An <b>experimental</b> mode using [strfry](https://linux.die.net/man/3/strfry) on the entire string is also implemented.
But beware: Generation using stryfry will likely take forever.

## Usage

Call with:<br>
-s [string to generate]<br>
-h for help
