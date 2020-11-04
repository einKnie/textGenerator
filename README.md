# Text Generator

This generates a given string by randomly trying different characters.  
Once a correct character is found, it is locked in place.  
(Minimal) visual representation with colored output.  

![](textgen.apng)

### Modes

Regular mode uses random character generation, one character at a time.  
An __experimental__ mode using [strfry](https://linux.die.net/man/3/strfry) on the entire string is also implemented.  
But beware: Generation using stryfry will likely take forever.

The above example video shows the regular output. Be aware that on strings longer than one line on the output terminal, the visuals will glitch. But interesting to look at still.

Input string length is currently capped at 200 characters. A dynamic mode is planned.

## Usage

Call with:  
-s ... string to generate [default: Hello, world!]  
-x ... activate strfry generation  
-h ... help

