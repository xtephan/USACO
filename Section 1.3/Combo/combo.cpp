/*
ID: xtephan1
PROG: combo
LANG: C++11
http://train.usaco.org/usacoprob2?a=4epkhbCvb9v&S=crypt1
 */
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cstdlib>

using namespace std;

// CONSTANTS
const string PROG = "combo";
const int COMB_SIZE = 3;
const int TOLERANCE = 2;

int max_dial;
int master_comb[COMB_SIZE], farmer_comb[COMB_SIZE];
int correct_comb_count;

unordered_set<string> used_combination;

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> max_dial;

    for(int i=0; i<COMB_SIZE; i++) {
        fin >> farmer_comb[i];
    }

    for(int i=0; i<COMB_SIZE; i++) {
        fin >> master_comb[i];
    }

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << correct_comb_count
         << endl;

    fout.close();
}

/**
 *
 * @param a
 * @param b
 * @return
 */
int cycle_sum( int a, int b, int max ) {

    int result = a;
    int limit = abs(b);
    int step = b < 0 ? -1 : +1;

    for(int i=0; i<limit; i++) {

        // Make a step
        result += step;

        // from END to START
        if( result > max ) {
            result = result % max;
        }

        // from START to END
        if( result == 0 ) {
            result = max;
        }

    }

    return result;
}

/**
 * Checks if a combination is unique
 * @param combination
 * @return
 */
bool isUniqueCombination(int combination[]) {

    string key = "";

    for(int i=0; i<3; i++) {
        key += to_string(combination[i]) + "-";
    }

    auto search = used_combination.find(key);

    if( search != used_combination.end() ) {
        return false;
    } else {
        used_combination.insert(key);
        return true;
    }

}

/**
 * Count the unique combinations based on the correct one
 * @param combination
 */
void countUniqueCorrectCombinations(int combination[]) {

    int current_combination[COMB_SIZE];

    for(int i=0-TOLERANCE; i<=TOLERANCE; i++) {
        current_combination[0] = cycle_sum( combination[0], i, max_dial );

        for(int j=0-TOLERANCE; j<=TOLERANCE; j++) {
            current_combination[1] = cycle_sum( combination[1], j, max_dial );

            for(int k=0-TOLERANCE; k<=TOLERANCE; k++) {
                current_combination[2] = cycle_sum( combination[2], k, max_dial );


                if( isUniqueCombination(current_combination) ) {
                    correct_comb_count++;
                }

            }
        }
    }

}

/**
 * Solve the problem
 */
void solve() {

    countUniqueCorrectCombinations(farmer_comb);

    countUniqueCorrectCombinations(master_comb);

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