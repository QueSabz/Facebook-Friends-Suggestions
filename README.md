# Facebook-Friends-Suggestions
Aim: to create a program that 1) receives as input a list of facebook users and their friends and 2) 
provides friends suggestions for a specific user given as input.
The objective for this assignment is to create a program that:
Asks the user to provide as input from the command line the name of a Facebook user. At most 6 users can be provided as input. For each user, at most 4 friends can be provided as input. To indicate you do not want to add more users or more friends of a user, you can press “Enter” or a character of your choice.

For example, this is how the console should ask the users to provide the singers/groups names and their songs as input. Note that command line output is indicated in black while the command line input is indicated in blu.

Insert a Facebook User:
Mark Zuckerberg

Insert friend 1 for Mark Zuckerberg
Jeff Bezos
Insert friend 2 for Mark Zuckerberg
Hillary Clinton
Insert friend 3 for Mark Zuckerberg
George Orwell
Insert friend 4 for Mark Zuckerberg


Insert a Facebook User:
Jeff Bezos

Insert friend 1 for Jeff Bezos
Alexa Jones
Insert friend 2 for Jeff Bezos
Mark Zuckerberg
Insert friend 3 for Jeff Bezos
George Orwell
Insert friend 4 for Jeff Bezos
Edward Snowden


Insert a Facebook User:
Alexa Jones

Insert friend 1 for Alexa Jones
Jeff Bezos
Insert friend 2 for Alexa Jones
Michelle Obama
Insert friend 3 for Alexa Jones


Insert a Facebook User:
George Orwell
Insert friend 1 for George Orwell
Jeff Bezos
Insert friend 2 for George Orwell
Mark Zuckerberg
Insert friend 3 for George Orwell


Insert a Facebook User:
Edward Snowden
Insert friend 1 for Edward Snowden
Vladimir Putin
Insert friend 2 for Edward Snowden
Jeff Bezos
Insert friend 3 for Edward Snowden


Insert a Facebook User:
Julian Assange
Insert friend 1 for Julian Assange



Then the program should ask the user to input the number of the facebook user for which it should provide friend suggestions (e.g., 1 for Mark Zuckerberg, or 4 for George Orwell) 

Input the Facebook user to which you want to provide friends suggestions:
 Mark Zuckerberg
 Jeff Bezos
 Alexa Jones
 George Orwell
 Edward Snowden
 Julian Assange


The program should identify at most 2 friends suggestions for the user selected at step 2. Suggested friends cannot already be friends of the selected user. If there are more than two friend suggestions the program should choose those who have the biggest number of friends among all possible friends suggestions. If two or more friends suggestions have the same number of friends the smallest ones in alphabetical order will be selected.

If the user selects Jeff Bezos (i.e. inputs 2 at step 2 ), the program output will be 

Suggested Friends for Jeff Bezos:
Julian Assange

If the user selects Julian Assange (i.e. inputs 6 at step 2 ), the program output will be 

Suggested Friends for Julian Assange:
Jeff Bezos
Mark Zuckerberg

If the user selects Edward Snowden (i.e. inputs 5 at step 2 ), the program output will be 

Suggested Friends for Edward Snowden:
Mark Zuckerberg
Alexa Jones


If the user selects Mark Zuckerberg (i.e. inputs 1 at step 2 ), the program output will be 

Suggested Friends for Mark Zuckerberg:
Alexa Jones
Edward Snowden
 

