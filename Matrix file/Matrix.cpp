#include "Matrix.h"
#include <iostream>
#include <stdexcept>


/*Matrix constructor takes m, n and makes them 0*/
Matrix ::Matrix(unsigned  int m, unsigned int n) {
    rowsV = m;
    columnsV = n; /*assigning row and column*/
    matrix = new unsigned int* [rowsV];

    for(int i = 0; i < rowsV; i++){
        matrix[i] = new unsigned int[columnsV];

        for(int j = 0; j < columnsV; j++){
            matrix[i][j] = 0; /*make 0 default value*/
        }
    }
}

/*Matrix copy construtor*/
Matrix ::Matrix(const Matrix &mat) {
    rowsV = mat.rowsV;
    columnsV = mat.columnsV; /*assigning row and column*/
    matrix = new unsigned int* [rowsV];

    for(int i = 0; i < rowsV; i++){
        matrix[i] = new unsigned int[columnsV];

        for(int j = 0; j < columnsV; j++){
            matrix[i][j] = mat.matrix[i][j]; /*copies the values into the new matrix*/
        }
    }
}

/*Matrix constructor for 2d array*/
Matrix ::Matrix(int **array, unsigned int m, unsigned int n) {
    rowsV = m;
    columnsV = n; /*assigning row and column*/
    matrix = new unsigned int*[rowsV];

    for(int i = 0; i < rowsV; i++){
        matrix[i] = new unsigned int[columnsV];

        for(int j = 0; j < columnsV; j++){
                matrix[i][j] = array[i][j]; /*Copy the element*/
        }
    }
}

/*returns num of rows*/
unsigned int Matrix ::rows() const {
    return rowsV;
}

/*returns num of columns*/
unsigned int Matrix ::columns() const {
    return columnsV;
}

/*Get ixj*/
int Matrix ::get(unsigned int i, unsigned int j) const {
    return matrix[i][j];
}

/*Set value*/
void Matrix ::set(unsigned int i, unsigned int j, int value) {
    matrix[i][j] = value;
}

/* addition */
Matrix Matrix::operator+(const Matrix &mat) {
    if(mat.rowsV != rowsV || mat.columnsV != columnsV){ // checks size
        std::cerr << "Error: Matrices must be of the same size to perform matrix addition." << std::endl; //display an error message
        return Matrix(0,0); //returns matrix 0x0
    }else{
        Matrix add(rowsV,columnsV); // creates object
        add.matrix = new unsigned int * [rowsV];
        for(int i = 0; i < rowsV; i++){
            add.matrix[i] = new unsigned int [columnsV];
            for(int j = 0; j < columnsV; j++){
                add.matrix[i][j] = matrix[i][j] + mat.matrix[i][j]; //adds ixj elements in the new matrix
            }
        }
        return add; // result of addition
    }
}

/*subtraction*/
Matrix Matrix::operator-(const Matrix &mat) {
    if(mat.rowsV != rowsV || mat.columnsV != columnsV){ // check size
        //throw argument
        std::cerr << "Error: Matrices must be of the same size to perform matrix subtraction." << std::endl; // error message
        return Matrix(0,0); //returns matrix 0x0
    }else{
        Matrix sub(rowsV,columnsV); // creates object
        sub.matrix = new unsigned int * [rowsV];
        for(int i = 0; i < rowsV; i++){
            sub.matrix[i] = new unsigned int [columnsV];
            for(int j = 0; j < columnsV; j++){
                sub.matrix[i][j] = matrix[i][j] - mat.matrix[i][j]; //subtracts elements
            }
        }
        return sub; // result
    }
}

/*multiply*/
Matrix Matrix::operator*(const Matrix &mat) {
    if(columnsV != mat.rowsV){ // check
        //throw argument
        std::cerr << "Error: First matrix must have same number of columns as Second matrix's rows." << std::endl; // error message
        return Matrix(0,0); //returns matrix 0x0
    }else{
        Matrix mult(rowsV,mat.columnsV); // creates object

        for (int i = 0; i < rowsV; i++) {
            for (int j = 0; j < mat.columnsV; j++) {
                for (int k = 0; k < columnsV; k++) {
                    mult.matrix[i][j] += matrix[i][k] * mat.matrix[k][j]; // multiply
                }
            }
        }
        return mult; // result
    }
}

/*Overload*/
Matrix Matrix::operator~() const {
    Matrix trans(columnsV,rowsV); // makes new matrix
    trans.matrix = new unsigned int* [columnsV];
    for(int i = 0; i < columnsV; i++){
        trans.matrix[i] = new unsigned int[rowsV];
        for(int j = 0; j < rowsV; j++){
            trans.matrix[i][j] = matrix[j][i]; // move to new matrix
        }
    }
    return trans; //return transposed matrix
}

/*Overload for ==*/
bool Matrix::operator==(const Matrix &mat) {
    if(mat.rowsV == rowsV && mat.columnsV == columnsV){ // check
        bool equal = true; // make boolean if same

        for(int i = 0; i < rowsV; i++){
            for(int j = 0; j < columnsV; j++){
                if(matrix[i][j] != mat.matrix[i][j]){ // checks if element at i x j in both matrices are equal
                    equal = false; // if not boolean = false
                }
            }
        }
        return equal; //return boolean
    }else{
        return false; //if not the same size return false
    }
}

/*String representation*/
std::string Matrix::toStr() const {
    std::string stringMatrix = "";

    for(int i = 0; i < rowsV; i++){
        for(int j = 0; j < columnsV; j++){
            stringMatrix = stringMatrix + std::to_string(matrix[i][j]) + " ";; //loops through matrix
        }
        stringMatrix = stringMatrix + "\n"; //adds new line
    }
    return stringMatrix; //return string representation
}

/*Destructorfor post use*/
Matrix::~Matrix() {
    for (int i = 0; i < rowsV; ++i) {
        delete matrix[i]; //deletes values in matrix
    }
    std :: cout << "Matrix destroyed" << std :: endl;
    delete [] matrix; //deletes matrix
}
