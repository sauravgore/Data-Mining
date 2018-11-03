
//Normalization Techniques

#include<bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define ll long long
#define ld long double
#define pb push_back

using namespace std;

vector<string>minMaxNorm(vector <ll>);    //MinMax Normalization 

vector<string>zscoreNorm(vector <ll>);	  //zscore Normalization

class CSVReader{
	string _fn,_del;
	public:
		CSVReader(string _fn,string _del=","):_fn(_fn),_del(_del){}
		vector<vector<string> > getData();
};
 

vector<vector<string> > CSVReader::getData(){
	ifstream ip("/home/hduser/Music/Untitled Folder/DM/2/input.csv");
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


class CSVWriter{
	string _fn;;
	string _del;
	ll c;
 	public:
		CSVWriter(string _fn,string _del = ",") :
			_fn(_fn), _del(_del), c(0){}
	
		template<typename T>
		void addData(T L,T R);
};


template<typename T>
void CSVWriter::addData(T L, T R){
	fstream f;
	f.open(_fn,ios::out);
	for(;L != R;){
		f << *L;
		if(L != R)
			f << _del;
		L++;
	}
	f << "\n";
	//c++;
	f.close();
}

ld calc_avg(vector <ll> v){
	ld avg = 0.0;
	for(int i = 0;i < v.size();i++)
		avg+=(ld)v[i];
	avg/=(ld)(v.size());
	return avg;
}

ld varience(vector <ll> v){
	ld sm = 0.0,mnVal;
	mnVal = calc_avg(v);
	for(int i = 0;i < v.size();i++)
		sm+=((ld)(mnVal-v[i])*(ld)(mnVal-v[i]));
	sm/=(ld)(v.size());
	return sqrt(sm);
}

//Min-Max Normalization
vector<string>minMaxNorm(vector <ll> v){
	ll newMin,newMax;
	cout << "Enter values of newMin and newMax:  " << endl;
	cin >> newMin >> newMax;
	vector <string> res;
	ll min = *min_element(v.begin(),v.end());
        ll max = *max_element(v.begin(),v.end());
        ld minMax = 0.0;
        for(int i = 0;i < v.size();i++){
                minMax = ((ld)(v[i]-min)/(ld)(max-min))*(ld)(newMax-newMin)+(ld)(newMin);
                //cout << v2[i] << setw(10) << fixed << setprecision(2) << minMax << endl;
                if(i==0){
                	res.pb(" ");
                	res.pb(to_string(v[i]));
                	res.pb(to_string(minMax));
                }
                else{
                	res.pb(to_string(v[i]));
                	res.pb(to_string(minMax));
                }
                 
                res.pb("\n");
        }
        return res;
}

//zscore Normalization
vector<string>zscoreNorm(vector <ll> v){
	ld vr = varience(v),avg = calc_avg(v);
	vector <ld> z;
	vector<string> res;
	ld zscore = 0.0;
	for(int i = 0;i < v.size();i++)
		z.pb((v[i]-avg)/vr);
	sort(z.begin(),z.end());
	for(int i = 0;i < z.size();i++){
		zscore = (ld)(z[i]);
		if(i==0){
                	res.pb(" ");
                	res.pb(to_string(v[i]));
                	res.pb(to_string(zscore));
                }
                else{
                	res.pb(to_string(v[i]));
                	res.pb(to_string(zscore));
                }
                 
                res.pb("\n");	
	}
	return res;
}


int main(){
	CSVReader cr("/home/hduser/Music/Untitled Folder/DM/2/input.csv");
	CSVWriter wr1("/home/hduser/Music/Untitled Folder/DM/2/min_max_output.csv");
	CSVWriter wr2("/home/hduser/Music/Untitled Folder/DM/2/zscore_output.csv");
	vector<vector<string> > ans1 = cr.getData();
	vector<ll> v2;
	for(vector<string>v:ans1){
		for(string d:v){
			stringstream ss(d);
			ll x = 0;
			ss >> x;
			v2.pb(x);
		}
		//wr.addData(ans2.begin(),ans2.end());
		cout << endl;
	}
	vector<string> ans2 = minMaxNorm(v2);	
        wr1.addData(ans2.begin(),ans2.end());
        vector<string> ans3 = zscoreNorm(v2);
        wr2.addData(ans3.begin(),ans3.end());
	return 0;
}
