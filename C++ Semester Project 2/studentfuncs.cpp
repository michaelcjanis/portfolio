#include "Student.h"








Student::Student():name()
	{
	
	for(long i=0; i<5; i++)
		{
		grades [i]=0;
		}
	
	}


Student::Student(const char * s, const int grade []): name(s)
	{
	
	for(long i=0; i<5; i++)
		{
		grades [i]=grade[i];
		}	
		
	}
Student::Student(const String & s, const int grade []): name (s)
    {
	
	for(long i=0; i<5; i++)
		{
		grades [i]=grade[i];
		}	
	
	}

Student::Student(const Student &  s): name (s.name)
	{
	
	for(long i=0; i<5; i++)
		{
		grades [i]=s.grades[i];
		}
		
	}


 Student::~Student() 
	{	
	}
