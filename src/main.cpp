/*
 * BSD 3-Clause License
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * @file main.cpp
 * @brief This is the main C++ file
 *
 * @copyright Copyright (c) Chinmay Joshi
 *            This project is released under the BSD 3-Clause License.
 *
 * @author Chinmay Joshi
 * @date 04-03-2020
 */
#include <BFS.h>

int main() {
    // Creating an object of the Bfs class
    Bfs test;
    // Creating an empty vector to hold the start state
    std::vector<std::vector<int>> start;
    /*
     * creating a string variable to hold the answer the
     * user gives to entering own state or using default state
     */
    std::string ans;
    // variable to hold the vector values eg. 1, 2 ,3....
    int val;
    // Just to make it easy on the eyes
    std::string visual = "________________________________________";
    std::cout << "Welcome to the 8 Puzzle problem!" << '\n';
    std::cout << "Would you like to enter your own start state? (y/n): ";
    // storing the user input
    std::cin >> ans;
    std::cout << visual <<'\n';
    // checking if the user entered yes and checking all options of yes
    if (ans == "y" || ans == "Y" || ans == "yes" || ans == "Yes") {
        // looping to get the vector values
        for (int i = 0; i < 3; ++i) {
           /*
            * this is used to insert an element after the last element
            * in a vector back. Useful here since it is an empty vector
            */
            start.emplace_back();
            for (int j = 0; j < 3; ++j) {
                std::cout << "Enter value for [" << std::to_string(i)
                          << "][" << std::to_string(j) << "]: ";
                // storing the values
                std::cin >> val;
                // pushing it into the array
                start[i].push_back(val);
            }
        }
    } else { // If the user chooses no then a default state is used
        std::cout << "The default start state is: " << '\n';
        start = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
        // Range based for loop for printing the vector
        for (auto & i: start) {
            for (auto j: i) {
                std::cout << j << '\t';
            }
            std::cout << '\n';
        }
    }
    std::cout << visual <<'\n';
    // Passing the start vector into the Bfs class method
    test.setStart(start);
    // setting a flag for if goal is reached
    int goal = 0;
    // till goal has not been reached
    while (goal == 0) {
       // Class method to run the BFS algorithm
       goal = test.movement();
       // goal has reached so break the loop
       if (goal == 1) {
           break;
       }
       // This happens when the puzzle is not solvable
       if (goal == 2) {
           std::cout << "Puzzle cannot be solved: ";
           break;
       }
    }

    return 0;
}
