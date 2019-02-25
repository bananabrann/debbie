# C'ing the Light
In this readme, I will define what the MVP and Gold Medal goals are, as well as adding the things that I have learned about C in the order that was learned. I plan on building a simple robot that will "listen" to the surronding area, and display its decibel level.

# The Goal
The mission is build a simple robot that measures the surronding sounds and displays a decibel level. The robot will...
* ... be named Decibel Debbie.
* ... be completely self-sustaining --not hooked to a computer.
* ... have the motherboard be an Arduiono Uno.
* ... not have any moving motors or peripherals.
* ... use an external microphone to detect sound.
* ... display the decibels on a 7-segment LED display.

### MVP
(Most Viable Product)
At the minimum, Debbie should ...
- [ ] ... successfully read the decibel level.
- [ ] ... successfully display the decibel level.

### Gold Medal
After reaching MVP, it would be nice if Debbie ...
- [ ] ... had an additional display where it displays the text of sounds of a similar decibel level that is currently being picked up. E.g., displayed "vacuum clearner" when the decibel level is between 75 to 85 dB.
- [ ] ... displayed a brief greeting when first booting.
- [ ] ... had an external shell protecting her inner bits.

___ 

# What I Learned About C
For General Assembly teach yourself day, my focus is to understand the basic syntax of C for project 4. The "built" product for today is the test document on example.c.

### gcc
C cannot just be simplely run like JavaScript. It needs special programs to compile the code, and then execute the file.

### Void
Like integers, strings, booleans, etc., void is a data type that is defined as being non-existent. In JavaScript, leaving a parameter empty does not cause any errors becasue JavaScript assumes empty parameters are void automatic. This process in not automatic in C.
* `int myFunction(void)` The function does not take any parameters.
* `void myFunction(int)` The function does not return anything.

### Compiling
C does not automatically compile code before it executes. I've found that executing the file prior to compiling or a fail in the compile leads to the file being removed from the disl.
To compile, you need to download and use gcc.

`gcc yourcode.c -o output` is the command line syntax for compiling. `gcc` is the npm package, `yourcode.c` is the file that you have typed, `-o` says it's an object (unsure why you need this) and the `output` is the file name you're assigning to send your compiled code. After running that, you can execute the file simply by running that file.
So with the code above, you would just type `output` in the terminal.