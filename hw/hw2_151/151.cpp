#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N, i, m, ans, s;
	cin >> N;
	while(N!=0){
		vector<int> v;
		for(m=1;m<N;m++){
			int index=0;
			int key;
			for(i=2;i<=N;i++)
				v.push_back(i);
			while(v.size()>0){
				index=(index+(m-1))%v.size();
				key=v[index];
				v.erase(v.begin()+index);
			}
			if(key==13){
				ans=m;
				break;
			}
		}
		cout << ans << endl;
		cin >> N;
	}
} 
