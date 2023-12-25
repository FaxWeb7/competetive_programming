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
// #include <iostream>

// int main(){
//     std::string name;
//     while (name.empty()){
//         std::cout << "Enter your name: ";
//         std::getline(std::cin, name);
//     }
//     std::cout << "Hello " << name;

//     return 0;
// }


//------------ DO WHILE LOOPS ------------//
// #include <iostream>

// int main(){
//     // do while loop = do some block of code first, THEN repeat again if condition is true.
//     int number;

//     do{
//         std::cout << "Enter a positive number: ";
//         std::cin >> number;
//     } while (number < 0);

//     std::cout << "The number is " << number;

//     return 0;
// }


//------------ FOR LOOPS ------------//
// #include <iostream>

// int main(){
//     for (int i = 5; i > 0; i--){
//         std::cout << i << std::endl;
//     }
//     std::cout << "HAPPY NEW YEAR!";

//     return 0;
// }


//------------ BREAK & CONTINUE ------------//
// #include <iostream>

// int main(){
//     // break = break out of loop
//     // continue = skip current iteration

//     for (int i = 1; i <= 20; i++){
//         if (i == 13){
//             // continue;
//             break;
//         }
//         std::cout << i << std::endl;
//     }

//     return 0;
// }


//------------ NESTED LOOPS ------------//
// #include <iostream>

// int main(){
//     int rows;
//     int cols;
//     char symbol;

//     std::cout << "Enter # of rows: ";
//     std::cin >> rows;
//     std::cout << "Enter # of columns: ";
//     std::cin >> cols;
//     std::cout << "Enter symbol: ";
//     std::cin >> symbol;

//     for (int i = 0; i < rows; i++){
//         for (int j = 0; j < cols; j++){
//             std::cout << symbol << ' ';
//         }
//         std::cout << '\n';
//     }

//     return 0;
// }


//------------ RANDOM NUMBERS  ------------//
// #include <iostream>

// int main(){
//     // pseudo random = NOT truly random (but close)

//     srand(time(NULL));
//     int num = (rand() % 100) + 1;

//     std::cout << num << std::endl;

//     return 0;
// }


//------------ NUMBER GUESSING GAME ------------//
// #include <iostream>

// int main(){
//     int number;
//     int guess;
//     int tries;

//     srand(time(NULL));
//     number = (rand() % 100) + 1;
//     tries = 0;

//     do{
//         std::cout << "Enter a guess between 1-100: ";
//         std::cin >> guess;
//         tries++;
//         if (number < guess){
//             std::cout << "Too high!\n";
//         }
//         else{
//             std::cout << "Too low!\n";
//         }
//     } while (number != guess);

//     std::cout << "CORRECT! # of tries: " << tries;

//     return 0;
// }


//------------ FUNCTIONS ------------//
// #include <iostream>

// double countArea(double length);

// int main(){
//     // function = block of reusable code  
//     double length;
//     double area;

//     std::cout << "Enter length (cm): ";
//     std::cin >> length;

//     area = countArea(length);
//     std::cout << "Area: " << area << " cm2";

//     return 0;
// }

// double countArea(double length){
//     return length * length;
// }


//------------ OVERLOADED FUNCTIONS ------------//
// #include <iostream>

// void bakePizza();
// void bakePizza(std::string topping);

// int main(){
//     bakePizza();
//     bakePizza("pepperoni");
//     return 0;
// }

// void bakePizza(){
//     std::cout << "Here is your pizza!\n";
// }
// void bakePizza(std::string topping){
//     std::cout << "Here is your " << topping << " pizza!\n";
// }


//------------ BANKING PROGRAM ------------//
// #include <iostream>
// using namespace std;

// void showBalance(double balance);
// double deposit();
// double withdraw();

// int main(){
//     double balance = 100;
//     int choice;

//     do{
//         cout << "Enter your choice (1-4):\n";
//         cout << "1. Show balance\n";
//         cout << "2. Deposit money\n";
//         cout << "3. Withdraw money\n";
//         cout << "4. Exit\n";
//         cin >> choice;
//         switch(choice){
//             case 1:
//                 showBalance(balance);
//                 break;
//             case 2:
//                 balance += deposit();
//                 showBalance(balance);
//                 break;
//             case 3:
//                 balance -= withdraw();
//                 showBalance(balance);
//                 break;
//         }
//     } while (choice != 4);
//     cout << "Thanks for using our bank!";

//     return 0;
// }

// void showBalance(double balance){
//     cout << "Your balance: " << balance << "$\n\n";
// }
// double deposit(){
//     double deposit = 0;
//     cout << "Enter how much do you want to deposit: ";
//     cin >> deposit;
//     cout << "You successfully deposit " << deposit << "$\n";
//     return deposit;
// }
// double withdraw(){
//     double withdraw;
//     cout << "Enter how much do you want to withdraw: ";
//     cin >> withdraw;
//     cout << "You successfully withdraw " << withdraw << "$\n";
//     return withdraw;
// }


//------------ ROCK PAPER SCISSORS GAME ------------//
// #include <iostream>
// using namespace std;

// string convertChoice(char choice);
// string winnerText(char playerChoice, char computerChoice);

// int main(){
//     srand(time(NULL));
//     char player_choice;
//     char computer_choice;
//     int randomNumber = (rand() % 3) + 1;

//     computer_choice = randomNumber == 1 ? 'r' : randomNumber == 2 ? 'p' : 's';
//     cout << "Choose one of the following\n";
//     cout << "*************************\n";
//     cout << "'r' - for rock\n";
//     cout << "'p' - for paper\n";
//     cout << "'s' - for scissors\n";
//     cin >> player_choice;

