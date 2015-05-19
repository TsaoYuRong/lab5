#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include"HugeInt.h"
using namespace std;
HugeInt::HugeInt(int number){
	int i=0,b=1,tem=number;
	while(tem%b!=number){//計算有幾位數
		i++;
		b*=10;
	}
	num.resize(i);//給vector記憶體空間
	for(int j=0;j<i;j++){
		tem=number%10;//把數字填到vector裡
		num.at(j)=tem;
		number=(number-tem)/10;
	}
	reverse(num.begin(),num.end());//因取餘數要相反
}
HugeInt::HugeInt(const char* number){
	int a,leng=0;
	while(number[leng]!='\0') leng++;

	num.resize(leng);
	for(int i=0;i<leng;i++){
                	switch (number[i]){
                        	case '1':num.at(i)=1;break;
                        	case '2':num.at(i)=2;break;
                        	case '3':num.at(i)=3;break;
	                        case '4':num.at(i)=4;break;
        	                case '5':num.at(i)=5;break;
                	        case '6':num.at(i)=6;break;
	                       	case '7':num.at(i)=7;break;
        	                case '8':num.at(i)=8;break;
                	        case '9':num.at(i)=9;break;
	                        case '0':num.at(i)=0;break;
        	        }
	}
}

HugeInt HugeInt::operator+(HugeInt number){
	HugeInt result;
	vector<int> tem(num);
	int a,leng;
	if(number.num.size()>tem.size()) {//看哪個較長
		leng=number.num.size();
		reverse(tem.begin(),tem.end()); 
		tem.insert(tem.end(),number.num.size()-tem.size(),0);
		reverse(number.num.begin(),number.num.end());
	}
	else if(number.num.size()<tem.size()) {
		leng=tem.size();
		reverse(number.num.begin(),number.num.end());
		number.num.insert(number.num.end(),tem.size()-number.num.size(),0);
		reverse(tem.begin(),tem.end());
	}
	else{
		leng=tem.size();
		reverse(tem.begin(),tem.end());
		reverse(number.num.begin(),number.num.end());
	}
	
	result.num.resize(leng);	
	for(int i=0;i<leng;i++){
		a=tem.at(i)+number.num.at(i);
		if(a<10) result.num.at(i)=a;
		else{
			result.num.at(i)=a%10;
			tem.at(i+1)+a/10;

		}
	}
	reverse(result.num.begin(),result.num.end());
	return result;
}
HugeInt HugeInt::operator-(HugeInt number){
	HugeInt result;
	int a,leng,j;
	vector<int>tem(num);
        if(number.num.size()>tem.size()) {
                leng=number.num.size();
                reverse(tem.begin(),tem.end());
                tem.insert(tem.end(),number.num.size()-tem.size(),0);
                reverse(number.num.begin(),number.num.end());
        }
        else if(number.num.size()<tem.size()) {
                leng=tem.size();
                reverse(number.num.begin(),number.num.end());
                number.num.insert(number.num.end(),tem.size()-number.num.size(),0);
                reverse(tem.begin(),tem.end());
        }
        else{
                leng=tem.size();
                reverse(tem.begin(),tem.end());
                reverse(number.num.begin(),number.num.end());
        }
	result.num.resize(leng);
	
	for(int i=0;i<leng;i++){
		a=tem.at(i)-number.num.at(i);
		if(a>=0) result.num.at(i)=a;
		else{
			result.num.at(i)=a+10;
			j=i+1;
			cout<<tem.at(j)<<endl;
			tem.at(j)=tem.at(j)-1;
			
			while(tem.at(j)-1<0){
				tem.at(j)=9;
				tem.at(j+=1)-1;	
			}
		}
	}
	reverse(result.num.begin(),result.num.end());
	return result;
}
HugeInt& HugeInt::operator=( const HugeInt& right){
	int leng=right.num.size();
	if(num.size()<leng) num.insert(num.end(),leng-num.size(),0);
	if(&right!=this){ //不等於自己
		for(int i=0;i<leng;i++){
			num.at(i)=right.num.at(i);
		}
	}
	return *this;
}
ostream &operator<<(ostream &output,const HugeInt& number){
	for(int i=0;i<number.num.size();i++){
			output<<number.num.at(i);	
	}
	return output;
}
istream &operator>>(istream &input,HugeInt& number){
	int tem,number1,b=1,i=0,c;
	input>>tem;
	number1=tem;
        while(tem%b!=number1){
                i++;
                b*=10;
        }
        number.num.resize(i);
        for(int j=0;j<i;j++){
                c=number1%10;
                number.num.at(j)=c;
                number1=(number1-c)/10;
        }
        reverse(number.num.begin(),number.num.end());

	
	return input;
}
