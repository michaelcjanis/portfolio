#ifndef AIR_LINE_FUNCS_H
#define AIR_LINE_FUNCS_H


char *	readcommand ();
long readnumber ();


struct party
	{
	char * pPartyname;
	long   numpeople;
	char  whichplane;


	};
struct plane
	{
	char c;
	long numseats;
	long numparties;
	long numemptyseats;
	 party * pParty;
	 char * pnames;
	};

void arriveparty (party &);
void loadplane (plane & alpha,plane & bravo, plane & lounge, party Party );
void flycommand (char * , plane & , plane & );
void autofly ( plane & , plane & );
void shutdownairline (plane & , plane & , plane & );
void refillalpha (plane & , plane &, bool &);

#endif 