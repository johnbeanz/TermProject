# Term Project - John Beanblossom
Term project for Data Structures and Algorithms course
Goal of the assignment: Develop a simple spell checker and word suggestion program using Hashing.

A dictionary of words should be given as a first argument (filename) in the program. This input file is the simple text file "Dictionary.txt", where each line is a word (see Files section).

The program must ask the user to give a word.

(case 1) The program must respond with “True” if the word exists in the dictionary, and must suggest words (from Dictionary) starting with the same first two letters. At the end of each suggestion the exec. time (in micro-sec) must be displayed (see "TimeInterval.h" in Files section).

(case 2) If the input word does not exist in Dictionary due to user misspelling, and considering the first letter is correct, the program should return a recommended word from the dictionary (only one word). For example, instead of the word sentence, the user enters snetence, setnence, sentens, or setence, etc; the program should return: "do you mean sentence?" If "no", return "false". If "yes", return "true", and continues as normal (returns words starting with the same two letters).

(case 3) If the input word does not exist in Dictionary (no "resemblance" with an existing word), the program should return "false".

Example:

user enters:

$ hi

the program responds:

$ True

hic

him

hip

his

hit

500 micro-sec

Personal thoughts: This assignment really challenged me to think more critically than I have had to before on an assignment in this course. When I first started I had various ideas on how I should implement the assignment, but once I started digging into it, that got flipped upside down. Learning to code in C++ I really struggled with file I/O, which made this assignment way harder to begin than I had hoped. Not only did I have to relearn file I/O, but I had to learn to put this file into a hashtable, which I had not a ton of experience doing up until this point. I really enjoyed learning that new skill, though. Case 1 was not ultra hard to implement, although I did have a few bugs which took me quite some time to figure out. For example, at first the program would be able to find some words in the file, but not others. Which just led to incorrect results. Once that was sorted out and I had to move to case 2 is when things got tricky for me. I had to change the data structure I was using into a struct (something I havent worked with much before) and that was what had given me the most trouble on this assignment. I struggled learning what structs were, and how they were to be implemented. Since I didn't have the strongest knowledge on structs, it made it extremely hard for me to learn how to debug all the problems I was having (thousands it seemed). Funny enough, after writing that sentence, I decided to not use a struct and was able to find an alternative route. Instead I was just able to use vectors of strings and vectors of unsigned ints. This made it much easier for me to work with because I was familiar with both of those. For my suggestion algorithm I simply made the function void, and looped through all of the words, when it found a word that had the same first two letters as what was inputted by the user, it would simply print them. There was no reason to use a secondary array/vector or anything complicated like that, as I had originally thought. For my closest word algorithm, I looped through all words that start with the same first letter, and sets the last word in that category to be the closest word. It is not very accurate, I know. I really struggled with forming an idea on how to make this accurate.

How the user uses this project: Once running, the program will ask the user to input a word. If the word is found in the dictionary, the program will print true and give a list of all words in the dictionary that start with the same first two letters. If the word is misspelled, the program will ask the user if they meant _________, the program will suggest a word to them. If it is the word, the user will input 0 and the program will repeat the loop that shows the words with the same first two letters. If it is not the word, the program will return false, then start over. The program will continue to run until the user presses CNTRL-C.
