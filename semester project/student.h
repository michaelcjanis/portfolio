#ifndef _STUDENT_H
#define _STUDENT_H
#include <fstream>
#include "clsop.h"
#include <stdio.h>
#include <string.h>

class Student
	{
	public:
		
		Student ();
		Student (const Student &);
		Student (const String &, const int [] );
		Student (const char*, const int []);
	    Student& operator= (const Student & );
		void gradedisplay ()const;
		void display () const;
		void copy (const Student&);
		void copy ( const char* n,const char* grade);
		long compare (const Student &)const;
	

		int read_student ( fstream &, const int & beg );

		int write_student (fstream &,  int & pos);

		~Student ();

	private:
		String  name;
		int     grades [5];
	};


inline int Student::write_student(fstream & f1, int & pos)
	{
	int i;
	i=name.write_string(f1, pos);
	f1<<endl;
	for(i=0; i<4; i++)
		{
		f1<<grades[i];
		f1<<',';
		}
	f1<<grades[i];
	f1<<endl;
	return f1.tellp();
	}





inline void Student::copy( const char* n,const char *grade)
	{
	name.copy(n);

	char h;
	char c[20];
	long k(0),b(0),g(0), l(0),p(0),num, i(0), j=0;
	for(i=0;i<5;i++)
		{
		

		num=0;
		p=k;
		
		do{
			h=grade[k];
			k++;
			}while(h!=','&& h!='\0');
		
		l=k-p;
	
		if(i>0)
			{
						
			
			
			
			for(g=0;g<l;g++,p++)
				{
				c[g]=grade[p];
				}
			
			c[g-1]='\0';
			
			}
		
		else
			{
		
		for(b=0;b<k;b++)
			{
			c[b]=grade[b];
			}
		c[b-1]='\0';
			}
  

	for(j=0;j<strlen(c);j++)
		{
	
		
		
		switch (c[j])
			{
			case '0':
				num*=10;
				break;
			case '1':
				num*=10;
				num+=1;
				break;
			case '2':
				num*=10;
				num+=2;
				break;
			case '3':
				num*=10;
				num+=3;
				break;
			case '4':
				num*=10;
				num+=4;
				//cout<<num<<endl;
				break;
			case '5':
				num*=10;
				num+=5;
				break;
			case '6':
				num*=10;
				num+=6;
				break;
			case '7':
				num*=10;
				num+=7;
				break;
			case '8':
				num*=10;
				num+=8;
				break;
			case '9':
				num*=10;
				num+=9;
				break;
			default:
				break;

			}
		
		}
	

	
	grades[i]=num;
		}
	}



inline long Student::compare (const Student & s) const
	{
	return name.compare(s.name);

	}

inline void Student::copy(const Student & s)
	{
	long i(0);
	for (i=0; i<5; i++)
		{
		grades[i]=s.grades[i];
		}
	name.copy(s.name);
	}

inline void Student::display()const
	{
	name.display();
	cout<<endl;
	gradedisplay();
	long i=grades[0]+grades[1]+grades[2]+grades[3]+grades[4];
	cout<<"average: "<<i/5<<endl;
	}


inline void Student::gradedisplay ()const
	{
	long i;
	for(i=0;i<4;i++)
		cout<<grades[i]<<",";
	cout<<grades[i]<<endl;

	}


inline int Student::read_student(fstream & f1, const int& beg)
	{
	const char delimeters[3]=", ";
	char * lname;
	char * grade1,grade3,grade4,grade5;
	char c[100],h;
	char* grade2;
	long i=0,j=0,num(0);
	bool counting=true;
	while (f1.get(h) && counting)
		{
		if(h!='\n')
		i++;
		else
			counting=false;
         c[i-1]=h;
		}
	lname= new char [i+1];
    f1.seekg (beg, ios::beg);
	f1.getline(lname,i+1,'\n');
	
	//if(c[0]=='E' && c[1]=='O' && c[2]=='F')
		//{
	//	cout<<"end of file found"<<endl;
	//	return -1;
		//}
		
	name.copy(lname);
	
	delete [] lname;
	counting=true;

       while (f1.get(h) && counting)
		{
		
		if(h!='\n')
		j++;
		else
			counting=false;

		}

	   f1.seekg(beg+i+2, ios::beg);
	lname= new char [j+1];
	grade2=new char [j+1];
	
	
	f1.getline(lname,j+1,'\n');
	
	memcpy(grade2,lname,j+1);
	long k(0),b(0),g(0), l(0),p(0);
	

long v(-1);
	
	for(i=0;i<5;i++)
		{
		

		num=0;
		p=k;
		
		do{
			h=grade2[k];
			k++;
			}while(h!=','&& h!='\0');
		
		l=k-p;
	
		if(i>0)
			{		
			
			for(g=0;g<l;g++,p++)
				{
				c[g]=grade2[p];
				}
			
			c[g-1]='\0';
			
			}
		
		else
			{
		
		for(b=0;b<k;b++)
			{
			c[b]=grade2[b];
			}
		c[b-1]='\0';
			}
  

	for(j=0;j<strlen(c);j++)
		{
	
		
		
		switch (c[j])
			{
			case '0':
				num*=10;
				break;
			case '1':
				num*=10;
				num+=1;
				break;
			case '2':
				num*=10;
				num+=2;
				break;
			case '3':
				num*=10;
				num+=3;
				break;
			case '4':
				num*=10;
				num+=4;
				//cout<<num<<endl;
				break;
			case '5':
				num*=10;
				num+=5;
				break;
			case '6':
				num*=10;
				num+=6;
				break;
			case '7':
				num*=10;
				num+=7;
				break;
			case '8':
				num*=10;
				num+=8;
				break;
			case '9':
				num*=10;
				num+=9;
				break;
			default:
				break;

			}
		
		}
	

	
	grades[i]=num;
		}
	
	

	delete [] grade2;
	delete [] lname;
	
	return f1.tellg();
	
	}



inline Student& Student::operator = (const Student & s)
	{
	name.copy (s.name);
	for(long i=0; i<5; i++)
		{
		grades[i]=s.grades[i];
		}
	return * this;
	}


inline Student::~Student()
	{
	}
inline Student::Student ()
	{
	}






































#endif
