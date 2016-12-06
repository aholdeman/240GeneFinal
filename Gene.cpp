/* 
 * File:   Gene.cpp
 * Author: PhoebeNgo
 * 
 * Created on December 5, 2016, 9:21 PM
 */

#include "Gene.h"
#include "Sequence.h"
#include <iostream>

Gene::Gene() {
    length = 0;
    sequenceArray = 0;
}

Gene::Gene(ifstream& infile) {
    length = 0;    
    string Input = " ";
    char charInput[256] = " ";
    //finds how many sequences there are in file
    while(!infile.eof()) { //while the scanner is not at the end of the file
            getline(infile, Input); //skips the first line that will be an ID
            getline (infile, Input); //reads line and assigns it to the string Input
            length++;
    }
    
    infile.clear();
    infile.seekg(0);

    int counter = length - 2;
    Sequence *sequenceArray;
    sequenceArray = new Sequence[length];


    length = 0;
    infile.clear();
    infile.seekg(0);
    while(length <= counter){
            getline(infile, Input);
            getline (infile, Input); // this is the actual sequence info
            int i = 0;
            while(Input[i] != '\0') {
                    if(Input[i] == 'C' || Input[i] == 'A' || Input[i] == 'G' || Input[i] == 'T') {    
                        charInput[i] = Input[i];
                        i++;
                    }
                    else {
                            cout << "Invalid input. Sequences must contain ONLY A, G, C, or T." << endl;
                            exit(1);
                    }
            }

            sequenceArray[length] = charInput;
            length++;
    }
    
    int i(0);
    while(i <= length) {
        cout << sequenceArray[i] << endl;
        i++;
    }
}

void Gene::compare(Sequence &second) {
    //TODO
}

/*
void Gene::print(ofstream &outstream) {
    outstream.open("testOutput.txt");
    if (outstream.fail()) {
        cout << "There's an error you dingus!!!!!!!!!" << endl;
        exit(1);
    }
    
    int actualValuesInFile = length - 2;
    int i(0);
    while(i <= actualValuesInFile) {
        cout << sequenceArray[i] << endl;
        i++;
    }
}*/

int Gene::getLength() {
    return length;
}

Gene::Gene(const Gene& orig) {
}

Gene::~Gene() {
    delete [] sequenceArray;
}
