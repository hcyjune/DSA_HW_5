#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;
int main(){
	int task;
	cin >> task;
	for (int T=0;T<task;T++){
		int n;
		cin >> n;
		int x[n],y[n];
		for (int i=0;i<n;i++)
			cin >> x[i] >> y[i];
		int p_set[n][n];
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				int p=(1<<i)+(1<<j);
				int vertical=x[i]-x[j];//check if they form a vertical line
				int origin=x[i]*y[j]-x[j]*y[i];//check if they form a line passing the origin
				int tmp=x[i]*x[i]*y[j]-x[j]*x[j]*y[i];//=x[i]*origin-vertical*x[j]*y[i];
				if (vertical*origin>0){
					for (int t=0;t<n;t++){
						if (t!=i and t!=j){
							int right=x[t]*(-origin*x[t]+tmp);
							int left=x[i]*x[j]*vertical*y[t];
							if (right==left){
								p+=(1<<t);
							}
						}
					}
				}
				p_set[i][j]=p;
				p_set[j][i]=p;
				//bitset<sizeof(p)*8> s(p);
				//cout << i << ' ' << j << ' ' << s << endl;
			}
		}
		int state=1<<n;
		vector<int> dp;
		dp.push_back(0);
		for (int i=1;i<state;i++){
			int dp_tmp=n;
			for (int j=0;j<n;j++){
				if ((1<<j)&i){
					int flag=0;
					for (int k=0;k<n;k++){
						if ((1<<k)&i and k!=j){
							flag=1;
							int val;
							int vertical=x[j]-x[k];
							int origin=x[j]*y[k]-x[k]*y[j];
							if (vertical*origin<=0)
								val=dp[i&(~p_set[j][k])]+2;
							else
								val=dp[i&(~p_set[j][k])]+1;
							if (val<dp_tmp)
								dp_tmp=val;
						}
					}
					if (flag==0)//only one pig
						dp_tmp=1;
					break;
				}
			}
			dp.push_back(dp_tmp);
			//cout << i << ' ' << dp_tmp << endl;
		}
		cout << dp[state-1] << endl;
	}
	return 0;
}
