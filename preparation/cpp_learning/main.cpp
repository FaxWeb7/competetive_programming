//------------ VAIABLES ------------//
// #include <iostream>

// int main()
// {
//     // integer (whole numbers)
//     int age = 16;
//     int year = 2023;

//     // double (numbers including decimal)
//     double price = 9.99;
//     double gpa = 2.004;

//     // char (single character)
//     char grade = 'A';
//     char initial = 'B';

//     // boolean (true or false)
//     bool student = true;
//     bool power = false;

//     // strings (objects that represents a sequence of text)
//     std::string name = "Artem";
//     std::string day = "Friday";
//     std::cout << "Hello " << name << "\nYou are " << age << " years old";

//     return 0;
// }


//------------ CONST ------------//
// #include <iostream>

// int main(){
//     // The const keyword specifies that a variable's value is constant
//     // tells the compiler to prevent anything from modifying it (read-only) 

//     const double PI = 3.14159;
//     double radius = 10;
//     double circumference = 2 * PI * radius;
//     std::cout << circumference << "cm";

//     return 0;
// }


//------------ NAMESPACES ------------//
// #include <iostream>

// namespace first{
//     int x = 1;
// }
// namespace second{
//     int x = 2;
// }

// int main(){
//     // Namespace = provides a solution for preventing name conflicts in large projects.
//     //              Each entity needs a unique name. A namespace allows for identically 
//     //              named entities as long as the namespaces are different.

//     // using namespace first;
//     // std::cout << x << std::endl;
//     // std::cout << second::x << std::endl;

//     // using namespace std; 
//     using std::string;
//     using std::cout;
//     string hello = "Hello Bro!";
//     cout << hello;

//     return 0;
// }


//------------ TYPEDEF & TYPE ALIASES ------------//
// #include <iostream>

// // typedef 
// typedef std::string text_t;
// typedef int number_t;
// // alias (it's better practice to write aliaces than typedefs)
// using text_t = std::string;
// using number_t = int;

// int main(){
//     // typedef = reversed keyword used to create an additional name(alias) for another 
//     //                          data type. New identifier for an existing type.
//     //                          Helps with readability and reduces typos 

//     text_t firstName = "Artem";
//     number_t age = 16;
//     std::cout << firstName << " is " << age;

//     return 0;
// }


//------------ TYPE CONVERSION ------------//
// #include <iostream>

// int main(){
//     // type conversion = conversion a value of one data type to another.
//     //          Implicit = automatic. Explicit = Precede value with new data type
//     std::cout << (char) 100 << std::endl;

//     int correct = 8;
//     int questions = 10;
//     // std::cout << correct / questions << '%'; not working, cause int/int = int
//     std::cout << (double)correct/questions * 100 << '%';

//     return 0;
// }


//------------ USER INPUT ------------//
// #include <iostream>

// int main(){
//     std::string name;
//     int age;

//     std::cout << "What's your age?: ";
//     std::cin >> age; 

//     std::cout << "What's your full name?: ";
//     std::getline(std::cin >> std::ws, name); // save input with spaces (white-spaces, ws)

//     std::cout << "Your name is " << name << " and you are " << age << "!\n";

//     return 0;
// }


//------------ USEFULL MATH RELATED FUNCTIONS ------------//
// #include <iostream>
// #include <cmath>

// int main(){
//     double x = 3.14;
//     double y = 4;
//     double z;

//     // z = std::max(x, y);
//     // z = std::min(x, y);
//     // z = pow(2, 4); //2**4
//     // z = sqrt(9);
//     // z = abs(-10);
//     // z = round(x);
//     // z = ceil(x);
//     z = floor(x);

//     std::cout << z;

//     return 0;
// }


//------------ HYPOTENUSE PROGRAM ------------//
// #include <iostream>
// #include <cmath>

// int main(){
//     double a;
//     double b;
//     double c;

//     std::cout << "Write A side: ";
//     std::cin >> a;
//     std::cout << "Write B side: ";
//     std::cin >> b;

