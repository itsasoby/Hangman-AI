//
//  Hangman.hpp
//  Hangman-AI
//
//  Created by Asoby on 6/20/20.
//  Copyright © 2020 Asoby. All rights reserved.
//

#ifndef Hangman_hpp
#define Hangman_hpp

#include <stdio.h>
#include <iostream>
#include <string>
class Hangman{
    std::string Word;
    int WordLength;
    int WrongLetters;
    int GuessedLetters[20];
public:

    //Default constructot
    Hangman();
    //Parametrized constructor
    Hangman(std::string);
    
/* ---- methods ---- */
    std::string GetWord();
    int GetWordLength();
    int GetWrongLetters();
    void IncrementWrongLetters();
    void SetGuessedLetter(int);
    char GetLetterByIndex(int);
    bool GuessLetter(char);
    void PrintCurrent();
    int *GetGuessedLetters();
    
};

#endif /* Hangman_hpp */
