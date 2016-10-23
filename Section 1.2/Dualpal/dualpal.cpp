/*
ID: xtephan1
PROG: dualpal
LANG: C++11
http://train.usaco.org/usacoprob2?a=WP4N7raLcWb&S=dualpal
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// CONSTANTS
const string PROG = "dualpal";

int result_count, lower_limit;

vector<int> result;

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> result_count >> lower_limit;

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    for(int thisResult : result) {
        fout << thisResult
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

    int number = lower_limit;

    while(result.size()<result_count) {

        number++;

        int pal_found = 0;

        for(int b=2; b<=10 && pal_found<2; b++) {

            if( isPalindrom( convertNumberToBase(number, b) ) ) {
                pal_found++;
            }

        }

        if( pal_found == 2 ) {
            result.push_back(number);
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