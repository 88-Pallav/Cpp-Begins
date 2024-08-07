/* 

**************************** Declaring an array **********************************************

element_type element_name [conts_no_of_elements]

eg.     int scores [5];

    'int' is element_type 
    'scores' is array_name
    '[5]' is number of elements


****************************** Declaring a vector ********************************************

vector<element_type> vector_name;

eg.     vector<char> vowels;

    'vector' is vector_keyword for declaring a vector
    'char' is element_type
    'vowels' is vector_name


***************************** Inititalzing an array *****************************************

element_type array_name [no. of elements] {initialization_list}

eg.     int scores [5] {99};  

        '[5]' 5 in square brackets is no of elements
        '{99}' 99 in curly braces means 1st scrores is initialized to 99
               and rest all are initialized to 0.

        
***************************** Inititalzing a vector *****************************************

vector<elemet_type> vector_name {intilialization_list}

eg.     vector<int> score {55, 66, 77, 88, 99}         


***************************** Accessing an array *****************************************

array_name [index_position_of_element]

    score[0] - element at 0th index
    score[3] - element at the 4th index and so on.


***************************** Accessing a vector *****************************************

Vector has two ways of accessing an element:

    vector_name[index_position_of_element];
            or
    vector_name.at(index_position_of_element);

    score.at(2) - element at 3rd index
            or
    score


***************************** Dynamic nature of a vector ***********************************

    vector_name.push_back(element);

eg.
    score.push_back(58);

    - if there were 3 elements in the vecor a 4th element '58' will be added to the vector
    - we can also calculate size of a vector:
eg.
    vector_name.size();


***************************** Iterating through an array - for loop *****************************************
    
    array_type array_name = {initiliazed_list};
    for (int iteration_number = 0; iteration_number < array_size; ++iteration_number) {
        cout << iteration_number << " = " << array_name[i] << endl;
    }
eg.
    string cars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
    for (int i = 0; i < 5; i++) {
    cout << i << " = " << cars[i] << endl;
    }


***************************** Iterating through a Vector - for loop *****************************************

    vector<element_type> vector_name {initialization_list};
    for (element_type interation{initialized_value}; iteration <= vector_size; ++interation)
        cout << vector_name[iteration] << endl; 
eg.
    vector<int> nums {10, 20, 30, 40, 50};
    for (unsigned int i {0}; i <= nums.size(); ++i)     // nums.size will return an 'unsigned int' hence 
        cout << nums[i] << endl;                           we use the same element type


***************************** Iterating through an array - Range based loop **********************************

    element_type array_name [] {initlized_list};

    for (element_type array_iteration: array_name)
        cout << array_iteration << endl;
eg.
    int scores [] {100, 98, 96}
    
    for (auto score: scores)
        cout << score << endl;

    - 'auto' here is for compiler to automatically find the type of the elements in array

   
***************************** Iterating through an array - Range based loop **********************************

    vector_keyword<element_type> vector_name {initialized_list}

    for (element_type vector_iteration: vector_name)
        cout << vector_iteration << endl;
eg. 
    vector<double> temps{87.2, 77.1, 80.0, 72.5}
    
    for (double temp: temps)
        cout << temp << endl;


***************************** Iterating through an array - while loop **********************************

    element_type array_name [] {initialized_list};
    element_type iteration {initialization};

    while (condition) {
        cout << array_name[iteration] << endl;
        ++iteration;
    }
eg.
    int scores [] {100, 90, 87};
    int i {0};

    while (i < 3) {
        cout << scores[i] << endl;
        ++i;`
    }
*/



#include <iostream>
#include <vector>

using namespace std;

