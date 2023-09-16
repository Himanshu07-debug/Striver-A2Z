// Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// [[1,2,3],[4,5,6],[7,8,9]]  ->  [[7,4,1],[8,5,2],[9,6,3]]

// NAIVE -> O(n^2)  + O(n^2)

#include<bits/stdc++.h>
using namespace std;

vector < vector < int >> Naive(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
        // ACW -> 
        // rotated[n-j-1][i] = matrix[i][j];
    }
    }
    return rotated;
}

// OPTIMAL -> O(n^2) + O(1) 

// SAME code for ACW also

void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // vector <vector<int>> rotated = Naive(arr);
    rotate(arr);

    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "n";
    }

}

