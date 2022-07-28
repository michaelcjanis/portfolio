//*****************************************************
// 
//	PROGRAM:   semester project >>> airline ticketing system
//	CLASS:		COSC 1436.S02
//	AUTHOR:		Michael Janis
//	DATE:		December 2, 2010
//
//*****************************************************

#include <iostream>


using namespace std;
#include "airlinefuncs.h"


;void main ()
	{	
	party   Party;
	plane	alpha;
	plane	bravo;
	plane	lounge;
	char *	command,*subcommand;
	bool	alphainitialized=false;
	bool	bravoinitialized=false;
	bool	loungeinitialized=false;
	bool    shutdown=false;
	bool    fly=false;
	bool    bravofilled=false;

	do{

	command = readcommand ();
	
	if (((_strcmpi(command, "alpha")==0)) && !alphainitialized)
		{

		alpha.c='A';
		alpha.numseats=readnumber ();
		alpha.numparties=0;
		alpha.numemptyseats=alpha.numseats;
		alphainitialized=true;		
		}
	
	else if (((_strcmpi(command, "bravo")==0)) && !bravoinitialized)
		{
		bravo.c='B';
		bravo.numseats=readnumber ();
		bravo.numemptyseats=bravo.numseats;
		bravo.numparties=0;
		bravoinitialized=true;
		}
   else if (((_strcmpi(command, "lounge")==0)) && !loungeinitialized)
		{
		lounge.c='L';
		lounge.numseats=readnumber ();
		lounge.numemptyseats=lounge.numseats;
		lounge.numparties=0;
		loungeinitialized=true;
		}
      else
		cout<< "invalid entery, please re-enter a command line"<<endl;
	delete [] command;
		}while (!alphainitialized    ||   !bravoinitialized   ||     !loungeinitialized);

	cout<< " aircraft and lounge successfully initialized"<<endl;

	do{
		command = readcommand ();

		
	     if (_strcmpi(command, "arrive")==0)
			{
			arriveparty (Party);
			
			if (Party.whichplane!= 'F')
				{				
            loadplane ( alpha, bravo, lounge, Party );
			delete [] Party.pPartyname;
				}			
			}
		else if (_strcmpi(command, "fly")==0)
			{
			subcommand=readcommand ();
			
			flycommand (subcommand, alpha, bravo);
				if (_strcmpi (subcommand,"alpha")==0)
					 refillalpha (lounge,alpha,fly);
				else if(_strcmpi (subcommand,"bravo")==0)
					 refillalpha (lounge,bravo,fly);
			delete [] subcommand;
				}
		else if (_strcmpi(command, "shutdown")==0)
			{
			cout<<" shutting down"<<endl;
			if (lounge.numparties>0)
				shutdownairline (lounge, alpha, bravo);
			else 
				{
				char * commands [2]={"alpha","bravo"};				
				flycommand (commands [0],alpha, bravo);
				flycommand (commands [1],alpha, bravo);
				}
			shutdown=true;
			}
		else 
		   cout<< "invalid entry...please re-enter a command"<<endl;
		
		delete [] command;
		if ((alpha.numemptyseats==0 || bravo.numemptyseats==0) && _strcmpi (command, "shutdown")!=0   && lounge.numparties>0)
			{
			autofly (alpha, bravo);
			if (alpha.numemptyseats==alpha.numseats )
					refillalpha (lounge, alpha,fly);

            if (bravo.numemptyseats==bravo.numseats)
					refillalpha(lounge, bravo,fly);
			}	
		else if((alpha.numemptyseats==0 || bravo.numemptyseats==0) && _strcmpi (command, "shutdown")!=0 && lounge.numparties==0)
			autofly (alpha, bravo);

		}while (!shutdown);
	}