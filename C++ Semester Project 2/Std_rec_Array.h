#ifndef _STD_REC_ARRAY_H
#define _STD_REC_ARRAY_H

#include <iostream>
#include <fstream>
#include "totalstudent.h"

using namespace std;

class StudentArray
	{
	public:
		StudentArray ();
		StudentArray ( StudentArray&);

		int read_Array(fstream&, int &);
		int write_Array(fstream &, int &);
		void display();

		void sort_name (); 
		void sort_ID ();
		void lastdisplay ();

		void copy_S (const char* n, const char * grades, const char* ID, const char * phn, const char* first, const char * middle, const char * last, const char * street, const char *city, const char *state, const char* zip, const int& index);




		~StudentArray ();


	private:

		fullstudent   Array[25];
		int           numstudents;
	};

inline int StudentArray::write_Array (fstream & f1, int & pos)
	{
	int i(pos);
	long j=0;
	
	for(j=0; j<numstudents; j++)
		{
	
		i=Array[j].write_full_student(f1, i);
		
		}
	numstudents=0;
	f1<<'E';
	f1<<'O';
	f1<<'F';

	return i;
	}


inline void StudentArray::copy_S (const char* n, const char * grades, const char* ID, const char * phn, const char* first, const char * middle, const char * last, const char * street, const char *city, const char *state, const char* zip, const int& index)
	{
	if(numstudents<25)
	Array[index].copy(n,grades, ID,phn,first,middle,last,street,city,state,zip);
	
	numstudents++;
	}
inline void StudentArray::lastdisplay()
	{
	int i(0);
	for (i=0; i<numstudents; i++)
		{
		Array[i].displaylast();
		cout<<endl;
		}
	}



inline void StudentArray::sort_name()
	{
	 fullstudent fs;
	long i(0);
	do {
		
		if ( Array[i].compare_name(Array[i+1])>0)
			{
		       	fs.copy(Array[i]);
				Array[i].copy(Array[i+1]);
				 Array[i+1].copy(fs);
				i=0;
			}
		else
			i++;
		}while(i<numstudents-1);
	}

inline void StudentArray::display()
	{
	long i;
	for (i=0; i<numstudents; i++)
		Array[i].display_student();
	}



inline void StudentArray::sort_ID ()
	{

    fullstudent fs;
	long i(0);
	do {
		
		if ( Array[i].compare_ID(Array[i+1])>0)
			{
		       	fs.copy(Array[i]);
				Array[i].copy(Array[i+1]);
				 Array[i+1].copy(fs);
				i=0;
			}
		else
			i++;
		}while(i<numstudents-1);
		
	}

inline int StudentArray::read_Array(std::fstream & f1, int & beg)
	{
	int i(beg);
	long j=0;
	
	while (i>-1 && numstudents<25)
		{
	
		i=Array[j].read_full_student(f1,i);
		j++;
		numstudents++;
		}
	return i;
	}






inline StudentArray::~StudentArray ()
	{
	}

inline StudentArray::StudentArray( StudentArray & s)
	{
	numstudents=s.numstudents;
	for(long i=0; i<numstudents; i++)
		Array[i].copy(s.Array[i]);
		

	}

inline StudentArray::StudentArray()
	{
	numstudents=0;
	}










#endif
