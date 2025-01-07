# Maze Game
## Description
This is a project for course Object Oriented Programming 2. A C++ maze escape game with OOP principles, where players navigate the maze, collect items, and avoid the Minotaur.

## How to Play
- Use arrow keys to move up, left, down, and right.
- The goal is to find the exit marked with `I` while avoiding walls (`#`) and minotaur `M`
- Collect items (`P`) to gain special effect
- Pressing `Q` will exit the game
## Rules
### Maze
Maze is dinamically generated with input parameters **n, m, item_numbers**. Robot is displayed as `R`, minotaur as `M`, items as `P`.

### Special effects 
Each item will give robot special effect that lasts 3 moves. Special effects are:
 - Hammer
 - Shield
 - Fog of war
 - Sword

### Minotaur
Minotaur is moving randomly across the board. If he steps on the item, he will **destroy** it. 
If the minotaur is 1 move away from robot, minotaur will **kill the robot**.

## Installation
1. Clone the repository:
   ```bash
    git clone https://github.com/vedranbajic4/maze-game
    ```
2. Navigate to solution file
    ```bash
    cd maze-game/MazeGame
    ```
3. Build the project (MazeGame.sln)

4. Run the MazeGame.exe file
    ```bash
    cd maze-game/MazeGame/x64/Release
    ./MazeGame.exe 20 20 5
    ```

## Arguments of command line
 To play the Maze Game, you need to provide three input parameters via the command line:
 * **Height**: This will be height of maze (*number of rows*) minimal height is **15**
 * **Width**: This will be width of maze (*number of columns*) minimal width is **15**
 * **Number of items**: This is the number of items that will be displayed. Minimal number of items is **3**

## Example Gameplay
![Starting game.](https://i.imgur.com/OpWZok2.png[/img] "Start of game")
![Special effect.](https://i.imgur.com/bEgDZPt.png[/img] "Fog of war effect")
