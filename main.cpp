/**************************************************************************************************
 *     Program name: Archer's Paradox                                                    	    				*
 *	    Programmer name: Wesley Gue									                                                      	*
 *                                                                                                *
 *                                                                                                *
 *     Last Updated: December 9th 2013 4:00AM                                                     *
 *                                                                                                *
 *          Details: This program takes user input and makes a profile for them while asking      *
 *                   the user questions to determine thier arrow spine.                           *
 *                                                                                                *
 *                                                                                                *
 *                                                                                                *
 **************************************************************************************************/

// various headers needed for this program.
#include <iostream>                    
#include <string>                  
#include <vector>                 
#include <algorithm>             
#include <cstring>              
#include <ctype.h>               
#include <fstream>            
#include <iostream>           
#include <cstdlib>            
#include <iomanip>          
#include <cmath>           
#include <vector>          
#include <cstring>         
#include <stdio.h>       
#include <string.h>     
#include <sstream>     
using namespace std;

// struct is for storing the profile
struct profile{     
    //used for storing archer's name                 
    string archername;   
    // used for storing archer's draw length          
	float drawlength;   
	// used for storing archer's draw length          
	float drawweight;	
	// used for storing archer's bow type       
	string bowtype;  
	// used for storing archer's arrow spine             
	string archersspine;         
	 
	 
	 
}* pointer = new profile[50];

// used for array sizes and list sizes   
const int MAX=50;

// * Function Index *
// prints a menu for the user to navigate the program.
void printmenu();
// uses to determine what function to run bases on user input.                                                                                                               
void choice(string archers,float draw,float poundage,string bow,int& counter,int& scounter,const int MAX,int& tester);  
// used to create archer profiles.               
void create(string,float,float,string,int&,int&);  
// used to calculate the archer's spine.                                                                           
void spine(string,float,float,string,int&);	 
// used to save the profile list                                                                                                                   
void save(int& counter,int& scounter);
// used to open the files filled with profiles.                                                                                                                         
void open(int& counter,const int MAX);
// used for displaying the list of profiles.                                                                                                                        
void display(int& counter);   
// used to edit profiles.                                                                                                                               
void edit(int& counter);   
// used to delete profiles.                                                                                                                                 
void thedelete(int& counter);	
// used to find a profile.																													      
void find(int& counter);  
// used to check if list is empty.                                                                                                                                
bool check(int& counter);            
// used to add a profile to the list.                            																							 
void add(string archers,float draw,float poundage,string bow,int& counter);     
// used to sort the list by ether the name or draw length.                                                                                                                                                             
void thesort(int& counter,const int MAX); 	
// displays a menu that uses vectors to display information on the programm.																										   
void info(); 			
// used to quit the program.    																														     
void quit(int& tester);                                                                                                                                                                                                                                                                                                                                                                                              																																																					
																																																										
                                                                                


//MAIN FUNCTION
int main(){
	

	
	//  For storing struct storing information
	string archers;         
	float draw =0;        
	float poundage =0;    
	string bow;          
	string thespine;     
	
	// For keeping track of how many profiles are in the struct array
	int counter=0;  
	// For the sort function    
	int scounter=0;    
	
	//for display functions
	string fullname[50];
	float d[50];
	float p[50];
	string bowt[50];
	string s[50];
  int tester=0;



  	//  Initial Greeting 
    cout<<"Welcome to the \"Archer Paradox\""<<endl;            
    cout<<" Please choose one of the following"<<endl<<endl;   
  

      // loop used to keep the menu going until the user wants to quit.
      while(tester ==0){                                                              
	    printmenu();                                                               
	    choice(archers,draw,poundage,bow,counter,scounter,MAX,tester);           
	    cout<<"Want to Continue? 0=Yes/1=No: ";                                 
    	cin>>tester;                                                            
      }                                                                        
	    if (tester==1){                                                      
	    system("CLS");                                                        
	    system("PAUSE");                                                  
	    return EXIT_SUCCESS;	                                        
   	  }                                                                   
	
	
	
}

