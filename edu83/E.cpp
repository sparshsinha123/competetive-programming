  #include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,k;
	    cin>>m>>k;
	    if(m<=5)
	     cout<<"NO"<<endl;
	    else if(m>5 && m%k==0)
	     cout<<"YES"<<endl;
	    else
	     cout<<"NO"<<endl;
	}
	return 0;
}