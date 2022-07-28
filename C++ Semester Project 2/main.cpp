#include <iostream>



#include <fstream>

#include "Std_rec_Array.h"


using namespace std;

void main ()
	{
	String  filename;
	char* temp;
	int num(0);
	fstream  file;
	
	
	
StudentArray      sa1;






cout<<"please name the file: ";

filename.read();

temp=new char[filename.len()];

int i;
for (i=0; i<filename.len(); i++)
	{
	temp[i]=filename[i];
	
	}
cout<<temp<<endl;


file.open(temp, ios_base::out);
  

sa1.copy_S("smith","25,36,89,13,100","123456789","972 7891234","frank","alfred","smith","11014 cr 290","mckinney","tx","23456",0);
sa1.copy_S("franklin","45,78,67,90,55","132156784","972 7891234","john","larken","franklin","11014 cr 290","dallas","tx","23456",1);
sa1.copy_S("lamp","11,12,43,78,87","234533657","972 7891234","nietche","jaques","lamp","11014 cr 290","frisco","tx","23456",2);
sa1.copy_S("mconnel","56,23,100,19,23","123465235","972 7891234","mitch","larken","mconnel","11014 cr 290","blueridge","tx","23456",3);


cout<<"\n\n\n the students read in(hardcoded): "<<endl;

sa1.display();


sa1.sort_ID();

cout<<"\n\n\n after sorting by ID : "<<endl;

sa1.display();

sa1.sort_name();

cout<<"\n\n\n after sorting by Name : "<<endl;
cout<<endl;

sa1.display();



num=0;
cout<<"\n\n\n writing student information to file........"<<endl;

num=sa1.write_Array(file,num);

file.close();


file.open(temp, ios_base::in);

num=0;
num=sa1.read_Array(file,num);


cout<<"\n\n\n after reading the information from the file location originaly provided: "<<endl;
cout<<endl;

sa1.display();




	
	



	file.close();


	

	delete [] temp;

	}