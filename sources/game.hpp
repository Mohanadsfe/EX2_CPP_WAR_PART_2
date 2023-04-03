#ifndef GAME_H_
#define GAME_H_

#define   NUMBER_OF_CARDS = 52
#include "player.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;







namespace ariel{
        
    class Game{


array <ariel::Card,52> cardsBig{ {
{0,1.0,"A's of Hearts",1},{0,2.0,"2 of Hearts",1},{0,3.0,"3 of Hearts",1},{0,4.0,"4 of Hearts",1},{0,5.0,"5 of Hearts",1},{0,6.0,"6 of Hearts",1},{0,7.0,"7 of Hearts",1},{0,8.0,"8 of Hearts",1},{0,9.0,"9 of Hearts",1},{0,10.0,"10 of Hearts",1},{0,11.0,"Jack of Hearts",1},{0,12.0,"Queen of Hearts",1},{0,13.0,"King of Hearts",1},
{1,1.0,"A's of Spades",1},{1,2.0,"2 of Spades",1},{1,3.0,"3 of Spades",1},{1,4.0,"4 of Spades",1},{1,5.0,"5 of Spades",1},{1,6.0,"6 of Spades",1},{1,7.0,"7 of Spades",1},{1,8.0,"8 of Spades",1},{1,9.0,"9 of Spades",1},{1,10.0,"10 of Spades",1},{1,11.0,"Jack of Spades",1},{1,12.0,"Queen of Spades",1},{1,13.0,"King of Spades",1},
{0,1.0,"A's of Diamonds",1},{0,2.0,"2 of Diamonds",1},{0,3.0,"3 of Diamonds",1},{0,4.0,"4 of Diamonds",1},{0,5.0,"5 of Diamonds",1},{0,6.0,"6 of Diamonds",1},{0,7.0,"7 of Diamonds",1},{0,8.0,"8 of Diamonds",1},{0,9.0,"9 of Diamonds",1},{0,10.0,"10 of Diamonds",1},{0,11.0,"Jack of Diamonds",1},{0,12.0,"Queen of Diamonds",1},{0,13.0,"King of Diamonds",1},
{1,1.0,"A's of Clubs",1},{1,2.0,"2 of Clubs",1},{1,3.0,"3 of Clubs",1},{1,4.0,"4 of Clubs",1},{1,5.0,"5 of Clubs",1},{1,6.0,"6 of Clubs",1},{1,7.0,"7 of Clubs",1},{1,8.0,"8 of Clubs",1},{1,9.0,"9 of Clubs",1},{1,10.0,"10 of Clubs",1},{1,11.0,"Jack of Clubs",1},{1,12.0,"Queen of Clubs",1},{1,13.0,"King of Clubs",1}}}; 


        int counter = 0;
        // int counter2= 52;
        int equals = 0;

    //then we present it in 13 cards only. (like Color black, red)
    // Note:- in the hand there a 26 cards.
    // A - 1 
    // 2 - 2
    // 3 - 3
    // 4 - 4
    // 5 - 5
    // 6 - 6
    // 7 - 7
    // 8 - 8
    // 9 - 9
    // 10 10
    // J - 11
    // Q - 12
    // K - 13

    const int number_of_cards = 52;

  // color , value , shape , status 
 

        Player &pl1;
        Player &pl2;

        
        int counterZ;

        string winner;
        
       

        public:

           Game(Player& pl1, Player& pl2):pl1(pl1),pl2(pl2),counterZ(1){


                

                    if (!pl1.getName().empty()&&!pl2.getName().empty())
                {
                    this->pl1.setName(pl1.getName());
                    this->pl2.setName(pl2.getName());
                    splitArray();
                    

                }else{

                     throw runtime_error("The name should not be empty!!");

                }
                //updateBigCards();

           };



        void addPl1(Card const &cardPlayer){

             this->pl1.cards_turn.push_back(cardPlayer);
           
        };


          void addPl2(Card const &cardPlayer){

             this->pl2.cards_turn.push_back(cardPlayer);
           
        };





      void splitArray(){

        cout << endl;
       

         while(counter!=number_of_cards){
          
             
             // Should check that we don't get the same card , if yes then continue to get another one.
             
            Card *cardPlayer =  getCardFromBig(); // choose card randomly from the arraycards (there 52 cards);

             if((*cardPlayer).getStatus()==1){ // chcek if the card actually in the stack of the card or not.
                    
                    if(counter%2==0){ // this if, only to add one time to the player1 and in the second tim eto player 2, ...

                        addPl1(((*cardPlayer))); // add the card to the vector of cards that's belong to the player 1.
                        (*cardPlayer).setStatus(0);
                       
                        counter++; 


                    }else{

                        addPl2(((*cardPlayer))); // add the card to the vector of cards that's belong to the player 2.

                  
                        (*cardPlayer).setStatus(0); // change the status to 0 of the card that get from the arrayCards , that means is not allowed to get more time.
                       
                     counter++;

               }

                 }


                 else{
                    cardPlayer = getCardFromBig(); // call function, to get a new card .
               }
     

         }

      };



    // void updateBigCards(){


    //         for (size_t i = 0; i < number_of_cards; i++)
    //         {
    //             cardsBig[i].setStatus(1); // alive the card again in the big array of all cards the game.
    //         }
            

    // };




     Card * getCardFromBig(){ // get a randomly index , return card that's in this index in the arrayCards.


        unsigned long index = (unsigned long)rand()%(unsigned long)number_of_cards;
        return &(cardsBig[index]);

     };

  
           
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            string WinnerLevel();
            void Equal_Cards();
            int compare_valuesCard(Card card1, Card card2);
            void printCardsPlayer();
            string printWiner2();


           

            

        
    
    };

 };

    

#endif