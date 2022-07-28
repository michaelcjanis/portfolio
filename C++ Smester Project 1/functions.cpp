#include <iostream>
#include "airlinefuncs.h"

using namespace std;

#include <ctype.h>
#include <conio.h>


char *	readcommand ()
	{
	char * pnames;
	char  c;
	char * ptemp;
	long i (25),j(0),l(0),k=0;

	pnames=new char [i];

	while (!isspace(c=_getch()))
		{
		if (c<'0' || c>'9')
			{		
		
		_putch (c); 			
			
		 l++;
			
		pnames [ j]= c;
		
		j+=1;
			
		if (j==25)
			{
			i+=25;
			ptemp=new char [i];
			memcpy (ptemp, pnames, j);
			delete [] pnames;
			pnames=new char [i];
			
			memcpy (pnames, ptemp, j);
			delete [] ptemp;			
			}
		  }          
		}	
		
*(pnames +j)='\0';
if (c<'0'||c>'9')
_putch (c);
if (c=='\r')
cout<<endl;
return pnames;
	}

long readnumber ()
	{
	bool validop=1,signop=1;
	char c;
	long number(0), L3(10), numdecplaces (0);
	long numdigits (0), numdec (0), a(10), b, m=0;	

while (!isspace(c=_getch()) )
		{		
		switch (c)
			{
			case '-':
				if (numdigits==0)
					{
					signop=0;
					numdigits++;
					}
				else
					c='\a';
				break;
				
			
			case '0':
				if (numdigits==0)
					c='\a';          

			case '1':
			case '2':
			case '3':
            case '4':
			case '5':
			case '6':
			case '7':
            case '8':
			case '9':			
				
				 number = (number*10)+(c-'0');							
				  numdigits++;

				break;
			case '\b':
				if(numdigits>0)
					{
				
				_putch (c);
				_putch (' ');
				numdigits--;					
				
					b=number%10;
					
					if (b>0)
						
						number=(number-b)/10;
						
					else
						number/=10;					
									
					}
				else
					c='\a';
				break;
			default:
				c='\a';
				

				break;

			}
          
		_putch (c);

		}
        
		cout<<endl;	
		
		if (signop==0)
			number*=-1;		
		
  return number;
  }



void arriveparty (party & Party)
	{
	char*command;
	long i;
	bool cont=true;	
	bool init=false;
	
	command= readcommand ();
	
			     if (_strcmpi(command, "bravo")==0)
					 {
					 Party.whichplane='B';
					 init=true;
					 }

				 else if (_strcmpi(command, "alpha")==0)
					 {
					 Party.whichplane='A';
					 init=true;
					 }
				 else
					 {
					 cout<<endl;
					 cout<<"please reenter that command"<<endl;
					 cont=false;
					 init=true;
					 Party.whichplane='F';
					 }
			delete [] command;
			if (cont)
				{
			command=readcommand ();
			if(strlen (command)==0)
				{
				Party.whichplane='F';
				cout<<"please try again"<<endl;
				}
			else
				{
				i=readnumber ();
				
				if (i>0)
					{
				Party.pPartyname=new char [strlen (command)+1];
				memcpy (Party.pPartyname, command, strlen (command)+1);
			    Party.numpeople=i;
				
					}
				else 
					{
					cout<<"error"<<endl;
					Party.whichplane='F';
					}
				}
			delete [] command;
				}
			
		}




