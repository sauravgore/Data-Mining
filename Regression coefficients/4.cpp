
//Regression coefficients

#include<bits/stdc++.h>
#include<boost/algorithm/string.hpp>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"

using namespace std;

class CSVReader{
	string _fn,_del;
	public:
		CSVReader(string _fn,string _del=","):_fn(_fn),_del(_del){}
		vector<vector<string> > getData();
};
 

vector<vector<string> > CSVReader::getData(){
	ifstream ip("/home/hduser/Music/Untitled Folder/DM/4/input.csv");
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


//Regression equation 

void reg_eq(vector <ll> v1,vector <ll> v2){
	ll n = v1.size();
	ll _smx = 0,_smy = 0,_smxx = 0,_smxy = 0;
	for(int i = 0;i < n;i++){
		_smx += v1[i];
		_smxx += (v1[i]*v1[i]);
		_smy += v2[i];
		_smxy += (v1[i]*v2[i]);
	}
	ld mnx = (ld)(_smx)/(ld)(n);
	ld mny = (ld)(_smy)/(ld)(n);
	ld b = (ld)(n*_smxy-_smx*_smy)/(n*_smxx-_smx*_smx);
	ld a = mny-b*mnx; 
	if(a>0)
		cout << fixed << setprecision(2) << b << "x + " << fixed << setprecision(2) << a << endl;
	else
		cout << fixed << setprecision(2) << b << "x - " << fixed << setprecision(2) << a << endl;
}


int main(){
	CSVReader cr("/home/hduser/Music/Untitled Folder/DM/4/input.csv");
	vector<vector<string> > ans1 = cr.getData();
	vector<ll> v1,v2;
	ll f = 0,c = 0;
	for(vector<string>v:ans1){
		for(string d:v){
			if(f==0 && c>1){
				stringstream ss(d);
				ll x = 0;
				ss >> x;
				v1.pb(x);
				f = 1;
			}
			else if(f==1 && c>1){
				stringstream ss(d);
				ll x = 0;
				ss >> x;
				v2.pb(x);
				f = 0;
			}
			++c;
		}
	}
	cout << "Regression equation is:     ";
	reg_eq(v1,v2);	
	return 0;
}
