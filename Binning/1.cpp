
//Bining Techniques

#include<bits/stdc++.h>
#include<boost/algorithm/string.hpp>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"

using namespace std;

void binning(vector <ll> ,ll);				//Binning techniques

void binEq_freq(vector <ll> [],ll);                	//Binning by equal frequency

void binMean(vector <ll> [],ll);			//Binning by mean			

void binBound(vector <ll> [],ll);			//Binning by boundaries


class CSVReader{
	string _fn,_del;
	public:
		CSVReader(string _fn,string _del=","):_fn(_fn),_del(_del){}
		vector<vector<string> > getData();
};
 

vector<vector<string> > CSVReader::getData(){
	ifstream ip("/home/hduser/Music/Untitled Folder/DM/1/input.csv");
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

//Bin by equal frequency

void binEq_freq(vector <ll> bns[],ll _nob){
	cout << "Binning by equal frequency:      " << endl;
	for(int i = 0;i < _nob;i++){
		cout << "Bin - " << i+1 << " : ";
		for(int j = 0;j < bns[i].size();j++)
			cout << bns[i][j] << " ";
		cout << endl;
	}
}

//Bin by mean

void binMean(vector <ll> bns[],ll _nob){
	cout << "Binning by mean:             " << endl;
	ld binMean = 0.0;
	for(int i = 0;i < _nob;i++){
		cout<<"Bin - " << i+1 << " : ";
		binMean = 0.0;
		for(int j = 0;j < bns[i].size();j++)
			binMean += bns[i][j];
		binMean /= bns[i].size();
		for(int j = 0;j < bns[i].size();j++)
			cout << (ll)(round(binMean)) << " ";
		cout << endl;
	}
}

//Bin by boundaries

void binBound(vector <ll> bns[],ll _nob){
	cout << "Binning by boundaries:        " << endl;
	for(int i = 0;i < _nob;i++){
		cout << "Bin - " << i+1 << " : ";
		ll _mn = bns[i][0];
		ll _mx = bns[i][bns[i].size()-1];
		for(int j = 0;j < bns[i].size();j++){
			if(j != 0 && j != bns[i].size()-1){
				if(abs(bns[i][j]-_mn) <= abs(bns[i][j]-_mx))
					cout << _mn << " ";
				else
					cout << _mx << " ";
			}				
			else
				cout << bns[i][j] << " ";
		}
		cout << endl;
	}
}

void binning(vector <ll> v){
	ll _nob,_bs,n = v.size();
	cout << "Enter bin size and no of bins:  " << endl;
	cin >> _bs >> _nob;
	sort(v.begin(),v.end());
	_bs = (n/_nob);
	if(n%2!=0)
		++_bs;
	vector <ll> bns[_nob];
	ll k = 0;
	for(int i = 0;i < n;i++){
		bns[k].pb(v[i]);
		if((i+1)%_bs==0)
			++k;
	}
	binEq_freq(bns,_nob);
	binMean(bns,_nob);
	binBound(bns,_nob);
}


int main(){
	vector<ll> v2;
	CSVReader cr("/home/hduser/Music/Untitled Folder/DM/1/input.csv");
	vector<vector<string> > ans1 = cr.getData();
	ll c = 0;
	for(vector<string>v:ans1){
		for(string d:v){
			if(c>0){
				//cout << d << " ";
				stringstream ss(d);
				ll x = 0;
				ss >> x;
				v2.pb(x);
			}
			++c;
		}
		cout << endl;
	}
	sort(v2.begin(),v2.end());
	binning(v2);	
	return 0;
}
