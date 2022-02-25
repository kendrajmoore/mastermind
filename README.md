# MasterMindGame
Mastermind is a game composed of 8 pieces of different colors.
A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

You must read the player's input from the standard input.

Your program will also receive the following parameters:
-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.


## Environment
This project is compiled using C language 

## Installation
* Clone this repository: `git clone`
* Compile all the source files with the command: `make`
* Run the game without options: `./mastermind`
* To set the four (4) digit code run `./mastermind -c code `
* To set the number of attempts run `./mastermind -t 5`
* You can combine and run `./mastermind -c 2345 -t 5`



## Authors
Me


## License
Me
