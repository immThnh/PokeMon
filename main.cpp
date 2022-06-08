#include<iostream>
#include<vector>
#include<fstream>
#include"Pokemon.cpp"
using namespace std;

int main()
{
    // vector<Pokemon> v_poke;
    Pokemon pkm1("BeXuanMaiLonTo", 50, 45, 200, "Fire");
    Pokemon pkm2("ChuBeDan", 60,35, 170, "Water");
    
    ofstream fileOut;
    fileOut.open("WINNER.OUT", ios_base::in);
    fileOut << pkm1.Fight(pkm2);
    return 0;
}
