#ifndef _ID_H
#define _ID_H

#include "ID.h"
#include "fixedarray.h"
#include "ctype.h"
#include <fstream>

//typedef FixedArray<10>      identification;
 template <int length=10>
class ID: public  FixedArray <length>
	{
	public:
		
		
	
     long compare(ID<length>&);

	 int write_id(fstream &, int &);



	private:

		


	};


template <int length>
inline int ID<length>::write_id(std::fstream  & f1, int & pos)
	{
	int i;
	i=write_file(f1, pos);
	f1<<endl;
	return f1.tellp();
	}

template <int length>
inline long ID<length>::compare(ID<length> & s)
	{
	return (_strcmpi(DigitString,s.DigitString));
	
	}





	
















#endif 