/*
FileName: replace.cc
Date: 2021-04-27
Author: looptoto
描述：
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string s ="abcdae";
	string s1 ="()[]{}";
	string s2 ="({[]})";
	cout<<s.length()<<endl;
	for (int i = 0; i<3;i++){
		cout<<s1.find("()")<<endl;
		cout<<s1.find("}}")<<endl;
		cout<<s1.find("[]")<<endl;
		//s1.replace(s1.find("()"),2,"");
}
    return 0;
}
