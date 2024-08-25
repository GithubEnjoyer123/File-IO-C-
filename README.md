##This is a simple file I/O for C++, basically a simple "database".

Steps on how to use:

1. Clone repository into a folder of your choosing

2. Run g++ for our cpp files
```g++ -o FileIO .main.cpp studymor.cpp```

3. Run the exe created. You can execute it in windows or run it in your local environment by typing the name of the exe
```./FileIO```

While using the program, you will create 2 .dat files that is used for our file IO. One is to keep track of the participants and one is to keep track fo survey results.
On a new program, it will display the number of current participants, and skip them so we don't lose progress. There is not much input validation, so please follow the directions carefully. Any invalid inputs will not be saved in case of a program crash.
