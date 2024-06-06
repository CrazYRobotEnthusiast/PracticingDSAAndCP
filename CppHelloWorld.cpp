#include <iostream>

using namespace std;

int main(){
    cout<<"Hello World";
    //Playing with Operators
    int a;
    int b;
    cin>>a;
    cin>>b;
    cout<<a+b;
    //
    //Playing with increment, decrement
    int x=3;
    int y=x++;
    int z=2;
    int alpha=++z;
    cout<<x<<y<<z<<alpha;
    return 0;
    //
    //Playing with For loops
    for(int i=0;i<5;i++){
        cout<<i<<endl;
    }
    //Note: in cpp, single quotes are used for single characters(and they are given datatype 'char'); Double quotes is used for strings (with datatype string)
    //Playing with for and continue, break
    for (int i=0;i<20;i+=2){
        if(i==4){
           continue;
        }
        else if(i==12){
           break;
        }
        cout<<i;
    }
    //Double Loops!!
    for (int i=0, j=1; (i<5 && j<5);i++ , j++){
        cout<<i<<"   "<<j<<endl;

    }
    //More Playing with loops
    int i=0;
    while (true){
        
        cout<<i<<endl;
        if (i==i/2) break; //Here in the first execution of the loop, we will get 0=0/2
        i++;
    }
}