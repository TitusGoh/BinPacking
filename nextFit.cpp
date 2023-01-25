#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int nextFit(vector<float> weights) {
    if(weights.size() == 0) {
        return 0;
    }
    if(weights.size() == 1) {
        return 1;
    }
    int binCount = 1;
    float remainWeight = 1.0;
    for(int i = 0; i < weights.size(); i++) {
        if(weights[i] > remainWeight) {
            binCount++;
            remainWeight = 1 - weights[i];
        } else {
            remainWeight -= weights[i];
        }
    }
    return binCount;
}
int main() {
    srand(static_cast <unsigned> (time(0)));
    int runs = 11;
    for(int j = 0; j < runs; j++) {
        vector<float> v;
        int size = j + 1;
        for(int i = 0; i < size; i++) {
            float element = rand() % 100 + 1;
            float rounded = element/ 100;
            cout << rounded << " ";
            v.push_back(rounded);
        }
        int bins = nextFit(v);
        auto start = high_resolution_clock::now();
        cout << endl << bins << " bin(s) are needed." << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Needed " << duration.count() << " microseconds." << endl << endl;

    }
}