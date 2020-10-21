# include "TwoStacks.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    size_t a = 6;
    TwoStacks<size_t>s(a);    

    s.push_second(20);
    s.push_second(19);
    s.push_second(18);

    s.push_first(1);
    s.push_first(2);
    s.push_first(3);
    s.push_first(4);
    s.push_first(5);

    //cout << s.size_first() << endl;
    //cout << s.size_second() << endl;
    //s.printStacks();

    s.pop_first();
    s.pop_second();

    cout << s.size_first() << endl;
    cout << s.size_second() << endl;
    s.printStacks();
    

    return 0;
  
}
