// COMS 2104-002, lab#2
// Peng,Rong


#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int orders; //user inout
float total;
float tax;
float total_before_t;
cout<<"Welcome to Burger Town!"<<endl;
cout<< endl;
cout<<"******************Menu**************"<<endl;
cout<<"*                                  *"<<endl;
cout<<"*1.Cheese Burger..............$2.89*"<<endl;
cout<<"*                                  *"<<endl;
cout<<"*Free drink and fries with purchase*"<<endl;
cout<<"************************************"<<endl;
cout<<endl;
cout<<"How many cheese burger would you like to order?"<<endl;
cin>>orders;

total_before_t=2.89*orders;
tax=total_before_t*0.08;
 total=total_before_t+tax;
 cout<< fixed<<showpoint<<setprecision(2);
 cout<<setw(3)<<orders<<"cheese burger(s)"<<setw(10)<<total_before_t<<endl;
 cout<<"   Tax             "<<setw(10)<<tax<<endl;
 cout<<"   Total           "<<setw(10)<<total<<endl;
 return 0;

}
