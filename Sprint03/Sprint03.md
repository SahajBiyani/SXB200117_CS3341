#The Sorting Competition
Sprint 3 - CSE 2341 - Fall 2016

## Introduction
Here's what you will have to do:  develop a program that can sort a list of words from a text file.  The words must be sorted according to the following conditions:

1. **Primary Sort Condition** - Sort by length of word (number of characters)
2. **Secondary Sort Condition** - Sort alphabetically
    Since this is a secondary sort condition, it will be applied to words that are all of the same length. So, all 2 letter words would be sorted alphabetically, all 3 letter words would be sorted alphabetically, and so on.

### The Fun Part
This will be a sorting competition!  The competition will be based on actual running time of your program.

## Implementation Points/Details

+ The input to your program will be one file. The first line of the file will be the number of words in the file. The second line of the file will be the number of words which you need to extract from the sorted list of words. For example, if the first line were 10 and the second line were 2, you would need to find the top 2 items from the 10 in the list. (It's possible that sorting the entire list just to find the top few is very inefficient!)

+ The output of your program will be one file. The file will consist of a sorted list of words from the input file, delimited with a linebreak.

+ The input will contain ASCII-encoded sequences of printable characters (likely, they will be words). Punctuation may be present, but you do not need to parse it out. Just assume that it is part of the word (example: **mark!!** would be length 6 and it would be different from **mark** as well as **MaRk**). This also implies that you’ll perform case-sensitive sorting - in other words, you essentially need to tokenize the input data file using whitespace characters as the delimiter.

+ The dataset may contain duplicate words.  Duplicates shall not be removed.

+ There is a reduced list of headers that you may include in your project.  You may only use the following headers from the STL:
    + iostream
    + fstream
    + cstring
+ You may use any of the classes you have built so far.

The spirit behind these stipulations is to prevent the use of any standard library functionality that already implements sorting.  We want everyone to go through the process of researching, testing, and iterating on their own implementations.  

+ You may work independently OR in teams of no more than two students. NO EXCEPTIONS, so PLEASE DON'T ASK

## Prizes
The First Place winner(s) can choose one of the following options as prizes:

+ Raise a programming project grade to a perfect score as long as a reasonable attempt was made on the assignment you wish to apply this to.  (Note: this is not the same as allowing you to skip a programming project). This does NOT apply to the final project.
+ Drop a homework grade.
+ 3 points added to your SEMESTER AVERAGE (yes, that's right.... your semester average)!!
+ Free dinner with Fontenot and some of the TAs (Fontenot gets veto power over restaurant).

The Second Place winner(s) can choose one of the following options as prizes:

+ Drop a homework grade.
+ Add 20 points to a programming project final grade (not including the final project).
+ Free Pokey-O's or FroYo (or some other kind of dessert) with Fontenot and some of the TAs

The Third Place winner(s) will get the following:

+ 10 points added to either a homework grade OR programming assignment of their choice.

## Writing the Sorter

Your sorting program must accept two command line arguments, one with the name of the input file of words, and the other with the name of the output file of sorted words:
```
./sorter <InputFile> <OutputFile>

```
How you design your sorting program is up to you! Your only goal is to make it work as fast as possible!

## Timing the Sorter

We will be timing your sorting algorithms by measuring the CPU time it takes to execute your entire program (from reading in the data all the way to writing it out to a file).
Every optimization you can make along the way will work in your favor.

We will use an OS-level tool to time the time it takes for the following command to run:
```
./sorter <InputFile> <OutputFile>

```

We will use a number of test datasets, varying in length from 10 elements to 10 million elements. For each dataset, the number of words we request will vary from 0% to 100% of the total words. (For example, for the 10 million word dataset, we may request  50 words, or we may request 9 million -- so your code should be prepared to do either in an optimal time).


## Things that will get you disqualified
These things will get you disqualified from the competition:

+ not conforming to the specification listed herein
+ attempting to hack the timing mechanism in some/any way
+ other sketchy things that violate the spirit of the exercise (we'll be looking at your source code, ya know!)


## Grading

|Outcome                  		 	| Points | Points Earned |
|:------------------------			|:----------:|---------------|
|Sorting Functionality      			| 50        |               |
