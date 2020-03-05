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
 * @file BFS.cpp
 * @brief This is the implementation file for the Bfs class
 *
 * @copyright Copyright (c) Chinmay Joshi
 *            This project is released under the BSD 3-Clause License.
 *
 * @author Chinmay Joshi
 * @date 04-03-2020
 */
#include <BFS.h>

/*
 * @brief This is the eleventh method of the class. It is used to add the nodes which are
 *        opened using the above method.
 *
 * @param The input to this method is the 2D vector obtained from the above method.
 *
 * @return This method returns nothing.
 */
Bfs::Bfs() = default;

/*
 * @brief This is the eleventh method of the class. It is used to add the nodes which are
 *        opened using the above method.
 *
 * @param The input to this method is the 2D vector obtained from the above method.
 *
 * @return This method returns nothing.
 */
void Bfs::setStart(std::vector<std::vector<int> > &initial) {
    // Setting the start node of the puzzle in openNode 3D vector
    for (int z = 0; z < 1; ++z){
       /*
        * this is used to insert an element after the last element
        * in a vector back. Useful here since it is an empty vector
        */
        openNode.emplace_back();
        for(int x = 0; x < 3; ++x) {
           /*
            * this is used to insert an element after the last element
            * in a vector back. Useful here since it is an empty vector
            */
            openNode[z].emplace_back();
            for (int y = 0; y < 3; ++y) {
                // adding the values in the 3D vector at position [0][x][y]
                openNode[z][x].push_back(initial[x][y]);
            }
        }
    }
}

/*
 * @brief This is the second method of the class. It is used to
 *        convert a 2D array to a 1D array. This helps in decreasing
 *        the time for checking if a node has been opened or closed.
 *
 * @param The input to this method is a 2D vector of type int, passed
 *        by reference.
 *
 * @return This method returns a 1D vector.
 */
std::vector<int> Bfs::getOneD(std::vector<std::vector<int> > &node) {
    // defining a vector variable to store the 2D->1D conversion.
    std::vector<int> vec;
    // adding the elements in the vector.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vec.push_back(node[i][j]);
        }
    }
    // returning the 1D vector
    return vec;
}

/*
 * @brief This is the third method of the class. It is used to check
 *        if the new node has been already opened (visited) or not.
 *
 * @param The input to this method is a const variable of type string.
 *
 * @return This method returns a true for visited and false if not visited.
 */
bool Bfs::isVisited(const std::string& state) {
    // initializing with a value of false
    bool val = false;
    // looping in the visited vector
    for (auto & i : visited) {
        // checking if the current node is already present
        if (i == state) {
            // returning true if it is present
            val = true;
            return val;
        } else {
            // otherwise returning false
            val = false;
        }
    }
    // returning the state of val
    return val;
}

/*
 * @brief This is the fourth method of the class. It is used to add nodes
 *        to the visited vector.
 *
 * @param The input to this method is a const variable of type string.
 *
 * @return This method returns nothing.
 */
void Bfs::addVisited(const std::string& str) {
    // adding the 1D vector converted to string variable in visited
    visited.push_back(str);
}

/*
 * @brief This is the fifth method of the class. It is used to check if the
 *        current node is the goal node.
 *
 * @param The input to this method is a const variable of type string which is
 *        1D vector converted to a string.
 *
 * @return This method returns true if goal state or false otherwise.
 */
bool Bfs::isGoal(const std::string& str) {
    // checking if goal is reached.
    return str == goal;
}

/*
 * @brief This is the sixth method of the class. It is used to convert the 1D
 *        vector of type int to string variable.
 *
 * @param The input to this method is a 1D vector of type int.
 *
 * @return This method returns a converted string of the 1D vector.
 */
std::string Bfs::convertStr(std::vector<int> &node) {
    // making a stringstream variable
    std::stringstream ss;
    // going from the beginning to the end of the vector
    std::copy(node.begin(), node.end(), std::ostream_iterator<int>(ss));
    // converting the integer stream to string
    std::string str = ss.str();
    // returning the string
    return str;
}

/*
 * @brief This is the eighth method of the class. It is used to get the position
 *        of the blank tile or in this case the position of zero.
 *
 * @param The input to this method are 2 pointers pointing to the row and
 *        column of zero.
 *
 * @return This method returns nothing.
 */
void Bfs::getZero(int *i, int *j) {
    // looping in the 3D vector
    for (int z = 0; z < 1; z++){
        for(int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                // checking for zero and returning row and col value
                if (openNode[z][x][y] == 0) {
                   /*
                    * doing this because in C++ you can't return more than 1
                    * variable.
                    */
                    *i = x;
                    *j = y;
                }
            }
        }
    }
}

