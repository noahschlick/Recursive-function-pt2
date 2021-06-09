//
//  Assign2_Q2
//  CS 3358 Data Structures and Algorithms
//  (Section 3358-256) Spring 2021
//
//  Created by Noah Schlickeisen on 3/11/21.
//
//  The purpose of this program is to test 4 recursive functions
//  that operate different task.
//

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
// IMPOTANT MESSAGE: When compiling the program on Texas State school
// servers type in command//
//
//                  g++ Assign2_Q2.cpp -std=c++11
//                  ./a.out
//
// This will run the orject on the latest version of C++ to make the program
// effectively.
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


/*                    Print Values
This function takes in a integer along with a index that
indicates the 10th value of the number. The function will
recure untill each number of the integer is printed followed
by a space.
*/
void printValues(int value, int i)
{
    // Calculate the 10th place of number
    int a = int(pow(10,i));
    int b = int(pow(10,i+1));
    
    // end function when i = 0
    if (i == 0)
    {
        cout << (value % b)/a << endl;  //Calculate next integer
        return;
    }
    else
    {
        cout << (value % b)/a << " ";   //Calculate next integer
        printValues(value, i-1);
    }
}

/*             Print Long Forward
 This function takes in a integer and a index as a parameter.
 Its primary job is to see how large the decimal value is so
 that i can decrement in the print values function.
 */
void printLongFwd(int value, int i)
{
    // Divide by 10^i until 0
    int temp = int(value / (pow(10,i)));
    
    // Print values when i value is found
    if (int(temp) == 0)
        printValues(value, i-1);
    else
        printLongFwd(value, i+1);
}
// Override function for printLongFwd with only
// the integer value as the parameter.
void printLongFwd(int value)
{
    printLongFwd(value, 0);
}



/*             Print Long Backward
This function takes in a integer value and an index
as a integer value. This function prints each single
charcter of the value.
*/
void printLongBwd(int value, int i)
{
    // Decrement temp value
    int temp = int(value / (pow(10,i)));
    
    // Get the 10^i values
    int a = int(pow(10,i));
    int b = int(pow(10,i+1));
    
    // end function if temp = 0
    if (int(temp) == 0)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << (value % b)/a << " "; //Calculate next integer
        printLongBwd(value, i+1);
    }
}
// Override function for printLongBwd with out
// the i parameter
void printLongBwd(int value)
{
    printLongBwd(value, 0);
}


/*                  Matching Index
The purpose of this function is a search function
that finds a value in an array in O(logn) time. The
paramenters in this function include the array of
integers, the lowest index, the highest index, and
the target value being searched for.
 */
int binarySearch(int array[], int low, int high, int target)
{
    // If the array does not have the element
    if (low > high)
        return -1;
    
    // get mid index
    int mid = (low + high) / 2;
    
    // Find out which side of the array the value is on
    if (target == array[mid])
        return mid;
    else if (target < array[mid])
        return binarySearch(array, low, mid-1, target);
    else
        return binarySearch(array, mid+1, high, target);
}



/*
             Prints vector
This function prints out the the elements in the vacter. It
parameter is a vector of integer values.
 */
void printVector(vector<int> const &sets)
{
    for (int i: sets)
        cout << i << " ";
    cout << endl;
}

/*              Prints subsets
This function sorts and prints all of the subsets for a
set of element inside a vector. It takes in parameters
of two veactors. One vectr for the set of elements and the
other for the sub sets of elements. Thhe function also
has the indexfor the vector
 */
void printSubSets(vector<int> &vect, vector<int> &sets, int i)
{
    // All subsets generated
    if (i < 0)
    {
        printVector(sets);
        return;
    }

    // get the current subset from vector
    sets.push_back(vect[i]);
    printSubSets(vect, sets, i-1);
    sets.pop_back();

    // Remove duplicates
    while (vect[i] == vect[i-1])
        i--;

    printSubSets(vect, sets, i-1);
}

/*              Get sub sets
Gets the vector from main.cpp to create subsets
 */
void getSubSets(vector<int> &vect)
{
    // Empty vectors containing subsets
    vector<int> sets;
    printSubSets(vect, sets, (vect.size()) - 1);
}

/*              recursive Multiply
This function takes in two integers as a parameter
and then recures while adding one number to another
till the value of integer a multiplied by b is generated
*/

int multiply(int a, int b)
{
    // Check if any value is 0
    if (a == 0 || b == 0)
        return 0;
    
    //Check if values = 1
    if (a == 1)
        return b;
    
    // recure multiply
    return multiply(a - 1, b) + b;
}




int main() {
    int value = 1234567890;
    
    int array[] = {-1, 0, 1, 2, 4, 10};
    
    cout << "Input: " << value << endl;
    
    cout << "fwd output: ";
    printLongFwd(value);
    
    cout << "bwd output: ";
    printLongBwd(value);
    
    cout << "Searching 4: ";
    cout << binarySearch(array, 0, 5, 4) << endl;
    
    vector<int> vect = {1, 2, 3};
    getSubSets(vect);
    
    cout << "Multiplying 3 and 3: ";
    cout << multiply(3, 3) << endl;
}
