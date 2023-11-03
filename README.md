# Data Structure and Algorithms course
## Elector Management project

### For running the project, type the following commands : 
* gcc -o dsaproject dsaproject.c main.c
* ./dsaproject

### Introduction
The Elector Management Program is a C-based project designed to manage a list of electors. The program allows users to create, modify, and manipulate the list of electors based on their names, ID numbers, and choices. This report will provide an overview of the program's architecture, discuss the implemented functions, and analyze the complexity of each function.

### Additional Structures and Functions
The program includes some additional functions to manage electors efficiently. Below, we discuss the added function and the rationale behind their implementation.

* **T_Elector creation_T_Elector_Linked_List() Function:**
This function allows users to create a linked list of electors by specifying the number of voters and entering their details by using creationelector function. It provides a more convenient way to input multiple electors into the system. This function was added for seperating creation of one elector from creation of all Linked List. This function helps us to separate our algorithm and makes our code more convenient.

* **T_Elector insertSorted(T_Elector head, T_Elector newVoter) Function:**
This function takes 2 parameters: head and newVoter, and adds newVoter to the linked list in a sorted in alphabetical order. This function was added for seperating the insertion of the voter alphabetically from the creation of voter. It provides a way to separate our algorithm.

* **int alphaOrder(const char *name1, const char *name2) Function:**
This function takes 2 string parameters and check if they are sorted in alphabetical order. This function was added for seperating the checking process of strings from their insertion to the linked list in an alphabetical order.  It provides a way to separate our algorithm and makes the code more convenient.

### Changed prototypes
In the program, one function prototype was changed to manage the electors efficiently. This function prototype was discussed below : 

* **T_Elector creationelector(T_Elector head):**
This function’s prototype was changed by adding one more parameter: T_Elector head. This parameter was added, because when the user enter the new user ID, the program should check if a voter with this ID already exists or not. So using T_Elector head parameter, it checks if the voter with the ID entered by the user exists in this Linked List or not by using findelector(T_Elector head, long cin_num) function inside of this function.  

### Complexity Analysis
The complexity of each implemented function was decribed briefly below : 

* **T_Elector creationelector():**  O(1) - Constant time complexity for creating a single elector.
* **T_Elector creation_T_Elector_Linked_List():** O(n) - Linear time complexity for creating a linked list of n electors.
* **void freelist(T_Elector head):** O(n) - Linear time complexity for freeing memory for n electors.
* **int findelector(T_Elector head, long cin_num):** O(n) - Linear time complexity for searching the list for an elector.
* **void decomposelist(T_Elector originalList, T_Elector *leftList, T_Elector *rightList, T_Elector *whiteList):** O(n) - Linear time complexity for decomposing the list into three sub-lists.
* **void deletelector(T_Elector *head, long cin_num):** O(n) - Linear time complexity for deleting an elector from the list.
* **void sortlist(T_Elector head):** O(n^2) - Quadratic time complexity for sorting the list using the bubble sort algorithm.
* **T_Elector mergelists(T_Elector headLeft, T_Elector headRight):** O(n) - Linear time complexity for merging and sorting two lists.
* **int countLR(T_Elector headLeft):** O(n) - Linear time complexity for counting left-leaning electors in a list.

### Conclusion 
The Elector Management project is a well-structured management program that designed to efficiently manage electors. It provides some functions for adding, deleting, searching, categorizing, and sorting electors based on their attributes. The added structures and functions enhance the program's functionality and usability, making it a valuable tool for managing elector information.

## Thank you for your attention!

