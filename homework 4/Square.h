//
//  Square.h
//  homework4
//
//  Created by Casey Taylor on 10/24/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef Square_h
#define Square_h

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "Collection.h"

//DERIVED CLASS
class Square: public Shape{
private:
public:
    Square(int, int, int);
    virtual void setStars();
    virtual ~Square() = default;
    
};


/*Square constructor creates a square object with the appropriate coordinates and size property
 @param xPos is the x value of the coordinate in the top left corner
 @param yPos is the y value of the coordinate in the top left corner
 @param sz is the size property of the square (number of stars for its height/ width)
 @returns void
 */
Square::Square(int xPos, int yPos, int sz): Shape(xPos, yPos, sz) {
    setStars();
}


/* This function identifies the coordinates within the bound of each new square shape, pushing back those coordinates into a vector of coordinate pairs
 @param void
 @returns void
 */
void Square::setStars(){
    coordPairs.clear(); //clear vector
    //loop through coordinate combinations within bounds of shape
    for(int y=yPos; y<(yPos+sz); y++){
        for(int x=xPos; x<(xPos+sz); x++){
            //add coordinate pairs of shape to vector
            coordPairs.push_back(std::make_pair(x, y));
        }
    }
}



#endif /* Square_h */
