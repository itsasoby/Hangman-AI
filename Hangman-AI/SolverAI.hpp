//
//  SolverAI.hpp
//  Hangman-AI
//
//  Created by Asoby on 6/20/20.
//  Copyright © 2020 Asoby. All rights reserved.
//

#ifndef SolverAI_hpp
#define SolverAI_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Hangman.hpp"

typedef struct Letter{
    char c;
    int reps;
}Letter;

class SolverAI{
    std::vector<std::string>WordBase;
    std::vector<std::string>PotentialWords;
    std::vector<Letter>Letters;
    Hangman CurrentHangmanInstance;
    bool isWordGuessed;
    
public:
    SolverAI();
    SolverAI(Hangman);
    void LoadWordsBase();
    int UpdatePotentialWordsByLength();
    int UpdatePotentialWordsByChars();
    Letter GetLetterByChar(char);
    Letter GetLetterByReps(int);
    void IncrementLetterRep(int);
    Hangman* GetCurrentHangmanInstance();
    bool GetWordGuessed();
    void SetWordGuessed();
};
#endif /* SolverAI_hpp */
