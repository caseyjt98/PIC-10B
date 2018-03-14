//
//  main.cpp
//  homework4
//
//  Created by Casey Taylor on 10/20/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "Shape.h"
#include "Collection.h"
#include "Square.h"
#include "Diamond.h"

using namespace std;

int main() {
    
    // top left at (1,2), size 2x2
    std::shared_ptr<Shape> sp1 = std::make_shared<Square>(1, 2, 2);
    // centre at (5,8), size 3
    std::shared_ptr<Shape> sp2 = std::make_shared<Diamond>(5, 8, 3);
    // top left at (-1,1-), size 4
    std::shared_ptr<Shape> sp3 = std::make_shared<Square>(-1, -1, 4);
    // x from 0 to 10, y 0 to 10, inclusive
    Collection c(0, 10, 0, 10);
    // add the shapes
    c.addShape(sp1);
    c.addShape(sp2);
    c.addShape(sp3);
    // display the shapes
    c.display();
    std::cout << std::endl;
    // check total number of stars on display
    std::cout << "Total visible stars: " << c.totalStars() << std::endl;
    // add another square
    c.addShape(std::make_shared<Square>(5, 5, 1)); // top left at (5,5), size 1x1
    // change all shapes to have size 2 including the newly added square
    c.setSize(2);
    // move sp3 right 2 and down by 4
    sp3->moveBy(2, 4);
    // move all shapes left 1
    c.moveBy(-1, 0);
    // display the shapes
    c.display();
    std::cout << std::endl;
    // check total number of stars on display
    std::cout << "Total visible stars: " << c.totalStars() << std::endl;
    std::cin.get();
    
    return 0;
}


