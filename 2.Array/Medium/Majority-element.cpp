// Given an array of N integers, write a program to return an element that occurs more than N/2 times in the 
// given array. You may consider that such an element always exists in the array.


// Brute -> O(n^2) [ 2 loops ]
// Naive -> O(n) + O(n) [Hashmap / map]
// Better -> O(n*logn) + O(1) [ Sort the array and then cnt the occurences ]
// Optimal -> O(n) + O(1)


// Optimal -> MOORE'S VOTING ALGORITHM

// Apne pass ek element hai jiska cnt n/2 se jyada hai, this means that ki baaki elements ka cnt n/2 se kam hai,
// Agar hum majority element ke cnt ko cancel kiye baaki elements se definitely hum cnt>0 milna chahiye
// So in this algorithm, hum hypotetically elements ko majority select kar rhe hai aur uske cnt ko selected element
// ke equal no. aane pe add aur different aane pe cancel becz we are sure agar yeah element majority hai to cnt 0
// nhi hone denga, agar diya select another majority element


#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {

        // last selected element majority nhi hai, start with new 
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    // If question states that there might exist majority element, then check that the hypothetical selected element 
    // is exactly majority element or not, kyuki array me majority na ho iski bhi possibility hai
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;

    // If question states that there must exists a majority element, no need to write second loop
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
