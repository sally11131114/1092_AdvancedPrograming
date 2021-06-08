#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i, input;
    cin >> input;
    float temp2=sqrt(input);
    int temp;
    while(input){
        temp=temp2;
        if(temp2==temp){
            if(temp%2)
                cout << "1 " << temp << endl;
            else
                cout << temp << " 1" << endl;
        }
        else{
            temp++;
            if(temp%2){
                if(temp*temp-input<=temp-1)
                    cout << temp*temp-input+1 << " " << temp << endl;
                else
                    cout << temp << " " << input-(temp-1)*(temp-1) << endl;
            }
            else{
                if(temp*temp-input<=temp-1)
                    cout << temp << " " << temp*temp-input+1 << endl;
                else 
                    cout << input-(temp-1)*(temp-1) << " " << temp << endl;
            }
        }
        cin >> input;
        temp2=sqrt(input);
    }
    
}