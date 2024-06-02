#include <iostream>
#include "./chess_API/board.h"

int main(){
    Board b;
    b.setPieces();
    std::cout << b.toString() << std::endl;
    return 0;
}