//     cout << "Your choice: " << convertChoice(player_choice) << endl;
//     cout << "Computer's choice: " << convertChoice(computer_choice) << endl;
//     cout << winnerText(player_choice, computer_choice) << endl;

//     return 0;
// }

// string convertChoice(char choice){
//     string fullChoice;
//     switch(choice){
//         case 'r':
//             fullChoice = "Rock";
//             break;
//         case 'p':
//             fullChoice = "Paper";
//             break;
//         case 's':
//             fullChoice = "Scissors";
//             break;
//     }
//     return fullChoice;
// }

// string winnerText(char playerChoice, char computerChoice){
//     string winnerText;
//     if (playerChoice == computerChoice){
//         winnerText = "It's a tie!";
//     }
//     else if ((playerChoice == 'r' && computerChoice == 's') || (playerChoice == 's' && computerChoice == 'p') || (playerChoice == 'p' && computerChoice == 'r')){
//         winnerText = "You win!";
//     }
//     else{
//         winnerText = "You lose :(";
//     }
//     return winnerText;
// }


//------------ ARRAYS ------------//
// #include <iostream>

// int main(){
//     // std::string cars[] = {"Mustang", "Corvette", "BMW"};
//     std::string cars[3];
//     cars[0] == "Mustang";
//     cars[1] == "Corvette";
//     cars[2] == "BMW";

//     std::cout << cars[0] << std::endl;
//     std::cout << cars[1] << std::endl;
//     std::cout << cars[2] << std::endl;

//     return 0;
// }


//------------ SIZEOF OPERATOR ------------//
// #include <iostream>

// int main(){
//     // sizeof() = determines the size in bytes of:
//     //          variable, data type, class, object, etc.

//     int age = 16;
//     std::string name = "Artem";
//     double gpa = 2.5;
//     char grade = 'F';
//     bool student = true;
//     std::string students[] = {"Patrick", "SpongeBob", "Squidward"};


//     std::cout << "int - " << sizeof(age) << " bytes\n";
//     std::cout << "string - " << sizeof(name) << " bytes\n";
//     std::cout << "double - " << sizeof(gpa) << " bytes\n";
//     std::cout << "char - " << sizeof(grade) << " bytes\n";
//     std::cout << "boolean - " << sizeof(student) << " bytes\n";
//     std::cout << sizeof(students)/sizeof(students[0]) << " elements in array";

//     return 0;
// }


//------------ ITERATE OVER IN ARRAY ------------//
// #include <iostream>

// int main(){ 
//     std::string students[] = {"SpongeBob", "Patrick", "Squidward"};
//     for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++){
//         std::cout << students[i] << std::endl;
//     }

//     return 0;
// }


//------------ FOREACH LOOP ------------//
// #include <iostream>

// int main(){
//     // foreach loop = loop that eases the traversal over an iterable data set (less flexibility)

//     std::string students[] = {"SpongeBob", "Patrick", "Squidward"};
//     for (std::string student : students){
//         std::cout << student << std::endl;
//     }

//     return 0;
// }


//------------ PASS ARRAY TO A FUNCTION ------------//
// #include <iostream>

// double getTotal(double prices[], int size);

// int main(){
//     double prices[] = {49.99, 75, 9.99};
//     int size = sizeof(prices)/sizeof(prices[0]);
//     double total = getTotal(prices, size);
//     std::cout << total << '$';

//     return 0;
// }

// double getTotal(double prices[], int size){
//     double total;
//     for (int i = 0; i < size; i++){
//         total += prices[i];
//     }
//     return total;
// }


//------------ SEARCH AN ARRAY FOR AN ELEMENT ------------//
// #include <iostream>

// int searchElement(int array[], int size, int number);

// int main(){
//     int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int size = sizeof(numbers)/sizeof(numbers[0]);
//     int myNum;
//     int index;

//     std::cout << "Enter a number to search for: ";
//     std::cin >> myNum;
//     index = searchElement(numbers, size, myNum);
//     if (index != -1){
//         std::cout << "Your number is on " << index << " index";
//     }
//     else {
//         std::cout << "There isn't this number in array :(";
//     }

//     return 0;
// }

// int searchElement(int array[], int size, int number){
//     for (int i = 0; i < size; i++){
//         if (array[i] == number){
//             return i;
//         }
//     }
//     return -1;
// }


//------------ SORT AN ARRAY ------------//
// #include <iostream>

// void sort(int array[], int size);

// int main(){
//     int numbers[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
//     int size = sizeof(numbers)/sizeof(numbers[0]);

//     sort(numbers, size);
//     for (int i = 0; i < size; i++){
//         std::cout << numbers[i] << " ";
//     }

//     return 0;
// }

// void sort(int array[], int size){
//     int temp;
//     for (int i = 0; i < size-1; i++){
//         for (int j = 0; j < size-i-1; j++){
//             if (array[j] > array[j+1]){
//                 temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//             }
//         }
//     }
// }


//------------ FILL FUNCTION ------------//
// #include <iostream>

// int main(){
//     // fill() = fills a range of elements with a specified value 
//     //          fill(begin, end, value)

//     std::string foods[100];
//     fill(foods, foods+50, "pizza");
//     fill(foods+50, foods+100, "hamburgers");

//     for (std::string food : foods){
//         std::cout << food << std::endl;
//     }

//     return 0;
// }


//------------ FILL AN ARRAY WITH USER INPUT ------------//
#include <iostream>

int main(){
    

    return 0;
}