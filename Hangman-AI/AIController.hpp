//
//  AIController.hpp
//  Hangman-AI
//
//  Created by Asoby on 6/20/20.
//  Copyright © 2020 Asoby. All rights reserved.
//

#ifndef AIController_hpp
#define AIController_hpp

#include <stdio.h>
#include <iostream>
#include "Hangman.hpp"
#include "SolverAI.hpp"

class AIController{
    SolverAI SolverInstance;
    AIController(SolverAI _SolverInstance){
        SolverInstance = _SolverInstance;
    }
    
    bool RepeatActions();
};
#endif /* AIController_hpp */






/* Behavior type designed in this script is fairly simple:
  1. The controller gets the SolverAI instance reference from the main program;
  2. Controller then has the SolverAI execute methods related both to it and Hangman class
  3. The loop breaks when the isWordGuessed variable is true.
*/
