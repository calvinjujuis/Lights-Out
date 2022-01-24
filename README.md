# Lights-Out

*A C++ command-line Lights Out game* \
<img src="https://github.com/calvinjujuis/Lights-Out/blob/main/lightsOut.png" width="120" height="240">

## Rules for Lights Out
> Switch a cell to toggle it and its immediate neighbours. The objective is to turn all cells off within certain number of moves.

## Commands

Command  | Effect
------------- | -------------
new x | create a x times x board
init x y | initialize the board with (x, y) turned on <br /> (you can provide multiple (x, y)'s). End with -1 -1.
game | set moves left
switch x y | toggle (x, y)
neighbours | print neighbours of each cell

## Sample Gameplay
