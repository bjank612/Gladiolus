/*-----------
Program 1: Gladiolus
        Prompt for the number of sections and display
        an ASCII gladiolus flower, with the sections centered
above each other.

Course: CS 141, Fall 2021. Tues 12pm lab
        System: Mac using Xcode
Author: Bianca Jankiewicz

Original ASCII graphics gives:
------------------------------------------

      \     \     \    \
      /     /     /    /
      \     \     \    \
      /     /     /    /
  /------------------------\
 ( ████████████████████████ )
  \                        /_______
   \                      /------\ \
    \                    /        ) )
     \                  /_______ / /
      \                / ----------
 ____-------------------____
 \__________________________/


---------------------------------------------
*/

#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.
#include <cmath>
using namespace std;  // so that we don't need to preface every cin and cout with std::

// Entire program is given inside of main(), which is acceptable since this is the first program.
int main() {

    // Display the menu and get the user choice
    int menuOption = 0;
    cout << "Program 1: Gladiolus            \n"
         << "Choose from among the following options:  \n"
         << "   1. Display original graphic  \n"
         << "   2. Display Gladiolus         \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menuOption;

    // Handle menu option of 3 to exit
    if( menuOption == 3) {
        exit( 0);
    }
        // Handle menu option of 1 to display custom ASCII graphics
    else if( menuOption == 1) {

        cout << setw(6) << " " <<"\\     \\     \\    \\ \n";
        cout << setw(6) << " " <<  "/     /     /    /\n";
        cout << setw(6) << " "<<"\\     \\     \\    \\ \n";
        cout << setw(6) << " "<<"/     /     /    /\n";
        cout << setw(2) << " "<<"/------------------------\\ \n";
        cout << " "<<"( ████████████████████████ )\n";
        cout << setw(2) << " " <<  "\\                        /_______ \n";
        cout << setw(3) << " " <<"\\                      /------\\  \\ \n";
        cout << setw(4) << " " <<"\\                    /        ) )\n";
        cout << setw(5) << " "<<"\\                  /_______ /  / \n";
        cout << setw(6) << " " <<"\\                / ----------/\n";
        cout  << " " <<       "____-------------------____\n";
        cout  << " "  << "\\__________________________/";

        cout << endl;
    } //end if( menuOption == 1)  // menu option to display custom graphic


    else if( menuOption == 2) {

        int numberOfSections = 0;
        cout << "Number of sections -> ";
        cin >> numberOfSections;

        int currentSection = 1;

        // This while loop creates each separate flower and ends when it has printed the final flower
        while (currentSection <= numberOfSections) {
            cout << setw(numberOfSections+3);
            cout << "---" << endl;

            // Direction variable to determine if the flower petal spacing is decreasing or increasing.
            // It starts out increasing so it begins at 1. When it switches directions it's set to -1.
            // This is so the number of spacing decreases after the middle section is printed.
            int direction = 1;
            char midToken = ' ';

            // For loop prints each line of the flower and loops until direction switches to negative one and
            // decreases spaces to zero.
            for(int spaces = 1; spaces > 0; spaces += direction) {

                // Determines if the current line is the middle section with the @ and switches directions if it is.
                if (spaces == currentSection) {
                    direction = -(direction);
                    midToken = '@';
                } else {
                    midToken = ' ';
                }

                // Creates the spaces outside of the parentheses by using a formula that counts the opposite way
                // of the inner spaces.
                int outerSpace = (numberOfSections-spaces)+1;
                cout << setw(outerSpace);
                cout << "(" << setw(spaces + 1) << midToken << setw(spaces+1) << ")" << endl;
            }
            currentSection++;
        }

        // Prints bottom of the flower
        cout << setw(numberOfSections*2);
        cout << "---" << endl;
        string leaf = "right";
        bool stem = false;

        // For loop to create each line of the stem until it reaches the number entered by the user
        for (int k=0; k < (numberOfSections); k++){
            // Checks if only the stem should be there and then sets stem to false so a leaf will print next
            if (stem == true){
                cout << setw(numberOfSections +1) << " " << "|" << endl;
                stem = false;
            }
           else if (stem == false && leaf == "right"){
                cout << setw(numberOfSections +1) << " " << "|/" << endl;
                stem = true;
                leaf = "left";
            }
         // Leaf switches from left to right and checks each time the loop iterates
          else if (stem == false && leaf == "left"){
                cout << setw(numberOfSections +2) << " \\|" << endl;
                stem = true;
                leaf = "right";
            }

        }
        cout << setw(numberOfSections +2) << " |" << endl;

    } //end if( menuOption == 2) // menu option to display building

    cout << "Exiting" << endl;
    return 0;
}// end main()
