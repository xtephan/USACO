/*
ID: xtephan1
PROG: milk
LANG: C++11
http://train.usaco.org/usacoprob2?a=WP4N7raLcWb&S=milk
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_FARMERS 5001

// CONSTANTS
const string PROG = "milk";

int required_milk, farmers_count, total_cost;

struct Farmer {
    int price;
    int available;
} farmers[MAX_FARMERS];

/**
 * Read input
 */
void readInput() {

    ifstream fin ( PROG + ".in" );

    fin >> required_milk >> farmers_count;

    for(int i=0; i<farmers_count; i++) {

        Farmer thisFarmer;

        fin >> thisFarmer.price >> thisFarmer.available;

        farmers[i] = thisFarmer;
    }

    fin.close();
}

/**
 * Output result
 */
void outputResult() {

    ofstream fout ( PROG + ".out" );

    fout << total_cost
         << endl;

    fout.close();
}

/**
 * Callback function for sorting farmers
 * @param x
 * @param y
 * @return
 */
bool sortingCallback(Farmer x, Farmer y) {
    return x.price < y.price;
}

/**
 * Solve the problem
 */
void solve() {

    // sort the farmers by the price of the milk
    sort(farmers, farmers + farmers_count, sortingCallback);

    int sourced_milk = 0;
    int farmer_index=0;

    while( sourced_milk<required_milk ) {

        // How much milk we're gonna buy fro, this farmer
        int purchase_milk = min(
                (required_milk - sourced_milk),
                farmers[farmer_index].available
        );

        // Update the cost
        total_cost += purchase_milk * farmers[farmer_index].price;

        // Update the milk available
        sourced_milk+=purchase_milk;

        // Next please!
        farmer_index++;
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