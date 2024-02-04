// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int processGuess(char* word, const char* targetWord, char guess);

const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // Initialized with *'s and then
                  //  changed to the actual letters when the 
                  //  user guesses the letter

  //fills word[] with *'s and is the length of targetWord
  for(int i = 0; i < strlen(targetWord); i++) { 
    *(word +i) = '*';
  }
  
  *(word + strlen(targetWord)) = '\0';
  

  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while(numTurns>0 ) {
    cout << "Current word: " << word << endl;
    
    cout << numTurns << " remain...Enter a letter to guess: " << endl;
    cin >> guess;
    cout << endl;
        
    if(processGuess(word, targetWord, guess) == 0) {
      numTurns--;
    }
      
    //if words are the same, exit the while loop
    if(strcmp(targetWord, word) == 0) {
      break;
    } 
  }

  // Print out end of game status
  if (numTurns > 0) {
    cout << "The word was: " << targetWord << ". You win!" << endl;
  }
  
  else {
    cout << "Too many turns...You lose! " << endl;
  }
 
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int occur = 0;
  
  for(int i = 0; i < strlen(targetWord); i++) {
    if(*(targetWord+i) == guess) {
      occur++;
      *(word+i) = guess; 
    }
   
  }
  return occur;
  
}

