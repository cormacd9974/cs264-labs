#ifndef CS264_MATRIX_H
#define CS264_MATRIX_H
#include <iostream>

class Matrix {
    private:
        int rowsV; // NUMBER OF ROWS
        int columnsV; // NUMBER OF COLUMNS
        unsigned int** matrix; // STORE MATRIX
    public:
        Matrix(unsigned int m, unsigned int n); // MAKES M AND N
        Matrix(const Matrix &mat); // COPY EVERY ELEMENT FROM &MAT
        Matrix(int** array, unsigned int m, unsigned int n); // FOR 2D
        unsigned int rows() const; // RETURN ROW
        unsigned int columns() const; // RETURN COLUMN
        int get(unsigned i, unsigned j) const; // RETURNS I AND J
        void set(unsigned i, unsigned j, int value); // UPDATES VALUES
        Matrix operator+(const Matrix &mat); // ADD
        Matrix operator-(const Matrix &mat); // SUBTRACTION
        Matrix operator*(const Matrix &mat); // MULTIPLY
        Matrix operator~() const; // TRANSPOSE
        bool operator==(const Matrix &mat); // RETURNS TRUE
        std :: string toStr() const; // RETURNS STRING
        ~Matrix(); // DESTRUCTOIR
};


#endif
