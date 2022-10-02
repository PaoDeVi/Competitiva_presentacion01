#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
int fenwick[N];

void updateBIT(int index, int val){
	while (index>0 && index < N){
	fenwick[index] += val;
	index += (index & (-index));
	}
}

int getSum(int index)
{
	int sum = 0; 
	while (index>0){
		sum += fenwick[index];
		index -= (index & (-index));
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n,q,aux;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>aux;
		updateBIT(aux,1);
	}
	for(int i=0;i<q;i++){
		int query;
		cin>>query;
		if(query>0) updateBIT(query,1);
		else{
			query = query*(-1);
			 int low=0,high = N;
			while(low<high){
				int mid = (low+high)/2;
				int val = getSum(mid);
				if(query<=val) high = mid;
				else low = mid+1;
			}
			updateBIT(low,-1);
		}
	}
	
	int ans = getSum(n);
	if(!ans) cout<<0<<endl;
	else{
			 int low=0,high = N;
			while(low<high){
				int mid = (low+high)/2;
				int val = getSum(mid);
				if(ans<=val) high = mid;
				else low = mid+1;
			}
			cout<<low<<endl;
		}
}


