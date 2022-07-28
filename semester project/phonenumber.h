#ifndef _PHONE_NUMBER_H
#define _PHONE_NUMBER_H

#include <iostream>
#include "fixedarray.h"
#include "phonenumber.h"
#include <fstream>

using namespace std;

typedef FixedArray <3>    areacode;
typedef FixedArray <7>    number;

class pNumber
	{
	public:
		void copy(const pNumber &);
		void copy (const char* );
		void read ();
		void display ();
		int read_phNumber (fstream &, int &);
		int write_number (fstream &, int &);
	private:
		areacode    first;
		number      second;
	};


inline int pNumber::write_number(fstream& f1, int & pos)
	{
	int i;
	i=first.write_file(f1, pos);
	f1<<' ';
	i=second.write_file(f1, i);
	f1<<endl;
	return f1.tellp();
	}



int pNumber::read_phNumber(std::fstream & f1, int & beg)
	{
	int i(0);
	char h;
	bool counting=true;
	while (f1.get(h) && counting)
		{
		
		if( h!=' ')
		i++;
		else
			counting=false;
		
        }
	
	
	int k;


	
	f1.seekg (beg, ios::beg);
	
	f1.getline(first.DigitString,i+1,' ');
	first.DigitString[3]='\0';
	
	first.numchars=i+1;
	
	beg=f1.tellg();
	counting=true;
	i=0;


	while (f1.get(h) && counting)
		{
		
		if( h!='\n')
		i++;
		else
			counting=false;
		
        }
	
	
		
	f1.seekg (beg, ios::beg);
	
	f1.getline(second.DigitString,i+1,'\n');
	second.numchars=i+1;


	return f1.tellg();






	}



void pNumber::display()
	{
	cout<<"phonenumber:  ";
	first.display ();
	cout<<" ";
	second.display ();
	cout<<endl;
	}


void pNumber::read ()
	{
	first.read ();
	second.read ();
	}
void pNumber::copy (const char* s)
	{
	long i,j;
	for (i=0,j=0;i<3;i++,j++)
		first.DigitString[i]=s[i];
	first.DigitString[i]='\0';
	
	for (i=0;i<7;j++,i++)	
		second.DigitString[i]=s[j];
	second.DigitString[i]='\0';
	

	}

void pNumber::copy(const pNumber & s)
	{
	long i;
	for(i=0; i<4;i++)
	first.DigitString[i]=s.first.DigitString[i];
	for(i=0; i<8;i++)
	second.DigitString[i]=s.second.DigitString[i];

	}







#endif
