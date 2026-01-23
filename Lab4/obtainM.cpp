#include <iostream>
char** CreateMemBlock(int width, int height) {
    if (width <= 0 || height <= 0) {
        return nullptr; 
    }
    char** block = new char*[height];
    for (int i = 0; i < height; ++i) {
        block[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            block[i][j] = 'z';
        }
    }
    return block;
}
void DisplayMemBlock(char** block, int width, int height) {
    if (!block) {
        std::cout << "NULL\n";
        return;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << block[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void FreeMemBlock(char** block, int height) {
    if (!block) return;
    for (int i = 0; i < height; ++i) {
        delete[] block[i];
    }
    delete[] block;
}
int main() {
    int width = 6, height = 7;
    char** block = CreateMemBlock(width, height);
    DisplayMemBlock(block, width, height);
    FreeMemBlock(block, height);
    width = -1;
    block = CreateMemBlock(width, height);
    DisplayMemBlock(block, width, height);
    return 0;
}
