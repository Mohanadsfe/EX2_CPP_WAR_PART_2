#include "card.hpp"
#include <iostream>
#include <string>
using namespace std;


    string ariel::Card::toString(){

        string v = to_string(this->getValue());
        string c = to_string(this->getColor());
        string s = to_string(this->getStatus());


        return "Card :-  value , " + v + " color , " + c + " shape , " + this->getShape() + " status , " + s;

    }

    bool ariel::Card::emptyCard(){

        return this->color==0 && this->value==0 && this->status ==0 && this->shape.empty() ? true : false;

    }

    double ariel::Card::getValue(){
        return this->value;
    };


    int ariel::Card::getColor(){
        return this->color;
    };

    int ariel::Card::getStatus(){
        return this->status;
    };

    void ariel::Card::setStatus(int status){
        this->status = status;
    };

    void ariel::Card::setColor(int color){
        this->color = color;
    };

    string ariel::Card::getShape(){
        return this->shape;
    };

    void ariel::Card::setShape(string shape){
        this->shape = shape;
    };