//     c = sqrt(pow(a, 2) + pow(b, 2));
//     std::cout << "The C side is: " << c;

//     return 0;
// }


//------------ IF STATEMENTS ------------//
// #include <iostream>

// int main(){
//     int age;
//     std::cout << "Enter your age: ";
//     std::cin >> age;

//     if (age >= 100){
//         std::cout << "You are too old!";
//     }
//     else if (age >= 18){
//         std::cout << "Welcome to the site!";
//     }
//     else if (age < 0){
//         std::cout << "You have not been born yet!";
//     }
//     else {
//         std::cout << "You are too young!";
//     }

//     return 0;
// }


//------------ SWITCHES ------------//
// #include <iostream>

// int main(){
//     int month;
//     std::cout << "Enter the month (1-3): ";
//     std::cin >> month;

//     switch (month)
//     {
//         case 1:
//             std::cout << "It's January";
//             break;
//         case 2:
//             std::cout << "It's February";
//             break;
//         case 3:
//             std::cout << "It's March";
//             break;
//         default:
//             std::cout << "Please enter only numbers (1-3)";
//     }

//     return 0;
// }


//------------ CONSOLE CALCULATOR PROGRAM ------------//
// #include <iostream>

// int main(){
//     char op;
//     double num1;
//     double num2;

//     std::cout << "Enter either (+ - / *): ";
//     std::cin >> op;
//     std::cout << "Enter #1: ";
//     std::cin >> num1;
//     std::cout << "Enter #2: ";
//     std::cin >> num2;

//     switch(op){
//         case '+':
//             std::cout << num1 + num2;
//             break;
//         case '-':
//             std::cout << num1 - num2;
//             break;
//         case '*':
//             std::cout << num1 * num2;
//             break;
//         case '/':
//             std::cout << num1 / num2;
//             break;
//     }

//     return 0;
// }


//------------ TERNARY OPERATOR ------------//
// #include <iostream>

// int main(){
//     // ternary operator ?: = replacement to an if/else statement
//     // condition ? expression1 : expression2
//     int grade = 75;
//     grade >= 60 ? std::cout << "You pass!" : std::cout << "You fail!";

//     return 0;
// }


//------------ LOGICAL OPERATORS ------------//

// operator && - check if two conditions are true
// operator || - check if at least one of two conditions is true
// operator ! = reverses the logical state of its operand


//------------ TEMPERATURE CONVERTION PROGRAM ------------//
// #include <iostream>

// int main(){
//     using namespace std;

//     int temp;
//     char unit;

//     cout << "F = Fahrenheit" << endl;
//     cout << "C = Celsius" << endl;
//     cout << "What unit you would like to convert to: ";
//     cin >> unit;

//     if (unit == 'F' || unit == 'f'){
//         cout << "Enter temperature in Celsius: ";
//         cin >> temp;

//         temp = (1.8 * temp) + 32;
//         cout << "It's " << temp << " in Fahrenheit!\n";
//     }
//     else if (unit == 'C' || unit == 'c'){
//         cout << "Enter temperature in Fahrenheit: ";
//         cin >> temp;

//         temp = (temp - 32) / 1.8;
//         cout << "It's " << temp << " in Celsuis!\n";
//     }
//     else{
//         cout << "Enter only F or C!";
//     }

//     return 0;
// }


//------------ USEFULL STRING METHODS ------------//
// #include <iostream>

// int main(){
//     std::string name;

//     std::cout << "Enter your name: ";
//     std::getline(std::cin, name);

//     // name.length() - string length
//     // name.empty() - true if string is empty
//     // name.clear() - clear string variable
//     // name.append("smth") - append smth to end of string
//     // name.at(0) - get character on index 0
//     // name.insert(0, "smth") - insert smth on index 0
//     // name.find("smth") - find an index of finding element
//     name.erase(0, 3) - remove characters on 0, 1 and 2 indexes

//     return 0;
// }


//------------ WHILE LOOPS ------------//
#include <iostream>

int main(){


    return 0;
}