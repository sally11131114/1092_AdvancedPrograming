#include<iostream>
#include<set>
using namespace std;

int main(){
    char c;
    string temp="";
    set<string> s;
    cin>>noskipws;
    while(cin >> c){
        if(isalpha(c)){
            if(isupper(c))
                c += 32;
            temp += c;
        }
        else{
            s.insert(temp);
            temp="";
        }
    }
    for(auto i=s.begin(); i!=s.end(); i++){
        if(*i=="")
            continue;
        cout << *i << endl; 
    }

}