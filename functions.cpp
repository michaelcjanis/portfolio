#include <iostream>

using namespace std; 

#include "clsdecl.h"

#include <ctype.h>
#include <memory.h>
#include <string.h>

String::String ()
	{
	numchars=0;
	pchar= new char [numchars+1];
	pchar [0]='\0';

	}
String::~String()
	{
	
	delete [] pchar;

	}

String::String (const char * str): numchars (strlen (str))
	{
	pchar=new char [numchars+1];
	memcpy (pchar,str,numchars);
	pchar [numchars]='\0';
	numchars+=1;
	}

String::String (const String & str): numchars (str.numchars)
	{
	pchar=new char [numchars];
	memcpy (pchar,str.pchar, numchars);
	}

void String:: copy (const String & strobj)
	{
	
	if (numchars>=strobj.numchars)
		numchars=strobj.numchars;
	else
		{
		delete [] pchar;
		pchar=new char [strobj.numchars];
		numchars=strobj.numchars;
		}
	memcpy (pchar,strobj.pchar, numchars);
	}

void String:: copy ( const char* pointer)
	{
numchars= strlen (pointer);
delete [] pchar;
pchar = new char [numchars+1];
memcpy (pchar,pointer, numchars);
pchar[numchars]='\0';
numchars+=1;
	}

long String::len()const
	{
	return numchars;
	}

void String::display() 
	{
	for(long i=0; i<numchars; i++)
		{
		cout<< pchar [i];

		}
    cout<<endl;
	}

bool String::compare (const String & s)
	{
	return _strcmpi(pchar,s.pchar)==0;
	}
bool String::compare (const char* s)
	{
	bool i=false;
	i=(strcmpi (pchar,s)==0);
	return i;
	}

void String::concat ( String & s)
	{
	long i;
	long j;
	j=0;
	char*  temp;
	temp= new char [strlen (pchar)+strlen(s.pchar)+1];
    memcpy (temp,pchar,strlen(pchar));
	for(i=(strlen(pchar)); i<(strlen (pchar)+strlen(s.pchar)), j<s.numchars; i++,j++)
		{
		temp[i]=s.pchar[j];
		}
	
	
	//temp[i]='\0';
	//delete [] pchar;
	pchar=new char [strlen(temp)+1];
	
	memcpy (pchar, temp, strlen (temp));
	pchar[strlen (temp)]='\0';
	delete [] temp;
	numchars=numchars+s.numchars-1;

	}


void String::concat (const char * s)
	{
	long i=0;
	long j=0;
	char* temp;
	temp=new char [strlen (pchar)+strlen(s)+1];
	for (i=0; i<strlen(pchar);i++)
		temp[i]=pchar [i];
	--i;
	for (j=0; j<(strlen (pchar)+strlen(s));j++,i++)
		temp[i]=s[j];
	
	delete [] pchar;
	pchar = new char [strlen (temp)+1];
	memcpy (pchar,temp, strlen(temp));
	pchar [strlen (temp)]='\0';
	numchars= strlen (temp)+1;

	
	}





