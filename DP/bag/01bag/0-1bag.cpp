//j<w(i)      V(i,j)=V(i-1,j)
//j>=w(i)     V(i,j)=max｛V(i-1,j)，V(i-1,j-w(i))+v(i)｝
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void DP(vector<int>& w, vector<int>& v,int bound){
	int DP[100][100] = {{0}}, n = w.size();
	for(int i=0;i<=n;i++){
		DP[i][0] = 0;
		DP[0][i] = 0;
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=bound;j++){
			if(w[i-1] > j)	
				DP[i][j] = DP[i-1][j];
			else
				DP[i][j] = max(DP[i-1][j], DP[i-1][j-w[i-1]] + v[i-1]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=bound;j++){
			cout<<DP[i][j]<<"\t";
		}
		cout<<endl;
	}
}
int main(){
	int n, bound;
	cin>>n>>bound;
	vector<int> w, v;
	for(int i=0;i<n;i++){
		int W, V;
		cin>>W>>V;
		w.push_back(W);
		v.push_back(V);
	}
	DP(w, v, bound);
	system("pause");
}

