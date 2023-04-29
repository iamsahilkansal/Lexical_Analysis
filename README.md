# Lexical_Analysis
This program is a simple lexical analyzer for C++ code. It takes in a file containing C++ code and analyzes it to extract information about the keywords, operators, variables, constants, and special symbols used in the code.

Installation
Clone the repository to your local machine:
bash
Copy code
git clone https://github.com/your_username/lexical-analysis.git
Compile the program using a C++ compiler:
Copy code
g++ lexical_analysis.cpp -o lexical_analysis
Run the program with the input file as an argument:
bash
Copy code
./lexical_analysis input_file.cpp
Usage
The program takes in a single argument, which is the path to the input file containing the C++ code to be analyzed. The program will output the following information about the code:

Keywords: A list of all the C++ keywords used in the code.
Operators: A list of all the operators used in the code.
Variables: A list of all the variable names used in the code.
Constants: A list of all the constant values used in the code.
Special Symbols: A list of all the special symbols used in the code.
Example
Suppose we have the following C++ code in a file called example.cpp:

c
Copy code
#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int y = 20;
    int z = x + y;
    cout << "The sum of x and y is: " << z << endl;
    return 0;
}
Running the program with this file as an argument:

bash
Copy code
./lexical_analysis example.cpp
will produce the following output:

vbnet
Copy code
Keywords: int, using, namespace, std, main, cout, return
Operators: =, +, <<
Variables: x, y, z
Constants: 10, 20, 0
Special Symbols: <, >, #, {, }, (, ), ;, :, ,, [, ], |
Contributing
Contributions are welcome! If you have any suggestions for improvements or bug fixes, feel free to open an issue or pull request on the GitHub repository.

License
