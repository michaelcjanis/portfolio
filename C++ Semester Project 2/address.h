#ifndef _ADDRESS_H
#define _ADDRESS_H
#include "clsop.h"
#include <fstream>
#include <conio.h>


class address
	{
	public:
		address ();
		address(const address&);
		address(const char* street, const char* city, const char * state, const char* zip);
		address(const String & street, const String & city, const String & state, const String & zip);
	    address & operator = (const address&);
		void copy (const address&);
		void read ();
		void display ()const;
		long compare (const address&)const;
		long compare (const String & street,const String & city,const String & state,const String & zip)const;
		long compare (const char* street,const char* city,const char* state,const char* zip)const;

		bool operator ==(const address &) const;

		int read_address (fstream &, int &);

		int write_address (fstream &, int &);

		String & getstreet ();
		String & getcity ();
		String & getstate ();
		String & getzip ();
		void setstreet (const String &);
		void setcity (const String &);
		void setstate (const String &);
		void setzip (const String &);
		


			~address ();

	private:
		String street;
		String city;
		String state;
		String zip;
	};

inline int address::write_address (fstream & f1, int & pos)
	{
	int i;
	i=street.write_string (f1,pos);
	f1<<endl;
	i=city.write_string (f1,i);
	f1<<' ';
i+=1;
	i=state.write_string (f1,i);
  f1<<',';
  f1<<' ';
  i+=2;
	i=zip.write_string (f1,i);
	f1<<endl;
	i+=1;
	//cout<<i<<" "<<f1.tellp()<<endl;
	return i;

	}




inline int address::read_address(std::fstream & f1, int& beg)
	{
	
	int i (0);
	long j(0);
	char* lname;
	char h;
	bool counting=true;
	
	//cout<<beg<< " " << f1.tellg()<<endl;
	while (f1.get(h) && counting)
		{
		if(h!='\n')
		i++;
		else
			counting=false;
		
		}
	
	                                       
	lname= new char [i+1];
    f1.seekg (beg, ios::beg);
	f1.getline(lname,i+1,'\n');
	street.copy(lname);
	                         // cout<<"street "<<lname<<endl;                   
	delete [] lname;

	beg=f1.tellg();
	i=0;
	counting=true;
	                                          
	while (f1.get(h) && counting)
		{
		if(h!=' ')
		i++;
		else
			counting=false;
		//cout<<"in city "<<endl;
		}
	lname= new char [i+1];
    f1.seekg (beg, ios::beg);
	f1.getline(lname,i+1,' ');

	
	city.copy (lname);
	delete [] lname;
	
	beg=f1.tellg();
	i=0;
	counting=true;

	while (f1.get(h) && counting)
		{
		if(h!=',')
		i++;
		else
			counting=false;
		}
	lname= new char [i+1];
    f1.seekg (beg, ios::beg);
	f1.getline(lname,i+1,',');
	
	state.copy(lname);
	delete [] lname;

	beg=f1.tellg ();
	i=0;
	counting=true;

	while (f1.get(h) && counting)
		{
		if(h!='\n')
		i++;
		else
			counting=false;
		}
	  
	
	lname= new char [i+1];
    f1.seekg (beg, ios::beg);
	f1.getline(lname,i+1,'\n');
	zip.copy(lname);
	

	delete [] lname;
i=0;
counting=true;
beg=f1.tellg();

char c[5];
	while (f1.get(h) && counting)
		{
		if(h!='\n')
		i++;
		else
			counting=false;
		if (i<=3)
      c[i-1]=h;
		}
	  if(c[0]=='E' && c[1]=='O' && c[2]=='F')
		{
	 	cout<<"end of file found"<<endl;
	 	return -1;
	 	}
	  else
		  {
		  f1.seekg(beg, ios::beg);
		  }
	  

	return beg;
	}


inline long address::compare (const char* s,const char* c,const char* st,const char* z)const
	{
	long val(0);

	val=street.compare(s);
	if(val!=0)
		return val;
	val=city.compare(c);
	if(val!=0)
		return val;
	val=state.compare(st);
	if(val!=0)
	   return val;
	val=zip.compare(z);
	   return val;
	}
inline long address::compare(const String &street, const String &city, const String &state, const String &zip) const
	{
long val(0);

	val=street.compare(street);
	if(val!=0)
		return val;
	val=city.compare(city);
	if(val!=0)
		return val;
	val=state.compare(state);
	if(val!=0)
	   return val;
	val=zip.compare(zip);
	   return val;
	}
inline bool address::operator==(const address & n)const
	{
	return (compare(n)==0);
	}

inline long address::compare(const address &n) const
	{
long val(0);

	val=street.compare(n.street);
	if(val!=0)
		return val;
	val=city.compare(n.city);
	if(val!=0)
		return val;
	val=state.compare(n.state);
	if(val!=0)
	   return val;
	val=zip.compare(n.zip);
	   return val;
	}

inline String& address::getstreet()
	{
	return street;
	}

inline String& address::getcity()
	{
	return city;
	}

inline String& address::getstate()
	{
	return state;
	}

inline String& address::getzip()
	{
	return zip;
	}
inline void address::setstreet(const String & s)
	{
	street.copy(s);
	}
inline void address::setcity(const String & s)
	{
	city.copy(s);
	}
inline void address::setstate(const String & s)
	{
	state.copy(s);
	}
inline void address::setzip(const String & s)
	{
	zip.copy(s);
	}






inline void address::copy(const address &s)
	{
	street.copy(s.street);
	city.copy(s.city);
	state.copy(s.state);
	zip.copy(s.zip);
	}

inline address & address::operator =(const address &a)
	{
    copy (a);
	return *this;
	}


inline void address::read()
	{
	street.read ();
	city.read ();
	state.read ();
	zip.read ();	
	}
inline void operator>>(const istream &, address & s)
	{
	s.read();
	}
inline void address::display()const
	{
	street.display();
	cout<<endl;
	city.display ();
	cout<<" ";
	state.display();
	cout<<", ";
	zip.display ();
	cout<<endl;
	}
inline void operator << (const ostream &, const address &s)
	{
	s.display();
	}



inline address::address()
	{
	}
inline address::address(const address & s): street(s.street), city (s.city),state(s.state),zip (s.zip)
	{
	}
inline address::address(const char *street, const char *city, const char *state, const char *zip): street(street), city(city), state (state), zip (zip)
	{
	}
inline address::address(const String &street, const String &city, const String &state, const String &zip):street(street), city(city), state (state), zip (zip)
	{
	}
inline address::~address()
	{
	}





#endif 