//printmenu FUNCTION
void printmenu()
{
	
	
  

  
  // Menu that gets printed to the screen
  cout<<"(1) = Create Profiles"<<endl;                                                
  cout<<"(2) = Open Profiles"<<endl;                                              
  cout<<"(3) = Save Progile"<<endl;                                               
  cout<<"(4) = Add Profile"<<endl;                                              
  cout<<"(5) = Display Profiles"<<endl;                                       
  cout<<"(6) = Edit Profile"<<endl;                                             
  cout<<"(7) = Sort Profile List"<<endl;                                       
  cout<<"(8) = Delete Profile"<<endl;                                          
  cout<<"(9) = Search for Profile"<<endl;                                  
  cout<<"(10)= Information about \"Archers Paradox\""<<endl;               
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;                                  
  cout<<"Enter your Choice: ";                                         
  
}


//choice FUNCTION
void choice(string archers,float draw,float poundage,string bow,int& counter,int& scounter,const int MAX,int& tester){
	
	// switch statement that uses the menu input
	int option = 0;                                                                           
	cin>> option;                                                                           
	  if(option >0 && option < 11){                                                    
	    switch(option){                                                                
		                                                                         
	    case 1: create(archers,draw,poundage,bow,counter,scounter);break;               
	    case 2: open(counter,MAX);break;                                             
      case 3: save(counter,scounter);break;                                           
      case 4: add(archers,draw,poundage,bow,counter);break;                         
      case 5: display(counter);break;	                                            
	    case 6: edit(counter);break;                                             
	    case 7: thesort(counter, MAX);break;	                                 
      case 8: thedelete(counter);break;                                     
      case 9: find(counter);break;												
      case 10:info();break;							     				  	
                                                                            
	    }
    }
    else{
    	// lets the user know they picked a wrong choice.
      cout<<"You muxt pick a number between 1 and 12"<<endl;   
        // reprints the menus.        
	    printmenu();	                                                  
    }
}


//create FUNCTION
void create(string archers,float draw,float poundage,string bow,int& counter,int& scounter){
	
	//getting archer's name
	string firstName;      //to get first name
	string lastName;      //to get last name
  char thebow;

	//getting first and last name
	cout<<"Please enter the Archer's first name: ";
	cin>>firstName;
	cout<<endl<<"Please enter the Archer's last name: ";
	cin>>lastName;
	
	//putting first and last name together with last name first.
	archers=lastName+", "+firstName;
	cout<<endl<<"Your name will be stored as: "<<archers<<endl;
	
	//getting Draw Length
	cout<<endl<<"Please enter your Draw Length: ";
	cin>>draw;
	cout<<endl<<"Your answer will be stored as: "<<draw<<endl;
	
	
	// Getting Draw weight
	cout<<endl<<"Please enter the Poundage you bow is set at: ";
	cin>>poundage;
	cout<<endl<<"Your answer will be stored as: "<<poundage<<endl;
	
	
	//getting bow type
	  while(true){
	  cout<<" Choose which bow best describes yours from the following: "<<endl
	      <<"R = Recurve"<<endl
	      <<"L = Longbow"<<endl
	      <<"C = Compound"<<endl;
	      cin>>thebow;
	      cout<<endl<<"You chose: "<<thebow<<endl;
	    
  	// makes sure the choice is valid
    if ( thebow=='R' || thebow=='L' || thebow=='C' || thebow=='r' || thebow=='l' 
      || thebow=='c')
    break;	
    }
  // naming the bow type
	if(thebow == 'r' || thebow == 'R') bow="Recurve";
	if(thebow == 'l' || thebow == 'L') bow="Longbow";
	if(thebow == 'c' || thebow == 'C') bow="Compound";
	cout<<"Arrow spine will not be calculated if poundage isn't betweeen 30 and 75 and your draw length between 22 and 32"<<endl<<endl;
	//run the spine function
	spine(archers,draw,poundage,bow,counter);	
	save(counter,scounter);
}

