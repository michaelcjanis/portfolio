#ifndef _PERSON_H
#define _PERSON_H

#include "name.h"
#include "address.h"
#include "clsop.h"

class Person
	{
	public:
		Person ();
		Person (const Person &);
		Person(const Name & n, const address & a);
		void operator = ( Person &);
		void copy ( Person &);
		void copy (Name&, address&);
		bool operator ==(const Person&)const;
		

		Name & getname ();
		void setname (Name&);

		address & getaddress ();
		void setaddress ( const address &);

		void read();
		void display()const;

		int read_add (fstream &, int &);

		int write_person (fstream &, int &);

		long compare (const Person &)const;
        void displayname();
			


		~Person ();


	private:
		Name         N;
		address      A;

	};

inline int Person::write_person(fstream & f1, int & pos)
	{
	int i;
	i=N.write_name(f1, pos);
	i=A.write_address(f1, i);
	return i;

	}



inline void Person::displayname()
	{
	N.last_display();
	}

inline long Person::compare (const Person &s)const
	{
	return (N.compare(s.N));
	}




int Person::read_add (fstream & f1, int & beg)
	{
	int num(0);
//cout<<beg<<endl;
	num=N.read_name (f1, beg);
//cout<<num<<endl;

	num=A.read_address (f1, num);
//cout<<num<<endl;
//num-=1;
	//num+=1;
	return num;
	} 


inline bool Person::operator ==(const Person & p)const
	{
	bool val (0);
	val=N.compare (p.N);
	if(val=false)
		return val;
	val=A.compare(p.A);
	return val;
	}

inline void Person::copy (Name & n, address& a)
	{
	N.copy(n);
	A.copy(a);
	}
inline void Person::copy( Person & s)
	{
    N.copy(s.N);
	
	A.copy(s.A);
	}

inline Name& Person::getname ()
	{
	return N;
	}
inline void Person::setname ( Name& n)
	{
	N.copy (n);
	}
inline address & Person::getaddress()
	{
	return A;
	}
inline void Person::setaddress (const address & a)
	{
	A.copy(a);
	}


inline void Person::operator =( Person &p)
	{
	N.copy(p.N);
	A.copy(p.A);
	}
inline void Person::read()
	{
	N.read();
	A.read();
	}
inline void operator >> (const istream &, Person & p)
	{
	p.read();
	}
inline void Person::display ()const
	{
	
	cout<<endl;
	N.display();	
	A.display();
	cout<<endl;
	}
inline void operator<<(const ostream &, const Person & p)
	{
	p.display();
	}



inline Person::Person ()
	{
	}
inline Person::Person (const Person & p): N(p.N), A (p.A)
	{
	}
inline Person::Person(const Name & n, const address & a): N(n), A(a)
	{
	}
inline Person::~Person ()
	{
	}


#endif 
