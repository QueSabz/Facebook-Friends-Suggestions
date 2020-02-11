#include <stdio.h>
#include <string.h>
#include "input.h"

/**
 * This method asks the user to provide as input the friends
 * of a Facebook user.
 * 
 * Input:   
 * friends, contain the names of friends provided as input
 * 
 * Output:
 * Returns the number of friends provided as input. Note that
 * a user may decide to input less than 6 friends. 
 */
int inputFriends(char friends[][80]){
    //Provide here function implementation
	
	// use of static int to retain its value
	static int userID = -1;
	// use of local variable for number of friends (4)
	int friendID=0;
	++userID;
	// check if user is a valid user, not an empty set.
	if(users[userID][0] != '\n')
	{
		// ask for friends 4 times at max		
		while(friendID < 4){
			printf("Insert friend %i for %s",friendID+1,users[userID]);
			fgets(friends[friendID],80,stdin);
			if(friends[friendID][0] == '\n')
			{
				break;
			}
			++friendID;
		}
	}
 return friendID;   
}

