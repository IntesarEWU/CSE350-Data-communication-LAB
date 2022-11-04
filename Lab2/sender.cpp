//#include <iostream>
#include <string.h>
#include <bitset>
#include <fstream>
#include <bits/stdc++.h>
//#define MAXRESULT 1000
using namespace std;


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

void sender()
{
    //FILE *fptr;
    string txt;
    //fptr = fopen("input.txt","r");
    //while (fgets(str, MAXRESULT, fptr) != NULL);
    //fclose(fptr);
    printf("Sender  : ");
    getline(cin,txt);
    //int txtlen = txt.length();
    //int i=0,j=0;
    //ifstream input("input.txt");
    /*while(getline(input,txt))
    {
            //cout << str << '\n';
    }*/
    //cout << txt << '\n';

    //input.close();
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


}