//spine FUNCTION
void spine(string archers,float draw,float poundage,string bow,int& counter){

  string thespine;
  
  float adraw= draw+1.5;
  // 600 spine chart
  if(poundage <= 30 && poundage <= 35 && adraw >=22 && adraw <=29.5) thespine= "1535/600";
  if(poundage <= 35 && poundage <= 40 && adraw >=22 && adraw <=28.5) thespine= "1535/600";
  if(poundage <= 40 && poundage <= 45 && adraw >=22 && adraw <=26.5) thespine= "1535/600";
  if(poundage <= 45 && poundage <= 50 && adraw >=22 && adraw <=24.5) thespine= "1535/600";
  if(poundage <= 50 && poundage <= 55 && adraw >=22 && adraw <=23.5) thespine= "1535/600";
  
  // 500 spine chart
  if(poundage <= 30 && poundage <= 35 && adraw >= 29.5 && adraw <=32) thespine= "3555/500";
  if(poundage <= 35 && poundage <= 40 && adraw >=28.5 && adraw <=31.5) thespine="3555/500";
  if(poundage <= 40 && poundage <= 45 && adraw >=26.5 && adraw <=29.5) thespine="3555/500";
  if(poundage <= 45 && poundage <= 50 && adraw >=24.5 && adraw <=27.5) thespine="3555/500";
  if(poundage <= 50 && poundage <= 55 && adraw >=22.5 && adraw <=24.5) thespine="3555/500";
  if(poundage <= 60 && poundage <= 65 && adraw >=23 && adraw <=23.5) thespine="3555/500";
 
  // 400 spine chart
  if(poundage <= 35 && poundage <= 40 && adraw >= 31.5 && adraw <=31.5) thespine="5575/400";
  if(poundage <= 40 && poundage <= 45 && adraw >=29.5 && adraw <=32) thespine="5575/400";
  if(poundage <= 45 && poundage <= 50 && adraw >=27.5 && adraw <=32) thespine="5575/400";
  if(poundage <= 50 && poundage <= 55 && adraw >=25.5 && adraw <=30.5) thespine="5575/400";
  if(poundage <= 55 && poundage <= 60 && adraw >=24.5 && adraw <=28.5) thespine="5575/400";
  if(poundage <= 60 && poundage <= 65 && adraw >=23.5 && adraw <=26.5) thespine="5575/400";
  if(poundage <= 65 && poundage <= 70 && adraw >=22.5 && adraw <=25.5) thespine="5575/400";
  if(poundage <= 70 && poundage <= 75 && adraw >=22 && adraw <=24.5) thespine="5575/400";
  
  // 340 spine chart
  if(poundage <= 50 && poundage <= 55 && adraw >= 30.5 && adraw <=32) thespine="7596/340";
  if(poundage <= 55 && poundage <= 60 && adraw >=28.5 && adraw <=32) thespine="5575/400";
  if(poundage <= 60 && poundage <= 65 && adraw >=26.5 && adraw <=31.5) thespine="5575/400";
  if(poundage <= 65 && poundage <= 70 && adraw >=25.5 && adraw <=29.5) thespine="5575/400";
  if(poundage <= 70 && poundage <= 75 && adraw >=24.5 && adraw <=27.5) thespine="5575/400";
  
/********************************************************************
 * With the next update to "Archers Paradox" will have:             *
 *  more specialized arrow charts that cover the more extream case. *
 *  There will also be arrow tuning menus. As well as sight tuning  *
 *  menus and rest tuning menus                                     *
 ********************************************************************/
 
	//storing the information in a struct
	
	
	pointer[0].archername=archers;
	pointer[0].drawlength=draw;
	pointer[0].drawweight=poundage;
	pointer[0].bowtype=bow;
	pointer[0].archersspine=thespine;
	counter=1;
	
	
}

// save FUNCTION
void save(int& counter,int& scounter){

string filename;
// gets the file name.
cout<<"Please Enter the name of the file to write to.\n";               
cout<<"File Name: ";									    	     
cin>>filename;                                                       
   // checks if file exsist then askes if user
  ifstream ifile(filename.c_str());                                                                    
if (ifile) {																					    	
	char answer;      																																				
	cout<<"The File: \""<<filename<<"\" already exsist. Do you wish to overwrite it? Y/N:";        
	cin>>answer;																																										
	if(answer=='N' || answer =='n'){																																 
	exit;	                                                                                        
	}

}
  // Writes the information to the file
ofstream writetofile(filename.c_str());           																																																									 
                                                       																																																					 
for(int i=0;i<=counter-1;i++){  																																																																		 
writetofile<<pointer[i].archername<<endl<<pointer[i].drawlength<<endl<<pointer[i].drawweight<<endl<<pointer[i].bowtype<<endl<<pointer[i].archersspine<<endl;        //   |
scounter++;																																																																												 
}																																																																															
counter=scounter;																																																																								
}																																																																														

