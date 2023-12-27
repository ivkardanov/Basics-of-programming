#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MedianFinder {
    vector<int> counter;
    int totalNumbers;

public:
    MedianFinder() : counter(101, 0), totalNumbers(0) {}

    void addNum(int num) {
        counter[num]++;
        totalNumbers++;
    }

    double findMedian() {
        int count = 0;
        int median1 = -1, median2 = -1;

        for (int i = 0; i <= 100; i++) {
            count += counter[i];
            if (median1 == -1 && count >= (totalNumbers + 1) / 2) {
                median1 = i;
            }
            if (count >= (totalNumbers + 2) / 2) {
                median2 = i;
                break;
            }
        }

        if (totalNumbers % 2 == 0) {
            return (median1 + median2) / 2.0;
        }
        else {
            return median2;
        }
    }
};

int main() {
    string choice;
    do {
        MedianFinder mf;
        int arr[] = { 1,2,3,4,5 };
        int n = sizeof(arr) / sizeof(arr[0]);

        for (int i = 0; i < n; i++) {
            mf.addNum(arr[i]);
        }

        cout << "Median is: " << mf.findMedian() << std::endl;
        cout << "Run again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");
    return 0;
}