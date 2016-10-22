/*
ID: xtephan1
PROG: friday
LANG: C++11
http://train.usaco.org/usacoprob2?a=uHffjHMdSy6&S=friday
*/
#include <iostream>
#include <fstream>

using namespace std;

// CONSTANTS
const string PROG = "friday";

// globals
int years;

int days[7] = {0,0,0,0,0,0,0};
int month_size[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> years;

    fin.close();


}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    for(int i=6; i<13; i++) {
        fout << days[i%7];
        if( i == 12 ) {
            fout <<endl;
        } else {
            fout <<" ";
        }
    }

    fout.close();

}

/**
 * Solve the problem
 */
void solve() {

    // Jan 1st 1900 is on a monday
    int month_start_day = 1;

    for(int i=0; i<years; i++) {

        int thisYear = 1900+i;

        bool is_leap_year = ((thisYear%4==0) && ((thisYear%100!=0) || (thisYear%400==0)));

        for(int thisMonth = 0; thisMonth<12; thisMonth++) {

            // Index of the day 13th will be in
            int d13 = (month_start_day + 13 - 1) % 7;
            days[d13]++;

            int days_in_month = month_size[thisMonth];

            // take into account leap year
            if(is_leap_year && thisMonth==1) {
                days_in_month = 29;
            }

            // Index of the day next month will start on
            month_start_day = (month_start_day+days_in_month)%7;

        }

    }
}

int main() {

    readInput();

    solve();

    outputResult();


    return 0;
}