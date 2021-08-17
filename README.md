# Monopoly In C
 This is an implementation of the board game Monopoly in C for windows systems.

## THE GAME

### Welcome screen
The game starts off at the welcome screen.

<p align="center">
  <img width="512" alt="WelcomeScreen" src="https://user-images.githubusercontent.com/73733877/129778830-9543316d-25c3-4a12-b52c-adc41d646a00.jpg">
</p>

### Main Menu
The player has the options to play Monopoly or view the rules of the game.

<p align="center">
  <img width="512" alt="MainMenu" src="https://user-images.githubusercontent.com/73733877/129779696-014a216d-17a6-41e8-b3c3-581399761cdb.jpg">
</p>

### Game Mode Menu
Player can select the game mode they wish to play with.

<p align="center">
  <img width="512" alt="GameMode" src="https://user-images.githubusercontent.com/73733877/129778850-896587a6-f515-4875-ae60-04af5013e921.jpg">
</p>

### Player Details
Players enter number of players and their names. The program emulates the players rolling a die to the player order based on the highest rolls.

A maximum number of 8 players can play.

<p align="center">
  <img width="512" alt="PlayerDetails" src="https://user-images.githubusercontent.com/73733877/129778756-8ed5dc11-f563-4395-b565-d65b26322999.jpg">
  <img width="512" alt="PlayerOrders" src="https://user-images.githubusercontent.com/73733877/129778766-a3801097-dcff-4fbf-9724-b34da9bdfcb3.jpg">
</p>

### Main Game Starts
This is where the actual gameplay starts. All players are assigned a colour and starting positions are set at START. 

<p align="center">
  <img width="512" alt="MainGame" src="https://user-images.githubusercontent.com/73733877/129778872-5c433627-2df6-4aeb-8f6d-57ee2eb7e97a.jpg">
</p>

Each turn, each player who isn't in jail and bankrupt/given up is given options to roll, buy houses and hotels, sell properties they own or to give up.

#### PLAYER ROLLS
Player rolls two dice each of 1-6 thus with a total possibility of 2-12. 
If the player gets doubles (the same number on both dice) the player gets to play again. 
If the player gets too many doubles, they are sent to jail for overspeeding.

<p align="center">
  <img width="512" alt="PlayerRolls" src="https://user-images.githubusercontent.com/73733877/129778779-59e0c8dc-708a-4b6e-bad8-ec18f23db33f.jpg">
</p>

After rolling, if the player lands on a purchasable tile, they are given the option to buy the property.

<p align="center">
  <img width="512" alt="BuyProperty" src="https://user-images.githubusercontent.com/73733877/129778743-2846eaa2-d5cb-4889-bd36-42261a2d2594.jpg">
</p>

If the player has a sufficient balance of cash in hand, they can buy the property and a X of their colour is shown in the map.

#### BUY HOUSES AND HOTELS
If the player has completed a set, they are now allowed to buy a max of 4 Houses or a hotel if they have a sufficient balance.
The player can build houses in only property type locations whose sets are completed.
The player can only build a hotel if 4 houses have been built.

<p align="center">
  <img width="512" alt="BuyHotelHouse" src="https://user-images.githubusercontent.com/73733877/129778861-5240ea59-4e62-4da5-8e31-6f1fc1dfeb49.jpg">
</p>

If the player owns x houses, xH of their colour is shown next to the property.
If the player owns a hotel, HL of their colour is shown next to the property.

<p align="center">
  <img width="512" alt="HousesHotels" src="https://user-images.githubusercontent.com/73733877/129778796-6aa6ebdf-1d94-4727-a92a-8d4b31be04ac.jpg">
</p>


#### SELL MENU
A list of properties the player owns is listed. On selection the property is sold and the player recieves the property value.

<p align="center">
  <img width="512" alt="SellMenu" src="https://user-images.githubusercontent.com/73733877/129778788-9b0ecc81-b12c-41cf-8c28-ad4807e255dc.jpg">
</p>

#### GIVE UP
If a player gives up, they are automatically set to last and all their properties are available for other players to buy.

### Jail
A player can be sent to jail when they land on "GO TO JAIL" or roll a certain number of doubles.

The player is given the option to pay a certain amount to get out or can stay for a certain number of turns.

If the player stays, at each turn, the number of turns to wait is displayed. The player cannot sell properties or buy houses/hotels when in jail.

<p align="center">
  <img width="512" alt="Jail" src="https://user-images.githubusercontent.com/73733877/129778866-09a35eb1-6862-4bab-91ff-380f94ce040d.jpg">
</p>

### Bankrupt
Once the player has a value of less than -500 in cash in hand, they are set to bankrupted and can no longer play.

<p align="center">
  <img width="512" alt="Bankrupt" src="https://user-images.githubusercontent.com/73733877/129778846-5fdded4e-cedd-452a-90cc-4e589d1c2ece.jpg">
</p>

### GAME MODE BASED ENDINGS
Based on the game mode chosen, the game ends.

If the game mode was NETWORTH, once a player reaches a certain amount, the game ends.

If the game mode was TURNS, once certain number of turns have passed, the game ends.

If the game mode was ENDLESS, once all players except one become bankrupt, the game ends.

<p align="center">
  <img width="512" alt="TurnsPassed" src="https://user-images.githubusercontent.com/73733877/129778826-993398c2-db99-409c-9c90-399a26afc76d.jpg">
</p>

### RESULTS
After the game ends, a result screen of the game is shown. 
Players are arranges on their networth. 
Players who give up are at the bottom of the list disregarding their networths.

<p align="center">
  <img width="512" alt="Results" src="https://user-images.githubusercontent.com/73733877/129778810-05dfd300-4529-48a6-9efc-fb116f469190.jpg">
</p>

### THANK YOU SCREEN
After the game ends, a thank you screen is shown.

<p align="center">
  <img width="512" alt="ThankYou" src="https://user-images.githubusercontent.com/73733877/129778821-905503c7-0a4c-49ff-a04c-017e642bb820.jpg">
</p>
 

 
## Running the Program:
 To run the program, clone the repo and make the [Makefile](./Makefile).
 
 > `mingw32-make all` if using mingw32
 
 Run on command prompt.
 
 > `Monopoly.exe`
 
 NOTES:
 Before running the program, make sure command prompt is maximised and in full screen for best experience. 
 Failure to do so can result undesirable outputs.
 Some screen resolutions are not supported.

## Makefile Targets:

### all
 Compiles all necessary files and creates .o files and places them in a folder called obj and makes Monopoly.exe

### Monopoly
 Directly compiles necessary files and creates Monopoly.exe

### OFiles 
 Compiles all necessary files and creates .o files and places them in a folder called obj.
 
### clean
 Removes all .o and .exe files created during make `all`.


## Future Plans
 - Might extend to linux based systems.
 - Might add automatic command prompt resizing and resolution detection and accordingly setting up. 
 
