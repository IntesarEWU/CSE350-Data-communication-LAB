//#include <iostream>
//#include <fstream>
//#include <string>
#include <bits/stdc++.h>
using namespace std;

void RapplicationLayer(string str1)
{
    int i= str1.length();
    string str = str1.substr(3,i);
    cout << "\nReceiver: ";
    cout << str;
    //RpresentationLayer(str);
    ofstream output;
    output.open("output.txt",ios::app);
    output << str;
    output.close();
}

void RpresentationLayer(string str1)
{
    int i= str1.length();
    string str = str1.substr(3,i);
    //cout << str<<'\n';
    RapplicationLayer(str);
}

void RsessionLayer(string str1)
{
    int i= str1.length();
    string str = str1.substr(3,i);
    //cout << str<<'\n';
    RpresentationLayer(str);
}

void RtransportLayer(string str1)
{
    int i= str1.length();
    string str = str1.substr(3,i);
    //cout << str<<'\n';
    RsessionLayer(str);
}

void RnetworkLayer(string str1)
{
    int i= str1.length();
    string str = str1.substr(3,i);
    //cout << str<<'\n';
    RtransportLayer(str);
}

void RdataLinkLayer(string str1)
{
    int i= str1.length();
    string str = str1.substr(3,i);
    str = str.substr(0,str.size()-3);
    //cout << str << '\n';
    RnetworkLayer(str);
}

void RphysicalLayer(string str1)
{
    int i= str1.length();
    string str = str1.substr(4,i);
    //cout << str<<'\n';
    RdataLinkLayer(str);
}

int binaryToDecimal(string n)
{
    string num = n;

    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {

        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;

}

void setStringtoASCII(string str)
{
    int N = int(str.size());

    string res = "";

    for (int i = 0; i < N; i += 8) {
        int decimal_value
            = binaryToDecimal((str.substr(i, 8)));

        res += char(decimal_value);
    }

    //cout << res << '\n';
    RphysicalLayer(res);
}

void receiver()
{
    string txt;
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    int txtlen = txt.size();
    //cout << txtlen <<'\n';
    int i=0;
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
    //cout << "XX" << '\n';
}
