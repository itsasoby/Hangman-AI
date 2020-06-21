//
//  Hangman.cpp
//  Hangman-AI
//
//  Created by Asoby on 6/20/20.
//  Copyright © 2020 Asoby. All rights reserved.
//

#include "Hangman.hpp"
#include <string>

Hangman::Hangman(){ }
Hangman::Hangman(std::string _Word){
    Word = _Word;
    WordLength = _Word.length();
    for(int i=0; i<WordLength; i++) GuessedLetters[i] = 0;
    WrongLetters=0;
}
std::string Hangman::GetWord(){
    return Word;
}
int Hangman::GetWordLength(){
    return WordLength;
}
int Hangman::GetWrongLetters(){
    return WrongLetters;
}
void Hangman::IncrementWrongLetters(){
    WrongLetters++;
}
void Hangman::SetGuessedLetter(int _Index){
    GuessedLetters[_Index]=1;
}
char Hangman::GetLetterByIndex(int _Index){
    return Word[_Index];
}
bool Hangman::GuessLetter(char _c){
    bool isAnythingGuessed=false;
    for(int i=0; i<GetWordLength(); i++){
        if(Word[i] == _c) {
            GuessedLetters[i]=1;
            isAnythingGuessed=true;
        }
    }
    if(!isAnythingGuessed) WrongLetters++;
    return isAnythingGuessed;
}

void Hangman::PrintCurrent(){
    std::cout << "\nCurrent word state is: ";
    for(int i=0; i<GetWordLength(); i++){
        if(GuessedLetters[i]==0) std::cout <<"_";
        else std::cout << Word[i];
    }
    std::cout << std::endl;
    std::cout << GetWrongLetters() << " wrong letters by now.\n";
}

int* Hangman::GetGuessedLetters(){
    return GuessedLetters;
}
