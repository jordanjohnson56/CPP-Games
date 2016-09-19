# CPP-Games
A collection of games made in C++

### Usage
Each file can be compiled on its own using g++. Once the file is compiled, run the .exe and the instructions will be on screen.

### Guess Game (guessgame.cpp)
This has been a favorite of mine for getting started in a programming language. The first time I made a number guessing game was using Lua on a scripting app that I had found for my iPod Touch when I was 13. Since then, it's become a tradtion for me to recreate this simple guessing game in each language that I learn.

The object of the game is simple. The computer picks an integer between 1 and 100, inclusively. You then get 7 tries to guess the chosen integer. Each time you make a guess, the computer will tell you if the number is too high, too low, or correct. If you can guess the number within 7 tries, you win. If you run out of guesses you lose.

The reason why this game is so convenient as a starter for a programming language is that it doesn't require much in the way of programming techniques. You tell the computer to pick a random number, then run through a game loop, using conditionals to determine if the player guesses the number, guesses too high or too low, or runs out of guesses. Once you've got that completed, the game can then be expanded upon with things such as letting the user choose the range of integers that the computer picks from. The possibilites are endless.

### Tic Tac Toe (tictactoe.cpp)
Nearly everyone has heard of Tic Tac Toe. It's a simple game which only requires something to write with and a surface to write on. It's not quite as simple to present on a computer screen, but using some clever string tricks, I managed to recreate Tic Tac Toe using C++.

This was one of the first ideas that I programmed while learning C++. It allowed me to come up with a method to use the command line interface to present graphical elements made up of text, and reminded me of Rogue: a classic hardcore dungeon crawler which used ASCII characters to display the world and its objects. Using two for loops and a 2 dimensional array, I came up with a way to draw a Tic Tac Toe board and fill in the spaces with the current game objects. For a blank space, I show a number representing the tile's number, which is used to select which tile you want to place your letter in. For the tiles that have been filled, I presented a graphical representation of X or O, depending on what letters had been placed where. 

The rest of the game was as simple as accepting user input, placing letters where they belonged and ending the game when either player had three in a row or the board was filled.

### Tic Tac Toe Plus (tictactoeplus.cpp)
The last game on this list also happens to be the most complex. It's an advanced version of Tic Tac Toe, appropriately named Tic Tac Toe Plus. It presents a 9x9 grid, or rather a 3x3 grid of 3x3 grids. The way this game works is that the first player selects one of the smaller 3x3 grids to play his or her piece. The position on the small board which the first player picks is the same as the position of the 3x3 grid on the big board which the second player must place his or her piece on.

For example:
* Player 1 chooses the upper right grid. He then places his piece in the center of the upper right 3x3.
* Player 2 must now place a piece on the center 3x3 grid. He places his piece in the middle right position.
* Player 1 must now place a piece on the middle right 3x3 grid. He places his piece in the upper right.
* Player 2 must now place a piece on the upper right 3x3 grid. Player 1 has already placed a piece in the center, so he chooses to place his piece in the lower right.

Whenever a player wins a smaller 3x3 grid, he or she then gets to place their letter on the big 3x3 grid, replacing the smaller 3x3 grid. Play continues until one player wins 3 of the smaller grids such that his or her letter forms three in a row on the big board. If a player chooses a tile in a small grid such that the tile in the big grid has already been won, the next player gets to choose where he or she would like to play a tile, similar to how the first player gets to choose where he or she wants to place the first tile. If a small grid ends in a draw, it is crossed out and treated as a tile that has already been won.

To recreate this in C++, I reused the basic 3x3 grid code from my original Tic Tac Toe game. I then expanded it to allow for two instances of the grid. One instance controls the current state of the big board, the other instance contains the state of each of the smaller boards. After filling in the current game pieces into the two-dimensional array which has been expanded to 9x9, I draw the board using a similar loop as in the basic Tic Tac Toe program.

In this program, I decided to separate most of the game logic into separate functions. This made it much easier to track what was happening and where it was happening at. The only thing that wasn't in its own function was the main game loop which included gathering input before running the appropriate functions to verify the input and then process the input.
