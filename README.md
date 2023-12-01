# Project3VideoGameSort
Project 3b for DSA 2023 Team "Draw 3". Project members of Maya Folsom, Ethan "Roll my Dice" Durand, and Tyler Hull. Project title pending.

This description is an updated and simplified version of the previous proposal document. Please visit https://docs.google.com/document/d/1AFMjAXXnl2V8hwJdDIU0YFsGd1VGG372ktiLNZ_L-Ys/edit for the original version.

Problem: What are we trying to solve?
The problem we are solving with this program is how to best recommend steam video games to users. The video games will be recommended based on user-selected parameters such as genre, mechanics, release year, and system.

Features: How do we know when we have solved this problem?
We know that we have solved this issue when all of the steam games from the given database can be sorted in such a way that any permutation of different specifications for the games will provide a list of applicable games in a short period of time. In addition, the User Interface should allow the user to easily understand what the results of the search were.

Data: What is the data set we will be using? (MOST IMPORTANT CHANGE)
The dataset that we will be using is a modified version of this dataset: https://www.kaggle.com/datasets/fronkongames/steam-games-dataset/data. The dataset is modified to remove (hopefully) all of the inappropriate entries. It is also modified to remove some of the unnecessary columns and make it easier to read into our program.

Tools: What will we be using to complete this task?
For this task, we will be using C++ as a programming language, and the Simple Fast Multimedia Library to provide visuals (probably).

Visuals: What will the final product look like?
I'm not making a second wireframe for the new program until we fully decide what the specifications will be. Please see the old one on the previous document for now.

Strategy: What Algorithms/Data Structures will we be using to accomplish this task?
For our two data structure implementations we will be using a red-black tree and a splay tree. The red-black tree would serve as a basic tree implementation that would be relatively static as it was searched through, giving it a static time. 
The splay tree would be a more dynamic tree implementation. The tree would adjust each time that a certain segment of games are searched for. In doing so, the games that the individual would be most likely to search for are kept near the top, so related similar searches would be more effective after the first search.

In both of these data structures, the data would be represented as node objects, each of which has internal variables which represent its different systems, genres, etc. There would likely be a few Red-Black Trees, each sorted by one of the following: Rating, Total Sales, and Genre (Alphabetically). There would be one splay tree which dynamically updated the locations of these nodes each time any search query was called.

Distribution of Responsibilities and Roles: What will each team member do?
Ethan “Roll my dice!” Durand: Menu implementation backend and splay tree algorithm.
Tyler Hull: Menu implementation backend and red-black tree algorithm, as well as CSV reading.
Maya Folsom: Menu Interface and frontend, Data collection method, helping with splay and red-black tree algorithm.
