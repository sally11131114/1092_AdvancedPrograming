#include<iostream>
using namespace std;

int main(){
    int n;
    string A[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cin >> n;
    while(n--){
        int m, d;
        int sum=0;
        cin >> m >> d;
        switch(m){
            case 1:
                sum=((d+5)%7);
                cout << A[sum] << endl;
                break;
            case 2:
                sum=((d+1)%7);
                cout << A[sum] << endl;
                break;
            case 3:
                sum=((d+1)%7);
                cout << A[sum] << endl;
                break;
            case 4:
                sum=((d+4)%7);
                cout << A[sum] << endl;
                break;
            case 5:
                sum=((d+6)%7);
                cout << A[sum] << endl;
                break;
            case 6:
                sum=((d+2)%7);
                cout << A[sum] << endl;
                break;
            case 7:
                sum=((d+4)%7);
                cout << A[sum] << endl;
                break;
            case 8:
                sum=((d+0)%7);
                cout << A[sum] << endl;
                break;
            case 9:
                sum=((d+3)%7);
                cout << A[sum] << endl;
                break;
            case 10:
                sum=((d+5)%7);
                cout << A[sum] << endl;
                break;
            case 11:
                sum=((d+1)%7);
                cout << A[sum] << endl;
                break;
            case 12:
                sum=((d+3)%7);
                cout << A[sum] << endl;
                break;
        }
    }
}