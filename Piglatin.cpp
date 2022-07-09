//Benjamin van Rhee PigLatin Translate Program
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>

std::string piglatin_woord( std::string woord);

int main(){
    //Ask a Sentence 
    std::string woordofzin;
    std::cout << "Geef mij een zin of een woord alsjeblieft:" << std::endl;


    std::getline(std::cin, woordofzin);
    std::istringstream iss(woordofzin);

    std::string piglatinzin;
    std::string woord;

    //Here the piglatin sentence is created word for word 
    while (iss >> woord)
    {
        piglatin_woord(woord.c_str());
        piglatinzin +=  piglatin_woord(woord.c_str()) + " ";
    }

    std::cout << piglatinzin << "\n";

    return 0;
}

//Here it checks if one of the words in the centence is a vowel
bool isMedeklinker(char input){

    char medeklinker[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r','s', 't', 'y', 'v', 'w', 'x', 'z', '\0'};

    for(int x = 0; x < 21; x++){
        if (tolower(input) == medeklinker[x]){
            return true;
        }
    }
    return false;
}

//Here it checks if one of the words in the centence is a constant
bool isKlinker(char input){
    
    char klinker[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    
    for(int x = 0; x < 5; x++){
        if(tolower(input) == klinker[x]){
            return true;
        }
    }
    return false;

}

//Here it turns the word into a Piglatin word
std::string piglatin_woord( std::string woord){

    std::string leesteken;
    char klinker[] = {'a', 'e', 'i', 'o', 'u'};

    //Here it looks at the first character if it is a vowel 
    if(isMedeklinker(woord[0])){
        
        //Here it looks at the first constant
        std::string eersteMedeklinkers;
        while(isMedeklinker(woord[0]))
        {
            eersteMedeklinkers += woord[0];
            woord.erase(0,1);
        }
        
        //This checks if the first character is capitalized, then capitalizes the new first character
        if (isupper(eersteMedeklinkers[0])){
            eersteMedeklinkers[0] = tolower(eersteMedeklinkers[0]);
            woord[0] = toupper(woord[0]);
        }
        
        //Here it looks at the punctuation marks, first it removes all punctuation marks then it stores it in a variable.
        while(ispunct(woord[woord.length()-1])){ 
            leesteken = woord[woord.length()-1] + leesteken;
            woord.resize(woord.length()-1);
        }

        //Here the output is given to be printed in the main
        std::string output = woord + eersteMedeklinkers + "ay" + leesteken; 
        return output;
    }
    //Here it looks like the first character is a vowel
    else if(isKlinker(woord[0])){

        //Here it looks at the punctuation marks, first it removes all punctuation marks then it stores it in a variable 
        while(ispunct(woord[woord.length()-1])){ 
            leesteken = woord[woord.length()-1] + leesteken;
            woord.resize(woord.length()-1);
        }

        //Here the output is given to be printed
        std::string output = woord + "way" + leesteken;
        return output;
    }
    
    return woord;
}
