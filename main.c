
#include <stdio.h>
#include <string.h>
#include "input.h"

//The array containing facebook users
  char users[6][80];
  
  //Friends for User 1
  char friendsUser1[4][80];
  //Friends for User 2
  char friendsUser2[4][80];
  //Friends for User 3
  char friendsUser3[4][80];
  //Friends for User 4
  char friendsUser4[4][80];
  //Friends for User 5
  char friendsUser5[4][80];
  //Friends for User 6
  char friendsUser6[4][80];
  
  //The total number of facebook users (Note it can be less than 6)
  int numOfUsers =0;
  int userChoosed = 0;
  
  //The total number of friends for each user (Note that less than 4 friends can be provided for each facebook user)
  int numFriendsPerUser[6];
  
  //The function to provide users as input
  int inputFacebookUsers();

  // The function to select a user
  int SelectUser();

  // This function display the suggested friends to the user
  void DisplaySuggestedFriend();

  int inputFriends(char friends[][80]);

int main(void)
{
  
	// step 1:

	// invoke here the function to provide users as input
   numOfUsers = inputFacebookUsers();

   printf("%d Facebook users have been provided as input.\n",numOfUsers);
  
   // step 2:

   // here is the function to display users and ask for a number corresponding to the user.
   userChoosed = SelectUser();

   // step 3:
   // sorting algorithm
   DisplaySuggestedFriend();
   return 0;

}


/**
 * This function asks the users to provide a list of facebook users.
 * For each facebook users it will be necessary to add a set of friends
 */
int inputFacebookUsers(){
    int i=0;
    while(i< 6){
        printf("%s", "Input the next Facebook User \n");
        fgets(users[i],80,stdin);
        switch(i){
            case 0: numFriendsPerUser[i]= inputFriends(friendsUser1);
                    break;
            case 1: numFriendsPerUser[i]= inputFriends(friendsUser2);
                    break;
            case 2: numFriendsPerUser[i]= inputFriends(friendsUser3);
                    break;
            case 3: numFriendsPerUser[i]= inputFriends(friendsUser4);
                    break;
            case 4: numFriendsPerUser[i]= inputFriends(friendsUser5);
                    break;
            case 5: numFriendsPerUser[i]= inputFriends(friendsUser6);
            default: break;
        }
        //Checks whether a carriage return symbol was provided as input
        if(users[i][0] == '\n')
            break;
        i++;
    }
    return i;
}
/*
	This function ask to select a given user.
	This function return the User that have been selected
*/
int SelectUser()
{
	// initializing return value to 0
	int returnValue = 0; 
	// display the statement to select.
	printf("Input the Facebook user to which you want to provide friends suggestions:\n");
	// for maximum 6 users can be checked
	for(int userID = 0; userID < 6; userID++)
	{
		if(users[userID][0] == '\n')
		{
			// if user is empty, break the loop
			break;
		}
		else
		{
			//if user is not empty, display it
			printf("(%i) %s",userID + 1,users[userID]);
		}

	}
	// return value gets the selected user.
	scanf("%d", &returnValue);
	// return the selected value.
	return returnValue;
}


// This function display the suggested friends to the user
void DisplaySuggestedFriend()
{
	printf("Suggested Friends for %s",users[userChoosed - 1]);
	// use of insertion sorting to sort with respect to number of friends.
	// Requirement: biggest number of friends among all possible friends suggestions. 
	int IndexOfUser[6]={0,1,2,3,4,5};
	for(int i =0; i<6; i++)
	{
		int value = numFriendsPerUser[i];
		int j = i-1;
		while((j>=0) && (numFriendsPerUser[j]<value))
		{
			numFriendsPerUser[j+1]=numFriendsPerUser[j];
			IndexOfUser[j+1] = IndexOfUser[j];
			j--;
		}
		numFriendsPerUser[j+1] = value;
		IndexOfUser[j+1] = i;
	}
	
	// smallest ones in alphabetical order will be selected. 	
	for(int i =0; i<5; i++)
	{
		// if same number of user friends, selected the smallest character.
		if((numFriendsPerUser[i] == numFriendsPerUser[i+1]) && (strncmp(users[IndexOfUser[i]],users[IndexOfUser[i+1]],80) >0))
		{
			// swap
			int temp =numFriendsPerUser[i];
			numFriendsPerUser[i]=numFriendsPerUser[i+1];
			numFriendsPerUser[i+1] = temp;

			temp = IndexOfUser[i];
			IndexOfUser[i] = IndexOfUser[i+1];
			IndexOfUser[i+1] = temp;
		}
	}
	// cannot already be friends of the selected user. 
	int AlreadySuggestedFriend = 0;
	char suggestedFriend[80];
	for(int indexloop = 0; indexloop<6; indexloop++)
	{
		int foundInFriendList =0;
		if (AlreadySuggestedFriend>=2)
		{
			// at most 2 friends
			break;
		}
		// check if not the same user itself
		if(userChoosed -1 != IndexOfUser[indexloop])
		{
			strcpy(suggestedFriend,users[IndexOfUser[indexloop]]);
			// check the friend list of 4 and compare it with the suggested friend to avoid repetition.
			for(int i = 0; i<4; i++)
			{
				switch(userChoosed -1)
				{
					case 0: if(strncmp(friendsUser1[i],suggestedFriend,80)==0)
							foundInFriendList = 1;
							break;
					case 1: if(strncmp(friendsUser2[i],suggestedFriend,80)==0)
				 			foundInFriendList = 1;
						   break;
					case 2: if(strncmp(friendsUser3[i],suggestedFriend,80)==0)
							foundInFriendList = 1;
				       break;
					case 3: if(strncmp(friendsUser4[i],suggestedFriend,80)==0)
							foundInFriendList = 1;
					   break;
					case 4: if(strncmp(friendsUser5[i],suggestedFriend,80)==0)
							foundInFriendList = 1;
					    break;
					case 5: if(strncmp(friendsUser6[i],suggestedFriend,80)==0)
							foundInFriendList = 1;
					default: break;
				}
			}
			if(foundInFriendList == 0)
			{
				printf(suggestedFriend);
				AlreadySuggestedFriend++;
			}
		}
	}
}
