/*
ID: xtephan1
PROG: test
LANG: C++11
http://train.usaco.org/usacoprob2?S=test&a=c1w2PLj4GCK
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}