/*
ID: xtephan1
PROG: transform
LANG: C++11
http://train.usaco.org/usacoprob2?a=peKYoi4lRAf&S=transform
*/
#include <iostream>
#include <fstream>

#define MAX_SIZE 11

using namespace std;

// CONSTANTS
const string PROG = "transform";

int square_size;
int transformation;
char input_square[MAX_SIZE][MAX_SIZE], target_square[MAX_SIZE][MAX_SIZE];

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> square_size;

    // Read input square
    for(int i=0; i<square_size; i++) {
        fin >> input_square[i];
    }

    // Read target square
    for(int i=0; i<square_size; i++) {
        fin >> target_square[i];
    }

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << transformation
         << endl;

    fout.close();

}

bool squaresAreIdentical( char a[MAX_SIZE][MAX_SIZE], char b[MAX_SIZE][MAX_SIZE], int size ) {

    bool identical = true;

    for(int i=0; i<square_size && identical; i++) {
        for(int j=0; j<square_size && identical; j++) {
            identical = (a[i][j] == b[i][j]);
        }
    }

    return identical;
}

/**
 * Rotates a square 90deg clockwise
 * @param square
 * @param size
 */
void rotateSquare( char square[MAX_SIZE][MAX_SIZE], int size ) {

    char copy[MAX_SIZE][MAX_SIZE];

    // Make a copy of the original square
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            copy[i][j] = square[i][j];
        }
    }

    // Rotate
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            square[ j ][ size - i -1 ] = copy[i][j];
        }
    }

}

/**
 * Reflect a square horizontally
 * @param square
 * @param size
 */
void reflectSquare( char square[MAX_SIZE][MAX_SIZE], int size ) {

    // Reflect
    for(int i=0; i<size; i++) {
        for(int j=0; j<size/2; j++) {

            char tmp = square[i][j];

            square[i][j] = square[ i ][ size - j -1 ];

            square[ i ][ size - j -1 ] = tmp;
        }
    }

}

/**
 * Solve the problem
 */
void solve() {

    // No transformation
    transformation = 0;

    // Square are equal from the beginning
    if( squaresAreIdentical(target_square, input_square, square_size) ) {
        transformation = 6;
    }

    // Rotate the board 3 times 90 deg and check
    // for equality
    for(int i=0; i<3; i++) {

        rotateSquare(input_square, square_size);

        if( squaresAreIdentical(target_square, input_square, square_size) ) {
            transformation = 1+i;
            return;
        }

    }

    // original and reflected
    rotateSquare(input_square, square_size);
    reflectSquare(input_square, square_size);

    if( squaresAreIdentical(target_square, input_square, square_size) ) {
        transformation = 4;
        return;
    }

    for(int i=0; i<3; i++) {

        rotateSquare(input_square, square_size);

        if( squaresAreIdentical(target_square, input_square, square_size) ) {
            transformation = 5;
            return;
        }

    }

    // Are they identical
    if(transformation==6) {
        return;
    }

    transformation = 7;
}

int main() {

    readInput();

    solve();

    outputResult();

    return 0;
}