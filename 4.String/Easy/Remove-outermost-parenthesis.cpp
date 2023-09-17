

// With Stack -> O(n) Time and ( O(n) [stack] + O(n) [res] )

// There exist a Two pointer approach , jab open == close ho jayega, res += s.substr(st+1,en-st-1), st = en+1

#include<bits/stdc++.h>
using namespace std;

string Naive(string s) {
    string res = "";
    stack<char>st;                                        // int st = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){                                    
            if(!st.empty()){                              // st > 0
                res+="(";
            }
            st.push(s[i]);                                // st++;
        }
        else{
            if(st.size()!=1){                             // st > 1
                res+=")";
            }
            st.pop();                                     // st--;
        }
    }
    return res;
}

// Without Stack -> O(n) + O(n)

// In this Question, In place of Stack, we can use an integer, kyuki hume stack ke size se hi lena dena hai

string removeOuterParentheses(string s) {

    string res = "";
    int st=0;                                     
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){                                    
            if(st>0){                              
                res+="(";
            }
            st++;                                
        }
        else{
            if(st > 1){                             
                res+=")";
            }
            st--;                        
        }
    }
    return res;

}

// There exist a Two pointer approach , jab open == close ho jayega, res += s.substr(st+1,en-st-1), st = en+1



int main(){

    string s = "(()())(())(()(()))";
    
    cout<<removeOuterParentheses(s)<<"\n";

    return 0;
}