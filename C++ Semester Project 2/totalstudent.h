#ifndef _TOTAL_STUDENT_H
#define _TOTAL_STUDENT_H

#include <iostream>
#include <fstream>

#include "ID.h"
#include "fixedarray.h"
#include "phonenumber.h"
#include "address.h"
#include "student.h"
#include "person.h"
#include "name.h"
#include "clsop.h"



using namespace std;




class fullstudent
	{
	public:

		fullstudent ();
		fullstudent (const fullstudent &);

		void copy (const char* n, const char * grades, const char* ID, const char * phn, const char* first, const char * middle, const char * last, const char * street, const char *city, const char *state, const char* zip);

		void copy ( fullstudent &);
		void displaylast ();

		int read_full_student (fstream &, int &);

		int write_full_student (fstream &, int &);

		void display_student ();
		long compare_name (const fullstudent&)const;
		long compare_ID ( fullstudent &);
		~fullstudent ();

	private:
		Student   namegrade;
		ID  <>      id;
		pNumber    phnumber;
		Person    Address;

	};

inline int fullstudent::write_full_student (fstream & f1, int & pos)
	{
	int i;
	i=namegrade.write_student(f1, pos);
	i=id.write_id(f1, i);
	i=phnumber.write_number(f1,i);
	i=Address.write_person(f1, i);
	return f1.tellp();

	}

inline void fullstudent::copy(const char* n, const char * grades, const char* ID, const char * phn, const char* first, const char * middle, const char * last, const char * street, const char *city, const char *state, const char* zip)
	{
	
	namegrade.copy(n,grades);
	
	id.copy(ID);
	phnumber.copy(phn);
	Name temp(first,middle,last);
	address tempa(street,city,state,zip);
	
	Address.copy(temp,tempa);
	}



inline void fullstudent::displaylast()
	{
	Address.displayname();
	}


inline long fullstudent::compare_ID ( fullstudent & fs)
	{
	return id.compare(fs.id);
	}


inline long fullstudent::compare_name(const fullstudent & s) const
	{
	return (Address.compare(s.Address));
	}


inline void fullstudent::display_student ()
	{
	namegrade.display();
	cout<<"ID :";
	id.display();
	cout<<endl;
	
	phnumber.display();
	Address.display();

	}

inline int fullstudent::read_full_student (fstream & f1, int & beg)
	{
	int i(0);
	i=namegrade.read_student(f1,beg);

	i=id.read_file(f1,i);
	//cout<<"index after number 2   "<<i<<endl;

	i=phnumber.read_phNumber(f1, i);
		
	i=Address.read_add(f1,i);
	return i;
	}



inline void fullstudent::copy( fullstudent & fs)
	{
	namegrade.copy(fs.namegrade);
	id.copy (fs.id);
	phnumber.copy(fs.phnumber);
	
	Address.copy (fs.Address);
	}


inline fullstudent::fullstudent()
	{
	}
inline fullstudent::fullstudent(const fullstudent & fs): Address (fs.Address), phnumber(fs.phnumber), id(fs.id), namegrade(fs.namegrade)
	{
	}
inline fullstudent::~fullstudent()
	{
	}








#endif