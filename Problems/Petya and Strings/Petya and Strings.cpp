    #include <bits/stdc++.h>
    using namespace std;
    int p;
    string s1,s;
    int main() {
    	cin>>s>>s1;
    	p=s.size();
    	for(int i=0 ; i<p; i++){
    		s[i]=tolower(s[i]);
    		s1[i]=tolower(s1[i]);
    		if(s[i]>s1[i]){
    			cout<<1;
    			return 0;
    		}
    		else if(s[i]<s1[i]){
    			cout<<-1;
    			return 0;
    		}
    		}
    	cout<<0;
    	return 0;
    }