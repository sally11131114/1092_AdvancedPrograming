#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int i, n;
    int input_ap, house_num;

    cin >> n;

    while(n--){
        cin >> input_ap >> house_num;
        vector<int> house;
        for(i=0;i<house_num;i++){
            int temp;
            cin >> temp;
            house.push_back(temp*10);
        }
        sort(house.begin(), house.end());

        //cout << "input_ap=" << input_ap << endl;
        int left, right, mid; //binary serch
        left=0;
        right=(house[house.size()-1]-house[0])/(input_ap+1);
        int now_ap=0, now_dist=0;
        while(left<=right){
            //cout << "left= " << left << endl << "right= " << right << endl;
            mid=(left+right)/2;
            //cout << "mid=" << mid << endl;
            now_ap=1;
            now_dist=house[0]+mid;
            i=1;
            while(house[house.size()-1]>now_dist){
                if(i>=house.size())
                    break;
                if(house[i]-mid-now_dist>0){
                    now_dist=house[i]+mid;
                    now_ap++;
                }
                i++;
            }
            if(now_ap>input_ap)
                left=mid+1;
            else
                right=mid-1;
        }
        float f=left;
        cout << fixed << setprecision(1) << f/10 << endl;
    }


}