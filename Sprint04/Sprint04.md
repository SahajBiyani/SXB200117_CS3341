# The (Mini) Search Engine!
Sprint 4 - CSE 2341 - Fall 2016

#### Due Monday Nov 7, 2016 at 6:00 am pushed to GitHub and Pull Request issued

## Introduction
In Sprint 4, you'll implement a very basic search engine.  A typical search engine consists of several substantial components working in concert to keep the index up to date as well as allow users to issue queries.  As part of implementing the search engine, you will implement an AVL Tree in C++ ( **maybe a hash table too?** ).  You will also make use of the classes you've built throughout the semester to support the implementation.

## Implementation Requirements

### The AVL Tree Class
The AVL tree class should provide an interface to a self-balancing binary search tree which performs self-balancing using the AVL algorithm. The AVL Tree class must be templated, and should contain inside of it a class to represent each individual node in the tree. The AVL Tree class must include a destructor which correctly frees all memory used by the tree.

### Dynamic Memory Management
Any class which manages dynamic memory (both of these will) needs to include an overloaded assignment operator, a copy constructor, and a destructor. Omitting any of these functions could cause segmentation faults, memory leaks, and shallow copy-related problems.

### Testing Your Classes
Be sure to include tests of your AVL tree class using the CATCH library.  

### Running Your Code
Using the CATCH testing interface, providing a TEST_CASE in tests.cpp is equivalent to providing a main function. Inside your Sprint3 folder, you can use ```g++ *.cpp -std=c++11``` to compile your code and then ```./a.out``` to execute it and run your test cases.

## The Mini Search Engine

You'll build a simple search engine that can read and parse a corpus of documents, create an inverted-file index from the corpus, and provide a simple boolean query processor for the UI.  

### The Corpus of Documents
A _corpus_ or _text corpus_ is a large, structured collection of text.  For our search engine, we will be using pre-processed articles from Wikipedia and/or Wikibooks.  The input data file will contain a set of "pages" marked up in an XML-like structure.  A Page will be demarked by <doc ...> ... </doc>.  Each <...> is called an _opening tag_ and each </...> is called a _closing tag_.  Each opening tag will conain a document id, a URL (hypothetical), and a title for the page/article.  The body of the page/article will appear between the opening and closing tags.  See the example file inside folder TestData.  

### The Inverted File Index Structure
The fundamental data structure of your search engine will be an Inverted File Index.  This is similar to the index you created in a previous sprint.  The difference here is that you'll be relating words to documents rather than words to pages from a book.  You'll implement the inverted file index using an AVL tree.  Essentially, each node in the tree will represent a word and a list of documents in which that word appears. 

When indexing the input data, you don't need to include words that are very common in the English language.  These are called _stop words_, and they don't really provide any substantive information when searching. You can use any list of stop words you can find online.  One such list can be found at http://www.ranks.nl/stopwords. 

### The Query Processor
Your interface to your search engine will be a very basic boolean query processor.  The input will come from a text file containing 1 to n queries.  Each query will:
 - be on a separate line of the input file
 - begin with the operator AND or OR
 - the operator will be followed by up to three query terms
 - an optional trailing NOT operator may be present with maximum one term to preclude from the search
 - no query will exceed 80 characters total
 
If the operator is AND, all query terms must be present in a page/article for it to be returned.  If the operator is OR, any one of the query terms must be present in a page/article for it to be returned.  If the NOT operator is present, you should remove any articles from the resultset that contain that word.  
 
### Input File
There will be two input files.  

1) The corpus of documents.  For an example of this input file, see small.xml in TestData folder.
2) A query file with an integer on the first line representing the number of queries in the file. 

Example Query:

```
AND beekeeper firefighter NOT arizona
```

### Output File
There will be one output file.  For each query in the 2nd input file:
- print the query exactly as it appears in the input file 
- print all pages/articles that satisfy the query in order by ID number.  For each article, print in the following format:
  - id|article title|URL
 


  - Maybe some extra features for extra credit? 
    - Hash table?
    - Compare performance of basic binary search tree to AVL tree?

## Submission
You must push your work to GitHub by the due date. Your git repository must contain all of your code, design documents, and test cases.

## Grading
Your project will be graded by one of the TAs for the course.  They've all taken the course, performed well, and understand the expectations of Professor Fontenot.  

|Outcome                  		 	  | Points    | Points Earned |
|:------------------------			  |:----------:|---------------|
|Design of AVLTree Classes      	| 20        |               |
|AVLTree Class Tests     			    | 20        |               |
|Boolean Query Processor          | 20        |               |   
|Design of Mini Search Engine     | 30        |               |
|Source Code Quality    			    | 30        |               |
|Mini Search Engine Functionality | 40        |               |

**Please note that if any memory leaks exist in any of your classes, you will lose up to 30 points per data structure.**
**Implementations which do not resemble an actual hash table or AVL tree will earn a grade of 0.**
