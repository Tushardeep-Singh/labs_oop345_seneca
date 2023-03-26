# Workshop 8: Smart Pointers

In this workshop, you will use smart pointers to manage a memory resource.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- create a program component of quadratic complexity
- use a smart pointer to move an object


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

This workshop consists of the following modules:
- `w8` (supplied)
- `Database`

Have all your code inside the `sdds` namespace and protect against multiple inclusions.

**Your task is to create** the `Database` module according to the specs below.  This module will load data from a file and stored it in some attributes; the data in the file is organized on two columns, separated by a number of blanks.  For simplicity purposes, you can assume that the text on each column contains no spaces. See the provided input file for more details on the structure of the file.

### `Database` Module

This module is built around two parallel array: an array of `keys` (for the first column in the input file) and an array of `values` (for the second column in the input file).

Add to this module the enumeration (will be used to signal that an operation finished with success, or some error occurred):

```cpp
enum class Err_Status
{
  Err_Success,
  Err_NotFound,
  Err_OutOfMemory,
};
```

***Class Members***

**This class can be instantiated only once.**  To accomplish this, the class will **NOT** have any public constructors (this will prevent clients to create instances).

Create a private class variable (`static` attribute) that will store the address of the one and only instance of type `Database`.  Use an STL smart pointer as a datatype for this attribute (*HINT*: use `std::shared_ptr`; explain in the reflection why `std::unique_ptr` is not a good choice).

Create a public class function (`static` member function) named `getInstance(const std::string& filename)`. This function:

- receives as a parameter a string representing the filename of the database file
- if the class `Database` has already been instantiated (the `static` attribute is not null), then this function returns the static attribute and does nothing else.
- if the class `Database` has not been instantiated (the `static` attribute is null), then this function creates an instance of type `Database` (using the private constructor) and stores it in the static attribute. Return the `static` attribute to the client.


***Private Members***

- A variable representing the number of entries in the database.
- A statically-allocated array of strings representing the keys. The size of this array is 20.
- A statically-allocated array of strings representing the values. The size of this array is 20.
- A string representing the database file name.
- A static attribute representing the instance (see above).

- `Database(const std::string& filename)`: a private constructor to prevent client from instantiating this class. This constructor:
  - prints to the screen the address of the current instance and the prototype of the constructor (see sample output for details)
  - opens the file and read the key/value pairs into the attributes. Assume that the file is correct and exists (no need to check for errors).
  - replaces any underscore character (`_`) that appears in the keys with a single space (` `) before storing it into attributes.

Add any other **private** members that your design requires (without changing the specs above)!

***Public members***

- `getInstance(const std::string& filename)`: see above.
- `GetValue(const std::string& key, std::string& value)`: a query that searches in the array of keys for a the first parameter:
  - if the key is found, store in the second parameter the corresponding value from the array of values and return `Err_Status::Err_Success`.
  - if the key is not found, return `Err_Status::Err_NotFound`.
- `SetValue(const std::string& key, const std::string& value)`: a modifier that receives as parameters a key and a value. If there is space in the database (the capacity of the array not been reached), the key/value pair is added and the function returns `Err_Success`. Otherwise, it returns `Err_OutOfMemory`.
- a destructor that
  - prints to the screen the address of the current instance and the prototype of the destructor (see sample output for details)
  - iterates over the database content and creates a database backup in a separate file. The backup file name will be the input file name with the string `.bkp.txt` appended to it. For example if the input file is `data.txt` the backup file should be `data.txt.bkp.txt`.
  - the format of this file is (see `sample_data.txt.bkp.txt`):
  ```
  KEY -> VALUE
  KEY -> VALUE
  KEY -> VALUE
  ...
  ```
  where `KEY` should be printed on a field of size 25 characters, aligned to the left.


### Sample Output

When the program is started with the command:
```
ws data.txt
```
the output should look like the one from the `sample_output.txt` file.

### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor's Seneca userid):
```
~profname.proflastname/submit 345_w8_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***




## Part 2 (100%)

For part 2 you will have to modify the `Database` module to transform it into a templated class that can work with values of any type (the keys will be strings), and to encrypt/decrypt the values existing in the database when loading from a file or saving into a file.

Have all your code inside the `sdds` namespace, and protect the header against double multiple inclusions.


### `Database` Module (update)

Design and code a templated class named `Database`; this class has only one template parameter `T` representing the type of a value.  Update any existing members from part 1, to work with this type.

***Private Members***

- `void encryptDecrypt(T& value)`: an empty body function (does nothing, we will specialize it later).
- update the constructor: after loading a `value` from the database file, call the `encryptDecrypt()` function, passing the `value` as a parameter (the `value` in the file is encrypted, and this function will decrypt it).



***Public Members***

- update the destructor: before saving a `value` into the backup database file, call the `encryptDecrypt()` function, passing the `value` as a parameter (the `value` stored in memory is decrypted, this function will encrypt it).


***Specializations***

- specialize the `encryptDecrypt()` for the type `std::string` as following (pseudocode)
  ```
  encryptDecrypt(value)
  {
    const char secret[]{ "secret encryption key" };

    foreach character C in the parameter
      foreach character K in the secret
        C = C ^ K
  }
  ```

- specialize the `encryptDecrypt()` for the type `long long` as following (pseudocode)
  ```
  encryptDecrypt(value)
  {
    const char secret[]{ "super secret encryption key" };

    foreach byte B in the parameter
      foreach character K in the secret
        B = B ^ K
  }
  ```

  To access the individual bytes in the parameter use the conversion operator (`reinterpret_cast<char*>(&value)`).  The number of bytes in a `long long` object can be found using `sizeof` operator.

This is a simple encryption procedure (not to be used for security since is very easy to break by modern computers); more details at [https://kylewbanks.com/blog/Simple-XOR-Encryption-Decryption-in-Cpp](https://kylewbanks.com/blog/Simple-XOR-Encryption-Decryption-in-Cpp).


Add any other **private** members that your design requires (without changing the specs above)!

### Sample Output

When the program is started with the command:
```
ws data_str.txt data_num.txt
```
the output should look like the one from the `sample_output.txt` file (**on the second run**, first run will show that the backup files are empty).

### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor's Seneca userid):
```
~profname.proflastname/submit 345_w8_p2
```
and follow the instructions.





### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation-**but do not limit it to**-the following points:

- why could we not use a `unique_ptr` in your `Database` class?
- what changes you had to make in *part 1* to transform the class into a templated one?
- a class that allows only one instance to be created is called a *singleton*. Can you think at another way to create a singleton without using static members? How would that object be managed?
- the class `Database` has a resource attribute (the database instance), yet no copy/move operations were implemented. Is that a bug (justify your answer)?
- we said that the class `Database` can be instantied only once, yet in the output we see that the custom constructor is called twice (same for the destructor). Explain.

To avoid deductions, refer to code in your solution as examples to support your explanations.





### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor's Seneca userid):
```
~profname.proflastname/submit 345_w8_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
