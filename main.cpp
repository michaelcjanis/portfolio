//*****************************************************
// 
//	PROGRAM:   1st lab >>> String class
//	CLASS:		COSC 1437.S01
//	AUTHOR:		Michael Janis
//	DATE:		February 3, 2011
//
//***************************************************** 
#include <iostream>

using namespace std;

#include "clsdecl.h"

void main ()
	{


String class3;
String class8;
string class5;
String class9;
String  class1("abcdefg");
String class2(class1);

class1.display ();
class2.display();

char* test="testing123";
class3.copy(class1);

class9.copy (test);


class9.display ();

cout<<class1.len()<<endl;



bool i=false;

i=class3.compare(class1);
cout<<i<<endl;

char* temp="abcdefghij";

i=class8.compare (temp);
cout<<i<<endl;


class3.concat(class1);

class3.display ();

class2.concat(temp);

class2.display ();

	}