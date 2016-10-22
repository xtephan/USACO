/*
ID: xtephan1
PROG: ride
LANG: C++11
http://train.usaco.org/usacoprob2?a=8agbQzFpbP9&S=ride
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// CONSTANTS
const string PROG = "ride";

// INPUT DATA
string comet, group;

// OUTPUT
string result = "";

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    getline(fin, comet);
    getline(fin, group);

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << result << endl;

    fout.close();

}

/**
 *
 * @param str
 * @return
 */
int computeMod( string str ) {

    const int MOD = 47;
    const int OFFSET = 64;

    int strlen = (int)str.length();
    int mod = 1;

    for(int i=0; i<strlen; i++) {

        int ascii_value = (int)str[i] - OFFSET;

        mod = (mod * ascii_value) % MOD;

    }

    return mod;
}

/**
 * Main solver
 */
void solve() {

    result = computeMod(comet) == computeMod(group) ? "GO" : "STAY";

}

int main() {

    readInput();

    solve();

    outputResult();

    return 0;
}