//open FUNCTION
void open(int& counter,const int MAX){
	
	// varibles to store profile info
	string filename;                                 
	string name1[MAX];
	string name2[MAX];
	string fullname[MAX];
	float d[MAX];
	float p[MAX];
	string bowt[MAX];
	string s[MAX];
	
	
	//asks user what what file they want to open 
	ifstream readfile;
	cout<<"What file do you want to open?\n";
	cout<<"File Name: ";
	cin>>filename;
	readfile.open(filename.c_str());                 
	
	
	//checks if file exsist
	  if(!readfile.is_open()){
	   cout<<"File does not exsist"<<endl;
	  }
    else{
	    for(int i=0;readfile.good();i++){
	    readfile>>name1[i]>>name2[i]>>d[i]>>p[i]>>bowt[i]>>s[i];
	    fullname[i]=name1[i]+" "+name2[i];
      pointer[i].archername=fullname[i];
	    pointer[i].drawlength=d[i];
	    pointer[i].drawweight=p[i];
	    pointer[i].bowtype=bowt[i];
	    pointer[i].archersspine=s[i];
	    counter++;
      }
    }
}


//display FUNCTION
void display(int& counter){
	
	//displays the profiles
	for(int i=0; i<=counter-1;i++){
	cout<<"Archer's Name: "<<pointer[i].archername<<endl;
	cout<<"  Draw Length: "<<pointer[i].drawlength<<endl;
  cout<<"  Draw Weight: "<<pointer[i].drawlength<<endl;
	cout<<"     Bow Type: "<<pointer[i].bowtype<<endl;
	cout<<"  Arrow Spine: "<<pointer[i].archersspine<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
  }	
}



// edit FUNCTION
void edit(int& counter){
	
	//varibles for profile info
	int answer=0;
	int storeanswer=0;
	string lastName;
	string firstName;
	string thearcher;
	float newdraw=0;
	float newpoundage=0;
	string newbowtype;
	string newspine;
	
	
	//displays archer names and gets the part of the profile you want to edit
	for(int i=0; i<=counter-1;i++){
	  cout<<"("<<i+1<<")"<<"Archer's Name: "<<pointer[i].archername<<endl;
  }
	cout<<"Enter the number you want to Edit: ";
	cin>>answer;
	
	cout<<"(1)"<<"Archer's Name: "<<pointer[answer-1].archername<<endl;
	cout<<"(2)"<<"  Draw Length: "<<pointer[answer-1].drawlength<<endl;
  cout<<"(3)"<<"  Draw Weight: "<<pointer[answer-1].drawlength<<endl;
	cout<<"(4)"<<"     Bow Type: "<<pointer[answer-1].bowtype<<endl;
	cout<<"(5)"<<"  Arrow Spine: "<<pointer[answer-1].archersspine<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<"Enter the number you want to Edit: ";
 cin>>storeanswer;
 
 // change name
  if(storeanswer==1){
   
    cout<<"Please enter the Archer's first name: ";
	  cin>>firstName;
	  cout<<endl<<"Please enter the Archer's last name: ";
	  cin>>lastName;
	
	  //putting first and last name together with last name first.
	  thearcher=lastName+", "+firstName;
	  cout<<endl<<"Your name will be stored as: "<<thearcher<<endl;
  	pointer[answer-1].archername=thearcher;
  }
  
  
  // change draw lengths
  if(storeanswer==2){
  	
  	//getting Draw Length
	  cout<<endl<<"Please enter your Draw Length: ";
	  cin>>newdraw;
	  cout<<endl<<"Your answer will be stored as: "<<newdraw<<endl;
  	pointer[answer-1].drawlength=newdraw;
  }
  
  if(storeanswer==3){
  	
  	
  	// Getting Draw weight
	  cout<<endl<<"Please enter the Poundage you bow is set at: ";
	  cin>>newpoundage;
	  cout<<endl<<"Your answer will be stored as: "<<newpoundage<<endl;
  	pointer[answer-1].drawweight=newpoundage;	
  }
  
  if(storeanswer==4){
  	
  	cout<<"Enter the type of bow you have (Recurve,Longbow,Compound): ";
  	cin>>newbowtype;
  	pointer[answer-1].bowtype=newbowtype;
  	
  }
  
  if (storeanswer==5){
  	
  	cout<<"Enter the Arrow Spine: ";
  	cin>>newspine;
  	pointer[answer-1].archersspine=newspine;
  	
  }
}

