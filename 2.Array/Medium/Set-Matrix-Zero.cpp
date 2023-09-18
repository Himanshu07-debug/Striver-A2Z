// Given a matrix if an element in the matrix is 0 then you will have to set its entire column and 
// row to 0 and then return the matrix.

// [ [1,1,1],[1,0,1],[1,1,1] ]  -->  [ [1,0,1],[0,0,0],[1,0,1] ]

// NAIVE -> 
// Hume jis cell pe 0 milega, uss complete row and col ko -1 kar denge , 0 nhi karenge becz 0 krne pe jis 
// row aur col pe 0 nhi honga, wo bhi 0 ho jayenge.. Last me jha pe -1 hai, wha 0
// EX -> arr[0][0] pe 0 hai, aapne first row and col ko zero kar diye, ab jab arr[0][1] pr jaonge, wo 0 kar denga col 
//       ko jabki uss col-1 me 0 nhi tha

// TIME -> O((N*M)*(N + M)) + O(N*M) -> O((N*M)*(N + M))
// SPACE -> O(1)

#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i) {

    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// BETTER --------------------------------------------------->>

// Original array ko mark karne se aacha, hum 2 extra array use krnge to keep track of 0 in row and col
// TIME -> O( 2*(N*M) )
// SPACE -> O( N + M ) 


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// NOTE -> In case of matirx, agar apko time O(n*m) mil rha hai, then this is the minimal, isko optimize krne ka koi
//          sense nhi, we can go for Space improvement


// OPTIMAL --------------------------------------------------->>

// Instead of using 2 array to keep track of 0's, we can use the first row and first col of original matrix to do this
// I/P matrix ke first row aur first column me 0 hai ki nhi yeah handle krne ke liye hum row and col naam ke 2 bool 
// varaibles le sakte hai jo batayenge ki O/P matrix me first row ko OR first column ko 0 krna hai kya

// OBSERVE, there is no need of taking marker variable for row, kyuki agar usme hua to matrix[0][0] ko update kar denga
// wo, hum usase check kar payenge, humko sirf j ko handle krna hai

// TIME -> O( 2*(N*M) )
// SPACE -> O(1)


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int col0 = 1;
    // int row = 1;

    // step 1: Traverse the matrix and mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // if(i==0) row=0;
                // else:
                matrix[i][0] = 0;

                // Hum j ko allow nhi kar sakte matrix[0][0] ko update krna, therefore j=0 ko handle kiye
                if (j != 0)       
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st row & then 1st col:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}


int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}








