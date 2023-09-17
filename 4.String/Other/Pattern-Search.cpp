// Print all occurrences of a string as a substring in another string

// Input : GeeksforGeeks , pattern -> Geeks        || Output : 0 8
// Input : Geeks ,         pattern -> g            || Output : None 


// NAIVE -> O(N^3) [Generating all possible substrings and comparing]



// BETTER ---------------------------------------------------> 

// Pure Substrings banane ki zaroorat nhi hai, index i se Pattern length ki substring se hi humko kaam hai

// O(N^2) & O(1)

#include <iostream>
using namespace std;

void Better(string str, string s)
{

	bool flag = false;
	for (int i = 0; i < str.length(); i++) {
        // Generating all possible valid substrings from index i
		if (str.substr(i, s.length()) == s) {
			cout << i << " ";
			flag = true;
		}
	}

	if (flag == false)
		cout << "NONE";
    
}

// USING STL ------->>> 

void printIndex(string str, string s)
{
 
    int pos = str.find(s, 0);
 
    if (pos == string::npos)
        cout << "NONE";
 
    while (pos != string::npos) {
        cout << pos << " ";
        // start searching from pos+1
        pos = str.find(s, pos + 1);
    }
}


// OPTIMAL ---------------------------------------------------> 

// REMEMBER -> Sliding Window of Pattern-length will not work becz string me O(1) me add kar paonge,remove front se nhi

// HERE TWO POINTER APPROACH CAN BE USED........






