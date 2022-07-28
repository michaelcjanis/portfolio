#ifndef    _FIXED_ARRAY_H
#define    _FIXED_ARRAY_H

#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;



template <int length>
class FixedArray
	{
	public:
		FixedArray ();
		FixedArray (const FixedArray <length> &);

		void read ();
		void display ()const;
		void display ();

		

		void copy ( FixedArray <length> & );
		void copy (const char*);

		int read_file (fstream &,  int & );
		int write_file (fstream &, int &);

		char& operator [](const int &)const;
		char& operator [](const int &);
		FixedArray<length>& operator=( FixedArray<length> &);
		~FixedArray();



	public:
		char DigitString [length+1];
		long       numchars;
		};


template <int length>
inline int FixedArray<length>::write_file(std::fstream & f1, int & pos)
	{
	int i;
	f1<<DigitString;
	
	return f1.tellp();

	}


template <int length>
int FixedArray<length>::read_file (fstream & f1, int & num)
	{
	int i(0);
	char h;
	bool counting=true;
	while (f1.get(h) && counting)
		{
		
		if( h!='\n' && h!=' ')
		i++;
		else
			counting=false;
		
        }
	
	
	int k;

	
	
	f1.seekg (num, ios::beg);
	//if (numchars >i)
	f1.getline(DigitString,i+1,'\n');
	
		k=f1.tellg();

	return k;
	}

template <int length>
void FixedArray<length>::copy (const char* s)
	{
	long i;
	for(i=0; i<strlen(s)+1; i++)
		DigitString[i]=s[i];
	}


template <int length>
FixedArray<length>& FixedArray<length>::operator =( FixedArray<length> & s)
	{
	copy(s);
	return *this;
	}


template <int length>
void FixedArray<length>::copy( FixedArray<length> & s)
	{
	long i;
	
	 if(numchars=s.numchars)
		{
		for (i=0; i<numchars; i++)
			DigitString[i]=s.DigitString[i];
		DigitString[i]='\0';
		numchars=i-1;
		}
	 else
		 cout<<"unable to copy string"<<endl;
	}




template <int length>
void FixedArray<length>::display () const
	{
	cout<<DigitString;
	}

template <int length>
void FixedArray<length>::display ()
	{
	cout<<DigitString;
	}


template <int length>
void FixedArray<length>::read()
	{
	
char * pnames;
	char  c;
	char * ptemp;
	long i (25),j(0),l(0);

	pnames=new char [i];

	while (((c=getch())!='\r') && l<(numchars-1))
		{
		
			
		 if (c<'0' ||  c>'9')
			_putch('\a');			 
		else
			{ 
			_putch(c);
			l++;
			
		pnames [ j]= c;
		j+=1;
			}
		if (j==25)
			{
			i+=25;
			ptemp=new char [i];
			memcpy (ptemp, pnames, j);
			delete [] pnames;
			pnames=new char [i];
			
			memcpy (pnames, ptemp, j);
			delete [] ptemp;
			
			}
          
			
		}

*(pnames +j)='\0';


	for(i=0;i<numchars;i++)
		{
		DigitString[i]=pnames[i];
		}
	DigitString[i]='\0';
delete [] pnames;
cout<<endl;
	}
	


template <int length>
char& FixedArray<length>::operator [](const int & t)const
	{
	if(0<=t && t<=numchars)
		return DigitString[t];
	else
		return DigitString[0];
	}

template <int length>
char& FixedArray<length>::operator [](const int & t)
	{
	if(0<=t && t<=numchars)
		return DigitString[t];
	else
		return DigitString[0];
	}



template <int length>
FixedArray<length>::~FixedArray()
	{
	}


template <int length>
FixedArray<length>::FixedArray (const FixedArray<length> & t)
	{
	long i;
	for(i=0;i<length;i++)
		DigitString [i]=t.DigitString[i];
	DigitString[i]='\0';
	}

template <int length>
FixedArray<length>::FixedArray ()
	{
	numchars=length+1;
	}
















#endif
