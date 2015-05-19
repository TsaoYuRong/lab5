#include<iostream>
#include<vector>
#include<string>
using namespace std;

class HugeInt{
       friend ostream &operator<<(ostream &,const HugeInt &);
       friend istream &operator>>(istream &,HugeInt &);
public:
	HugeInt(int=0);
	HugeInt(const char* number);
	HugeInt &operator=(const HugeInt &);
	HugeInt operator+(HugeInt);
	HugeInt operator-(HugeInt);
private:
	vector<int> num;

};
