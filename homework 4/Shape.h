//
//  Shape.h
//  homework4
//
//  Created by Casey Taylor on 10/24/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef Shape_h
#define Shape_h

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

//BASE CLASS
class Shape{
private:
protected:
    int xPos;
    int yPos;
    int sz;
    std::vector<std::pair<int, int>> coordPairs;
    
public:
    Shape(int, int, int); //shape's x pos, y pos, and size
    virtual void setStars() = 0; //purely virtual
    void moveBy(int, int);
    void setSize(int);
    virtual bool checkCoord(int, int);
    virtual ~Shape() = default;
    
};


/* Shape constructor creates a shape object with the appropriate coordinates and size property
 @param xPosition is the x value of the inputted initial coordinate
 @param Yposition is the y value of the inputted initial coordinate
 @param sz is the size property of the shape
 */
Shape::Shape(int xPosition, int yPosition, int size): xPos(xPosition), yPos(yPosition), sz(size) {
}


/* This function denotes how much to move the shape's center in the x and y directions
 @param moveX denotes how much to move the shape's center in the x direction
 @param moveY denotes how much to move the shape's center in the y direction
 @returns void
 */
void Shape::moveBy(int moveX, int moveY){
    //update xPos and yPos
    yPos = yPos + moveY;
    xPos = xPos + moveX;
    setStars(); //updates vector of coordinate pairs for shape
    
}


/* This function sets a new size parameter for the shape.
 @param size is the new size paramter 
 @returns void
 */
void Shape::setSize(int size){
    sz = size;
    setStars();
}

/* This function checks each individual coordinate within the display grid to see if it exists within the bounds of a shape.
 @param xPos is the x value of the coordinate being checked
 @param yPos is the y value of the coordinate being checked
 @returns bool, true if the coordinate exists within the bounds of shape
 */
bool Shape::checkCoord(int xPos, int yPos){
    bool isInShape = false; //default to false
    
    //express display coordinate as a pair of (x,y)
    std::pair<int, int> coordToCheck = std::make_pair(xPos, yPos);
    
    //loop through vector of coordinate pairs within shape and check against each coordinate
    for(int i = 0; i<coordPairs.size(); i++){
        if(coordPairs[i] == coordToCheck){
            isInShape = true; //coordinate exists within bounds of shape
        }
    }
    return isInShape;
}



#endif /* Shape_h */
