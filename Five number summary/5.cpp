
//Five Number Summary

#include<bits/stdc++.h>
#include<boost/algorithm/string.hpp>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"

using namespace std;

ld fM(vector <ll>);						//Find Median 

void fNS(vector <ll>);						//Five Number Summary

class CSVReader{
	string _fn,_del;
	public:
		CSVReader(string _fn,string _del=","):_fn(_fn),_del(_del){}
		vector<vector<string> > getData();
};
 

vector<vector<string> > CSVReader::getData(){
	ifstream ip("/home/hduser/Music/Untitled Folder/DM/5/input.csv");
	vector<vector<string> > dl;
	string s = "";
	while(getline(ip,s)){
		vector<string> v;
		boost::algorithm::split(v,s,boost::is_any_of(_del));
		dl.pb(v);
	}
	ip.close();
	return dl;
}

//Find Median

ld fM(vector <ll> v){
	ll n = v.size();
	sort(v.begin(),v.end());
	if((n%2)!=0)
		return (ld)(v[n/2]);
	else
		return (ld)(v[(n-1)/2]+v[n/2])/2.0;
}

//Five Number Summary

void fNS(vector <ll> v){
	ll n = v.size();
	sort(v.begin(),v.end());
	ll _mn = *min_element(v.begin(),v.end());
	ll _mx = *max_element(v.begin(),v.end());
	ld _md = fM(v);
	ld q1 = 0.0,q3 = 0.0;
	if((n%2)!=0){
		vector <ll> ans1,ans2;
		for(int i = 0;i < n;i++){
			if(i<n/2)
				ans1.pb(v[i]);
			else if(i>n/2)
				ans2.pb(v[i]);;
		}
		q1 = fM(ans1);
		q3 = fM(ans2);
	}
	else{
		vector <ll> ans1,ans2;
		for(int i = 0;i < n;i++){
			if(i<n/2)
				ans1.pb(v[i]);
			else if(i==n/2-1)
				ans1.pb(_md);
			else if(i==n/2)
				ans2.pb(_md);
			else if(i>n/2)
				ans2.pb(v[i]);
		}
		q1 = fM(ans1);
		q3 - fM(ans2);
	}
	ll _q1 = round(q1);
	ll _q3 = round(q3);
	cout << "Min : " << _mn << endl;
	cout << "Q1 : " << _q1 << endl;
	cout << "Median : " << _md << endl;
	cout << "Q3 : " << _q3 << endl;
	cout << "Max : " << _mx << endl;
}


int main(){
	CSVReader cr("/home/hduser/Music/Untitled Folder/DM/5/input.csv");
	vector<vector<string> > ans1 = cr.getData();
	vector<ll> v2;
	ll c = 0;
	for(vector<string>v:ans1){
		for(string d:v){
			if(c>0){
				stringstream ss(d);
				ll x = 0;
				ss >> x;
				v2.pb(x);
			}
			++c;
		}
	}
	cout << "Five Number Summary is:      " << endl;
	fNS(v2);	
	return 0;
}
