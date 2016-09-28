# Archers-Paradox
[![N|Solid](http://i.imgur.com/zIA690h.png)](https://nodesource.com/products/nsolid)

In this program we are going to solve the problem of trying to find the proper spined arrow for the archer. 
We are going to store information given by the user and create a simple profile to find these information agian to be used in the future.
The program will be able to add,remove,sort,display,open a file, and save a file.

- Displays message.

- Gets asked questions needed.

- Uses a menu system.

- Enter 'q' to quit.

- Store information.

- Calculate proper spined arrows.

- list the results on the profile. 

- Allow for multiple results

- Allow for removal of profiles.

- Open Files.

- Save Files. 



Program Description.

- Display greeting. "Welcome to the "Archers Paradox" The best damn program to figure out the spine of your arrow that you will need for your bow set up"

- Diplay menu " Please make a selection"
                 
              (A)dd Profile (D)isplay Profiles, (O)pen Files, (S)ave File, (SO)rt files (Q)uit

- Run operation depending on what they chose.

- If (A) display in this order 

  - "Please enter your first and last name seperated by a space" 
  - Store the answer
  - "Please enter your draw length"
  - store the answer
  - "Please enter the poundage of your bow, If it is a counbound bow enter the poundage you will be shooting at"
  - Store the answer
  - Use stored answers to calculate which spine is best for the Archer

- If (D) display
 
 - Display all Profiles

- If (O)

  - OPen files

- If (S)

  - Save file

- (SO) 
  
  - sort files

- If (q) quit

  - Quit program
  

Varibles and Constants

varibles 

 - drawLength = archer's draw length

 - bowPoundage = archer's bow poundage

 - bowType = Type of bow

 - name1 =  archer's first name

 - name2 =  archer's second name

 - profile = used for  

 - choice = used for the menu

 
 constants

 - q = quit program




modulization

The main fuction has a function called the menu(). In the menu there is spine(), getName(), Display(), Open(), Save(), Quit(), Sort(). 
in the spine fucntion there is 4 four functions it calls on called draw(),pound(),bow(),Cspine.

In main we start of with a greeting. Then the menu function is called allowing the user to pick what they are after. If the pic add then that will allow the to store thier first and last name into the program. following that the add() calls on the spine()
function. the spine function is used to figure out what spine is needed after getting stats from the archer/user. ((in later versions it will come with measuring instructions.)). It then uses the stats to calulate the proper spine needed.
(( later versions will allow for calculating arrow tuning recomindations)).There are other functions in the menu() function that allows you to call on the remove function(). It allows you to choose to remove a profile. then there's Displayname() which displays the list of 
profiles. then Open() ,Save(), and Quit() to exaclty what the name implies. open a profile, save a profile, and quit the program.

spine module

This function is for calculating the spine of arrow the user needs. it collects stats needed to calculate the proper spine by using  draw(),pound(),bow(),Cspine.

Control: a forever loop that will be used that only breaks if "quit" is entered
Task: Gets stats from the user and then calculates the proper spined arrows you need.
Accepts: 2 floats and 1 string
Returns: spine varible
Modifies: the spine varible
Locals: the local varibles


menu is the switch board of this program. It allows you to go down different paths to do different task. In the menu there is spine(), getName(), Display(), Open(), Save(), Quit(), Sort().

Task: Diplay's a menu for the user to navigate the programs
Accepts: 7 chars
Returns: nothing
Modifies:nothing
Locals: the local varibles
