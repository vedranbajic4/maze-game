#include "Robot.h"

Robot::Robot() {
    r = c = 0;
}

void Robot::set_position(pii pos) {
    r = pos.first;
    c = pos.second;
}

Robot::Robot(pair<int, int> pos) {
    r = pos.first;
    c = pos.second;
}


int Robot::play(Maze& maze) {
    Sleep(200);

    char prev;
    int dr, dc;
    while (1) {
        dr = dc = 0;
        if (GetAsyncKeyState(VK_UP) & 0x8000)          dr = -1;
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000)   dr = 1;
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000)   dc = -1;
        else  if (GetAsyncKeyState(VK_RIGHT) & 0x8000) dc = 1;
        else if (GetAsyncKeyState(0x51) & 0x8000)
            return 0;

        if (maze[r + dr][c + dc] == '#' || maze[r + dr][c + dc] == 'U') continue;
        if (dr == 0 && dc == 0) continue;

        maze[r][c] = '.';
        prev = maze[r + dr][c + dc];
        maze[r + dr][c + dc] = 'R';

        r += dr;
        c += dc;

        if (prev == 'I') return 2;
        else return 1;
    }
}