int main() {

   // Display all the menu: 

   vector<int> list_of_nums{};

   char select {};

   do {
      
      cout << "\nP-Print numbers" << endl;
      cout << "A - Add a number" << endl;
      cout << "M - Display mean of the numbers" << endl;
      cout << "S - Display the smallest number" << endl;
      cout << "L - Display the largest number" << endl;
      cout << "Q - Quit" << endl;
      cout << "\nEnter your choice: ";
      cin >> select;

      if (select == 'p' || select == 'P') {
         if (list_of_nums.size() == 0)
            cout << "[] - List is empty!" << endl;
         else {
            cout << "[ ";
            for (auto num: list_of_nums)
               cout << num << " ";
            cout << " ]";
         }
      }
      else if (select == 'A' || select == 'a') {
         int add_num {};
         cout << "Enter the number you want to add to the list: ";
         cin >> add_num;
         list_of_nums.push_back(add_num);
         cout << add_num << " added." << endl;
      }
      else if (select == 'M' || select == 'm') {
         if (list_of_nums.size() == 0)
            cout << "Unable to calculate mean - no data " << endl;
         else {
            int total{};
            for (auto num: list_of_nums)
               total += num;
            cout << "The mean of numbers is: " << static_cast<double>(total)/list_of_nums.size() << endl;
         } 
      }
      else if (select == 'S' || select == 's') {
         if (list_of_nums.size() == 0)
            cout << "Smallest can't be identified, the list is empty." << endl;
         else {
            int smallest = list_of_nums.at(0);
            for (auto num: list_of_nums)
               if (num < smallest)
                  smallest = num;
            cout << "The smallest number is: " << smallest << endl;
         }
      }
      else if (select == 'L' || select == 'l') {
         if (list_of_nums.size() == 0)
            cout << "Largest number cannot be identified, list is empty." << endl;
         else {
            int largest = list_of_nums.at(0);
            for (auto num: list_of_nums)
               if (num > largest)
                  largest = num;
            cout << "The largest number is: " << largest << endl; 
         }
      }
      else if (select == 'Q' || select == 'q') {
         cout << "Goodbye" << endl;
      }
      else {
         cout << "Unknown election, please try again" << endl;
      }
   } while (select != 'q' && select != 'Q');
        




    cout << endl;
    return 0;
};




 /* 
    *****************************  Table of a number using a comma expression  ************************************

    int table_num{};
    int table_size{};

    cout << "Please enter number and size of table required: " << endl;
    cin >> table_num;

    cout << "Please enter till where you want the table: " << endl;
    cin >> table_size;


    for (int i {table_num}, j {1}; j <= table_size ; ++j)
        cout << i << " * " << j << " = " << (i * j) << endl;

    
    ****************************************  Input Validation (while loop)  ***************************************

    int num {};

    cout << "Enter a number less than 100: " << endl;
    cin >> num;

    while (num > 100) {
        cout << "Please enter a number less than 100: ";
        cin >> num;
    }
    cout << "Thanks" << endl;


    *****************************  Input validation 2 (while loop): Using a Boolean flag  *****************************

    bool done {fasle};
    int number {0};

    while (!done) {

        cout << "Enter an integer between 1 and 5: ";
        cin >> number;

        if (number <= 1 || number >= 5)
            cout << "Out of range, try again" << endl;
        else {
            cout << "Thanks !" << endl;
            done = true;
        }
    }


    ************************************* Blastoff or Reverse Countdowns  *********************************

    int n {};

    while (n > 0) {
        cout << n << endl;
        --n;
    }
    cout << "Blastoff"


    ************************************  Forward or counting up **********************************************

    int n {};
    cout << "Enter a number you wish to count up to: ";
    cin >> n;

    int i{1};
    while (i <= n) {
        cout << i << endl;
        i++;
    } 


    ************************************ Average of temperatures **********************************************

    vector<double> temps {100.7, 88.9, 70.1, 96.1, 80.2};
    double temp_sum {};

    for (auto temp: temps)
        temp_sum += temp;

    average_temp = temp_sum / temps.size()
    cout << average_temp << endl;


    ************************************ Histogram ************************************************************

    int num_items {};

    cout << "How many data items do you have ? ";
    cin >> num_items;

    vector <int> data {};

    for (int i{1}; i <= num_items; ++i) {
        int data_items{};
        cout << "Enter data items: " << i << ": ";
        cin >> data_items;

        data.push_back(data_items);
    }   
    cout << "\nDisplaying Histogram" << endl;
    for (auto val: data) {
        for (int i{1}; i <= val; ++i)
            if (i % 5 == 0)
                cout << "*";
            else 
                cout << "-";
        }
        cout << endl;        
    }


    ************************************ Exercise 18 ************************************************************

    // Sum of product of all pairs of vector elements:
 
    int result {};

    int vec_ele {};
    cout << "How many elements you want in the vector: " << endl;
    cin >> vec_ele;

    vector<int> vector{}; 

    for (int i {1}; i < (vec_ele + 1); ++i) {
        int ele {};
        cout << "Enter the elements: " << i << endl;
        cin >> ele;

        vector.push_back(ele);
        }

    for (int i{}; i < vec_ele; ++i)
        for (int j = i+1; j < vec_ele; ++j) {
            result = result + vector.at(i) * vector.at(j);
            cout << endl;
            }
        cout << "Sum comes out to be: " << result << endl;


    ************************************ Section task *************************************************************
*/