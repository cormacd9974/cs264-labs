
#include <iostream>
using namespace std;

void flip(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        nums[i] = (~nums[i]) + 1; 
    }
}

int main() {
    int nums[] = {3, 2, -2, 1};
    int size = 4;
    flip(nums, size);
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
