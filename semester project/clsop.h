#ifndef _CLSOP_H
#define _CLSOP_H

#include <iostream>
#include <string.h>
#include <memory.h>
#include <fstream>
#include <conio.h>
using namespace std;

class String
	{    

	public:
		String ();
		String (const char *);
		String (const String &);

		void copy (const String &);
        void copy (const char* );
		long len ()const;
		void display ()const;
		long compare ( const String &)const;
		long compare (const char [])const;
		void concat (const String &);
		void concat (const char *);

	 String & operator = (const String &);
     String & operator = (const char*);
	 bool operator < (const String &);
	 bool operator < (const char*);
	 bool operator > (const String &);
	 bool operator > (const char*);
	 bool operator ==(const String &);
	 bool operator ==(const char*);
	 bool operator <= (const char*);
     bool operator <= (const String &);
	 bool operator != (const char *);
     bool operator != (const String &);
	 bool operator >= (const char*);
     bool operator >= (const String &);
    String operator & ( const String &);
	String operator & ( const char *);
	String & operator &= (const char* a);
	String & operator &= (const String &);
	void read(); 

	char& operator [] (const int &)const;
	char& operator [] (const int &);

 	int read_string(fstream &, int &);

	int write_string (fstream &, int &);

		~String ();

	private:
		char * pchar;
		long numchars;
		};


inline int String::write_string(fstream & f1, int & position)
	{
	f1<<pchar;

	return f1.tellp();
	}



inline char& String::operator [] (const int & i) const
	{
	return pchar[i];
	}

inline char& String::operator [] (const int & i) 
	{
	return pchar[i];
	}

 inline int String::read_string(std::fstream & f1, int & beg)
	{
	bool validop=true;
	int i(0);
	int j(0);
	char* lname;
	char h;
	bool counting=true;
	while (f1.get(h) && counting)
		{
		if(h!=' ' &&  h!='\n')
		i++;
		else
			counting=false;
		if (h='\n')
			validop=false;
		//cout<<"this "<<h<<endl;
		}
//	cout<<i<<endl;
	
	lname= new char [i+1];
	pchar=new char [i+1];
	numchars=i+1;
    f1.seekg (beg, ios::beg);
	f1.getline(lname,i+1,' ');
	copy(lname);
	//cout<<beg<<" "<<f1.tellg()<<endl;
	delete [] lname;

	
		
	//beg=f1.tellg();
	
	return f1.tellg();
	}  



inline String & String::operator &=(const String & s)
	{
     concat(s);
	 return * this;
	}
inline long String::compare (const String & s)const
	{
	return _strcmpi(pchar,s.pchar);
	}
inline long String::compare ( const char s [])const
	{
	
	return _strcmpi (pchar,s);
	}
inline String &  String::operator =(const String & s)
	{
	copy(s);
	return *this;
	}

inline String & String::operator = (const char* string)
	{
	copy(string);
	return *this;
	}

inline bool String::operator < (const String & string)
	{
	if (_strcmpi(string.pchar,pchar)<0)
		return true;
	else
		return false;
	}
inline bool String::operator < (const char* pointer)
	{
	if (_strcmpi(pointer,pchar)<0)
		return true;
	else
		return false;
	}
inline bool String::operator == (const char* pointer)
	{
	if (_strcmpi(pointer,pchar)==0)
		return true;
	else
		return false;
	}
inline bool String::operator ==(const String & pointer)
	{
	if (_strcmpi(pointer.pchar,pchar)==0)
		return true;
	else
		return false;
	}
inline bool String::operator <= (const char* pointer)
	{
	if (_strcmpi(pointer,pchar)<=0)
		return true;
	else
		return false;
	}
inline bool String::operator <=(const String & pointer)
	{
	if (_strcmpi(pointer.pchar,pchar)<=0)
		return true;
	else
		return false;
	}
inline bool String::operator != (const char * pointer)
	{
	if (_strcmpi(pointer,pchar)!=0)
		return true;
	else
		return false;
	}
inline bool String::operator != (const String & pointer)
	{
	if (_strcmpi(pointer.pchar,pchar)!=0)
		return true;
	else
		return false;
	}
inline bool String::operator >= (const char* pointer)
	{
	if (_strcmpi(pointer,pchar)>=0)
		return true;
	else
		return false;
	}
inline bool String::operator >=(const String & pointer)
	{
	if (_strcmpi(pointer.pchar,pchar)>=0)
		return true;
	else
		return false;
	}
inline String String::operator & ( const String & pointer)
	{
	String temp(*this);
	concat (pointer);
	return temp;
	}
inline String String::operator & ( const char * pointer)
	{
	String temp(*this);
	concat (pointer);
	return temp;
	}
inline String  operator & (const char* pointer, const String & s)
	{	
	String temp(pointer);
	temp.concat(s);
	return temp;
	}

inline bool String::operator > (const String & string)
	{
	if (compare(string)>0)
		return true;
	else
		return false;
	}
inline bool String::operator > (const char* pointer)
	{
	if (compare(pointer)>0)
		return true;
	else
		return false;
	}
inline bool operator < (const char* a, const String & s)
			{
			long i(0);

			i=s.compare(a);
			return (i>0);
			}
inline bool operator > (const char* a, const String & s)
			{
			long i(0);

			i=s.compare(a);
			return (i<0);
			}
inline bool operator <= (const char* a, const String & s)
			{
			long i(0);

			i=s.compare(a);
			return (i>=0);
			}
inline bool operator >= (const char* a, const String & s)
			{
			long i(0);

			i=s.compare(a);
			return (i<=0);
			}
inline bool operator == (const char* a, const String & s)
			{
			long i(0);

			i=s.compare(a);
			return (i==0);
			}
inline bool operator != (const char* a, const String & s)
			{
			long i(0);

			i=s.compare(a);
			return (i!=0);
			}
inline String & String::operator &= (const char* a)
			{
			concat(a);
			return *this;
			}
inline void operator << ( const ostream &, const String & s)
	{
	s.display ();
	}
inline void String::read ()
	{

	char * pnames;
	char  c;
	char * ptemp;
	long i (25),j(0),l(0);

	pnames=new char [i];

	while ((c=cin.get())!='\n'  )
		{			
		 if (c==' ')
			c='\a';
		else
			{ l++;
			
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
copy(pnames);
delete [] pnames;
	}
inline void operator >> (const istream & in, String & s)
	{
	s.read ();
	}




inline String::~String()
	{
	
	delete [] pchar;
     
	}
inline String::String ()
	{
	numchars=0;
	pchar= new char [numchars+1];
	pchar [0]='\0';

	}

inline String::String (const char * str): numchars (strlen (str))
	{
	pchar=new char [numchars+1];
	memcpy (pchar,str,numchars);
	pchar [numchars]='\0';
	numchars+=1;
	}

inline String::String (const String & str): numchars (str.numchars)
	{
	pchar=new char [numchars];
	memcpy (pchar,str.pchar, numchars);
	}

inline void String:: copy (const String & strobj)
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

inline void String:: copy ( const char* pointer)
	{
numchars= strlen (pointer);
delete [] pchar;
pchar = new char [numchars+1];
memcpy (pchar,pointer, numchars);
pchar[numchars]='\0';
numchars+=1;
	}

inline long String::len()const
	{
	return numchars;
	}

inline void String::display() const
	{
	
	for(long i=0; i<numchars; i++)
		{
		cout<< pchar [i];

		}
    
	}



inline void String::concat ( const String & s)
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


inline void String::concat (const char * s)
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

#endif 


