//
//  SolverAI.cpp
//  Hangman-AI
//
//  Created by Asoby on 6/20/20.
//  Copyright © 2020 Asoby. All rights reserved.
//

/* ------- WORK IN PROGRESS ------- */
#include <iostream>
#include <fstream>
#include "SolverAI.hpp"

SolverAI::SolverAI(){ }
SolverAI::SolverAI(Hangman h){
    CurrentHangmanInstance = h;
    for(int i=0; i<26; i++)
    {
        Letter temp;
        temp.c = 'a'+i;
        temp.reps = 0;
        Letters.push_back(temp);
    }
    isWordGuessed = false;
    LoadWordsBase();
}
void SolverAI::LoadWordsBase(){
    std::string buffer;
    std::ifstream WordReader;
    WordReader.open("wordbase.txt");
    while (std::getline(WordReader, buffer))
    {
        WordBase.push_back(buffer);
    }
    WordReader.close();
}
int SolverAI::UpdatePotentialWordsByLength(){
    int wordLength = CurrentHangmanInstance.GetWordLength();
    for(int i=0; i<(int)WordBase.size(); i++){
        if(WordBase[i].length() == wordLength) PotentialWords.push_back(WordBase[i]);
    }
    return (int)PotentialWords.size();
}
int SolverAI::UpdatePotentialWordsByChars(){
    std::vector<std::string> tempWords;
    int result=0;
    int *_guessedLetters = CurrentHangmanInstance.GetGuessedLetters();
    for(int i=0; i<(int)PotentialWords.size(); i++){
        if(*(_guessedLetters+i)==1){
            char c = CurrentHangmanInstance.GetLetterByIndex(*(_guessedLetters)+i);
            for(int j=0; j<(int)PotentialWords.size(); j++){
                for(int k=0; k<PotentialWords[j].length(); k++){
                    if(PotentialWords[j][*(_guessedLetters)+i] == c){
                        tempWords.push_back(PotentialWords[j]);
                        result++;
                    }
                }
            }
        }
    }
    return result;
}
Letter SolverAI::GetLetterByChar(char _c){
    for(int i=0; i<26; i++){
        if(Letters[i].c == _c) return Letters[i];
    }
    return Letters[0];
}
Letter SolverAI::GetLetterByReps(int _reps){
    for(int i=0; i<26; i++){
        if(Letters[i].reps == _reps) return Letters[i];
    }
    return Letters[0];
}
void SolverAI::IncrementLetterRep(int _index){
    Letters[_index].reps++;
}
Hangman* SolverAI::GetCurrentHangmanInstance(){return &CurrentHangmanInstance; }
bool SolverAI::GetWordGuessed(){return isWordGuessed; }
void SolverAI::SetWordGuessed(){
    for(int i=0; i<CurrentHangmanInstance.GetWordLength(); i++){
        if(CurrentHangmanInstance.GetGuessedLetters()[i]==0) {
            isWordGuessed = false; return;
        }
    }
    isWordGuessed = true;
}
