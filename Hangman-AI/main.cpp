//
//  main.cpp
//  Hangman-AI
//
//  Created by Asoby on 6/20/20.
//  Copyright © 2020 Asoby. All rights reserved.
//

#include <iostream>
#include "Hangman.hpp"
int main(int argc, const char * argv[]) {
    Hangman HangmanInstance("word");
    HangmanInstance.GuessLetter('o');
    HangmanInstance.PrintCurrent();
    HangmanInstance.GuessLetter('d');
    HangmanInstance.PrintCurrent();
    HangmanInstance.GuessLetter('p');
    HangmanInstance.PrintCurrent();
    return 0;
}
