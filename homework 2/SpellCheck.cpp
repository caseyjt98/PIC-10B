//
//  SpellCheck.cpp
//  HOMEWORK2
//
//  Created by Casey Taylor on 10/10/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#include "SpellCheck.h"

using namespace std;

//define functions

/* checks text file for white space (tab, new line, spaces)
 @param c is the character being checked for white space
 @return bool value indicates whethere or not the character is white space
 */
bool isWhiteSpace(char c){
    bool isWhiteSpace = false; //initialize to false
    if ((c == ' ') ||
        (c == '\n') ||
        (c == '\t') ||
        (c == '\r')) { //if it's an empty space
        isWhiteSpace = true;
    }
    return isWhiteSpace;
}

/* checks whether or not each word ends with a punctuation mark
 @param &word references each word from the inputted file
 @returns bool value indicating whether or not the word ends with punctuation
 */
bool finalPunctuation(const string &word){
    bool finalPunctuation = false; //initialize to false
    string finalChar = word.substr(word.length()-1, 1); //identify final char of word
    //check final char for punctuation mark
    if ((finalChar == ".") ||
        (finalChar == ",") ||
        (finalChar == "!") ||
        (finalChar == "?") ||
        (finalChar == ";") ||
        (finalChar == ":")) {
        finalPunctuation = true;
    }
    return finalPunctuation;
}


/* removes termianting punctuation mark and makes first letter lowercase
 @param &word references each punctuated word from the inputted file
 @returns void
 */
void dePunctuate(string &word){
    if (finalPunctuation(word)){ //if word is punctuated
        word = word.substr(0,word.length()-1); //remove punctuation mark
    }
    
    //extract first character of string word
    char c = word[0];
    
    if( ('A' <= c) && (c <= 'Z') ) { //if c is uppercase
        c += ('a' - 'A'); //convert to lowercase
    }
    
    word[0] = c;
}


/* compares inputted word with dictionary file to determine validity
 @param &toCheck references the unpunctuated, lowercase word being checked
 @param &wordSet references the set of words contained in the dictionary file
 */
bool isValidWord(const string &toCheck, const unordered_set<string> &wordSet){
    bool isValidWord = false; //initialize to false
    if(wordSet.find(toCheck) != wordSet.end()){ //if word is found in dictionary list
        isValidWord = true; //word is valid
    }
    return isValidWord;
}


/* marks mispelled words with asterisk symbols
 @param &word is the mispelled word that is being marked
 @returns void
 */
void markMispelledWord(string &word){
    if(finalPunctuation(word)){ //check for final punctuation
        //pad word with * * with punctuation outside
        word = "*" + word.substr(0,word.length()-1) + "*" + word.substr(word.length()-1,1);
    }
    else{ //if no punctuation
        //pad word with * *
        word = "*" + word + "*";
    }
}
