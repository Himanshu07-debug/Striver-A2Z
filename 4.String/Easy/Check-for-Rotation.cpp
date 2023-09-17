// Check if S2 is the rotation of S1 OR 
// Can we get S1 by rotating S2 either ACW or CW && vice versa

// S1 -> "ABCD" , S2 -> "CDAB"  ---> YES
// S1 -> "ABAB" , S2 -> "ABBA"  ---> NO

// NAIVE -> O(N^2) + O(n) [Extra String]

// All possible rotations banayenge S1 ke and compare krnge S2 Se

#include<bits/stdc++.h>
using namespace std;

bool Rotation(const string &s1, const string &s2){

    if(s1.size()!=s2.size()) return false;

    if(s1==s2){
        return true;
    }

    for(int i=1;i<s1.size();i++){
        
        string aux = "";
        aux+=s1[i];
        
        int j=i+1;

        while(j!=i){
            aux += s1[j];
            j = (j+1)%s1.size();
        }

        if(aux == s2){
            return true;
        }

    }
    return false;

}

// STL --------------------------------------------------------> 

bool Rotation2(string s1, string s2){

    // Initital cases check 

    for(int i=1;i<s1.size();i++){
        s1.push_back(s1[0]);
        // removing first character
        s1.erase(0,1);

        if(s1==s2){
            return true;
        }
    }

    return false;

}

// OPTIMAL ----------------------------------------------->>>

// Time -> O(n) + O(n) Space [ ( s1+s1) takes extra O(n) Auxiliary space ]

bool checkRotation(const string &s1, const string &s2){

    if(s1.size()!=s2.size()) return false;

    return ((s1+s1).find(s2)!=string::npos);

}



int main(){

    string s1 = "abcd";
    string s2 = "cdab";

    if(checkRotation(s1,s2)){
        cout<<"Yes"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }

}