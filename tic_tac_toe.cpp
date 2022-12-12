#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Token {
    char avatar;
    int player;

    public:
    Token(char x, int i) {
        avatar = x;
        player = i;
    }
    char getAvatar() {
        return avatar;
    }
    int getPlayer() {
        return player;
    }
};

class Board {
     /*
    -1->unplayed 
    0->won
    1->player 1 turn 
    2->player 2 turn
    */
    int state;
    int winner;
    char board[3][3];
    int validMoves;

    void handleWin(Token tkn) {
        winner = tkn.getPlayer();
        state = 0;
        cout<<"\nGame Won by Player "<<winner;
    }

    void handleDraw() {
        state = 0;
        cout<<"\nGame Drawn";
    }

    void computeState(int x, int y, Token tkn) {
        char c = tkn.getAvatar();
        bool hWin = true, vWin = true, ldWin = true, rdWin = true;
        for(int i=0; i<3; i++) {
          if(board[i][y] != c)  vWin = false;
          if(board[x][i] != c) hWin = false;
          if(x == y) {
            if(board[i][i] != c)    
                rdWin = false;
          } else rdWin = false;
          if(x+y == 2) {
            if(board[i][2-i] != c)
                ldWin = false;
          } else ldWin = false;
        }
        if(vWin || hWin || rdWin || ldWin) 
            handleWin(tkn); 
        else if(validMoves == 9) handleDraw();
        else    state = (tkn.getPlayer()%2) + 1;
    }

    void clearBoard() {
        state = -1;
        winner = 0;
        validMoves = 0;
        memset(board, '_', sizeof(board));
    }

    public:
    Board() {
        clearBoard();
    }

    int getState() {
        return state;
    }

    void startGame() {
        state = 1;
    }

    void resetGame() {
        clearBoard();
        startGame();
    }

    void placeToken(Token tkn, int x, int y) {
        if(state == 0) cout<<"\nGame over";
        if(x<0 || y < 0 || x > 2 || y > 2 || board[x][y] != '_' || tkn.getPlayer() != state) {
            cout<<"\nInvalid Move!";
            return;
        }
        validMoves++;
        board[x][y] = tkn.getAvatar();
        computeState(x, y, tkn);
    }

    void displayBoard() {
        cout<<"\n\nBOARD:\n";
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    Board b = Board();
    Token P1 = Token('X', 1);
    Token P2 = Token('O', 2);

    b.displayBoard();
    b.startGame();

    while(b.getState() != 0) {
        cout<<"Player "<<b.getState()<<":";
    
        int x, y;
        cin>>x>>y;
        if(b.getState() == 2) b.placeToken(P2, x, y);
        else b.placeToken(P1, x, y);

        b.displayBoard();
    }

    return 0;
}