/*
 * @brief This is the ninth method of the class. It is used to get the configuration
 *        of the puzzle.
 *
 * @param This method has no input.
 *
 * @return This method returns a 2D vector which is the 8 puzzle.
 */
std::vector<std::vector<int>> Bfs::getTempVec() {
    // creating a vector variable to get the first 2D vector in openNode
    std::vector<std::vector<int> > tempVec;
    // looping in 2D vector format because we only need to 2D vector at [0]
    for (int m = 0; m < 3; ++m) {
        tempVec.emplace_back();
        for (int n = 0; n < 3; ++n) {
            tempVec[m].push_back(openNode[0][m][n]);
        }
    }
    // returning the vector
    return tempVec;
}

/*
 * @brief This is the tenth method of the class. It is used to perform the up, down,
 *        left and right moves.
 *
 * @param The first input is the vector on which the moves are to be performed. Second,
 *        input is the move which has to be performed e.g. left, right, etc. Third and
 *        fourth input is the row and column of the zero tile.
 *
 * @return This method returns a string of the 1D vector on which the moves are done.
 */
std::string Bfs::swap(std::vector<std::vector<int>> &vec, const std::string& pos, int i, int j) {
    // creating a 1D vector to hold the converted 2D vector
    std::vector<int> tempNode;
    // creating a string the hold the converted string of the 1D vector
    std::string tempStr;
    // temporary variable used for swapping positions
    int tempVal;
    // moving up
    if (pos == "Up") {
        // swapping 0 with the number above it
        tempVal = vec[i][j];
        vec[i][j] = vec[i-1][j];
        vec[i-1][j] = tempVal;
        // converting the new vector to 1D
        tempNode = getOneD(vec);
        // converting 1D vector to string variable
        tempStr = convertStr(tempNode);
        // returning the string variable
        return tempStr;

    } else if (pos == "Down") {
        // swapping 0 with the number below it
        tempVal = vec[i][j];
        vec[i][j] = vec[i+1][j];
        vec[i+1][j] = tempVal;
        // converting the new vector to 1D
        tempNode = getOneD(vec);
        // converting 1D vector to string variable
        tempStr = convertStr(tempNode);
        // returning the string variable
        return tempStr;

    } else if (pos == "Right") {
        // swapping 0 with the number on the right
        tempVal = vec[i][j];
        vec[i][j] = vec[i][j+1];
        vec[i][j+1] = tempVal;
        // converting the new vector to 1D
        tempNode = getOneD(vec);
        // converting 1D vector to string variable
        tempStr = convertStr(tempNode);
        // returning the string variable
        return tempStr;

    } else { // swapping 0 with the number on the left
        tempVal = vec[i][j];
        vec[i][j] = vec[i][j-1];
        vec[i][j-1] = tempVal;
        // converting the new vector to 1D
        tempNode = getOneD(vec);
        // converting 1D vector to string variable
        tempStr = convertStr(tempNode);
        // returning the string variable
        return tempStr;
    }
}

/*
 * @brief This is the twelfth method of the class. It is used to print the goal node but it
 *        isn't the private variable called goal. It prints if the puzzle is solved just as
 *        a sanity check.
 *
 * @param The input to this method is a 2D vector.
 *
 * @return This method returns nothing.
 */
void Bfs::printGoal(std::vector<std::vector<int>> &tempVec) {
    // Printing to screen that the puzzle is solved
    std::cout << "Puzzle solved!!!" << '\n';
    // Printing how many nodes were opened for this configuration
    std::cout << "Opened " << openNode.size() << " nodes" << '\n';
    // printing the vector for sanity check
    for (auto & i : tempVec) {
        for (auto j: i) {
            std::cout << j << '\t';
        }
        std::cout << '\n';
    }
}

/*
 * @brief This is the eleventh method of the class. It is used to add the nodes which are
 *        opened using the above method.
 *
 * @param The input to this method is the 2D vector obtained from the above method.
 *
 * @return This method returns nothing.
 */
void Bfs::addNodes(std::vector<std::vector<int>> &tempVec) {
    // getting the size of the 3D vector
    int m = openNode.size();
   /*
    * resizing it to be 1 more than the size so that we can dynamically add 1 new node
    * as the vector will have an unknown size
    */
    openNode.resize(openNode.size() + 1);
    // adding the new 2D vector in the end
    for (unsigned int z = m; z < openNode.size(); ++z) {
        for(int x = 0; x < 3; ++x) {
            // see above for explanation
            openNode[z].emplace_back();
            for (int y = 0; y < 3; ++y) {
                openNode[z][x].push_back(tempVec[x][y]);
            }
        }
    }
}

