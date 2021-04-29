/*
FileName: dms_dig.cc
Date: 2021-04-29
Author: looptoto
描述：度分秒小数的转换
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
struct DMS{
double degrees, minutes, seconds, mseconds;
    DMS( double val){
        degrees = floor(val);
        double rem = (val -degrees)*60;
        minutes = floor(rem);
        rem = (rem-minutes)*60;
        seconds = floor(rem);
        rem = (rem-seconds)*1000;
        mseconds = floor(rem);
        
    }
    operator double()const{
        return degrees+minutes/60+seconds/3600+mseconds/3600000;
    }
};
    /* data */

int main(){
    DMS dms = DMS(12.3574544);
     cout << dms.degrees<< "°"<< dms.minutes <<"′" << dms.seconds<<"″"<<dms.mseconds<<"ms"<<endl;

    cout << double(dms) << endl; 
    return 0;
}
