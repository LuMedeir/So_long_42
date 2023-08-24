# So_long_42 🎮

<p align="center">
<img src="./img/so_long.png">
</p>

<p align="center">
</p>

</br>

## Description  
 
This project is a very small 2D game. It is built to make you work with
textures, sprites. And some very basic gameplay elements.

</br>

## How play the game

To play this game you can use any map of your choice as long follow the following rues:

* The extension need be `.ber`
* Its must be rectangular, surrounded by wall `1`
* Must have only one exit, only one player and at least one collectible
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player position			 |
|     *D*     | Enemy(Devil)  position   |

In folder [maps](./src/maps/) have some examples of maps.

</br>

### Control of play

You can use `AWSD` and `UP`, `DOWN`, `LEFT`, `RIGHT`.  
For restart the game press `ESC` or click on the red cross of window.
If you touch the enemy you loose the game.
To win the game its necessary pick up all collectible and pass for the exit.

</br>

### How execute the game

To start the game you need run the command `make bonus` root directory.
This will compile the executable file `so_long_bonus`, to execute its necessary run `./so_long_bonus ./src/maps/mapbonus2.ber` or any map of your choice.

</br>


## Makefile rules

| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make bonus` | Compile the bonus part of the program.                  |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program mandatory      |
|`make rebonus`| Do `fclean` rule and compile the program bonus          |

</br>

## Sponge Bob 🧽

Here is the game design:

There is a counter in the upper left corner counting steps.

<center>
<img src="./img/Screenshot from 2023-08-24 09-41-36.png">
</center>
