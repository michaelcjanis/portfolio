#ifndef CLSDECL_H
#define CLSDECL_H


#include <string.h>
#include <memory.h>


class String
	{
	public:
		String ();
		String (const char *);
		String (const String &);

		void copy (const String &);
        void copy (const char* );
		long len ()const;
		void display ();
		bool compare (const String &);
		bool compare (const char*);
		void concat (String &);
		void concat (const char *);

	 




		~String ();

	private:
		char * pchar;
		long numchars;
	};







#endif 


