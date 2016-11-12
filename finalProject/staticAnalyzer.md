
# Is it Good Enough?

#### Due Date: Tuesday Dec 6 by 6am with pull request issued on GitHub
#### Live Demos will take place on Monday Dec 5. 

## Introduction

Writing good code is hard work.  It may seem like one just needs to throw some control structures and other constructs on the screen and hope for the best.  But we all know through personal experiences that this isn't the best way to code.  One way that developers can generate better code is to use [static code analysis](https://en.wikipedia.org/wiki/Static_program_analysis) tools.  Basically, static analysis of code doesn't require the software to be executed; it analyzes the source code directly.

Let's look at some examples.  One thing we all know about good code is that good variable names are used by the developer.  It is horrendously painful to use variable names like 'i1', 'varA', 'varB', etc.  But what makes a good variable name?  How do you look at a block of code and evaluate the "goodness" of the variable names?  Can you reduce that to an algorithm?

Another simple example of static code analysis is counting the lines of code in the codebase (no comments included). Or how about the average number of lines of code per function/method?  Bill Gates once said, "Measuring programming progress by lines of code is like measuring aircraft building progress by weight."  Maybe he is right.  Maybe there's some other useful information you can deduce by knowing a count of the lines of code in a project.

A much more sophisticated measure of software quality is its [cyclomatic complexity](https://en.wikipedia.org/wiki/Cyclomatic_complexity).  Essentially, the cyclomatic complexity of a source code base is a measure of its overall complexity.  It can be measured at multiple levels as well (the function level, the module level, etc.). Cyclomatic complexity is based on the control flow graph of the source code which is a  representation of all of the paths that could be traversed through the source code when it is executing.  Related to this concept of knowing all paths through a block of code, you could determine if you have generated tests (as in CATCH or some other testing framework) that cover all possibilities.

The methods of analysis above are a small set of examples of ways to think about static code analysis.  There are tons more that you could come up with with a little thinking and/or research online. For your final project in 2341, you're going to build a custom Good Enough? tool that will help the developer write better code or tighten up an already existing code base.


## The Tool

The Good Enough? Tool will read in an entire codebase, analyze the C/C++ code, and provide a report out to the user about the goodness level of their source code using at least five (5) different metrics or types of analysis.  The output will either be in "brief" form or "verbose" form.  

Here are the fundamental steps:
1. Read a fully qualified path (START directory) from a file whose name will be a command line argument
2. Recursively descend through all of the folders and files in that directory and analyze each c/c++ file encountered.  A c/c++ source file can be identified by ending in .h, .hpp, .c, .cpp.
3. Output to a file the brief score(s) or the verbose analysis (would include the brief score as well).

### What Metrics Should You Use?

You decide!  Do some research.  Remember, you want to provide the most useful and valuable information to the developer as possible.  The only stipulation here is that the result must include a "goodness score" where "good" code has a lower score than "bad" code.

### Executing the tool

Your tool should be executable from the command line with 3 command line arguments:
1. -b or -v for brief or verbose output
2. the name of the input file which contains the path the the START directory
3. the name of the output file (should be written to the working directory, not to the START directory).

## Implementation Requirements

Your solution must be implemented in C/C++ using an object oriented design.  All code should primarily be written by you.  If, through your research, you discover a library of code that you'd like to make use of in your project, you must secure the permission of Professor Fontenot first.  The library should aid in the analysis, not perform the analysis for you.  Finally, you must make meaningful use of a hash table and binary search tree (AVL tree is fine) somewhere in your project.

### Teams, you ask?

This project may be tackled individually or in teams of no more than two students.

## What You Will Submit

* Your source code (obviously...)
* A report that details the following:
    * the metrics you chose, why you chose them, and how you implement them
    * a brief overview of the architecture of your tool
    * an annotated analysis of three different codebases, one of which should be a project you previously submitted for data structures, and one of which should be an open source project code base from GitHub that contains at least 50 source code files.
    * "How long should the report be?" Long enough to tell me everything I need to know, but no longer.

Each team will also sign up for a live demo of the project with Professor Fontenot and the TAs.  Details will be announced later.

## Evaluation/Grading

This project is worth 20% of your final grade.  Here's where that 20% will go:
* 1% - lab checkin during week of Nov 14.
* 1% - lab checkin during week of Nov 28.
* 3% - live demo
* 7% - report
* 8% - tool completion, functionality, robustness, etc.
    * Yes, we will evaluate the robustness of your tool.  It is impossible to quantify this.  But we can say this, if you implement five super trivial metrics, your grade will reflect that.  We are taking the training wheels off with respect to detailed directives.  You know what good work is by this point; put that knowledge to use.

<!-- * [Software Engineering Stack Exchange Response](http://softwareengineering.stackexchange.com/a/158709)
* -->
