// I/P -> "12.518"  --> 518

#include <bits/stdc++.h>
using namespace std;

string digitsAfterDecimal(const string &s){

    int pos = s.find(".");

    if(pos == string::npos){
        return "";
    }
    else{
        return s.substr(pos+1);
    }

}

int main(){
    string s = "12.518";
    string res = digitsAfterDecimal(s);
    cout<<"Output String is : "<<res;
}