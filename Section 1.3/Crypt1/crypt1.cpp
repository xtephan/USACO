/*
ID: xtephan1
PROG: crypt1
LANG: C++11
http://train.usaco.org/usacoprob2?a=4epkhbCvb9v&S=crypt1
 */
#include <iostream>
#include <fstream>

using namespace std;

#define MAX_DIGITS 10

// CONSTANTS
const string PROG = "crypt1";

const int prime_length = 5;
const int partial_limit = 999;

int digit_count, solution_count;
int digits[MAX_DIGITS];
bool allowed_digits[MAX_DIGITS];


/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> digit_count;

    for(int i=0; i<digit_count; i++) {
        fin >> digits[i];
        allowed_digits[ digits[i] ] = true;
    }

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << solution_count
         << endl;

    fout.close();
}

/**
 * Check if a numbe has allowed digits
 * @param number
 * @return
 */
bool hasAllowedDigits(int number) {

    bool result = true;

    while( number && result ) {

        int thisDigit = number % 10;

        result = result && allowed_digits[thisDigit];

        number /= 10;
    }

    return result;
}

/**
 * Check if a digit configuration can be prime cryptarithm
 * @param digit_configuration
 * @return
 */
bool isPrimeCryptarithm( int digit_configuration[] ) {

    int number, p1, p2, total;

    // Number to be multiplicated
    number = 100*digit_configuration[0] + 10*digit_configuration[1] + digit_configuration[2];

    // partial results
    p1 = number * digit_configuration[3];
    p2 = number * digit_configuration[4];

    // total
    total = p1 + p2*10;

    if( p1 > partial_limit || !hasAllowedDigits(p1) ) {
        return false;
    }

    if( p2 > partial_limit || !hasAllowedDigits(p2) ) {
        return false;
    }

    if( total > 9999 || !hasAllowedDigits(total) ) {
        return false;
    }

    // All fine if we got here
    return true;
}

/**
 * Generate a new generate cryptarithm
 * @param position
 * @param digit_configuration
 */
void generateCryptarithm( int position, int digit_configuration[] ) {

    if( position == prime_length ) {

        if( isPrimeCryptarithm(digit_configuration) ) {
            solution_count++;
        }

    } else {


        for(int i=0; i<digit_count; i++) {
            digit_configuration[position] = digits[i];
            generateCryptarithm(position+1, digit_configuration);
        }

    }

}

/**
 * Solve the problem
 */
void solve() {

    int initial_digit_configuration[prime_length];

    generateCryptarithm(0,initial_digit_configuration);
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