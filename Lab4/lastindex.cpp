#include <iostream>
using namespace std;
int lastIndexOf(const char* str, char c) {
    if (str == nullptr) return -1; 
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1; 
}
int main() {
    const char* str1 = "abbcba";
    char c1 = 'b';
    cout << "Last index of '" << c1 << "' in \"" << str1 << "\":  " << lastIndexOf(str1, c1) << endl;

    const char* str2 = "orange";
    char c2 = 't';
    cout << "Last index of '" << c2 << "' in \"" << str2 << "\": " << lastIndexOf(str2, c2) << endl;
}