/*
 * @brief This is the seventh method of the class. It is used to execute
 *        the BFS algorithm.
 *
 * @param This method has no input.
 *
 * @return This method returns an integer flag. 1 for goal reached, 0 for
 *         goal not reached and 2 for no solution.
 */
int Bfs::movement() {
    // variables used for the row and column of zero tile
    int i, j;
    // variable to store converted string
    std::string tempStr;
    // variable to store the converted 2D vector
    std::vector<int> tempNode;
    // variable to get the [0] 2D vector in openNode
    std::vector<std::vector<int>> tempVec;
    // getting the zero tile position in the puzzle
    getZero(&i, &j);
    // getting the first 2D vector in openNode
    tempVec = getTempVec();
    // converting it to 1D vector
    tempNode = getOneD(tempVec);
    // converting it to string
    tempStr = convertStr(tempNode);
    // checking if the node exists
    if (!isVisited(tempStr)){
        // adding it since it doesn't exist
        addVisited(tempStr);
    }

    // Up condition
    if (i-1 >= 0) {
        // getting the first 2D vector in openNode
        tempVec = getTempVec();
        // performing the Up movement
        tempStr = swap(tempVec, "Up", i, j);
        // checking for goal state
        if (!isGoal(tempStr)) {
            // checking if the node exists
            if (!isVisited(tempStr)){
                // adding the node to openNode
                addNodes(tempVec);
                // adding the string to visited
                addVisited(tempStr);
            }
        } else { // return 1 when goal node is reached
            printGoal(tempVec);
            return 1;
        }
        // clear the temp vector so that other movements can be performed
        tempVec.clear();

      // Down condition
    } if (i+1 <= 2) {
        // getting the first 2D vector in openNode
        tempVec = getTempVec();
        // performing the Down movement
        tempStr = swap(tempVec, "Down", i, j);
        // checking for goal state
        if (!isGoal(tempStr)) {
            // checking if the node exists
            if (!isVisited(tempStr)) {
                // adding the node to openNode
                addNodes(tempVec);
                // adding the string to visited
                addVisited(tempStr);
            }
        } else { // return 1 when goal node is reached
            printGoal(tempVec);
            return 1;
        }
        // clear the temp vector so that other movements can be performed
        tempVec.clear();

      // Right condition
    } if (j+1 <= 2) {
        // getting the first 2D vector in openNode
        tempVec = getTempVec();
        // performing the Right movement
        tempStr = swap(tempVec, "Right", i, j);
        // checking for goal state
        if (!isGoal(tempStr)) {
            // checking if the node exists
            if (!isVisited(tempStr)){
                // adding the node to openNode
                addNodes(tempVec);
                // adding the string to visited
                addVisited(tempStr);
            }
        } else { // return 1 when goal node is reached
            printGoal(tempVec);
            return 1;
        }
        // clear the temp vector so that other movements can be performed
        tempVec.clear();

      // Moving Left condition
    } if (j-1 >= 0) {
        // getting the first 2D vector in openNode
        tempVec = getTempVec();
        // performing the Left movement
        tempStr = swap(tempVec, "Left", i, j);
        // checking for goal state
        if (!isGoal(tempStr)) {
            // checking if the node exists
            if (!isVisited(tempStr)) {
                // adding the node to openNode
                addNodes(tempVec);
                // adding the string to visited
                addVisited(tempStr);
            }
        } else { // return 1 when goal node is reached
            printGoal(tempVec);
            return 1;
        }
        // clear the temp vector so that other movements can be performed
        tempVec.clear();
    }
    // // getting the first 2D vector in openNode
    tempVec = getTempVec();
   /*
    * deleting the first element which is equivalent to adding it to the closed
    * node list since we have exhausted all the moves of this configuration. This
    * also ensures that BFS algorithm is followed since it goes level by level.
    */
    openNode.erase(openNode.begin(), openNode.begin()+ 1);
    // when the puzzle is not solvable
    if (openNode.empty()) {
        // return the 2 flag
        return 2;
    }
    // return 0 which means goal not reached
    return 0;
}

/*
 * @brief This is the Destructor of the class.
 *
 * @param This method has no input.
 *
 * @return This method returns nothing.
 */
Bfs::~Bfs() = default;
