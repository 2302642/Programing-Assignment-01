/*!********************************************************************************************************************************************************************************************************************************
\file       q.cpp
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
#include <iostream>
#include <iomanip>
#include <fstream>  

// Important notes:
// The auto grader will look for exactly the above three includes. If there any additional includes, it will not compile your file.
// The auto grade will not accept any functions not declared in these three header files [even in comments]!!! You're warned!!!
namespace hlp2 {
//################################################################################################################################################################################################################################
  void q(char const *input_filename, char const *analysis_file){
//================================================================================================================================================================================================================================
//|                                                                              READ FILE SECTION                                                                                                                               |
//================================================================================================================================================================================================================================
    std::ifstream inputfile;                                                                                                  // setting file to be opened for reading
    inputfile.open(input_filename);                                                                                           // opening the file
    if (!inputfile.is_open()) {                                                                                               // check if the file can be opened
        std::cout << "File " << input_filename << " not found." << std::endl;                                                 // print to error stream if file cannot be opend
        inputfile.close();                                                                                                    // closing the file if cannot be opened
        return;
    } 
//********************************************************************************************************************************************************************************************************************************
  char character;                                                                                                       
  int totalnumchar = 0, whitespacecount = 0, othercount = 0;
  int lettercount = 0, uppercount = 0, lowercount = 0, alphabetcount[26] = {0};
  int digitcount = 0, numbercounter = 0,  integersum = 0, currentnumber = 0;
//===============================================================================================================================================================================================================================
//|                                                                 LETTER AND NUMBER STATISTICS SECTION                                                                                                                        |
//===============================================================================================================================================================================================================================
  while (inputfile.get(character)){totalnumchar++;}                                                                           // counting the total number of characters found in the file
  inputfile.close();

  inputfile.open(input_filename);
  char* input_data = new char[totalnumchar];                                                                                  // allocating storage for data taken from file  
  for (int i = 0; i<totalnumchar; i++){ inputfile.get(input_data[i]); }                                                       // storing data from file into a character array
  inputfile.close();

  for (int i = 0; i<totalnumchar; i++){
    if (input_data[i] >= 'A' && input_data[i] <= 'Z' ) {                                                                      // checking for uppercase letters and counting the number of uppercase letters 
        for(int ascii = 65; ascii <=90; ascii++){                                                                             // and total number of alphabets found in the file
            if(input_data[i] == ascii){ alphabetcount[ascii-65]++; }
        }
        uppercount++; lettercount++;  
    }
    else if (input_data[i] >= 'a' && input_data[i] <= 'z') {                                                                  // checking for lowercase letters and counting the number of lowercase letters 
        for(int ascii = 97; ascii <=122; ascii++){                                                                            // and total number of alphabets found in the file
            if(input_data[i] == ascii){ alphabetcount[ascii-97]++; }
        }
        lowercount++; lettercount++; 
    }
    else if (input_data[i]==' ' || input_data[i]=='\t' || input_data[i]=='\n' || input_data[i]=='\r'){whitespacecount++; }    // checking for white space and counting the number of white space found in the file
    else if (input_data[i] >= '0' && input_data[i] <= '9') {
      
      currentnumber = currentnumber * 10 + (input_data[i]-'0');                                                                 
      if(!(input_data[i+1]>= '0' && input_data[i+1]<= '9')){integersum +=currentnumber; currentnumber=0;numbercounter++;}     // identifing for multidigit number and adding to the total sum of integers
      digitcount++;                                                                                                           // checking for single digits and counting the number of digits found in the file

    }
  }
  othercount=totalnumchar-lettercount-digitcount-whitespacecount;                                                             // counting the total number of other characters that are in the file
  delete[] input_data;
//===============================================================================================================================================================================================================================
//|                                                LETTER STATISTICS SECTION (NOT USING to be used with NUMBER ANALYSIS SECTION)                                                                                                |
//===============================================================================================================================================================================================================================
/*  while (inputfile.get(character)) {                                                                                        // Read characters until the end of the file is reached
    if (character >= 'A' && character <= 'Z' ) {                                                                              // checking for uppercase letters and counting the number of uppercase letters 
        for(int ascii = 65; ascii <=90; ascii++){                                                                             // and total number of alphabets found in the file
            if(character == ascii){ alphabetcount[ascii-65]++; }
        }
        uppercount++; lettercount++; 
    }
    else if (character >= 'a' && character <= 'z') {                                                                          // checking for lowercase letters and counting the number of lowercase letters 
        for(int ascii = 97; ascii <=122; ascii++){                                                                            // and total number of alphabets found in the file
            if(character == ascii){ alphabetcount[ascii-97]++; }
        }
        lowercount++; lettercount++; 
    }
    else if (character == ' ' || character == '\t' || character == '\n' || character == '\r') {whitespacecount++;}            // checking for white space and counting the number of white space found in the file
    else if (character >= '0' && character <= '9') { digitcount++; }                                                          // checking for single digits and counting the number of digits found in the file
    else{othercount++;}                                                                                                       // counting the total number of other characters that are in the file
    totalnumchar++;                                                                                                           // counting the total number of characters found in the file
  }
  inputfile.close();*/
