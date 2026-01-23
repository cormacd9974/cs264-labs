#include <iostream>
unsigned int Binary2Decimal(const char* str) {
    unsigned int result = 0;
    while(*str) {
        result = (result << 1) + (*str - '0'); 
        ++str;
    }
    return result;
}
int main() {
    const char* str1 = "101";
    const char* str2 = "10101011";
    std::cout << "Binary: " << str1 << " to Decimal: " << Binary2Decimal(str1) << std::endl;
    std::cout << "Binary: " << str2 << " to Decimal: " << Binary2Decimal(str2) << std::endl;
    return 0;
}