void loadplane (plane & alpha,plane & bravo, plane & lounge, party Party )
	{
	party * temp;
	long i;


	if (Party.whichplane=='A' && Party.numpeople<=alpha.numseats && Party.numpeople<=alpha.numemptyseats  )		
		{				
			alpha.numemptyseats-=Party.numpeople;				
                   
				 alpha.numparties+=1;
				
				 temp=new party [alpha.numparties];
				 if(alpha.numparties==1)
					 {
				     alpha.pParty=new party;
					 alpha.pParty->pPartyname=new char [strlen(Party.pPartyname)+1];
					 memcpy (alpha.pParty->pPartyname,Party.pPartyname,strlen (Party.pPartyname)+1);
					 alpha.pParty->numpeople=Party.numpeople;
					 cout<<alpha.pParty->pPartyname<< " party of "<< alpha.pParty->numpeople<<" boarded alpha "<<endl;
					 delete [] temp;

					 }
				 else
					 {
					 
					 for (i=0; i<alpha.numparties-1;i++)												
					    temp[i].pPartyname=new char [strlen(alpha.pParty[i].pPartyname)+1];					 	
                           	
					 for (i=0; i<alpha.numparties-1; i++)						 
					    memcpy (temp[i].pPartyname,alpha.pParty[i].pPartyname,strlen(alpha.pParty[i].pPartyname)+1);

					 for(i=0; i<alpha.numparties-1; i++)
						temp[i].numpeople=alpha.pParty[i].numpeople;
											 	 
					 for(i=0; i<alpha.numparties-1;i++)
						 delete [] alpha.pParty[i].pPartyname;

					 delete [] alpha.pParty;
					 
					 alpha.pParty=new party [alpha.numparties];

					 for(i=0; i<alpha.numparties-1;i++)
						 alpha.pParty[i].pPartyname=new char [strlen(temp[i].pPartyname)+1];

					 alpha.pParty[alpha.numparties-1].pPartyname=new char [strlen (Party.pPartyname)+1];

					 for(i=0; i<alpha.numparties-1;i++)
						 memcpy (alpha.pParty[i].pPartyname, temp[i].pPartyname, strlen (temp[i].pPartyname)+1);
						 					
					 memcpy (alpha.pParty[alpha.numparties-1].pPartyname,Party.pPartyname, strlen(Party.pPartyname)+1);					
				
					 for(i=0; i<alpha.numparties-1; i++)
						alpha.pParty[i].numpeople= temp[i].numpeople;						  	 

					 alpha.pParty[alpha.numparties-1].numpeople=Party.numpeople;

					 for (i=0; i<alpha.numparties-1; i++)
						 delete [] temp[i].pPartyname;
		 
					 delete [] temp;

					 cout<<alpha.pParty[alpha.numparties-1].pPartyname<< " party of "<< alpha.pParty[alpha.numparties-1].numpeople<<" boarded alpha " <<endl;    						
		         }
		      }

	else if (Party.whichplane=='A' && Party.numpeople>alpha.numseats)
                      cout<< Party.pPartyname <<" party of "<< Party.numpeople<<" was too large to fit in the plane"<<endl;

	else if (Party.whichplane=='B' && Party.numpeople<=bravo.numseats &&  Party.numpeople<=bravo.numemptyseats )		
		{			
			bravo.numemptyseats-=Party.numpeople;			
                   
				 bravo.numparties+=1;
				 
				 temp=new party [bravo.numparties];
				 if(bravo.numparties==1)
					 {
				     bravo.pParty=new party;
					 bravo.pParty->pPartyname=new char [strlen(Party.pPartyname)+1];
					 memcpy (bravo.pParty->pPartyname,Party.pPartyname,strlen (Party.pPartyname)+1);
					 bravo.pParty->numpeople=Party.numpeople;
					 cout<<bravo.pParty->pPartyname<< " party of "<< bravo.pParty->numpeople<<" boarded bravo "<<endl;
					 delete [] temp;

					 }
				 else
					 {
					 
					 for (i=0; i<bravo.numparties-1;i++)												
					      temp[i].pPartyname=new char [strlen(bravo.pParty[i].pPartyname)+1];						 	
                          	
					 for (i=0; i<bravo.numparties-1; i++)						 
						memcpy (temp[i].pPartyname,bravo.pParty[i].pPartyname,strlen(bravo.pParty[i].pPartyname)+1);

					 for(i=0; i<bravo.numparties-1; i++)
						 temp[i].numpeople=bravo.pParty[i].numpeople;
											 	 
					 for(i=0; i<bravo.numparties-1;i++)
						 delete [] bravo.pParty[i].pPartyname;

					 delete [] bravo.pParty;
					 
					 bravo.pParty=new party [bravo.numparties];

					 for(i=0; i<bravo.numparties-1;i++)
						 bravo.pParty[i].pPartyname=new char [strlen(temp[i].pPartyname)+1];

					 bravo.pParty[bravo.numparties-1].pPartyname=new char [strlen (Party.pPartyname)+1];

					 for(i=0; i<bravo.numparties-1;i++)
						memcpy (bravo.pParty[i].pPartyname, temp[i].pPartyname, strlen (temp[i].pPartyname)+1);

					 memcpy (bravo.pParty[bravo.numparties-1].pPartyname,Party.pPartyname, strlen(Party.pPartyname)+1);					
					
					 for(i=0; i<bravo.numparties-1; i++)
						 bravo.pParty[i].numpeople= temp[i].numpeople;						 

					 bravo.pParty[bravo.numparties-1].numpeople=Party.numpeople;

					 for (i=0; i<bravo.numparties-1; i++)
						 delete [] temp[i].pPartyname;
		 
					 delete [] temp;
					 cout<<bravo.pParty[bravo.numparties-1].pPartyname<< " party of "<< bravo.pParty[bravo.numparties-1].numpeople<<" boarded bravo " <<endl;
					 }
		         }
	else if (Party.whichplane=='B' && Party.numpeople>alpha.numseats)
		cout<< Party.pPartyname <<" party of "<< Party.numpeople<<" was too large to fit in the plane"<<endl;	

	else if (lounge.numemptyseats>=Party.numpeople)		
			{
			lounge.numemptyseats-=Party.numpeople;
			
			 lounge.numparties+=1;
				 
				 temp=new party [lounge.numparties];

				 if(lounge.numparties==1)
					 {
				     lounge.pParty=new party;
					 lounge.pParty->pPartyname=new char [strlen(Party.pPartyname)+1];
					 memcpy (lounge.pParty->pPartyname,Party.pPartyname,strlen (Party.pPartyname)+1);
					 lounge.pParty->numpeople=Party.numpeople;
					 lounge.pParty->whichplane=Party.whichplane;
					 cout<<lounge.pParty->pPartyname<< " party of "<< lounge.pParty->numpeople<<" was sent to the lounge "<<endl;
					 delete [] temp;
					 }
				 else
					 {					 
					 for (i=0; i<lounge.numparties-1;i++)						 					
						   temp[i].pPartyname=new char [strlen(lounge.pParty[i].pPartyname)+1];
						 		
					 for (i=0; i<lounge.numparties-1; i++)						 
					 memcpy (temp[i].pPartyname,lounge.pParty[i].pPartyname,strlen(lounge.pParty[i].pPartyname)+1);

					 for(i=0; i<lounge.numparties-1; i++)
						 {
						 temp[i].numpeople=lounge.pParty[i].numpeople;
						 temp [i].whichplane=lounge.pParty[i].whichplane;
						 }
					 	 
					 for(i=0; i<lounge.numparties-1;i++)
						 delete [] lounge.pParty[i].pPartyname;

					 delete [] lounge.pParty;
					 
					 lounge.pParty=new party [lounge.numparties];

					 for(i=0; i<lounge.numparties-1;i++)
						 lounge.pParty[i].pPartyname=new char [strlen(temp[i].pPartyname)+1];

					 lounge.pParty[lounge.numparties-1].pPartyname=new char [strlen (Party.pPartyname)+1];

					 for(i=0; i<lounge.numparties-1;i++)
						 memcpy (lounge.pParty[i].pPartyname, temp[i].pPartyname, strlen (temp[i].pPartyname)+1);
						 					
					 memcpy (lounge.pParty[lounge.numparties-1].pPartyname,Party.pPartyname, strlen(Party.pPartyname)+1);					
					
					 for(i=0; i<lounge.numparties-1; i++)
						 {
						lounge.pParty[i].numpeople= temp[i].numpeople;
						lounge.pParty[i].whichplane=temp[i].whichplane;
						 }	 	 

					 lounge.pParty[lounge.numparties-1].numpeople=Party.numpeople;

					 lounge.pParty[lounge.numparties-1].whichplane=Party.whichplane;

					 for (i=0; i<lounge.numparties-1; i++)
						 delete [] temp[i].pPartyname;
		 
					 delete [] temp;
					 cout<<lounge.pParty[lounge.numparties-1].pPartyname<< " party of "<< lounge.pParty[lounge.numparties-1].numpeople<<" was sent to the lounge  " <<endl;
					 }
			    }
	else
		cout << Party.pPartyname <<" was unable to fit and sent away"<<endl;		
	}




