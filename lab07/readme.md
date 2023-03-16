# Workshop 7: STL Algorithms

In this workshop, you use the Algorithm category of the Standard Template Library.

You are going to create an application that manages a collection of baked goods.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- copy data from a file into a sequential container
- use the numeric library to accumulate data values 
- use a lambda expression to specify an operation on each value in a data set 
- use the algorithm library to sort data values




## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 0% of the workshop's total mark, is optional and designed to assist you in completing the second part.
- *Part 2*: worth 100% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *Part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. The reflection does not have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.



## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++17`: the code will be compiled using the C++17 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.




## Part 1 (0%)

The first portion of this workshop consists of modules:
- `w7` (supplied)
- `Bakery`

Enclose all your source code within the `sdds` namespace and include the necessary guards in each header file.

In the specs below, functions marked with `DO NOT USE MANUAL LOOPS` should not use `for`, `range based for`, `while` or `do while` in the implementation; these functions should use STL Algorithms.  The STL Algorithms you choose should use lambda expressions to process the collection; the lambdas should **capture the necessary variables from context only by value** (the stream object is the only one allowed to be captured by reference). Check course notes to identify which algorithm is appropriate in each situation.  Using manual loops will lead to **rejection** of the workshop or **severe penalties** (at the discretion of your professor).





### `Bakery` Module
This module defines an enum class BakedTyped as follows:

```c++
enum class BakedType{
  BREAD, PASTERY
}
```


and a simple structure called `BakedGood`, capable of storing the following information
- Baked Type (either BREAD or PASTERY from the above enum)
- Description of the baked item
- The shelf life of the item in days
- The amount of stock for the item
- The price of the item

There is no need to add any member functions to this structure but additions can be included for ease of development. Choose appropriate types for each attribute if not provided.


Lastly define a class called `Bakery` that manages a collection of objects of type `BakedGood`.


***Public Members for `Bakery`***

- a custom constructor that receives as a parameter the name of the file containing the information about the BakedGoods to be added to the collection. 

  If the filename is incorrect, this constructor should throw an exception.

  Each line from the file contains information about a single BakedGood in the following format:
  ```
  BakedType Description ShelfLife Stock Price 
  ```
  The fields are not separated by delimiters; each field has a fixed size: 
  - BakeType has a field size of 8
  - Description has a field size of 20
  - ShelfLife has a field size of 14
  - Stock has a field size of 8
  - Price has a field size of 6

  Any blank space at the begining/end of a token is not part of the token and should be removed.

  The read in BakedGood will populate the collection.

- `void showGoods(std::ostream& os) const`: print the content of the collection into the parameter. Use the insertion operator (see below). ***DO NOT USE MANUAL LOOPS!***



***Free Helpers***

- `std::ostream& operator<<(std::ostream& out, const BakedGood& b)`: inserts one BakedGood into the first parameter, using the following format (the width of each field is specified in brackets):
  ```
  * BakedType(10) * Description(20) * ShelfLife(5) * Stock(5) * Price(8) * 
  ```

  The price should be printed with two decimal place precision.

  Look in the sample output to see how the numbers should be formatted and the alignment of each field.


**Add any other private member that is required by your design!**







### `w7` Module (supplied)


The tester module for the first portion has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output

When the program is started with the command (the file `bakery-goods.txt` is provided):
```
ws bakery-goods.txt
```
the output should look like the one from the `sample_output.txt` file.




### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w7_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***










## Part 2 (100%)

The second part of this workshop upgrades your solution to include more functionality in the `Bakery` module.

**:warning:Important:** Your solution should not use the same algorithm twice across two different functions/tasks listed below.



### `Bakery` Module


***Public Members***

- `void showGoods(std::ostream& os) const`: update this function to display the total stock and price of the goods in the collection. See the sample output for the format.  ***DO NOT USE MANUAL LOOPS!***

- `void sortBakery()`: receives a parameter the name of the field used to sort the collection in ascending order. The parameter can have one of the values: `Description`, `Shelf`, `Stock`, `Price`. ***DO NOT USE MANUAL LOOPS!***

- `std::vector<BakedGood> combine()`: receives a parameter of another Bakery object reference and combines the collection of BakedGoods from the current object and the parameter and returns the combined collection. The combined collection should be ordered by price.  ***DO NOT USE MANUAL LOOPS!***

- `bool inStock() const`: receives the Description of a BakedGood and a BakedType as parameters, and returns `true` if the collection contains Stock of that BakedGood.  ***DO NOT USE MANUAL LOOPS!***

- `std::list<BakedGood> outOfStock() const`: receives a BakedType as a parameter, and returns the list of all the out of stock items in the collection.  ***DO NOT USE MANUAL LOOPS!***









### `w7` Module


The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output

When the program is started with the command (the input file is provided):
```
ws baked-goods.txt
```
the output should look like the one from the `sample_output.txt` file.




### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**


Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- list all the STL functions that you have used in this workshop; explain your reasoning for choosing each one, and not another.
- present the advantages of using STL algorithms vs. implementing the functionality by yourself using loops.
- for the sortBakery function, would anything differ in how it is implemented if the choice of collection was either a vector or a list? If there is a difference what is it?

To avoid deductions, refer to code in your solution as examples to support your explanations.





### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w7_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
