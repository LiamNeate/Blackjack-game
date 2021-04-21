# C-Project
My C++ project of a blackjack game! 

<h1>A quick summary!</h1>
My programs aim was to create a realistic gambling experience against an AI. The specifications were: <br>
-	Create a random and fair game<br>
-	Have multiple user profiles<br>
-	Use external files to store data<br>
-	Create a currency for the user to gamble with<br>
To create a random and fair game, each game will randomly select cards and deal them between the user and the dealer (computer). To have multiple user profiles, the program will give the user the option to either sign in or create an account. These accounts will be stored locally and be updated as the users uses them. The accounts and the cards will eb stored externally. This means that the user accounts will be able to store data when the program is closed, and that the cards are never changed. Once the user has created an account, they will be given a starting amount of currency to play with. This will then be changed depending on how well they do in the games. If the user runs out of money, it will reset them back to the default amount of money. Since each user has an account, I have added a check when creating an account to make sure that another user does not have the same username, as well as adding a check for the password to make sure it is hard enough.
When the user first starts the program, they will be given a simple menu asking if the user will either: 
-	Login
-	Register
-	Quit 
Once the user has logged in to an existing account, or created a new account, they will come to another menu with options about their account and the game. The options are:
-	Settings
-	See how much money you have
-	Play Blackjack
-	Logout
If the user goes to settings, they will be able to change their current password. If they chose to see how much money they have, the program will simply show the value stated in their account. Logout will return the user back to the main menu and remove any details of their account stored in the program (the user can still access it as it is stored externally). Play blackjack will take the user to the main game but will first ask the user how much they would like to gamble. Once they have selected a valid value, it will take them to the blackjack menu with these options:
-	View rules
-	View pay-out
-	Play
View rules simply displays the rules of this version of blackjack to the user. View pay-out will show the user the multiplier for if they win (1x for a win, 1.5x for a blackjack). Play will deal out the cards and begin the bulk of the game. 
Once in the main blackjack game, it will deal the users, and the computers, cards. It displays to the user their cards and asks if they would like another card or not. If they take another card, it will return with another card and show the user the card. It also says if the dealer gets another card or stays. If the user gets over 21, or gets 5 cards, they can no longer get anymore cards. Once both the player and the computer are done getting cards, it displays both hands and states who the winner is. It then returns to the account menu.
