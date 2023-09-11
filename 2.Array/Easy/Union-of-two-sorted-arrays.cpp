// O/P array should be in ascending order [Union only contain distict elements]

/* NAIVE -> O((m+n)log(m+n))

We can use :
MAP -> 2 loop chalake elements daal dete aur fir map ko iterate krte, map will itself only keep the data in sorted and distict form
SET -> Set Can also be used
HashSet  -> Phle sort krnge dono array ke combined array ko and then iterate to it, push distinct elements to the output vector

*/

/*  OPTIMIZATION ------------------>

Dono array sorted given hai, we can use this property to optimize the solution

// Approach 1 -> Merge two sorted arrays O(m+n) wala + Remove duplicates wala code

// Approach 2 -> Merge Two sorted arrays wala hi concept with handling duplicates

// Best Test Case for Approach 2 -> arr1 = [1,2,3,4,5] , arr2 = [2,3,4,4,5]

*/


#include <bits/stdc++.h>

using namespace std;

vector <int> FindUnion(int arr1[], int arr2[], int n, int m) {

    int i = 0, j = 0; // pointers
    vector < int > Union; // Uninon vector

    while (i < n && j < m) {

        if (arr1[i] <= arr2[j])
        {
            if (Union.size() == 0 || Union.back() != arr1[i])  // Checking the previous entered data in Union
                Union.push_back(arr1[i]);
            i++;
        } 
        else 
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
        Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
        Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}

int main()

{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
    vector < int > Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union)
        cout << val << " ";
    return 0;
}
