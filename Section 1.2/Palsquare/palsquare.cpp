/*
ID: xtephan1
PROG: palsquare
LANG: C++11
http://train.usaco.org/usacoprob2?a=WP4N7raLcWb&S=palsquare
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// CONSTANTS
const string PROG = "palsquare";

struct ResultEntry {
    string number;
    string square;
};

vector<ResultEntry> result;

int base;

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> base;

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    for(ResultEntry thisResult : result) {
        fout << thisResult.number
             << " "
             << thisResult.square
             << endl;
    }



    fout.close();
}

/**
 * Convert a number to a given base
 * @return
 */
string convertNumberToBase(int number, int toBase) {

    char baseDigits[20] = {
            '0', '1', '2', '3', '4',
            '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E',
            'F', 'G', 'H', 'I', 'J'
    };

    string result = "";

    while ( number ) {
        result += baseDigits[number%toBase];
        number /= toBase;
    }

    reverse(result.begin(), result.end());

    return result;
}

/**
 * Check is a string is palindrom
 * @param str
 * @return
 */
bool isPalindrom(string str) {

    string reverse_str = str;

    reverse(reverse_str.begin(), reverse_str.end());

    return (reverse_str == str);
}

/**
 * Solve the problem
 */
void solve() {

    for(int i=1; i<=300; i++) {

        string square_in_base = convertNumberToBase(i*i, base);

        if( isPalindrom( square_in_base ) ) {

            ResultEntry thisResult {
                    convertNumberToBase(i, base),
                    square_in_base
            };

            result.push_back(thisResult);
        }

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