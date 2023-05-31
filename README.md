# 42_so_long

## Description
My game was made in C with the graphical library <a href="https://harm-smits.github.io/42docs/libs/minilibx">MiniLibX</a>.

The goal of the game is to collect all items and go through the exit.

## Error Gestion
• Correct number of arguments <br>
• Empty map <br>
• .ber file extension <br>
• Correct elements in map file  <br>
• Rectangular map <br>
• Walls all around <br>
• Valid itinerary to pick up items <br>

## Input maps:

It can take different maps as input to generate the window, provided it passes all requirements. 
I provided valid and invalid maps in the maps folder. 
You can make your own maps provided they are rectangular, use the .ber extension, are fully enclosed by walls, 
include only one P, contains at least one C and E character. 
0 = empty space, E = exit, P = player starting location, 1 = wall, C = collectible 

## How To Play This Game
To play this game, copy the URL below into iTerm/Terminal:

• git clone https://github.com/calamitymandy/42_so_long <br>
• cd 42_so_long <br>
• make <br>
• ./so_long maps/mapBasic.ber (choose the map you want)
