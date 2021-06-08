#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i, j, input, a=2, b, len;
    cin >> input;
    while(input!=0){
        int check=1; //prime if check=1
        int check2=1;
        for(i=2;i<=sqrt(input);i++){
            if(input%i==0)
                check=0;
        }
        if(!check){
            for(i=input;i<=1299709;i++){
                check2=1;
                for(j=2;j<=sqrt(i);j++)
                    if(i%j==0){
                        check2=0;
                        break;
                    }
                if(check2){
                    b=i;
                    break;
                }
            }

            for(i=input;i>=2;i--){
                check2=1;
                for(j=2;j<=sqrt(i);j++)
                    if(i%j==0){
                        check2=0;
                        break;
                    }
                if(check2){
                    a=i;
                    break;
                }
            }
        }

        if(check)
            cout << "0" << endl;
        else
            cout << b-a << endl;
        cin >> input;
    }
    
}