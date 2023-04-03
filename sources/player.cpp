#include "player.hpp"
#include <iostream>
#include <string>
#include "card.hpp"
#include <bits/stdc++.h>
#include <vector>
#include <utility>
using namespace std;


 
 
    string name;
   
    
   
    //then we present it in 13 cards only. (like Color black)
    // Note:- in the hand there a 26 cards not 6. 
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

    string ariel::Player::getName(){
        return name;
    };
    
    void ariel::Player::setName(string name){
        this->name = name;
    };


    int ariel::Player::stacksize(){

        return this->cards_turn.size();

    };

    int ariel::Player::cardesTaken(){
        return this->cards_won.size();
    };


    double ariel::Player::win_Rate(){

      return  this->win_rate = ((double)this->cardesTaken()/52)*100;
      
    };

    