// delete FUNCTION
void thedelete(int& counter){          

    // Displays the archer's name then asks you for the number  
    // representing the namse you want to delete.
	int answer=0;																																			 
	for(int i=0; i<=counter-1;i++){																										
	  cout<<"("<<i+1<<")"<<"Archer's Name: "<<pointer[i].archername<<endl;					
  }																																							
	cout<<"Enter the number you want to Delete: ";																
	cin>>answer; 																																
	                    																												
	for (int i = answer; i < counter; i++){                                   
  pointer[i-1].archername = pointer[i].archername;                         
  pointer[i-1].drawlength = pointer[i].drawlength;                       
  pointer[i-1].drawweight = pointer[i].drawweight;                       
  pointer[i-1].bowtype = pointer[i].bowtype;                            
  pointer[i-1].archersspine = pointer[i].archersspine;                  
																																			
  }																																		
counter--;																													
	                                                                
}                                                                 

// find FUNCTION
void find(int& counter)
{
	
	  //checks if list is empty 
    if(check(counter)){
    	cout<<"The list is empty."<<endl;
    }
  // searches for the location of the name
  else
  {
    string target;
    string ping;
    
    cout << "Enter the name you are searching for: ";
    cin >> target;
    for (int i = 0; i <= counter ;i++)
    {
    ping =	pointer[i].archername;
      if (ping == target)
      {
        cout << "name  found at location " << i << endl;  
       return;
      }
    }
    
  }
 
}

//check Function
bool check(int& counter)
{
  bool test = true;
  for (int i = 0; i < counter; i++)
  {
    if (pointer[i].archername != "null")
    {
      test = false;
      return test;
    }
  }
  return test;
}

//add FUNCTION
void add(string archers,float draw,float poundage,string bow,int& counter){
	
	//getting archer's name
	string firstName;      
	string lastName;      
  char thebow;

	//getting first and last name
	cout<<"Please enter the Archer's first name: ";
	cin>>firstName;
	cout<<endl<<"Please enter the Archer's last name: ";
	cin>>lastName;
	
	//putting first and last name together with last name first.
	archers=lastName+", "+firstName;
	cout<<endl<<"Your name will be stored as: "<<archers<<endl;
	
	//getting Draw Length
	cout<<endl<<"Please enter your Draw Length: ";
	cin>>draw;
	cout<<endl<<"Your answer will be stored as: "<<draw<<endl;
	
	
	// Getting Draw weight
	cout<<endl<<"Please enter the Poundage you bow is set at: ";
	cin>>poundage;
	cout<<endl<<"Your answer will be stored as: "<<poundage<<endl;
	
	
	//getting bow type
	while(true){
	cout<<" Choose which bow best describes yours from the following: "<<endl
	    <<"R = Recurve"<<endl
	    <<"L = Longbow"<<endl
	    <<"C = Compound"<<endl;
	    cin>>thebow;
	    cout<<endl<<"You chose: "<<thebow<<endl;
  if ( thebow=='R' || thebow=='L' || thebow=='C' || thebow=='r' || thebow=='l' 
         || thebow=='c')
  break;	
  }
  // naming the bow type
	if(thebow == 'r' || thebow == 'R') bow="Recurve";
	if(thebow == 'l' || thebow == 'L') bow="Longbow";
	if(thebow == 'c' || thebow == 'C') bow="Compound";
	
	//run the spine function
		
	cout<<"Arrow spine will not be calculated if poundage isn't betweeen 30 and 75 and your draw length between 22 and 32"<<endl<<endl;



  string thespine;
  
  float adraw= draw+1.5;
  // 600 spine chart
  if(poundage <= 30 && poundage <= 35 && adraw >=22 && adraw <=29.5) thespine= "1535/600";
  if(poundage <= 35 && poundage <= 40 && adraw >=22 && adraw <=28.5) thespine= "1535/600";
  if(poundage <= 40 && poundage <= 45 && adraw >=22 && adraw <=26.5) thespine= "1535/600";
  if(poundage <= 45 && poundage <= 50 && adraw >=22 && adraw <=24.5) thespine= "1535/600";
  if(poundage <= 50 && poundage <= 55 && adraw >=22 && adraw <=23.5) thespine= "1535/600";
  
  // 500 spine chart
  if(poundage <= 30 && poundage <= 35 && adraw >= 29.5 && adraw <=32) thespine= "3555/500";
  if(poundage <= 35 && poundage <= 40 && adraw >=28.5 && adraw <=31.5) thespine="3555/500";
  if(poundage <= 40 && poundage <= 45 && adraw >=26.5 && adraw <=29.5) thespine="3555/500";
  if(poundage <= 45 && poundage <= 50 && adraw >=24.5 && adraw <=27.5) thespine="3555/500";
  if(poundage <= 50 && poundage <= 55 && adraw >=22.5 && adraw <=24.5) thespine="3555/500";
  if(poundage <= 60 && poundage <= 65 && adraw >=23 && adraw <=23.5) thespine="3555/500";
 
  // 400 spine chart
  if(poundage <= 35 && poundage <= 40 && adraw >= 31.5 && adraw <=31.5) thespine="5575/400";
  if(poundage <= 40 && poundage <= 45 && adraw >=29.5 && adraw <=32) thespine="5575/400";
  if(poundage <= 45 && poundage <= 50 && adraw >=27.5 && adraw <=32) thespine="5575/400";
  if(poundage <= 50 && poundage <= 55 && adraw >=25.5 && adraw <=30.5) thespine="5575/400";
  if(poundage <= 55 && poundage <= 60 && adraw >=24.5 && adraw <=28.5) thespine="5575/400";
  if(poundage <= 60 && poundage <= 65 && adraw >=23.5 && adraw <=26.5) thespine="5575/400";
  if(poundage <= 65 && poundage <= 70 && adraw >=22.5 && adraw <=25.5) thespine="5575/400";
  if(poundage <= 70 && poundage <= 75 && adraw >=22 && adraw <=24.5) thespine="5575/400";
  
  // 340 spine chart
  if(poundage <= 50 && poundage <= 55 && adraw >= 30.5 && adraw <=32) thespine="7596/340";
  if(poundage <= 55 && poundage <= 60 && adraw >=28.5 && adraw <=32) thespine="5575/400";
  if(poundage <= 60 && poundage <= 65 && adraw >=26.5 && adraw <=31.5) thespine="5575/400";
  if(poundage <= 65 && poundage <= 70 && adraw >=25.5 && adraw <=29.5) thespine="5575/400";
  if(poundage <= 70 && poundage <= 75 && adraw >=24.5 && adraw <=27.5) thespine="5575/400";

/********************************************************************
 * With the next update to "Archers Paradox" will have:             *
 *  more specialized arrow charts that cover the more extream case. *
 *  There will also be arrow tuning menus. As well as sight tuning  *
 *  menus and rest tuning menus                                     *
 ********************************************************************/
 
 

   
	
	
	
	//storing the information in a struct
	
	
	pointer[counter].archername=archers;
	pointer[counter].drawlength=draw;
	pointer[counter].drawweight=poundage;
	pointer[counter].bowtype=bow;
	pointer[counter].archersspine=thespine;
	counter++;
	
	
}
	
	// thesort FUNCTION
