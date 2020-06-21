# Hangman AI

## About
The creation of this AI is solely for my C++ skills practicing. This AI includes very basic machine learning, which is implemented via memorizing letters that appear the most in the given words and ranking them, only to use them based on the frequency of their appearings.

## How it works
#### Classes
There are three main classes included:
* Hangman
* SolverAI
* AIController

##### Hangman
This class implements basic rules of the Hangman game an methods such as letter guessing. It is instanced inside SolverAI every time a new word is initialized.
##### SolverAI
The purpose of this class is to implement methods of solving words, such as initializing the words base (the Wordbase.txt file has 100 thousand words for the AI to choose from), filtering those words to temporary vector lists and various methods such as IncrementLetterRep(), used to later rank letters based on their frequency. It is instanced inside AIController class.
##### AIController
A wrapper class, the only purpose of which is to loop SolverAI methods while every letter in the word is not guessed.
## Project status

This project is currently under development and will be updated frequently. Have a great day!
