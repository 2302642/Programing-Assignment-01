/*!********************************************************************************************************************************************************************************************************************************
\file       q.hpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202    
\par        Section:         RSE
\par        Tutorial:        Assignment 1
\par        File created on: 12/01/2024
\brief      Read data from file and identify the statics of the file (the number of letters, white spaces, digits, other charcters, how many of the letters are upper and lower case, quantitiy of each alphabets, total number of 
            integers, the sum and the average of the integers) 

\par        File information:            
            This file is contains 1 function definitions to called by main in wc-driver.
            Functions:
            - void q(char const *input_filename, char const *analysis_file);                                                  // reading data from file and identify the number of letters, white spaces, digits, other charcters, 
                                                                                                                              // how many of the letters are upper and lower case, quantitiy of each alphabets, total number of 
                                                                                                                              // integers, the sum and the average of the integers 
**********************************************************************************************************************************************************************************************************************************/
#ifndef Q_HPP_
#define Q_HPP_

// Important note:
// If there any includes in this file, the auto grade will not
// accept the submission.

namespace hlp2 {
  // declare function q here ...
  void q(char const *input_filename, char const *analysis_file);                        // reading data from file and identify the number of letters, white spaces, digits, other charcters, how many of the letters
}                                                                                       // are upper and lower case, quantitiy of each alphabets, total number of intigers, the sum and the average of the integers 
#endif