void thesort(int& counter,const int MAX){

// varibles for probile
int scounter=counter;
string n;
float l;
float w;
string b;
string s;
		
	int answer=0;
	// checkis if list is empty
  if (check(counter) == true)
  {
    cout << "The list is empty! There is nothing to sort." << endl;
  }
  //sorts list using bubble sort. a temp storage varible was created and used for the bubble sort
  else{
  	 cout<<" Do you want to sort the list by (1)Archer's Name or by the Archer's (2)Draw Weight?"<<endl;
   cout<<" Enter 1 or 2: ";
   cin>>answer;
  // sorts by name
  if(answer==1){
  	
  	for(int i=0;i<scounter;){
	    for(int i=0;i<counter;i++){
		
		
		    if(pointer[i].archername > pointer[i+1].archername){
		      n=	pointer[i].archername;
		      l=	pointer[i].drawlength;
		      w=	pointer[i].drawweight;
		      b=	pointer[i].bowtype;
		      s=	pointer[i].archersspine;
		
		      pointer[i].archername=   pointer[i+1].archername;
	        pointer[i].drawlength=   pointer[i+1].drawlength;
			    pointer[i].drawweight=   pointer[i+1].drawweight;
			    pointer[i].bowtype=      pointer[i+1].bowtype;
			    pointer[i].archersspine= pointer[i+1].archersspine;
			
			    pointer[i+1].archername=n;
		      pointer[i+1].drawlength=l;
		      pointer[i+1].drawweight=w;
		      pointer[i+1].bowtype=b;
		      pointer[i+1].archersspine=s;
		    }
		
		
	    }
  	//used to keep track of sorted
  	scounter--;  
    }
  	
  }
  //sorts by draw weight
  if(answer==0){
  	
		
		for(int i=0;i<scounter;){
	    for(int i=0;i<counter;i++){
		
		
		    if(pointer[i].drawweight > pointer[i+1].drawweight){
		      n=	pointer[i].archername;
		      l=	pointer[i].drawlength;
		      w=	pointer[i].drawweight;
		      b=	pointer[i].bowtype;
		      s=	pointer[i].archersspine;
		
		      pointer[i].archername=   pointer[i+1].archername;
	        pointer[i].drawlength=   pointer[i+1].drawlength;
			    pointer[i].drawweight=   pointer[i+1].drawweight;
			    pointer[i].bowtype=      pointer[i+1].bowtype;
			    pointer[i].archersspine= pointer[i+1].archersspine;
			
		      pointer[i+1].archername=n;
		      pointer[i+1].drawlength=l;
		      pointer[i+1].drawweight=w;
		      pointer[i+1].bowtype=b;
		      pointer[i+1].archersspine=s;
		    }
		
		
	    }
  	
  	scounter--;
    }
  	
  }
  
  }

}



