// PANGRAM String -> If the string contains all the characters, either in lower_case of in Upper_case

// I/P => The quick brown fox jumps over the lazy dog   , O/P -> True

// NAIVE -> O(n) + O(n)  [ USING HASHSET ]

#include <bits/stdc++.h>
using namespace std;

bool Naive(string& str)
{
	set<char> set;

	for (auto ch : str) {

		if (ch >= 'a' and ch <= 'z')
			set.insert(ch);

		if (ch >= 'A' and ch <= 'Z') {
            // converting to lowercase
			ch = tolower(ch);
			set.insert(ch);
		}
	}

	// check if the size is 26 or not
	return set.size() == 26;
}

// OTPIMAL -> O(n) + O(26) i.e O(1) SPACE

bool checkPangram(string& str)
{
    
    vector<bool> visited(26, false);

    for (int i = 0; i < str.length(); i++) {

        if ('A' <= str[i] && str[i] <= 'Z')
            visited[str[i]-'A']=true;
        
        else if ('a' <= str[i] && str[i] <= 'z')
            visited[str[i]-'a']=true;
        else{
            // Spaces
            continue;
        }
        
    }
 
    for (int i = 0; i <= 25; i++)
        if (visited[i] == false){
            // Univisited character
            return false;
        }
   

    // If all characters were present
    return true;
}

int main()
{
	string str = "The quick brown fox jumps over the"
				" lazy dog";
	if (checkPangram(str) == true)
		cout << "It is a Pangram" << endl;
	else
		cout << "It is Not a Pangram" << endl;

	return 0;
}
