//
//  SpellCheck.h
//  HOMEWORK2
//
//  Created by Casey Taylor on 10/10/17.
//  Copyright © 2017 Casey Taylor. All rights reserved.
//

#ifndef SpellCheck_h
#define SpellCheck_h

#include <iostream>
#include <unordered_set>
#include <string>


//declare functions
bool isValidWord(const std::string &toCheck, const std::unordered_set<std::string> &wordSet);
bool isWhiteSpace(char);
bool finalPunctuation(const std::string &word);
void dePunctuate(std::string &word);
void markMispelledWord(std::string &word);



#endif /* SpellCheck_h */
