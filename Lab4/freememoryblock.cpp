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
void FreeMemBlock(char** block, int width, int height) {
    if (block == nullptr) {
        return; 
    }
    for (int i = 0; i < height; ++i) {
        if (block[i] != nullptr) {
            delete[] block[i];
        }
    }
    delete[] block;
}
int main() {
    int width = 5, height = 5;
    char** block = CreateMemBlock(width, height);
    if (block != nullptr) {
       
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << block[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "fail" << std::endl;
    }
    FreeMemBlock(block, width, height);
    return 0;
}

