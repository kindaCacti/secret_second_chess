#pragma once
#include "pieces.h"


class Board{
    Piece board[64];

public:
    Board() = default;
    Board(Piece* _board){
        for(int i = 0; i<64; i++){
            board[i] = {_board[i].name, _board[i].color};
        }
    }

    void setPieces(){
        int resolve = 0;

        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                board[resolve] = {PIECE_NAMES::NO_PIECE};
                resolve++;
            }
        }

        for(int i = 0; i<8; i++){
            board[8 + i] =  {PIECE_NAMES::PAWN, PIECE_COLOR::BLACK};
            board[48 + i] = {PIECE_NAMES::PAWN, PIECE_COLOR::WHITE};
        }

        board[0] = {PIECE_NAMES::ROOK,      PIECE_COLOR::BLACK};
        board[1] = {PIECE_NAMES::KNIGHT,    PIECE_COLOR::BLACK};
        board[2] = {PIECE_NAMES::BISHOP,    PIECE_COLOR::BLACK};
        board[3] = {PIECE_NAMES::QUEEN,     PIECE_COLOR::BLACK};
        board[4] = {PIECE_NAMES::KING,      PIECE_COLOR::BLACK};
        board[5] = {PIECE_NAMES::BISHOP,    PIECE_COLOR::BLACK};
        board[6] = {PIECE_NAMES::KNIGHT,    PIECE_COLOR::BLACK};
        board[7] = {PIECE_NAMES::ROOK,      PIECE_COLOR::BLACK};

        board[56] = {PIECE_NAMES::ROOK,     PIECE_COLOR::WHITE};
        board[57] = {PIECE_NAMES::KNIGHT,   PIECE_COLOR::WHITE};
        board[58] = {PIECE_NAMES::BISHOP,   PIECE_COLOR::WHITE};
        board[59] = {PIECE_NAMES::QUEEN,    PIECE_COLOR::WHITE};
        board[60] = {PIECE_NAMES::KING,     PIECE_COLOR::WHITE};
        board[61] = {PIECE_NAMES::BISHOP,   PIECE_COLOR::WHITE};
        board[62] = {PIECE_NAMES::KNIGHT,   PIECE_COLOR::WHITE};
        board[63] = {PIECE_NAMES::ROOK,     PIECE_COLOR::WHITE};
    }

    std::string toString(){
        int resolve = 0;
        std::string out = "";

        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                out.push_back(pieceChar(board[resolve]));
                out.push_back(' ');
                resolve++;
            }
            out.pop_back();
            out.push_back('\n');
        }
        out.pop_back();

        return out;
    }

    bool isFreeAt(int x, int y){
        int index = y*8 + x;

        if(x < 0 or x > 7 or y < 0 or y > 7) return false;

        if(board[index].name == PIECE_NAMES::NO_PIECE) return true;
        return false;
    }

    std::vector<Move> makeMultipleMoves(Move mv, int fx, int fy){
        std::vector<Move> out;

        for(int i = 1; i<=8; i++){
            Move nm(mv*i);
            int nx = fx + nm.delta_x;
            int ny = fy + nm.delta_y;

            if(!br.isFreeAt(nx, ny)) break;
            out.push_back(nm);
        }

        return out;
    }

    std::vector<Move> getMoves(int x, int y){
        std::vector<Move> out;
        
        return out;
    }
};