#include<bits/stdc++.h>
using namespace std;


# define f first
# define s second
# define ll long long
# define nl '\n'
# define FIO ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(); 


struct Friend{
    string name;
    int arabic;
    int maths;
    int science;
    int english;
};

bool customSort(const Friend& a, const Friend& b){
    int suma = a.arabic + a.maths + a.science + a.english;
    int sumb = b.arabic + b.maths + b.science + b.english;
    int diff = abs(suma - sumb);
    if(diff > 10){
        return suma > sumb;
    }else{
        return a.name < b.name;
    }
}


signed main(){
    FIO

    int n;
    cin >> n;
    vector<Friend> friends(n);
    for(int i=0;i<n;i++){
        cin >> friends[i].name >> friends[i].arabic >> friends[i].maths >> friends[i]. science >> friends[i].english;
    }
    sort(friends.begin(), friends.end(), customSort);

    for(const Friend& f : friends){
        int sum = f.arabic + f.maths + f.science + f.english;
        cout << f.name << " " << sum << " " << f.arabic << " " << f.science << " " << f.english << nl;
    } 
}