void flycommand (char * whichplane,plane & alpha, plane & bravo)
	{
	long i;
	cout<<endl;

			if (_strcmpi (whichplane, "alpha")==0 && alpha.numemptyseats<alpha.numseats)
				{
				cout<< " parties: "<<endl;
				if (alpha.numparties>0)
					{
					for(i=0; i<alpha.numparties; i++)								
						cout<<alpha.pParty[i].pPartyname<<" "<<alpha.pParty[i].numpeople<<endl;
					}
				else
					cout<<alpha.pParty->pPartyname<<" "<<alpha.pParty->numpeople<<endl;
				alpha.numemptyseats=alpha.numseats;
				alpha.numparties=0;
				for (i=0; i<alpha.numparties; i++)
					delete [] alpha.pParty[i].pPartyname;
				delete [] alpha.pParty;
				 cout <<" departed on alpha "<<endl;
				}

		 else if (_strcmpi (whichplane, "bravo")==0 && bravo.numemptyseats<bravo.numseats)
				{
				cout<< " parties: "<<endl;
				if(bravo.numparties>0)
					{
					for(i=0; i<bravo.numparties; i++)						
						cout<<bravo.pParty[i].pPartyname<<" "<<bravo.pParty[i].numpeople<<endl;
					}
				else
					cout<<bravo.pParty->pPartyname<<" "<<bravo.pParty->numpeople<<endl;
				bravo.numemptyseats=bravo.numseats;
				bravo.numparties=0;

				for (i=0; i<bravo.numparties; i++)
					delete [] bravo.pParty[i].pPartyname;

				delete []bravo.pParty;
				cout<<" departed on bravo "<<endl;
				}
			else 
				cout <<" sorry, plane could not fly" <<endl;
	}




