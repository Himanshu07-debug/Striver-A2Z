#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    string res = "";
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            if(!st.empty()){
                res+="(";
            }
            st.push(s[i]);
        }
        else{
            if(st.size()!=1){
                res+=")";
            }
            st.pop();
        }
    }
    return res;
}

int main(){

    string s = "(()())(())(()(()))";
    
    cout<<removeOuterParentheses(s)<<"\n";

    return 0;
}