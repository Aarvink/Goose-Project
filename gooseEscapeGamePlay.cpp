#include <iostream>
#include <cmath>
using namespace std;
#include <BearLibTerminal.h>
#include "gooseEscapeUtil.hpp"
#include "gooseEscapeActors.hpp"
#include "gooseEscapeConsole.hpp"
#include "gooseEscapeGamePlay.hpp"

extern Console out;
/*
With graphics, screens are given an x,y coordinate system with the origin
in the upper left corner.  So it means the coordinate axes are:
---------------->   x direction
|
|
|
|
|
V

y direction 
*/
	
/*
    Print the game world
    
    The functions should draw characters to present features of the game
    board, e.g. win location, obstacles, power ups
*/

int printGameBoard(Actor const & win)// print the game board function
{
    win.put_actor();
    
    //terminal_put(10,10,WIN_CHAR);
    
    //terminal_put(10,10,WIN_CHAR);
    
}

/*
    Do something when the goose captures the player
    
    If you want to attack or something else, this is the function you 
    need to change.  For example, maybe the two touch each other and
    then fight.  You could add a health to the Actor class that is
    updated.  Run, use weapons, it's up to you!
*/

bool captured(Actor const & player, Actor const & monster)
{
    return (player.get_x() == monster.get_x() 
         && player.get_y() == monster.get_y());
}

/*
    Move the player to a new location based on the user input.  You may want
    to modify this if there are extra controls you want to add.
    
    All key presses start with "TK_" then the character.  So "TK_A" is the a
    key being pressed.
    
    A look-up table might be useful.
    You could decide to learn about switch statements and use them here.
*/

void movePlayer(int key, Actor & player, int gameWorld[MAX_BOARD_X][MAX_BOARD_Y] /* game board array and any other parameters */)
{
    int yMove = 0, xMove = 0;
    if (key == TK_UP)
        yMove = -1;
    else if (key == TK_DOWN)
        yMove = 1;
    else if (key == TK_LEFT)
        xMove = -1;
    else if (key == TK_RIGHT)
        xMove = 1;
        
    if (player.can_move(xMove, yMove) 
      && gameWorld[xMove][yMove] != SHALL_NOT_PASS)
        player.update_location(xMove, yMove);
}

// Function that allows the goose to chase the player 
void chase(Actor & player, Actor & monster, int gameWorld[MAX_BOARD_X][MAX_BOARD_Y] /* game board array and any other parameters */)
{
    int yMove = 0, xMove = 0;
    
    if(player.get_y() != monster.get_y())
    {
	    if (player.get_y() > monster.get_y())
	        yMove = 1;
	    else if (player.get_y() < monster.get_y())
	        yMove = -1;
	
	}
	else if(player.get_x() != monster.get_x())
	{
		if (player.get_x() > monster.get_x())
	        xMove = 1;
	    else if (player.get_x() < monster.get_x())
	        xMove = -1;
	}

    if (monster.can_move(xMove, yMove) 
      && gameWorld[xMove][yMove] != SHALL_NOT_PASS)
        monster.update_location(xMove, yMove);
}
/*
    What other functions do you need to make the game work?  What can you
    add to the basic functionality to make it more fun to play?
*/