void autofly (plane & alpha, plane & bravo)
	{
	long i;
	cout<<endl;

			if (alpha.numemptyseats==0)
				{
				cout<< " parties: "<<endl;
				if (alpha.numparties>0)
					{
				for(i=0; i<alpha.numparties; i++)					
					cout<<alpha.pParty[i].pPartyname<<" "<<alpha.pParty[i].numpeople<<endl;
					}
				else
					cout<<alpha.pParty->pPartyname<<" "<<alpha.pParty->numpeople<<endl;
				alpha.numemptyseats=alpha.numseats;
				alpha.numparties=0;

				for (i=0; i<alpha.numparties; i++)
					delete [] alpha.pParty[i].pPartyname;

				delete [] alpha.pParty;
				 cout <<" departed on alpha "<<endl;
				}

		if (bravo.numemptyseats==0)
				{
				cout<< " parties: "<<endl;
				if (bravo.numparties>0)
					{
				for(i=0; i<bravo.numparties; i++)									
					cout<<bravo.pParty[i].pPartyname<<" "<<bravo.pParty[i].numpeople<<endl;					
					}
				else
					cout<<bravo.pParty->pPartyname<<" "<<bravo.pParty->numpeople<<endl;
				bravo.numemptyseats=bravo.numseats;
				bravo.numparties=0;

				for (i=0; i<bravo.numparties; i++)
					delete [] bravo.pParty[i].pPartyname;

				delete [] bravo.pParty;
				 cout <<" departed on bravo "<<endl;
				}
	}



