//
//  Collection.h
//  homework4
//
//  Created by Casey Taylor on 10/24/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

/*
 I, CASEY TAYLOR, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
 I did not copy code from anyone, student or otherwise.
 */

#ifndef Collection_h
#define Collection_h

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "Square.h"
#include "Shape.h"

//stores a drawing area and shapes
class Collection{
    
private:
    std::shared_ptr<Shape> ptr;
    int lowX;
    int lowY;
    int highX;
    int highY;
    std::vector<std::shared_ptr<Shape>> shapes;
    std::vector<std::pair<int, int>> starCoords;
    
public:
    Collection(int, int, int, int);
    void addShape(std::shared_ptr<Shape>);
    void display();
    size_t totalStars();
    void moveBy(int, int);
    void setSize (int);
    ~Collection() = default;
    
    
};

/* Collection constructor creates a display grid based on the inputted range of x and y values
 @param lowestX is the lowest x value in the range of the display grid
 @param highestX is the highest x value in the range of the display grid
 @param lowestY is the lowest y value in the range of the display grid
 @param highestY is the highest y value in the range of the display grid
 */
Collection::Collection(int lowestX, int highestX, int lowestY, int highestY): lowX(lowestX), highX(highestX), lowY(lowestY), highY(highestY) {
}


/* This function adds each new shape to vector of shapes using smart pointers 
 @param pointer is a shared pointer to the new shape that is being added
 @returns void
 */
void Collection::addShape(std::shared_ptr<Shape> pointer){
    shapes.push_back(pointer);
}


/* This function displays the shapes over the appropriate range of values, printing '*' if there is a shape at the coordinate and '-' if there is no part of a shape there. It also prints a list of the displayed shape types in order.
  @param void
  @returns void
 */
void Collection::display(){ //make use of dynamic cast
    std::string displayString = "- "; //initialize to default
    
    //finding star coordinates
    for(int y = highY; y>=lowY; y--){ //loop through displayed coordinates
        for(int x = lowX; x<=highX; x++){
            
            //check coordinate against shapes
            for(int i = 0; i<shapes.size(); i++){ //loops through vector of shapes
                if (shapes[i]->checkCoord(x, y) == true){ //if coord is in shape
                    starCoords.push_back(std::make_pair(x,y)); //push back coordinate into vector of star coords
                }
            }
        }
    }
    
    //print display
    for(int y = lowY; y<=highY; y++){ //loop through displayed coordinates
        for(int x = lowX; x<=highX; x++){
            
            displayString = "- "; //assume no shape exists at coordinate
            for(int i = 0; i<starCoords.size(); i++){ //loop through vector of star coords
                if(starCoords[i].first == x && starCoords[i].second == y){ //if coordinate matches star coordinate
                    displayString = "* ";
                }
            }
            std::cout << displayString;
            
        }
        std::cout << std::endl; //end of row
    }
    
    std::cout << "Shapes are: ";
    //loop through vector of shared pointers to shapes
    for(const auto& x : shapes){
    
        
        auto p = std::dynamic_pointer_cast<Square>(x); //take shape pointer and try to make it into a square pointer if possible
        if(p){ //cast succeeded, underlying object was Square
            std::cout << "square ";
        }else{ //dynamic type doesnt point to square or derived class
            std::cout << "diamond ";
        }
    }
}

/* This function returns the total number of stars within the plot range, as stored in a vector of star coordinates.
 @param void
 @returns size_t, the number of stars within the plot range
 
 */
size_t Collection::totalStars(){
    return starCoords.size(); //return number of stars within plot range
}

/* This function moves ALL shapes up/down and left/right, depending on the inputted values
 @param moveX describes how much to move all shapes in the x direction
 @param moveY describes how much to move all shapes in the y direction
 @returns void
 */
void Collection::moveBy(int moveX, int moveY){
    //loop through vector of shapes
    for (int i = 0; i<shapes.size(); i++){
        //move each shape
        shapes[i]->moveBy(moveX, moveY);
    }
}

/* This function sets the size property of ALL shapes
 @param sz determines the size property of all shapes
 @returns void
 */
void Collection::setSize(int sz){
    //loop through vector of shapes
    for (int i = 0; i<shapes.size(); i++){
        //set size of each shape
        shapes[i]->setSize(sz);
    }
}



#endif /* Collection_h */
