/*
ID: xtephan1
PROG: barn1
LANG: C++11
http://train.usaco.org/usacoprob2?a=WP4N7raLcWb&S=barn1
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_STALLS 201

// CONSTANTS
const string PROG = "barn1";

int available_boards, total_stalls, total_cows, blocked_stalls;

bool occupied_stalls[MAX_STALLS];

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> available_boards >> total_stalls >> total_cows;

    for(int i=0; i<total_cows; i++) {

        int stall_index;

        fin >> stall_index;

        occupied_stalls[stall_index] = true;
    }

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << blocked_stalls
         << endl;

    fout.close();
}

/**
 * Callback function for sorting farmers
 * @param x
 * @param y
 * @return
 */
bool sortingCallback(int x, int y) {
    return x > y;
}

/**
 * Solve the problem
 */
void solve() {

    // Find out the index of the first and last stall occupied
    int first_stall_index, last_stall_index;
    int consecutive_unoccupied_stalls[MAX_STALLS];

    for(int i=1; i<total_stalls; i++) {
        if( occupied_stalls[i] ) {
            first_stall_index = i;
            break;
        }
    }

    for(int i=total_stalls; i>0; i--) {
        if( occupied_stalls[i] ) {
            last_stall_index = i;
            break;
        }
    }

    // By default
    blocked_stalls = last_stall_index - first_stall_index +1;

    // FIND out consecutive unused stalls
    int current_unused = 0;
    int consecutive_unoccupied_stalls_size = 0;

    for(int i=first_stall_index+1; i<=last_stall_index; i++) {

        if( occupied_stalls[i] ) {

            if( current_unused > 0 ) {
                consecutive_unoccupied_stalls[consecutive_unoccupied_stalls_size] = current_unused;
                consecutive_unoccupied_stalls_size++;
            }

            current_unused = 0;

        } else {
            current_unused++;
        }

    }

    // SORT it by size
    sort(
            consecutive_unoccupied_stalls,
         consecutive_unoccupied_stalls + consecutive_unoccupied_stalls_size,
            sortingCallback
    );

    // One board used for the whole barn
    available_boards--;

    for(int i=0; i<consecutive_unoccupied_stalls_size && available_boards > 0; i++) {
        blocked_stalls -= consecutive_unoccupied_stalls[i];
        available_boards--;
    }

}

/**
 * MAIN METHOD
 * @return
 */
int main() {

    readInput();

    solve();

    outputResult();

    return 0;
}