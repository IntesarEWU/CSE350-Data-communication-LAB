//#include <iostream>
#include <string.h>
#include <bitset>
#include <fstream>
#include <bits/stdc++.h>
//#define MAXRESULT 1000
using namespace std;

void man()
{
    int i=0;
    string txt,str="";
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    //cout << txt;

    while(i!=txt.size())
    {
        if(txt[i]=='0')
        {
            str = str + "+"+"-";
        }
        else
        {
            str = str + "-"+"+";
        }

        i++;
    }
    //cout <<"string: "<<str;
    ofstream signal;
    signal.open("signal.txt");
    signal<<str;
    signal.close();
}

void diffman()
{
    int i=0;
    string txt,str="",state = "+-",antiState="-+",t;
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    //cout << txt;
    if(txt[i]=='0')
    {
        str = str+antiState;
        t=antiState;
        antiState=state;
        state=t;
    }
    else
    {
        str=str+state;
    }
    i++;
    while(i!=txt.size())
    {
        if(txt[i]=='1')
        {
            str = str+antiState;
            t=antiState;
            antiState=state;
            state=t;
        }
        else
        {
            str=str+state;
        }

        i++;
    }
    cout <<"string: "<<str;
    ofstream signal;
    signal.open("signal.txt");
    signal<<str;
    signal.close();
}

void rz()
{
    int i=0;
    string txt,str="";
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    //cout << txt;

    while(i!=txt.size())
    {
        if(txt[i]=='0')
        {
            str = str + "-"+"0";
        }
        else
        {
            str = str + "+"+"0";
        }

        i++;
    }
    //cout <<"string: "<<str;
    ofstream signal;
    signal.open("signal.txt");
    signal<<str;
    signal.close();
}

void nrzL()
{
    int i=0;
    string txt;
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    //cout << txt;
    ofstream signal;
    signal.open("signal.txt");
    while(i!=txt.size())
    {
        if(txt[i]=='0')
        {
            signal << '+';
        }
        else
            signal << '-';
        i++;
    }
    signal.close();
}

void nrzI()
{
    int i=0;
    string txt;
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    //cout << txt;
    ofstream signal;
    signal.open("signal.txt");
    char state = '+',antiState = '-',t;
    while(i!=txt.size())
    {
        if(txt[i]=='0')
        {
            signal << state;
        }
        else
        {
            t = state;
            state =antiState;
            antiState = t;
            signal << state;
        }

        i++;
    }
    signal.close();
}

void physicalLayer(string str1)
{
    //char str[100]="PH-H";
    string str = "PH-H"+str1;
    //cout << str << "\n";
    //cout << str.length() << "\n\n";
    //cout<<"\n"<<str.length();
    ofstream temp;
    temp.open("temp.txt",ios::app);

    for(size_t i=0; i<str.size();i++)
    {
        temp << bitset<8>(str[i]);
    }
    temp.close();

}
void dataLinkLayer(string str1)
{
    //char str[100]="D-H",str2[]="D-T";
    string str = "D-H"+str1+"D-T";
    //cout << str << "\n";
    physicalLayer(str);
}
void networkLayer(string str1)
{
    //char str[100]="N-H";
    string str = "N-H"+str1;
    //cout << str << "\n";
    dataLinkLayer(str);
}
void transportLayer(string str1)
{
    //char str[100]="T-H";
    string str = "T-H"+str1;
    //cout << str << "\n";
    //printf("%d",strlen(str));
    networkLayer(str);
}
void sessionLayer(string str1)
{
    //char str[100]="S-H";
    string str = "S-H"+str1;
    //cout << str << "\n";
    transportLayer(str);
}
void presentationLayer(string str1)
{
    //char str[100]="P-H";
    string str = "P-H"+str1;
    //cout << str << "\n";
    sessionLayer(str);
}
void applicationLayer(string str1)
{
    //char str[100]="A-H";
    string str = "A-H"+str1;
    //printf("%s\n",str);
    //cout << str <<"\n";
    presentationLayer(str);
}

void ami()
{
    int i=0;
    string txt,str="",state= "+",antiState = "-",t;
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    while(i!=txt.size())
    {
        if(txt[i]=='0')
        {
            str = str + "0";
        }
        else
        {
            str = str + state;
            t= state;
            state =antiState;
            antiState = t;
        }

        i++;
    }
    //cout <<"string: "<<str;
    ofstream signal;
    signal.open("signal.txt");
    signal<<str;
    signal.close();
}

void pseudo()
{
    int i=0;
    string txt,str="",state= "+",antiState = "-",t;
    ifstream temp("temp.txt");
    while(getline(temp,txt))
    {
            //cout << str << '\n';
    }
    temp.close();
    while(i!=txt.size())
    {
        if(txt[i]=='1')
        {
            str = str + "0";
        }
        else
        {
            str = str + state;
            t= state;
            state =antiState;
            antiState = t;
        }

        i++;
    }
    //cout <<"string: "<<str;
    ofstream signal;
    signal.open("signal.txt");
    signal<<str;
    signal.close();
}

void S4b5b()
{
    int i=0;
    string partxt,txt,str="",state= "+",antiState = "-",t,
    bit4[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"},
    bit5[]={"11110","01001","10100","10101","01010","01011","01110","01111","10010","10011","10110","10111","11010","11011","11100","11101"};

    ifstream temp("temp.txt");
    getline(temp,txt);
    temp.close();
    //cout << txt;

    while(i!=txt.size()/4)
    {
        partxt=txt.substr(4*i,4);
        for(int j=0;j<16;j++)
        {
            if(partxt==bit4[j])
            {
                str = str+bit5[j];
                break;
            }

        }
        i++;
    }
    //cout<<"\n\n" << str.size();
    ofstream signal;
    signal.open("signal.txt");
    signal<<str;
    signal.close();
}

//int main()
void sender()
{
    string txt;
    printf("\nSender  : ");
    getline(cin,txt);
    /*
    ifstream input("input.txt");
    while(getline(input,txt))
    {
            //cout << str << '\n';
    }
    input.close()
    */
    int txtlen = txt.size();
    //cout << txtlen <<'\n';
    int i=0;
    while(i!=(txtlen/125)+1)
    {
        string str = txt.substr(125*i,125);
        //cout << str << '\n';
        applicationLayer(str);
        i++;
    }
//----Line Coding----//
    //nrzL();
    //nrzI();
    //rz();
    //man();
    //diffman();
    //ami();
    //pseudo();

//----Blocking Coding----//
    S4b5b();
}
