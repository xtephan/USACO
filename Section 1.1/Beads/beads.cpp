/*
ID: xtephan1
PROG: beads
LANG: C++11
http://train.usaco.org/usacoprob2?a=uHffjHMdSy6&S=beads
 */
#include <iostream>
#include <fstream>

using namespace std;

// CONSTANTS
const string PROG = "beads";

// globals
int necklace_length, max_beads = -1;
string necklace;

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> necklace_length;

    fin >> necklace;

    fin.close();


}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << max_beads << endl;

    fout.close();

}

/**
 *
 * @param array
 * @return
 */
void shift_array(string &array) {

    int length = (int)array.length();

    char first_item = array[length-1];

    for(int j=length-1; j>0; j--) {
        array[j] = array[j-1];
    }

    array[0] = first_item;
}

/**
 * Solve the problem
 */
void solve() {

    for(int i=0; i<necklace_length; i++) {

        bool continue_search;
        int left_size = 0;
        int right_size = 0;
        char color_search;

        // First the biggest string in the beginning
        continue_search = true;
        color_search = necklace[0];
        for(left_size=1; left_size<necklace_length && continue_search; left_size++) {

            // Assume we should stop
            continue_search = false;

            if(
                color_search == necklace[left_size] ||
                necklace[left_size] == 'w' ||
                color_search == 'w'
            ) {
                continue_search = true;
            }

            // In case we start with a white one
            if( color_search == 'w' && necklace[left_size] != 'w') {
                color_search = necklace[left_size];
            }

        }

        // We stop on first one wrong, adjust
        left_size--;

        // RIGHT SIDE
        continue_search = true;
        color_search = necklace[necklace_length-1];
        for(right_size=1; (right_size<necklace_length) && (necklace_length-right_size >= left_size) && continue_search; right_size++) {

            // Assume we should stop
            continue_search = false;

            if(
                    color_search == necklace[necklace_length - right_size - 1] ||
                    necklace[necklace_length - right_size - 1] == 'w' ||
                    color_search == 'w'
            ) {
                continue_search = true;
            }

            // In case we start with a white one
            if( color_search == 'w' && necklace[necklace_length - right_size - 1] != 'w') {
                color_search = necklace[necklace_length - right_size - 1];
            }
        }

        right_size--;

        if( left_size + right_size > max_beads ) {
            max_beads = left_size+right_size;
        }

        int bb = 0;

        // Shift the necklace
        shift_array(necklace);
    }

}

int main() {

    readInput();

    solve();

    outputResult();

    return 0;
}