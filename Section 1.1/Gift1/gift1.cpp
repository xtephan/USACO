/*
ID: xtephan1
PROG: gift1
LANG: C++11
http://train.usaco.org/usacoprob2?a=uHffjHMdSy6&S=gift1
*/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// CONSTANTS
const string PROG = "gift1";


int main() {

    ifstream fin ( PROG + ".in" );
    ofstream fout ( PROG + ".out" );

    int person_count;
    unordered_map<string, int> delta_money;
    vector<string> initial_order;

    // Number of people
    fin >> person_count;

    // person names
    for(int i=0; i<person_count; i++) {

        string person_name;

        fin >> person_name;

        delta_money[person_name] = 0;

        initial_order.push_back(person_name);
    }

    // Read data about each person
    for(int i=0; i<person_count; i++) {

        string person_name;
        int available_money, friend_count, per_person_money;

        fin >> person_name;
        fin >> available_money >> friend_count;

        // original delta
        if( available_money > 0 ) {
            delta_money[person_name] += ((available_money%friend_count) - available_money);
            per_person_money = available_money / friend_count;
        } else {
            per_person_money = 0;
        }

        for(int j=0; j<friend_count; j++) {
            string friend_name;
            fin >> friend_name;
            delta_money[friend_name] += per_person_money;
        }

    }

    // Iterate and print values of vector
    for(string thisPerson : initial_order) {
        fout << thisPerson << " " << (delta_money[thisPerson]) << endl;
    }

    fout.close();
    fin.close();

    return 0;
}