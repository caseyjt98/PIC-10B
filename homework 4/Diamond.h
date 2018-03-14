//
//  Diamond.h
//  homework4
//
//  Created by Casey Taylor on 10/24/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef Diamond_h
#define Diamond_h

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

//DERIVED CLASS
class Diamond: public Shape{
public:
    Diamond(int, int, int);
    virtual void setStars();
    virtual ~Diamond() = default;
};

/*Diamond constructor creates a diamond object with the appropriate coordinates and size property
 @param xPos is the x value of the coordinate in the center of the diamond
 @param yPos is the y value of the coordinate in the center of the diamond
 @param sz is the size property of the diamond (number of stars from its center point to its
 top inclusive)
 @returns void
 */
Diamond::Diamond(int xPos, int yPos, int sz): Shape(xPos, yPos, sz){
    setStars();
}


/* This function identifies the coordinates within the bound of each new diamond shape, pushing back those coordinates into a vector of coordinate pairs
 @param void
 @returns void
 */
void Diamond::setStars(){
    coordPairs.clear(); //clear vector
    int topY = yPos + (sz-1);
    int xStart = xPos;
    int starsInRow = 1; //starts at tip of diamond
    int numOfRows = topY - (sz+1);
    
    //start from the top of diamond
    for(int y= topY; y >= numOfRows; y--){
        
        //loop through each row starting at xStart
        for (int x = xStart; x< (xStart + starsInRow); x++){
            //push back coordinate pairs into vector
            coordPairs.push_back(std::make_pair(x,y));
        }
        
        if(y > yPos){ //if in top half of diamond
            starsInRow = starsInRow + 2; //increment stars in row by 2
            xStart--; //decrement starting x position by 1
        
        
        } else { //else in bottom half of diamond
            starsInRow = starsInRow - 2; //decrement stars in row by 2
            xStart++; //increment starting x position by 1
        }
        
    }
    
}


#endif /* Diamond_h */
