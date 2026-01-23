#include "iostream"
#include "Matrix.h"
#include <cstdlib>
using namespace std;

void Test_case_1_Matrix_default_constructor(){
    unsigned m = 4;
    unsigned n = 5;

    Matrix matrixA(m,n);
    bool isValid = true;
    //makes sure the matrix is initialized
    if (matrixA.rows() != m || matrixA.columns() != n) {
        cout << "TEST 1 FAIL";
        isValid = false;
    }
    //makes sure they are all 0
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (matrixA.get(i, j) != 0) {
                cout << "TEST 1 FAIL";
                isValid = false;
            }
        }
    }
    // Display test result
    if (isValid) {
        cout << "TEST 1 PASSED";
    }
}
void Test_case_2_Matrix_copy_Constructor(){
    unsigned int m = 3; // Rows
    unsigned int n = 4; // Columns
    Matrix originalMatrix(m, n);

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            originalMatrix.set(i, j, rand() % 101); // GIVE RANDOM NUMBER 0-100
        }
    }

    // MAKE A COPY OF THE COPY CONSTRUCTOR
    Matrix copiedMatrix(originalMatrix);

    // MAKE SURE SAME DIMENSIONS
    bool isValid = true;
    if (copiedMatrix.rows() != originalMatrix.rows() || copiedMatrix.columns() != originalMatrix.columns()) {
        cout << "TEST 2 FAIL";
        isValid = false;
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (copiedMatrix.get(i, j) != originalMatrix.get(i, j)) {
                cout << "TEST 2 FAIL";
                isValid = false;
            }
        }
    }

    copiedMatrix.set(0, 0, 999); // CHANGE THE COPIED MATRIX
    if (originalMatrix.get(0, 0) == copiedMatrix.get(0, 0)) {
        cout << "TEST 2 FAIL";
        isValid = false;
    }

    // Display test result
    if (isValid) {
        cout << "TEST 2 PASS";
    }
}

void Test_Case_3_Matrix_Array_Constructor(){
    unsigned int m = 3; // Rows
    unsigned int n = 4; // Columns

    // FILL THE ARRAY
    int **inputArray = new int*[m];
    for (unsigned int i = 0; i < m; i++) {
        inputArray[i] = new int[n];
        for (unsigned int j = 0; j < n; j++) {
            inputArray[i][j] = rand() % 101; // MAKE RANDOM VALUES
        }
    }

    // MAKE A MATRIX
    Matrix matrix(inputArray, m, n);

    // MAKE SURE DIMENSIONS MATCH
    bool isValid = true;
    if (matrix.rows() != m || matrix.columns() != n) {
        cout << "TEST 3 FAIL";
        isValid = false;
    }

    // MAKE SURE DIMENSIONS MATCH
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (matrix.get(i, j) != inputArray[i][j]) {
                cout << "TEST 3 FAIL";
                isValid = false;
            }
        }
    }

    // MAKE SURE ITS INDEPENDENT
    inputArray[0][0] = 999; // CHANGE THE ARRAY
    if (matrix.get(0, 0) == 999) {
        cout << "TEST 3 FAIL";
        isValid = false;
    }

    // OUTPUT
    if (isValid) {
        cout << "TEST 3 PASS";
    }

    // CLEAN THE ARRAY
    for (unsigned int i = 0; i < m; i++) {
        delete[] inputArray[i];
    }
    delete[] inputArray;
}

void Test_Case_4_Matrix_getRows(){
    unsigned int m = 5; // rows
    unsigned int n = 3; // columns
    Matrix Matrix(m, n);

    // MAKE SURE CORRECT NUM OF ROWS
    if (Matrix.rows() == m) {
        cout << "TEST 4 PASS";
    } else {
        cout << "TEST 4 FAIL";
    }
}

void Test_Case_5_Matrix_getColumns(){
    unsigned int m = 5; // Number of rows
    unsigned int n = 3; // Number of columns
    Matrix Matrix(m, n);

    // Validate that the columns() method returns the correct number of columns
    if (Matrix.columns() == n) {
        cout << "TEST 5 PASS";
    } else {
        cout << "TEST 5 FAIL";
    }
}

void Test_Case_6_Matrix_get(){
    unsigned int m = 3; // Rows
    unsigned int n = 4; // Columns

    // MAKE MATRIX
    Matrix matrix(m, n);

    // FILL IT
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            matrix.set(i, j, i * n + j + 1); // GIVE RANDOM VALUES
        }
    }

    bool isValid = true;
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            int expectedValue = i * n + j + 1; // WHAT TO EXPECT FOR I, J
            if (matrix.get(i, j) != expectedValue) {
                cout << "TEST 6 FAIL";
                isValid = false;
            }
        }
    }

    // OUTPUT
    if (isValid) {
        cout << "TEST 6 PASS";
    }
}

void Test_Case_7_Matrix_set(){
    unsigned int m = 3; // Rows
    unsigned int n = 4; // Columns

    // MAKE MATRIX
    Matrix matrix(m, n);

    // TEST VALUES
    bool isValid = true;
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            int testValue = i * n + j + 1; // RANDOM VALUE
            matrix.set(i, j, testValue); // SET VALUES

            // MAKE SURE VALUES ARE CORRECT
            if (matrix.get(i, j) != testValue) {
                cout << "TEST 7 FAIL";
                isValid = false;
            }
        }
    }

    // OUYTPUT
    if (isValid) {
        cout << "TEST 7 PASS";
    }
}