//info FUNCTION
void info(){
	int answer=0;
	vector<string> theInfo;
	//stores info in vectors for the switch statement
	theInfo.push_back(" The Archer's Paradox is a program in the alpha stage of development \n being designed to create profiles of Archers and their personalized \n archery stats.");
	theInfo.push_back(" The terms Archer's Paradox refers the the paradox that an archer strives \n to make his arrow fly as straight and true as possible, but arrow's warp \n and bend in the air and will never fly straight. That's why choosing the arrow spine,\n arrow tuning, bow tuning, proper set up, form is key to shooting accurately at a high level.");
	theInfo.push_back(" In this stage this program is focused on the foundation of creating \n a true profile based software that allows for the program to figure \n out the archery algorithms  that plague and overwelm new archers.In future updates  there will be more focus on arrow tuning, spine, \n   and bow set up.  Once that is flushed out a GUI will be implemented \n to make a user friendly application. Archers Paradox will have different \n versions for different uses. One version in the future will be \n  programmed with the typical bow shop in mind. A inventroy system  will \n   be fused into the archery algorithms to allow employee that knows nothing \n  archery to see what equipment in stock will suit the customers needs  \n  based on their answers and measurements. Another versions might be \n   programmed for easy use as  applications for iphones and androids");
	theInfo.push_back(" Wesley Gue is the creator of Archer's Paradox. He's been hunting and \n shooting bows since he was 4 years old. Grew up In rural West Virginia, self tought to make \n traditional bows and arrows. He Moved to Canada to live the married life. He took up programming in University while working \n at Oliver Queen Film Industies and local hunting outfitters as a bowtech. He fell in love \n with Programming and is trying to fuse his two passions of the Outdoors and Programming together. \n As his skill in the latter increases  more complex software projects geared toward the outdoorsmen will be undertaken by Wesley.");
	theInfo.push_back(" Contact Wesley Gue by emailing: wesgue22@gmail.com");
	
	//prints a menu out of the user
	while(answer==0){
	cout<<endl<<endl;
  cout<<"(1) =  The program \"Archer's Paradox\"?"<<endl;
  cout<<"(2) = The term Archer's Paradox mean"<<endl;
  cout<<"(3) =  The future of \"Archer's Paradox\""<<endl;
  cout<<"(4) = Creator"<<endl;
  cout<<"(5) = Contact Information"<<endl;
  cout<<"(6) = Quit"<<endl;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"Enter your Choice: ";
	
	
	//uses users input to display info based on that input
	int option = 0;
	cin>> option;
	if(option >0 && option < 10){
	  switch(option){
		
	  case 1: cout<< theInfo[0]; break;
	  case 2: cout<< theInfo[1]; break;
    case 3: cout<< theInfo[2];break;
    case 4: cout<< theInfo[3];break;
	  case 5: cout<< theInfo[4];break;	
	  case 6: answer=2;break;
	
	  }
  }
  
  // tells the user he needs to pick a valid number
  else{
    cout<<"You must pick a number between 1 and 12"<<endl;
	  printmenu();	
  }
	
}
}

// quit FUNCTION
void quit(int& tester){
	 // makes the while loop in the main() quit
	 tester=1;
}
