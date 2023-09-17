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


// REMEMBER -> Sliding Window of Pattern-length will not work becz string me O(1) me add kar paonge,remove front se nhi

// HERE TWO POINTER APPROACH CAN ALSO BE USED.....

// Time : O(N*M) [ M -> Pattern length ]  .. Agar match hua kisi indx pe to max m tak hi chalega

void printIndex(string str, string s)
{
 
    int i = 0;
    bool flag = 0;
 
    for (int j = 0; j < str.length(); j++) {

        if (str[j] == s[i])
            i++;
        else {
            // ROLLBACK
            j -= i;
            i = 0;
        }

        // PATTERN FOUND
        if (i == s.length()) {
            flag = 1;
            cout << j + 1 - i << " ";
        }
    }
 
    if (!flag)
        cout << "NONE";
}

int main()
{
    string str1 = "GFG";
    string str2 = "g";
    printIndex(str1, str2);
    return 0;
}


// NOTE -> None of them is the most Optimal one, In case of String Pattern Search, KMP is only EFFICIENT





