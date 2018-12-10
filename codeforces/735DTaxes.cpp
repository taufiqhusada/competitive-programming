// Codeforces Round #382 (Div. 2) :  D.taxes

#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if (n==2) return true;
    for(long long i=2;i<=sqrt(n);++i)
        if (n%i==0) {
            return false;
        }
    return true;
}

long long n;
int main(){
    cin>>n;
    if (isPrime(n)) cout<<1<<endl;
    else{
        if (n&1){
            if (isPrime(n-2))cout<<2<<endl;
            else cout<<3<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
    return 0;
}
