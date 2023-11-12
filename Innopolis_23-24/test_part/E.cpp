#include <iostream>
using namespace std;

int main(){
    long int x,y,w,s;
    cin>>x>>y>>w>>s;
    if (x<0) {x=x*(-1);}
    if (y<0) {y=y*(-1);}
    if (y>x) {
        long int b;
        b=y;
        y=x;
        x=b;
    }
    if (w+w<=s){
        cout<<(x+y)*w;
    }
    else{
        if (s>=w){cout<<y*s+(x-y)*w;}
        else{cout<<y*s+((x-y)/2)*2*s+((x-y)%2)*w;}
    }   
    return 0;
}