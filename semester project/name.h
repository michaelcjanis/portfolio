#ifndef NAME_H
#define NAME_H


#include "clsop.h"
#include <fstream>

class Name
	{
	public:
		Name ();
		Name  (const Name &);
		Name (const char f [], const char m[], const char l[]);
        Name (const String & f, const String & m, const String & l);
		long compare(const Name &) const;
		long compare(const char* f, const char* m, const char* l)const;
	    long compare(const String& f,const String& m,const String& l)const;

		void read ();
		void display ()const;
		
		void copy (  Name&);

		void last_display();
		

		String& getfirst ();
		String& getmiddle ();
		String& getlast ();
		void setfirst (const String&);
		void setmiddle (const String&);
		void setlast (const String&);

        void operator = ( Name&);
		bool operator == (const Name &)const;
		bool operator <  (const Name &) const;
		bool operator >  (const Name &) const;
		bool operator >= (const Name &) const;
		bool operator <= (const Name &) const;


		int read_name (fstream &, int &);

		int write_name (fstream &, int &);
		
		
		~Name ();


	private:

		String first;
		String last;
		String middle;

	};

inline int Name::write_name (fstream & f1, int & pos)
	{
	int i;
	i=first.write_string(f1, pos);
f1<<' ';

	i=middle.write_string(f1, i);
f1<<' ';

	i=last.write_string(f1, i);
	f1<<endl;
	return i;


	}

inline void Name::last_display ()
	{
	last.display();
	}

int Name::read_name(std::fstream & f1, int & beg)
	{
	int num (0);
	
	num=first.read_string (f1, beg);
	
	
	num=middle.read_string (f1, num);
	
	int i(0);
	int j(0);
	char* lname;
	char h;
	bool counting=true;
	while (f1.get(h) && counting)
		{
		if( h!='\n')
		i++;
		else
			counting=false;
		
		}

	
	lname= new char [i+1];
    f1.seekg (num, ios::beg);
	f1.getline(lname,i+1,'\n');
	last.copy(lname);
	
	delete [] lname;

	
	

	return f1.tellg();
	}  






inline bool Name::operator==(const Name & n)const
	{
	return (compare(n)==0);
	}

inline void Name ::copy(  Name &n)
	{
	first.copy(n.getfirst());
	middle.copy(n.getmiddle());
	last.copy(n.getlast());
	}
inline void Name::operator = ( Name & n)
	{
	copy(n);
	} 
inline String & Name::getfirst ()
	{
	return first;
	}
inline String & Name::getmiddle ()
	{
	return middle;
	}
inline String & Name::getlast ()
	{
	return last;
	}
inline void Name::setfirst (const String & s)
	{
	first.copy (s);
	}
inline void Name::setmiddle (const String & s)
	{
	middle.copy (s);
	}
inline void Name::setlast (const String & s)
	{
	last.copy (s);
	}



inline void operator<<(const ostream &, const Name & n)
	{
	n.display();
	}  




inline void operator>>(const istream &, Name &n)
	{
	n.read();
	}



inline bool Name::operator <(const Name & n) const
	{
     if ( compare(n)<0)
		 return true;
	 else
		 return false;	
	}

inline bool Name::operator >(const Name & n) const
	{
     if (compare(n)>0)
		 return true;
	 else
		 return false;	
	}


inline bool Name::operator <=(const Name & n) const
	{
	if (compare(n)<=0)
		 return true;
	 else
		 return false;	
	}

inline bool Name::operator >=(const Name & n) const
	{
	if (compare(n)>=0)
		 return true;
	 else
		 return false;	
	}

inline void Name::read ()
	{
	cin>> last;
	cin>> first;
	cin>> middle;
	}

inline void Name ::display()const
	{
	
	last.display();
	cout<<", ";
	first.display ();
	cout<<"  ";
	middle.display();
	
	cout<<endl;
	}









inline Name::Name() 
	{	
	}
inline Name::Name(const Name & s): first (s.first),last (s.last),middle (s.middle)
	{	
	}
inline Name::Name (const char f [], const char m [], const char l []): first (f), middle (m), last (l)
	{	
	}
inline Name::Name (const String & f, const String & m, const String & l): first (f), middle (m), last (l)
	{	
	}
inline Name::~Name()
	{
	}
inline long Name::compare(const Name & n) const
	{
	long val(0);

	val=last.compare(n.last);
	if(val!=0)
		return val;
	val=first.compare(n.first);
	if(val!=0)
		return val;
	val=middle.compare(n.middle);
	return val;
	}

inline long Name::compare(const char *f, const char *m, const char *l) const
	{
	long val(0);

	val=last.compare(l);
	if(val!=0)
		return val;
	val=first.compare(f);
	if(val!=0)
		return val;
	val=middle.compare(m);
	return val;
	}
inline long Name::compare(const String& f,const String& m,const String& l)const
	{
    long val(0);

	val=last.compare(l);
	if(val!=0)
		return val;
	val=first.compare(f);
	if(val!=0)
		return val;
	val=middle.compare(m);
	return val;

	}
#endif 