void refillalpha (plane & lounge , plane & alpha, bool & canprint)
	{
     long i,k,j=0,l;
	party * temp;
	char c;
	c=alpha.c;
	l=alpha.numparties;
	
	for (k=0;k<lounge.numparties;k++)
		{

			if (lounge.pParty[k].whichplane== c)
				{
				
					if(lounge.pParty[k].numpeople<= alpha.numemptyseats)
								{
								alpha.numemptyseats-=lounge.pParty[k].numpeople;								

						                   
								 alpha.numparties+=1;
								lounge.numparties-=1;
								lounge.numemptyseats+=lounge.pParty[k].numpeople;
								temp=new party [alpha.numparties];
					    if(alpha.numparties==1) // major loop
											 {
											 alpha.pParty=new party;
											 alpha.pParty->pPartyname=new char [strlen(lounge.pParty[k].pPartyname)+1];
											 memcpy (alpha.pParty->pPartyname,lounge.pParty[k].pPartyname,strlen (lounge.pParty[k].pPartyname)+1);
											 alpha.pParty->numpeople=lounge.pParty[k].numpeople;
											
											 delete [] temp;
						
											 }
								 else
											 {
											 
											 for (i=0; i<alpha.numparties-1;i++)												 								
											         temp[i].pPartyname=new char [strlen(alpha.pParty[i].pPartyname)+1];									 	
													
											 for (i=0; i<alpha.numparties-1; i++)												 
											         memcpy (temp[i].pPartyname,alpha.pParty[i].pPartyname,strlen(alpha.pParty[i].pPartyname)+1);

											 for(i=0; i<alpha.numparties-1; i++)
												     temp[i].numpeople=alpha.pParty[i].numpeople;
												 											 	 
											 for(i=0; i<alpha.numparties-1;i++)
												     delete [] alpha.pParty[i].pPartyname;

											 delete [] alpha.pParty;
						 
											 alpha.pParty=new party [alpha.numparties];

											 for(i=0; i<alpha.numparties-1;i++)
												     alpha.pParty[i].pPartyname=new char [strlen(temp[i].pPartyname)+1];
											 alpha.pParty[alpha.numparties-1].pPartyname=new char [strlen (lounge.pParty[k].pPartyname)+1];
						
											 for(i=0; i<alpha.numparties-1;i++)
												 	 memcpy (alpha.pParty[i].pPartyname, temp[i].pPartyname, strlen (temp[i].pPartyname)+1);
																							
											 memcpy (alpha.pParty[alpha.numparties-1].pPartyname,lounge.pParty[k].pPartyname, strlen(lounge.pParty[k].pPartyname)+1);
											
											
											 for(i=0; i<alpha.numparties-1; i++)												
												     alpha.pParty[i].numpeople= temp[i].numpeople;
												 							 	 

											 alpha.pParty[alpha.numparties-1].numpeople=lounge.pParty[k].numpeople;

											 for (i=0; i<alpha.numparties-1; i++)
												     delete [] temp[i].pPartyname;
								 
											 delete [] temp;									      
											
												
											 }
								 if (k==0)
													{
												temp=new party [lounge.numparties];

												   for (i=1; i<lounge.numparties+1; i++)
	  									                {						
																	 temp[i-1].pPartyname=new char [strlen (lounge.pParty[i].pPartyname)+1];

																	 memcpy (temp[i-1].pPartyname, lounge.pParty[i].pPartyname, strlen (lounge.pParty[i].pPartyname)+1);
																	 temp[i-1].numpeople=lounge.pParty[i].numpeople;
																	 temp[i-1].whichplane=lounge.pParty[i].whichplane;
														  }
												   for (i=0;i<lounge.numparties+1; i++)
													   {
													   delete [] lounge.pParty[i].pPartyname;
													   }
												   delete lounge.pParty;

				                                        lounge.pParty=new party [lounge.numparties];

														 for(i=0; i<lounge.numparties; i++)
															 {
																				 lounge.pParty[i].pPartyname=new char [strlen (temp[i].pPartyname)+1];
																				 memcpy (lounge.pParty[i].pPartyname, temp[i].pPartyname, strlen (temp[i].pPartyname)+1);
																				 lounge.pParty[i].numpeople=temp[i].numpeople;
																				 lounge.pParty[i].whichplane=temp[i].whichplane;
															 }
														  for (i=0;i<lounge.numparties; i++)
											 					 delete [] temp[i].pPartyname;
											 
										                  delete [] temp;													
											
												}
								 else if (lounge.numparties==1)
											 {
												   if (k==0)
													 {
															 delete [] lounge.pParty[k].pPartyname;
																lounge.pParty[k].pPartyname=new char [strlen (lounge.pParty[k+1].pPartyname)+1];
																memcpy (lounge.pParty[k].pPartyname,lounge.pParty[k+1].pPartyname, strlen (lounge.pParty[k+1].pPartyname)+1);
																lounge.pParty[k+1].numpeople=lounge.pParty[k].numpeople;
																lounge.pParty[k+1].whichplane=lounge.pParty[k].whichplane;

															delete [] lounge.pParty[k+1].pPartyname;
													
													 }
												   else if (k==1)	
													 			delete [] lounge.pParty[k].pPartyname;
												
											}
						    
						else if (k>0)// nested loop
							                  {
										  temp=new party [lounge.numparties];

										   for (i=0; i<k+1; i++)
											     {
															 temp[i].pPartyname=new char [strlen (lounge.pParty[i].pPartyname)+1];

															 memcpy (temp[i].pPartyname, lounge.pParty[i].pPartyname, strlen (lounge.pParty[i].pPartyname)+1);
															 temp[i].numpeople=lounge.pParty[i].numpeople;
															 temp[i].whichplane=lounge.pParty[i].whichplane;
											      }										

									    for(;i<lounge.numparties+1; i++)
											 {
															temp[i-1].pPartyname=new char [strlen (lounge.pParty[i].pPartyname)+1];

			    											 memcpy (temp[i-1].pPartyname, lounge.pParty[i].pPartyname, strlen (lounge.pParty[i].pPartyname)+1);
															 temp[i-1].numpeople=lounge.pParty[i].numpeople;
															 temp[i-1].whichplane=lounge.pParty[i].whichplane;
											 }
										 for (i=0; i< lounge.numparties+1;i++)
											                 delete [] lounge.pParty[i].pPartyname;
											 
										 delete [] lounge.pParty;

										 lounge.pParty=new party [lounge.numparties];

										 for(i=0; i<lounge.numparties; i++)
											 {
																 lounge.pParty[i].pPartyname=new char [strlen (temp[i].pPartyname)+1];
																 memcpy (lounge.pParty[i].pPartyname, temp[i].pPartyname, strlen (temp[i].pPartyname)+1);
																 lounge.pParty[i].numpeople=temp[i].numpeople;
																 lounge.pParty[i].whichplane=temp[i].whichplane;
											 }
										 
										 for (i=0;i<lounge.numparties; i++)
											 					 delete [] temp[i].pPartyname;
											 
										 delete [] temp;

								          }// goes with nested loop
			
						
                          k-=1;

								  }//  new goes with major loop
							}// end of if statements loop
					
			 }//end of for loop
	 if (canprint==true)
				 {
		if (c=='A')
			{
		
		for (i=0; i<alpha.numparties; i++)
			cout<< alpha.pParty[i].pPartyname<< " party of "<<alpha.pParty[i].numpeople<< " boarded alpha" <<endl;
			}
           else 
			{
			for (i=0; i<alpha.numparties; i++)
			cout<< alpha.pParty[i].pPartyname<< " party of "<<alpha.pParty[i].numpeople<< " boarded bravo" <<endl;
				 }
				 }
	 else if (alpha.numparties>0)
				 {
				 if(c=='A')
					 {			
			 for (i=l; i<alpha.numparties; i++)
			cout<< alpha.pParty[i].pPartyname<< " party of "<<alpha.pParty[i].numpeople<< " boarded alpha" <<endl;
			
				 }
			 else
				 {
				for (i=l; i<alpha.numparties; i++)
			cout<< alpha.pParty[i].pPartyname<< " party of "<<alpha.pParty[i].numpeople<< " boarded bravo" <<endl;
			
			    }
		    }  

	}



void shutdownairline (plane & lounge, plane & alpha, plane & bravo)
	{	
	bool canprint;
	char * commands [2] = {"alpha","bravo"};

	while (lounge.numparties>0)
		{
		if (alpha.numemptyseats==0)
			{
			canprint=true;
			flycommand (commands[0],alpha,bravo);
            refillalpha (lounge,alpha,canprint);
			}
		else 
			{
			canprint=false;
			refillalpha (lounge,alpha,canprint);
			flycommand (commands [0], alpha, bravo);			
			}

		if (bravo.numemptyseats==0)
			{	
			canprint=true;
			flycommand (commands[1],alpha,bravo);
            refillalpha (lounge,bravo,canprint);
			}
		else 
			{
			canprint=false;
			refillalpha (lounge,bravo,canprint);
			flycommand (commands [1], alpha, bravo);
			}		
		}
	}


