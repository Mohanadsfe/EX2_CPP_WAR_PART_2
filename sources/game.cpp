#include "game.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include "player.hpp"
#include "card.hpp"
#include <bits/stdc++.h>
#include <vector>
#include "stddef.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <exception>

using namespace std;
using namespace ariel;

      
  
  unsigned seed = std::chrono::system_clock::now()
                            .time_since_epoch()
                            .count();

  vector<Card> cardBuffer_Equal;
  vector<string> status_turns; 

  

    

    void ariel::Game::playTurn(){
  
     

      if(pl2.stacksize()!=0){

            if(addressof(pl1)==addressof(pl2)){

                    throw runtime_error("One player!!");

                }
    

    if(pl1.cards_turn.size()>0 && pl2.cards_turn.size()>0){


      shuffle (this->pl1.cards_turn.begin(),this->pl1.cards_turn.end(), std::default_random_engine(seed));
     
      Card cardP1=  this->pl1.cards_turn[pl1.cards_turn.size()-1]; 

      this->pl1.cards_turn.pop_back();
        


       // Player two get a card 
        
      shuffle (this->pl2.cards_turn.begin(),this->pl2.cards_turn.end(), std::default_random_engine(seed));

      Card cardP2=  this->pl2.cards_turn[pl2.cards_turn.size()-1];
      this->pl2.cards_turn.pop_back();

      // Check who win or equal
      int compare_valuesCard = this->compare_valuesCard(cardP1,cardP2); 


    
      if (compare_valuesCard>0) // CardP2 > cardP1
        {

            this->pl2.cards_won.push_back(cardP2);
            this->pl2.cards_won.push_back(cardP1);

            winner = pl2.getName();
            

            string s =  "Alice played " + cardP1.getShape() + " " + "Bob played " + cardP2.getShape()  + " " +  winner + ". wins.";
            status_turns.push_back(s);
          
            shuffle (this->pl2.cards_turn.begin(),this->pl2.cards_turn.end(), std::default_random_engine(seed));


      }else if (compare_valuesCard<0) // CardP2 < cardP1

        {

            this->pl1.cards_won.push_back(cardP2);
            this->pl1.cards_won.push_back(cardP1);
           
            winner = pl1.getName();

           string s =  "Alice played " + cardP1.getShape() + " " + "Bob played " + cardP2.getShape()  + " " +  winner + ". wins.";
           status_turns.push_back(s);

           shuffle (this->pl1.cards_turn.begin(),this->pl1.cards_turn.end(), std::default_random_engine(seed));

        }

      else{ // CardP1 = cardP2   The first (2 cards)

            cardBuffer_Equal.push_back(cardP1);
            cardBuffer_Equal.push_back(cardP2);

            string s =  "Alice played " + cardP1.getShape() + " " + "Bob played " + cardP2.getShape()  + " " + ". Equals.";
            status_turns.push_back(s);

            shuffle (this->pl2.cards_turn.begin(),this->pl2.cards_turn.end(), std::default_random_engine(seed));
            shuffle (this->pl1.cards_turn.begin(),this->pl1.cards_turn.end(), std::default_random_engine(seed));
                             


            Equal_Cards();
            
        }
    }else{

      throw runtime_error("Error 2!!!");
    }
      }
      else{
             throw runtime_error("The game end!");
      }

   
      
      };

 

    

  int ariel::Game::compare_valuesCard(Card card1, Card card2){ // if cardp1>cardp2 return -1 , if cardp1<cardp2 return 1 ,else 0

        int p1 = card1.getValue();
        int p2 = card2.getValue();

      
        if (p1==1 && p2==2)
          {
              return 1;
            }

        else if (p1==2 && p2==1)
            {
            return -1;
             }

        else{

    if(p1!=1 && p2!=1){

          int val = card1.getValue()-card2.getValue(); 

            if(val<0){
              
                return 1;
                        }

            else if(val>0){

                return -1;

                             }

            else{

                return 0;

                  }
              
              
        }

        else{  // wotk with A's

          if(card1.getValue()==1 && card2.getValue()==1){
            return 0;
          }
          else if (card1.getValue()==1 && card2.getValue()!=1){
              return -1;
          }
          else{
            return 1;
          }

        }

         }

      };




  void ariel::Game::Equal_Cards(){

      int flag = 1;

    equals++;

   

    do{
      

    

          // Get a  two card drom each player wthout know what is the value of the card.
    if(pl1.cards_turn.size()>0 && pl2.cards_turn.size()>0){

          shuffle (this->pl1.cards_turn.begin(),this->pl1.cards_turn.end(), std::default_random_engine(seed));
          
          if(pl1.cards_turn.size()==0 && pl2.cards_turn.size()==0){


          int len = cardBuffer_Equal.size();

          for (size_t i=0; i<len/2; i++)
          pl1.cards_won.push_back(cardBuffer_Equal[i]);

          for (size_t i=0; i<len/2; i++)
          pl2.cards_won.push_back(cardBuffer_Equal[i]);

    break;

}

          Card cardClose1=  this->pl1.cards_turn[pl1.cards_turn.size()-1];
          cardBuffer_Equal.push_back(cardClose1);
          this->pl1.cards_turn.pop_back();

          shuffle (this->pl2.cards_turn.begin(),this->pl2.cards_turn.end(), std::default_random_engine(seed));
          
          Card cardClose2 =  this->pl2.cards_turn[pl2.cards_turn.size()-1];

          cardBuffer_Equal.push_back(cardClose2);
          this->pl2.cards_turn.pop_back();

/// if there problem that there equals war , and after get one close card for each player, the capcity of cards is enough!!
if(pl1.cards_turn.size()==0 && pl2.cards_turn.size()==0){

  int len = cardBuffer_Equal.size();

  for (size_t i=0; i<len/2; i++)
  pl1.cards_won.push_back(cardBuffer_Equal[i]);

  for (size_t i=0; i<len/2; i++)
  pl2.cards_won.push_back(cardBuffer_Equal[i]);



   
    break;
}

         // The third thime  get (2 cards)
          shuffle (this->pl1.cards_turn.begin(),this->pl1.cards_turn.end(), std::default_random_engine(seed));
          Card cardOpen1 = this->pl1.cards_turn[pl1.cards_turn.size()-1]; //??? error !!!

          cardBuffer_Equal.push_back(cardOpen1);
          this->pl1.cards_turn.pop_back();


          shuffle (this->pl2.cards_turn.begin(),this->pl2.cards_turn.end(), std::default_random_engine(seed));
          Card cardOpen2 = this->pl2.cards_turn[pl2.cards_turn.size()-1];

          cardBuffer_Equal.push_back(cardOpen2);
          this->pl2.cards_turn.pop_back();

     
          string s =  "Alice played " + cardClose1.getShape() + " " + "Bob played " + cardClose2.getShape()  + " " + "Closing Cards";
          string s2 =  "Alice played " + cardOpen1.getShape() + " " + "Bob played " + cardOpen2.getShape()  + " " + "Openning Cards";
          status_turns.push_back(s);
          status_turns.push_back(s2);

         cout<< endl;


          int valueCompare = this->compare_valuesCard(cardOpen1,cardOpen2); 

          if (valueCompare>0) // pl2Card > pl1Card
            {

            int len = cardBuffer_Equal.size();

            for(size_t i=0; i<len; i++){
              this->pl2.cards_won.push_back(cardBuffer_Equal[i]);
                                          }

            cardBuffer_Equal.clear();
            flag=0;

            this->winner = pl2.getName();

            shuffle (this->pl2.cards_turn.begin(),this->pl2.cards_turn.end(), std::default_random_engine(seed));
                 }

          else if (valueCompare<0) // pl2Card < pl1Card

          {  


            int len = cardBuffer_Equal.size();

            for(size_t i=0; i<len; i++){

              this->pl1.cards_won.push_back(cardBuffer_Equal[i]);
              
                                          }

            cardBuffer_Equal.clear();
            this->winner = pl1.getName();
           

            shuffle (this->pl1.cards_turn.begin(),this->pl1.cards_turn.end(), std::default_random_engine(seed));

            flag=0;

          }

          else

          { // // pl2Card = pl1Card

            flag=1;
                  cout<< endl;


                 
              }

            shuffle (this->pl2.cards_turn.begin(),this->pl2.cards_turn.end(), std::default_random_engine(seed));
            shuffle (this->pl1.cards_turn.begin(),this->pl1.cards_turn.end(), std::default_random_engine(seed));

    }


      

    

      }while(flag&& pl1.stacksize()!=0 && pl2.stacksize()!=0);

    


 };


    




    void ariel::Game::printLastTurn(){

            cout << endl ;
            string s1 =  "Alice played " + status_turns[0] ;

            cout << s1 << endl;
          

    }



    void ariel::Game::playAll(){

       while (pl1.stacksize()!=0)
       {
         
          this->playTurn();
          

       }
     
       
    }

    string ariel::Game::WinnerLevel(){
         return winner;
    };



  
    
    void ariel::Game::printLog(){
      
        cout << endl << endl;

        int len = status_turns.size();

          for (size_t i = 0; i < 26; i++)
          {

              cout << "Turn "  + to_string(i+1) << " " << status_turns[i] << endl;

          }

    };

    void ariel::Game::printWiner(){

      

       int num1 = this->pl1.cardesTaken();
       int num2 = this->pl2.cardesTaken();
      
      if(num1>num2){

          cout << "The Winner is :- " << this->pl1.getName() <<endl <<endl;

      }
      else if(num1<num2){

        cout << "The Winner is :- " << this->pl2.getName() << endl << endl;

      }
      else{

        cout << "Ops " << "Equal" << endl << endl;

      }

    };

     string ariel::Game::printWiner2(){

      int num1 = this->pl1.cards_won.size();
      int num2 = this->pl2.cards_won.size();

     if(num1>num2){

        return  "The Winner is :- " + this->pl1.getName();
     }
        else{
           
             return  "The Winner is :- " + this->pl2.getName();

        } 


     };

    void ariel::Game::printStats(){

      int size1 = this->pl1.cards_won.size();
      
      int size2 = this->pl2.cards_won.size();


        cout << endl << endl;
        cout << "The win rate of first player " << pl1.getName() << " is " << this->pl1.win_Rate() <<"%"<< endl;
        cout << "The win rate of second player " << pl2.getName() << " is " << this->pl2.win_Rate() <<"%"<< endl;
        cout << endl << endl;

    for (size_t i = 0; i < size1; i++)
    {
        cout << to_string(i+1) <<  this->pl1.cards_won[i].toString() << endl;
    }

    cout<<endl<<endl;
    cout << "The Cards of the second player " << this->pl2.getName() << endl << endl;

    for (size_t j = 0; j < size2; j++)
    {
        cout << to_string(j+1) << this->pl2.cards_won[j].toString() << endl;
    }

    cout << endl << endl ;

    cout << " Amount of draws that happand " << to_string(equals) << endl<<endl;
    cout << "Draw rate " << endl << to_string((equals/(double)(26-equals))*100) << "%" << endl;


    };



    void ariel::Game::printCardsPlayer(){

      int len1 = this->pl1.cards_turn.size();
      int len2 = this->pl2.cards_turn.size();

        cout << endl << endl;

        cout << "The cards of each player ,after split it..." << endl << endl;

        cout << "The Cards of the first player " << this->pl1.getName() << endl << endl;
        cout << "Size of stack player 1 is " << len1 << endl;
        cout << "Size of stack player 2 is " << len2 << endl;


     for (size_t t = 0; t < len1; t++)
    {
        cout << to_string(t+1) <<  this->pl1.cards_turn[t].toString() << endl;
    }

        cout<<endl<<endl;

        cout << "The Cards of the second player " << this->pl2.getName() << endl << endl;

    for (size_t k = 0; k < len2; k++)
    {
        cout << to_string(k+1) << this->pl2.cards_turn[k].toString() << endl;
    }
      
        cout << endl << endl;

    };
   




    






