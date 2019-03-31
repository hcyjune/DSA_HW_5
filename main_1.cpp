#include <iostream>
#include <stack>
using namespace std;
int main(){
	int N=1000000007;
	int day;
	cin >> day;
	int tmp,arr[day+1],len[day+1],cnt[day+1],pre[day+1];
	for (int i=0;i<day+1;i++){
		if (i==day)
			tmp=N;//to make things easy for output
		else
			cin >> tmp;
		arr[i]=tmp;
		int len_tmp=1;
		int cnt_tmp=1;
		int pre_tmp=0;
		int val;
		for (int j=0;j<i;j++){
			if (tmp>=arr[j]){
				val=len[j]+1;
				if (val>len_tmp){
					len_tmp=val;
					cnt_tmp=cnt[j];
					pre_tmp=j+1;
				}
				else if (val==len_tmp){
					cnt_tmp=(cnt_tmp+cnt[j])%N;
				}
			}
		}
		len[i]=len_tmp;
		cnt[i]=cnt_tmp;
		pre[i]=pre_tmp;
	}
	cout << len[day]-1 << endl;//
	cout << cnt[day] << endl;//
	stack<int> s;
	int last=pre[day];//
	for (int i=0;i<len[day]-1;i++){
		s.push(last);
		last=pre[last-1];
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
		if (!s.empty())
			cout << ' ';
	}
	return 0;
}
