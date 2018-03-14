//  main.cpp
//  hw2
//  Created by Casey Taylor on 10/9/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.



/*
I, CASEY TAYLOR, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
I did not copy code from anyone, student or otherwise.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>
#include "SpellCheck.h"

using namespace std;


int main() {
    
    string word;
    string fileName; //name of inputted file
    unordered_set<string> wordSet; //empty set to store words from dictionary file
    vector<string> display; //strores entire text display as collection of words & strings of white space
    string s; //string to hold white characters and words, which will then be added to display vector

    
    //create input file stream to read from dictionary.txt
    ifstream dictionary("dictionary.txt");
    
    if (!dictionary.is_open()){ //check for successful opening of file
        cout << "Error. Input file could not be opened." << endl;
    }
    
    //read in each word from text file, get entire line
    while(dictionary >> word){
        wordSet.insert(word); //add each word to unordered set
    }
    
    //prompt for file to spell check
    cout << "Enter file to spell check: ";
    getline (cin, fileName);
    
    //create input file stream
    ifstream userFile(fileName);
    
    if (!userFile.is_open()){ //check for successful opening of file
        cout << "Error. Input file could not be opened." << endl;
    }
 

    
    while(!userFile.eof()){ //continue until end of file
        
        if(isWhiteSpace(userFile.peek())){ //returns an int-value based on the next char but does not remove it
            //extract as much white space as possible
            while(isWhiteSpace(userFile.peek())){
                char whiteChar = userFile.get(); //returns an int-value based on the next char and extracts it
                s += whiteChar; //add white character to string
            }
        } else{ //if it's a word
            userFile >> s;
            string toCheck = s;
            //check word for uppercase letters and punctuation
            dePunctuate(toCheck);
            
            //check if depunctuated word is valid
            if(isValidWord(toCheck,wordSet) == false){
                markMispelledWord(s); //mark mispelled word with * *
            }
        }
        
        display.push_back(s); //add string to display vector
        s.clear(); //clear string
    }
    
    string finalDisplay= ""; //initialize empty string
    //output each vector index in the form of a string
    for(int i=0; i < display.size(); i++){
        finalDisplay = finalDisplay + display[i];
    }
    
    //output final display of corrected text
    cout << endl << finalDisplay << endl << endl;
    
    //close files
    dictionary.close();
    userFile.close();
    
    return 0;
}




