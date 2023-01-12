// Spell Checker using Hashing by John Beanblossom, this was a doozy
#include "TimeInterval.h"
#include <cstring>
#include <iostream>
#include <vector>


// changed all unsigned int to int
unsigned int hashBuffer(const char *buf) {
    unsigned int hash = 0;

    int length = strlen(buf);
    for (int i = 0; i < length; i++) {
        //Ignore any whitespace.
        if(buf[i] < 65) continue;
        hash = (31 * hash) + buf[i]; // using prime number to multiply hash
    }                              // end for
  return hash;
} // end hashBuffer

int createDict(FILE *file, std::vector<std::string> *words, std::vector<unsigned int> *hashes) {

    char buf[64];
    while (!feof(file) && !ferror(file)) {
        fgets(buf, 64, file);
        int length = strlen(buf);
        if(buf[length-1] == '\n') buf[length - 1] = '\0';
    
            std::string item(buf);
            words->push_back(item);

            unsigned int hash = hashBuffer(buf);

            hashes->push_back(hash);

    } // end while
    return 0;
} // end createdict

bool isInDictionary(std::string userInput, std::vector<unsigned int> *hashes, std::vector<std::string> *words) {
    unsigned int hash = hashBuffer(userInput.c_str());

    for (int i = 0; i < hashes->size(); i++) {
        if (hash == hashes->at(i)) {
            return true;
        } // end if
    }   // end for
  return false;
} // end is in

void suggestions(std::string word, std::vector<std::string> *words) {
    // Iterate through all words
    for (int i = 0; i < words->size(); i++) {
        if ((word[0] == words->at(i)[0]) && (word[1] == words->at(i)[1])) {
            std::cout << words->at(i) << std::endl;
        }
    }
} // end suggestions

//closest word tries to find the closest word to a misspelling by taking the value at location 0,
//then it will iterate through all the words in the vector and use the last one
std::string closestWord(std::string word, std::vector<std::string> *words){
  
    std::string closestWord = words->at(0);
    for(int i = 0; i < words->size(); i++){
        if(word[0] == words->at(i)[0]){
            closestWord = words->at(i);
            break;
        }
    }
  
    return closestWord;  
}//end closest word

int main(int argc, char **argv) {
    int userInteger;
    // way to show usage to the user
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " Dictionary.txt" << std::endl;
        return 1;
    } // end if

    FILE *dict = fopen(argv[1], "r"); // creates pointer to file, r means read
                                    // only
    if (dict == NULL) {
        std::cout << "File not found. " << std::endl;
        return 1;
    } // end if

  // Our implementation of the HashSet
    std::vector<unsigned int> hashes;
    std::vector<std::string> words;

    createDict(dict, &words, &hashes);

    while (true) {

        std::string userInput;
        std::cout << "Please enter a word: " << std::endl;
        std::cin >> userInput;

        TimeInterval timer = TimeInterval();
        timer.start();

        // Check HashSet
        if (isInDictionary(userInput, &hashes, &words)) {
            std::cout << "True. " << std::endl;
            suggestions(userInput, &words);
        } // end check hashset
        else {
            std::string closest = closestWord(userInput, &words);
            timer.stop();
            // Find Closest Word & Print "Did you mean _____?"
            std::cout.flush();
            std::cout<<"  Did you mean: " << closest<<std::endl;
            std::cout.flush();
      
            std::cout<<"Yes (0) or No (1)?"<<std::endl;

            std::cin>>userInteger;
            std::cout<<std::endl;
            userInput.pop_back();
            timer.start();
        //if yes
            if(userInteger == 0){
                std::cout<<"True. "<<std::endl;
                suggestions(closest, &words);
            } else {
      //if no
                std::cout<<"False"<<std::endl;
                }
        }
    timer.stop();
    std::cout << timer.GetInterval() << " micro-sec" << std::endl;

  } // end while
  return 0;
} // end main
