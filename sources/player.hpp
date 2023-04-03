#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <iostream>
#include "card.hpp"
#include <bits/stdc++.h>
#include <vector>
using namespace std;


   


namespace ariel{


    class Player {

        


    string name;
    double win_rate;


    
   public:
    vector<Card> cards_turn;
    vector<Card> cards_won;
    // Player(string name):name(name),win_rate(0.0){

    
    Player(string const &name){

      
        if(!name.empty()){

             this->name=name;
             this->win_rate = 0.0;


        }else{
            throw runtime_error("The name should not be empty!!");
        }
    }
    

    void printCards_won(){

        size_t len = this->cards_won.size();

        for (size_t i = 0; i < len ; i++)
        {
            cout << cards_won[i].toString();
        }
        
    }


   
    

    string getName();
    void setName(string name);
    int stacksize();
    int cardesTaken();
    struct statistics getStatistics();
    double win_Rate();
    

   


    };
    

};

#endif 