void Test_Case_8_Matrix_add(){
    bool isValid = true;
    unsigned int m = 2, n = 2;
    Matrix mat1(m, n);
    Matrix mat2(m, n);

    // FILL MATRIXES
    mat1.set(0, 0, 1);
    mat1.set(1, 0, 3);
    mat1.set(0, 1, 2);
    mat1.set(1, 1, 4);

    mat2.set(0, 0, 5);
    mat2.set(1, 0, 7);
    mat2.set(0, 1, 6);
    mat2.set(1, 1, 8);

    // ADD
    Matrix result = mat1 + mat2;

    // MAKE SURE THE RESULT IS CORRECT
    int expected[2][2] = {{6, 8}, {10, 12}};
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (result.get(i, j) != expected[i][j]) {
                cout << "TEST 8 FAIL";
                isValid = false;
            }
        }
    }

    if (isValid) {
        cout << "TEST 8 PASS";
    }
}

void Test_Case_9_Matrix_subtract(){
    bool isValid = true;
    unsigned int m = 2, n = 2;
    Matrix mat1(m, n);
    Matrix mat2(m, n);

    // FILL MATRIXES
    mat1.set(0, 0, 8);
    mat1.set(1, 0, 6);
    mat1.set(0, 1, 7);
    mat1.set(1, 1, 5);

    mat2.set(0, 0, 3);
    mat2.set(1, 0, 1);
    mat2.set(0, 1, 2);
    mat2.set(1, 1, 0);

    // SUBTRACT
    Matrix result = mat1 - mat2;

    // MAKE SURE THE RESULT IS CORRECT
    int expected[2][2] = {{5, 5}, {5, 5}};
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (result.get(i, j) != expected[i][j]) {
                cout << "TEST 9 FAIL";
                isValid = false;
            }
        }
    }

    if (isValid) {
        cout << "TEST 9 PASS";
    }
}

void Test_Case_10_Matrix_multiply(){
    bool isValid = true;
    unsigned int m1 = 2, n1 = 3;
    unsigned int m2 = 3, n2 = 2;

    Matrix mat1(m1, n1);
    Matrix mat2(m2, n2);

    // FILL MATRIXES
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(0, 2, 3);
    mat1.set(1, 0, 4);
    mat1.set(1, 1, 5);
    mat1.set(1, 2, 6);

    mat2.set(0, 0, 7);
    mat2.set(0, 1, 8);
    mat2.set(1, 0, 9);
    mat2.set(1, 1, 10);
    mat2.set(2, 0, 11);
    mat2.set(2, 1, 12);

    // MULTIPLY
    Matrix result = mat1 * mat2;

    // MAKE SURE THE RESULT IS CORRECT
    int expected[2][2] = {{58, 64}, {139, 154}};
    for (unsigned int i = 0; i < m1; i++) {
        for (unsigned int j = 0; j < n2; j++) {
            if (result.get(i, j) != expected[i][j]) {
                cout << "TEST 10 FAIL";
                isValid = false;
            }
        }
    }
    if (isValid) {
        cout << "TEST 10 PASS";
    }
}

void Test_Case_11_Matrix_tranpose(){
    bool isValid = true;
    unsigned int m = 2, n = 3;

    Matrix mat(m, n);

    // FILL MATRIXES
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(0, 2, 3);
    mat.set(1, 0, 4);
    mat.set(1, 1, 5);
    mat.set(1, 2, 6);


    // TRANSPOSE
    Matrix result = ~mat ;

    // MAKE SURE THE RESULT IS CORRECT
    int expected[3][2] = {{1, 4}, {2, 5}, {3, 6}};
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            if (result.get(i, j) != expected[i][j]) {
                cout << "TEST 11 FAIL";
                cout << mat.toStr() << endl;
                cout << result.toStr() << endl;
                isValid = false;
            }
        }
    }
    if (isValid) {
        cout << "TEST 11 PASS";
    }
}

void Test_Case_12_Matrix_Equality(){
    // MAKE MATRIX
    unsigned int m = 3; // Rows
    unsigned int n = 4; // Columns
    Matrix originalMatrix(m, n);

    // FILL THE MATRIX
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            originalMatrix.set(i, j, rand() % 101); // GIVE RANDOM NUMBER
        }
    }

    // MAKE A COPY
    Matrix copiedMatrix(originalMatrix);

    if(originalMatrix == copiedMatrix){
        cout << "TEST 12 PASS";
    }else{
        cout << "TEST 12 FAIL";

    }
}

void Test_Case_13_Matrix_to_string(){
    bool isValid = true;

    unsigned int m1 = 2, n1 = 3;
    Matrix mat1(m1, n1);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(0, 2, 3);
    mat1.set(1, 0, 4);
    mat1.set(1, 1, 5);
    mat1.set(1, 2, 6);

    string expected = "1 2 3 \n4 5 6 \n";
    string result = mat1.toStr();
    if (result != expected) {
        cout << "TEST 13 FAIL";
        isValid = false;
    }

    if (isValid) {
        cout << "TEST 13 PASS";
    }
}


int main(){
    Test_case_1_Matrix_default_constructor();
    cout << "----------------------------------------------------------\n" << endl;
    Test_case_2_Matrix_copy_Constructor();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_3_Matrix_Array_Constructor();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_4_Matrix_getRows();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_5_Matrix_getColumns();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_6_Matrix_get();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_7_Matrix_set();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_8_Matrix_add();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_9_Matrix_subtract();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_10_Matrix_multiply();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_11_Matrix_tranpose();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_12_Matrix_Equality();
    cout << "----------------------------------------------------------\n" << endl;
    Test_Case_13_Matrix_to_string();
    cout << "----------------------------------------------------------\n" << endl;


    return 0;
}
