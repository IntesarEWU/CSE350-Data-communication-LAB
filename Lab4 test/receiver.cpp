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

void RnrzL(string signal)
{
    string txt="";
    int i=0;
    int siglen = signal.size();
    //cout << siglen;
    while(i!= siglen)
    {
        if(signal[i]=='-')
        {
            txt = txt+'1';
        }
        else
            txt = txt+'0';
        i++;
    }
    //cout << txt;
    i=0;
    int txtlen = txt.size();
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
}

void RnrzI(string signal)
{
    char state='0',antiState = '1',t;
    string txt="";
    int i=0;
    int siglen = signal.size();
    //cout << siglen;
    if(signal[i]=='+')
        txt=txt+'0';
    else
        txt = txt + '1';
    i++;
    while(i!= siglen)
    {
        if((signal[i]=='-' && signal[i-1] == '-') || (signal[i] == '+' && signal[i-1] == '+'))
            txt = txt +'0';
        else
            txt = txt + '1';

        i++;
    }
    cout << txt;
    cout << txt.size();
    i=0;
    int txtlen = txt.size();
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
}

void Rdiffman(string signal)
{
    string txt="";
    int i=0;
    int siglen = signal.size();
    //cout << siglen;
    if(signal[i]=='-')
    {
        txt = txt+'0';
    }
    else
        txt= txt+'1';
    i++;
    while(i!= siglen/2)
    {
        if((signal[(i-1)*2]=='-' && signal[i*2]=='+') || (signal[(i-1)*2]=='+' && signal[i*2]=='-'))
        {
            txt = txt+'1';
        }
        else
        {
            txt= txt+'0';
        }

        i++;
    }
    //cout << txt;
    i=0;
    int txtlen = txt.size();
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
}

void Rman(string signal)
{
    string txt="";
    int i=0;
    int siglen = signal.size();
    //cout << siglen;
    while(i!= siglen/2)
    {
        if(signal[i*2]=='+')
        {
            txt = txt+'0';
        }
        else
        {
            txt= txt+'1';
        }

        i++;
    }
    //cout << txt;

    i=0;
    int txtlen = txt.size();
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
}

void Rrz(string signal)
{
    string txt="";
    int i=0;
    int siglen = signal.size();
    //cout << siglen;
    while(i!= siglen/2)
    {
        if(signal[i*2]=='+')
        {
            txt = txt+'1';
        }
        else
        {
            txt= txt+'0';
        }

        i++;
    }
    //cout << txt;

    i=0;
    int txtlen = txt.size();
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
}



void Rami(string signal)
{
    string txt="";
    int i=0;
    int siglen = signal.size();
    //cout << siglen;
    while(i!= siglen)
    {
        if(signal[i]=='+' || signal[i]=='-')
        {
            txt = txt+'1';
        }
        else
        {
            txt= txt+'0';

        }

        i++;
    }
    //cout << txt;

    i=0;
    int txtlen = txt.size();
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
}

void Rpseudo(string signal)
{
    string txt="";
    int i=0;
    int siglen = signal.size();
    //cout << siglen;
    while(i!= siglen)
    {
        if(signal[i]=='+' || signal[i]=='-')
        {
            txt = txt+'0';
        }
        else
        {
            txt= txt+'1';

        }

        i++;
    }
    //cout << txt;

    i=0;
    int txtlen = txt.size();
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }
}

void receiver()
{
    string signal;
    ifstream temp("signal.txt");
    while(getline(temp,signal))
    {
            //cout << str << '\n';
    }
    temp.close();
    //cout << signal;

    // signal Types
    //RnrzL(signal);
    //RnrzI(signal);
    //Rrz(signal);
    //Rman(signal);
    //Rdiffman(signal);

//----LAB TEST----//
    //Rami(signal);
    Rpseudo(signal);

    //cout << txtlen <<'\n';
    /*int i=0;
    //cout << str << '\n';
    while(i!=(txtlen/1200)+1)
    {
        string str = txt.substr(1200*i,1200);
        //cout << str << '\n';
        setStringtoASCII(str);
        i++;
    }*/
    //cout << "XX" << '\n';
}
