#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <iostream>
using namespace std;

namespace ariel { 

   
    class Card{

        double value;
        int color;
        int status;
        string shape;
         public:
        
        
        // Card(){

        // }
        Card(int color, double value,string shape,int status):color(color),value(value),shape(move(shape)),status(status){
            // this->value = value;
            // this->color = color;
            // this->shape = shape;
            // this->status = status;
        }

        string toString();
        double getValue();
        int getColor();
        int getStatus();
        void setStatus(int status);
        void setColor(int color);
        string getShape();
        void setShape(string shape);
        bool emptyCard();




    };





};

#endif 