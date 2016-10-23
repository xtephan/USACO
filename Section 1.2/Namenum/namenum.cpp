/*
ID: xtephan1
PROG: namenum
LANG: C++11
http://train.usaco.org/usacoprob2?a=WP4N7raLcWb&S=namenum
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// CONSTANTS
const string PROG = "namenum";

string number;
vector<string> name_list;
vector<string> result_list;

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );
    ifstream findict ( "dict.txt" );

    // Read the number
    fin >> number;

    // Read all the possible names
    for(string thisName; findict >> thisName; ) {
        name_list.push_back(thisName);
    }

    fin.close();
    findict.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    if( result_list.size() > 0 ) {

        for(string thisName: result_list) {
            fout << thisName
                 << endl;
        }

    } else {

        fout << "NONE"
             << endl;

    }


    fout.close();

}



/**
 * Solve the problem
 */
void solve() {

    // Loop though all the names
    for(string thisName : name_list) {

        string thisNumber = "";

        // and decompose the name to number
        for(int i=0; i<thisName.length(); i++) {

            char thisDigit;

            switch(thisName[i]) {
                case 'A': case 'B': case 'C':
                    thisDigit = '2';
                    break;
                case 'D': case 'E': case 'F':
                    thisDigit = '3';
                    break;
                case 'G': case 'H': case 'I':
                    thisDigit = '4';
                    break;
                case 'J': case 'K': case 'L':
                    thisDigit = '5';
                    break;
                case 'M': case 'N': case 'O':
                    thisDigit = '6';
                    break;
                case 'P': case 'R': case 'S':
                    thisDigit = '7';
                    break;
                case 'T': case 'U': case 'V':
                    thisDigit = '8';
                    break;
                case 'W': case 'X': case 'Y':
                    thisDigit = '9';
                    break;
                default:
                    thisDigit = '0';
                    break;
            }

            thisNumber += thisDigit;
        }

        if( thisNumber == number ) {
            result_list.push_back(thisName);
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