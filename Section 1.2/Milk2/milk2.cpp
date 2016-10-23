/*
ID: xtephan1
PROG: milk2
LANG: C++11
http://train.usaco.org/usacoprob2?a=peKYoi4lRAf&S=milk2
*/
#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_FARMERS 5001

using namespace std;

// CONSTANTS
const string PROG = "milk2";

struct TimeInterval {
    int start;
    int end;
};

TimeInterval milkingTimes[MAX_FARMERS];
TimeInterval longest_milking_interval, longest_idle_interval;

int farmers_count;

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> farmers_count;

    for(int i=0; i<farmers_count; i++) {

        TimeInterval thisTime;

        fin >> thisTime.start >> thisTime.end;

        milkingTimes[i] = thisTime;
    }

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << (longest_milking_interval.end-longest_milking_interval.start)
         << " "
         << (longest_idle_interval.end-longest_idle_interval.start)
         << endl;

    fout.close();

}

bool sortingCallback(TimeInterval x, TimeInterval y) {
    return x.start < y.start;
}

/**
 * Returns the longest interval between 2
 * @param x
 * @param y
 * @return
 */
TimeInterval longestTimespan(TimeInterval x, TimeInterval y) {
    if( x.end-x.start > y.end - y.start) {
        return x;
    } else {
        return y;
    }
}

/**
 * Sort milking times
 */
void sortMilkingTimes() {

    // Sort the milking times in order
    sort(milkingTimes, milkingTimes + farmers_count, sortingCallback);

}

/**
 * Compute longest milking time and longest idle time
 */
void computeLongestIntervals() {

    TimeInterval current_interval;

    current_interval = milkingTimes[0];

    for(int i=1; i<farmers_count; i++) {

        // Chain broken
        if( milkingTimes[i].start > current_interval.end ) {

            // Got a bigger interval?
            longest_milking_interval = longestTimespan( current_interval, longest_milking_interval );

            // Current Idle interval
            TimeInterval current_idle_interval{
                    current_interval.end,
                    milkingTimes[i].start
            };

            // Check against the longest
            longest_idle_interval = longestTimespan( current_idle_interval, longest_idle_interval );

            // Reset next interval
            current_interval = milkingTimes[i];

        } else {

            // Continue the interval
            if( current_interval.end < milkingTimes[i].end ) {
                current_interval.end = milkingTimes[i].end;
            }

        }

    }

    // One more check
    longest_milking_interval = longestTimespan( current_interval, longest_milking_interval );
}

/**
 * Solve the problem
 */
void solve() {

    sortMilkingTimes();

    computeLongestIntervals();

}

int main() {

    readInput();

    solve();

    outputResult();

    return 0;
}