//===============================================================================================================================================================================================================================
//|                                                NUMBER ANALYSIS SECTION (NOT USING to be used with LETTER STATISTICS SECTION)                                                                                                |
//===============================================================================================================================================================================================================================
/*  int numsize = 0;
  char* input_data = new char[totalnumchar];                                                                                  // allocating storage for data taken from file
  inputfile.open(input_filename);
  for (int i = 0; i<totalnumchar; i++){ inputfile.get(input_data[i]); }                                                       // storing data from file till EOF/number of characters in the file into an array 
  inputfile.close();
  for (int i = 0; i < totalnumchar; ++i){
      if(!(input_data[i] >= '0' && input_data[i] <= '9')){ input_data[i] = ' '; }                                             // replacing all other characters except 0 to 9 into ' '(space)
  }
  for (int i = 0; i < totalnumchar; ++i){
    if((input_data[i] >= '0' && input_data[i] <= '9') && input_data[i+1] == ' ')   { input_data[i+1] = ','; numbercounter++;} // replacing a character besides 0 to 9 character into ','(comma)
    else if(!(input_data[i] >= '0' && input_data[i] <= '9') && input_data[i] != ','){ input_data[i] = '\0'; }                 // replacing a character besides 0 to 9 and ','(comma) to '\0'(null)
  }
  for (int i = 0; i < totalnumchar; ++i){
    if((input_data[i] >= '0' && input_data[i] <= '9') && input_data[i+1] == ','){                                             // adding all the single digit numbers 
      currentnumber = currentnumber * 10 + (input_data[i]-'0'); numsize++;
    }
    else if ((input_data[i] >= '0' && input_data[i] <= '9') &&(input_data[i+1] >= '0' && input_data[i+1] <= '9')){            // putting single digit numbers with another single digit number to get a multi digit number
      currentnumber = currentnumber * 10 + (input_data[i]-'0'); numsize++;
    }
    else if(numsize >0){ integersum +=currentnumber;  numsize =0;  currentnumber=0; }                                         // adding all the multi digit numbers
  }
  delete[] input_data;*/
//===============================================================================================================================================================================================================================
//|                                                                            WRITE FILE SECTION                                                                                                                               |
//===============================================================================================================================================================================================================================
   std::ofstream outputfile;                                                                                                  // setting file to be opened for writing
    outputfile.open(analysis_file);                                                                                           // opening the file
    if (!outputfile.is_open()) {                                                                                              // Check if the file can be opened
        std::cout << "Unable to create output file " << analysis_file << "." << std::endl;                                    // print to error stream if file cannot be opend
        outputfile.close();                                                                                                   // closing the file if cannot be opened
        return;
    } 
