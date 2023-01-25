#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
int numBins = 0;
vector<float> weights;
vector<float> bins;

void bruteHelper(int index) {
    int binCount = 0;
    for (int i = 0; i < bins.size(); i++) {
        if (bins[i] != 0) {
            binCount++;
        }
    }
    if (index >= weights.size()) {
        if (binCount < numBins) {
            numBins = binCount;
        }
        return;
    }
    for (int i = 0; i < bins.size(); i++) {
        if (bins[i] + weights[index] <= 1) {
            bins[i] += weights[index];
            bruteHelper(index + 1);
            bins[i] -= weights[index];
            if (bins[i] == 0) {
                binCount--;
            }
        }
    }
}
void bruteForce() {
    numBins = weights.size();
    bruteHelper(0);
}

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

int main()
{
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
        cout << endl;
        weights = v;
        vector<float> temp(v.size(), 0.0);
        bins = temp;
        auto start = high_resolution_clock::now();
        bruteForce();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << numBins << " bin(s) are needed." << endl;
        cout << "Brute Force needed " << duration.count() << " microseconds." << endl;

        auto start1 = high_resolution_clock::now();
        int nextFitAns = nextFit(v);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        cout << nextFitAns << " bin(s) are needed." << endl;
        cout << "NextFit needed " << duration1.count() << " microseconds." << endl << endl;
    }
}