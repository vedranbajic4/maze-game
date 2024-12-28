#include "Robot.h"

Robot::Robot() : r(0), c(0), item(nullptr){
}

void Robot::set_random_item() {
    int i = rand() & 4;
    delete item;
 
    if (i == 0) {
        item = new Fog_of_war(r, c);
    }
    else if (i == 1) {
        item = new Sword(r, c);
    }
    else if (i == 2) {
        item = new Hammer(r, c);
    }
    else {
        item = new Shield(r, c);
    }
}

void Robot::set_position(pii pos) {
    r = pos.first;
    c = pos.second;
}

bool condition(Maze& maze, const int r, const int c) {
    return (maze[r][c] == '#' || 
            maze[r][c] == 'U' || 
            maze[r][c] == 'M');
}

char previous = '.';
void Robot::play(Maze& maze) {
    Sleep(200);

    int dr = 0;
    int dc = 0;

    while (1) {
        if (GetAsyncKeyState(VK_UP) & 0x8000)          dr = -1;
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000)   dr = 1;
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000)   dc = -1;
        else  if (GetAsyncKeyState(VK_RIGHT) & 0x8000) dc = 1;
        else if (GetAsyncKeyState(0x51) & 0x8000) {
            cout << "\n\nEXIT\n";
            exit(0);
        }

        if (dr == 0 && dc == 0) {
            continue;
        }

        if (item != nullptr) {
            if ( (item->get_type() == "Hammer" || item->get_type() == "Sword") && item->duration > 0) {
                if (item->effect(maze, r + dr, c + dc)) {
                    continue;
                }
            }
            else if (condition(maze, r + dr, c + dc)) {
                continue;
            }
        }
        else if (condition(maze, r + dr, c + dc)) {
            continue;
        }
        
        if (maze[r + dr][c + dc] == 'P') {
            set_random_item();
        }
        
        maze[r][c] = previous;

        previous = maze[r + dr][c + dc];

        if (previous == 'P' || previous == 'M') {
            previous = '.';
        }
        
        maze[r + dr][c + dc] = 'R';

        r += dr;
        c += dc;

        break;
    }
}