#include <iostream>
#include "sender.cpp"
#include "receiver.cpp"
using namespace std;

int main()
{
    ofstream temp;
    temp.open("temp.txt");
    temp << "";
    temp.close();
    ofstream output;
    output.open("output.txt");
    output << "";
    output.close();
    sender();
    receiver();
    //cout<<"\nalu";
    return 0;
}
