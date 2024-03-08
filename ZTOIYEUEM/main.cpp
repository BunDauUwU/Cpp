#include <bits/stdc++.h>
#include <cstdlib>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define rand rd
using namespace std;
//**Variable**//
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ld NTEST = 10;
ofstream inp;
const string NAME = "uwu";
//**Struct**//

//**Function**//
long long Rand(long long l, long long h) {
    assert(l <= h);
    return abs(l + rd() * 1LL * rd() % (h - l + 1));
}
// vector<int> generateRandomNumbers(int N) {
    
// }
void sinhcondecai(){
    int n = Rand(10,400000), k = Rand(1,min(n-1,30));
    inp << n<<" " << k <<"\n";
    for(int i = 1; i<=n; i++){
        inp << Rand(1,1000000) << " ";
    }
}   
int main()
{
    //0949710383
    srand(time(NULL));
    system("g++ uwu.cpp -o uwu.exe -O2");
    system("g++ uwu_trau.cpp -o uwu_trau.exe -O2");
    ld dung = 0, sai = 0;
    ld tle = 0;
    for (ld iTest = 1; iTest <= NTEST; iTest++)
    {
        inp.open("uwu.inp");
        sinhcondecai();
        inp.close();
        system("uwu.exe");
        system("uwu_trau.exe");
        ifstream Time;
        ll timeC = 0;
        Time >> timeC;
        if(timeC > 1000)tle++;
        if (system("fc uwu.out uwu_trau.out") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            sai++;
            continue;
            return 0;
        }
        dung++;
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    cout<<dung<<" "<<sai<<" | "<<dung/(NTEST)*100<<"%\n";
    cout<<tle<<" test TLE";
    return 0;    
}
