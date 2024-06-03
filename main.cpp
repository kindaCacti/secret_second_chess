#include <iostream>
#include <vector>
#include "./chess_API/board.h"

int main(){
    Board b;
    b.setPieces();
    std::cout << b.toString() << std::endl;

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            std::cout<<pieceChar(b.at(i, j))<<" at "<<i<<"x"<<j<<" :\n";
            std::vector<Move> moves = b.getMoves(i, j);
            for(int k = 0; k<moves.size(); k++){
                std::cout<<moves[k].toString();
            }
        }
    }
    return 0;
}