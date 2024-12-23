#include "Player.h"


Player::Player() {
	r = c = 0;
    cout << "Deafualt kosntruktor\n";
}

void Player::set_position(pii pos) {
    r = pos.first;
    c = pos.second;
}

Player::Player(pair<int, int> pos) {
    cout << "Pravi kosntruktor\n";
	r = pos.first;
	c = pos.second;
}

int Player::handle_input(Maze& maze) {
    Sleep(200);
    cout << "Player moves\n";

    char prev;
    while (1) {
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (maze[r - 1][c] != '#') {
                maze[r][c] = '.';
                prev = maze[r - 1][c];
                maze[r - 1][c] = 'R';

                cout << maze[r][c] << " " << maze[r - 1][c] << endl;

                r--;
                if (prev == 'I') return 2;
                else return 1;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if (maze[r + 1][c] != '#') {
                maze[r][c] = '.';
                prev = maze[r + 1][c];
                maze[r + 1][c] = 'R';

                r++;
                if (prev == 'I') return 2;
                else return 1;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            if (maze[r][c - 1] != '#') {
                maze[r][c] = '.';
                prev = maze[r][c - 1];
                maze[r][c - 1] = 'R';
                c--;
                if (prev == 'I') return 2;
                else return 1;
            }
        }
        else  if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            if (maze[r][c + 1] != '#') {
                maze[r][c] = '.';
                prev = maze[r][c + 1];
                maze[r][c + 1] = 'R';
                c++;
                if (prev == 'I') return 2;
                else return 1;
            }
        }
        else if (GetAsyncKeyState(0x51) & 0x8000) {
            return 0;
        }
    }
}

bool Player::play(Maze& maze) {
    std::cout << maze[r][c] << "\n";
    bool ret = handle_input(maze);
    if (ret == 2) {
        
    }
    
    return ret;
}