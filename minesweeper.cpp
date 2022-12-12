#include<iostream>
using namespace std;

class Square {
    public:
    char avatar;
    bool visible;

    Square() {
        avatar = 'E';
        visible = false;
    }
    
    void makeVisible() {
        this->visible = true;
    }
    char getAvatar() {
        return avatar;
    }
};

class Flag : private Square {
    public:
    Flag() {
        this->avatar = 'F';
    }
};

class Mine : public Square {
    public:
    Mine() {
        this->avatar = 'M';
    }
    void printHello() {
        cout<<"hello";
    }
};

class Digit : private Square {
    public:
    Digit(char c) {
        this->avatar = c;
    }
};

class Board {
    int l;
    int b;
    Square grid[100][100];

    void init() {
        for(int i=0; i<l; i++) {
            for(int j=0; j<b; j++) {
                grid[i][j] = Mine();
            }
        }
    }
    
    public:
    
    Board(int length, int breadth) {
        l = length;
        b = breadth;
    }
    
    void placeMine(int i, int j) {
        grid[i][j] = Mine();
    }
    void displayGrid() {
        for(int i=0; i<l; i++) {
            for(int j=0; j<b; j++) {
                char c = grid[i][j].visible ? grid[i][j].getAvatar():'B';
                cout<<c<<" ";
            }
            cout<<"\n";
        }
    }
};

int main() {
    Board b = Board(8, 10);
    b.displayGrid();
}