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

void R4b5b(string signal)
{
    string txt="",partxt,
    bit4[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"},
    bit5[]={"11110","01001","10100","10101","01010","01011","01110","01111","10010","10011","10110","10111","11010","11011","11100","11101"};
    int i=0;
    //cout << signal.size();
    while(i!=signal.size()/5)
    {
        partxt=signal.substr(5*i,5);
        for(int j=0;j<16;j++)
        {
            if(partxt==bit5[j])
            {
                txt = txt+bit4[j];
                //cout << bit4[j]<<"\n";
                break;
            }

        }
        i++;
    }
    //cout << txt.size();
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

//----Line Coding----//
    //RnrzL(signal);
    //RnrzI(signal);
    //Rrz(signal);
    //Rman(signal);
    //Rdiffman(signal);
    //Rami(signal);
    //Rpseudo(signal);

//----Blocking Coding----//
    R4b5b(signal);

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