//===============================================================================================================================================================================================================================
//|                                                                            OUTPUT SECTION                                                                                                                                   |
//===============================================================================================================================================================================================================================
  outputfile << "Statistics for file: " << input_filename << std::endl;                                                       // writing the number for alphabets found in the file into another file
  outputfile << "---------------------------------------------------------------------\n" << std::endl;
  outputfile << "Total # of characters in file: " << totalnumchar << "\n" << std::endl;
  double max_char = static_cast<double>(totalnumchar);
  outputfile <<std::left<<std::setw(20)<< "Category" <<std::setw(29)<< "How many in file" << "% of file" << std::endl;
  outputfile << "---------------------------------------------------------------------" << std::endl;
  outputfile <<std::left<<std::setw(20)<< "Letters"          <<std::right<<std::setw(16)<< lettercount     <<std::setw(20)<< std::fixed << std::setprecision(2)<<(lettercount/max_char)*100     << " %" << std::endl;
  outputfile <<std::left<<std::setw(20)<< "White space"      <<std::right<<std::setw(16)<< whitespacecount <<std::setw(20)<< std::fixed << std::setprecision(2)<<(whitespacecount/max_char)*100 << " %" << std::endl;
  outputfile <<std::left<<std::setw(20)<< "Digits"           <<std::right<<std::setw(16)<< digitcount      <<std::setw(20)<< std::fixed << std::setprecision(2)<<(digitcount/max_char)*100      << " %" << std::endl;
  outputfile <<std::left<<std::setw(20)<< "Other characters" <<std::right<<std::setw(16)<< othercount      <<std::setw(20)<< std::fixed << std::setprecision(2)<<(othercount/max_char)*100      << " %" << std::endl;
//*******************************************************************************************************************************************************************************************************************************
 outputfile << "\n\nLETTER STATISTICS\n\n";                                                                                 // writing the statics of letters found in the file into another file
  double max_letters = static_cast<double>(lettercount);
  outputfile <<std::left<<std::setw(20)<< "Category" <<std::setw(22)<< "How many in file" << "% of all letters" << std::endl;
  outputfile << "---------------------------------------------------------------------" << std::endl;
  outputfile <<std::left<<std::setw(20)<< "Uppercase" <<std::right<<std::setw(16)<< uppercount <<std::setw(20) << std::fixed <<std::setprecision(2)<<(uppercount/max_letters)*100 << " %" << std::endl;
  outputfile <<std::left<<std::setw(20)<< "Lowercase" <<std::right<<std::setw(16)<< lowercount <<std::setw(20) << std::fixed <<std::setprecision(2)<<(lowercount/max_letters)*100 << " %" << std::endl;
  for(int i=0; i<26; i++){                                                                                                  // writing the statics of each alphabets found in the file
    outputfile <<std::left<<std::setw(20)<< static_cast<char>('a'+i) <<std::right<<std::setw(16)<< alphabetcount[i] <<std::setw(20)<<std::setprecision(2)<<(alphabetcount[i]/max_letters)*100 << " %" << std::endl;
  }
//*******************************************************************************************************************************************************************************************************************************
  outputfile << "\n\nNUMBER ANALYSIS\n\n";                                                                                  // writing the statics of numbers found in the file into another file
  outputfile <<std::left<<std::setw(37)<< "Number of integers in file:" << numbercounter <<std::endl;
  outputfile <<std::left<<std::setw(37)<< "Sum of integers:"            << integersum <<std::endl;
  outputfile <<std::left<<std::setw(37)<< "Average of integers:"        << std::fixed << std::setprecision(2);
  if (numbercounter != 0) { outputfile << (static_cast<double>(integersum) / numbercounter) << std::endl; }                 // writing the average of the sum of the numbers found in the file and storing it into another file
  else { outputfile << static_cast<double>(integersum)*100 << std::endl; }
  outputfile << "_____________________________________________________________________" << std::endl;
  outputfile.close();
  }
//##############################################################################################################################################################################################################################
}
