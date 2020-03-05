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
 * @file BFS.h
 * @brief This is the header file of the BFS class.
 *
 * @copyright Copyright (c) Chinmay Joshi
 *            This project is released under the BSD 3-Clause License.
 *
 * @author Chinmay Joshi
 * @date 04-03-2020
 */

#ifndef BFS_BFS_H
#define BFS_BFS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

class Bfs {
private:
    // variable to hold the goal state.
    std::string goal{"012345678"};
    // variable to hold the visited nodes.
    std::vector<std::string> visited;
    // 3D vector to hold all the nodes opened.
    std::vector<std::vector <std::vector <int>>> openNode;
public:

   /*
    * @brief This is the constructor of the class.
    *
    * @param There is no input to this method.
    *
    * @return This method returns nothing.
    */
    Bfs();

   /*
    * @brief This is the first method of the class. It is used
    *        to set the puzzle start position.
    *
    * @param The input to this method is a vector of type int.
    *
    * @return This method returns nothing.
    */
    void setStart(std::vector< std::vector <int>> &initial);

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
    static std::vector<int> getOneD(std::vector< std::vector <int>> &node);

   /*
    * @brief This is the third method of the class. It is used to check
    *        if the new node has been already opened (visited) or not.
    *
    * @param The input to this method is a const variable of type string.
    *
    * @return This method returns a true for visited and false if not visited.
    */
    bool isVisited(const std::string& state);

   /*
    * @brief This is the fourth method of the class. It is used to add nodes
    *        to the visited vector.
    *
    * @param The input to this method is a const variable of type string.
    *
    * @return This method returns nothing.
    */
    void addVisited(const std::string& str);

   /*
    * @brief This is the fifth method of the class. It is used to check if the
    *        current node is the goal node.
    *
    * @param The input to this method is a const variable of type string which is
    *        1D vector converted to a string.
    *
    * @return This method returns true if goal state or false otherwise.
    */
    bool isGoal(const std::string& str);

   /*
    * @brief This is the sixth method of the class. It is used to convert the 1D
    *        vector of type int to string variable.
    *
    * @param The input to this method is a 1D vector of type int.
    *
    * @return This method returns a converted string of the 1D vector.
    */
    static std::string convertStr(std::vector<int> &node);

   /*
    * @brief This is the seventh method of the class. It is used to execute
    *        the BFS algorithm.
    *
    * @param This method has no input.
    *
    * @return This method returns an integer flag. 1 for goal reached, 0 for
    *         goal not reached and 2 for no solution.
    */
    int movement();

   /*
    * @brief This is the eighth method of the class. It is used to get the position
    *        of the blank tile or in this case the position of zero.
    *
    * @param The input to this method are 2 pointers pointing to the row and
    *        column of zero.
    *
    * @return This method returns nothing.
    */
    void getZero(int *i, int *j);

   /*
    * @brief This is the ninth method of the class. It is used to get the configuration
    *        of the puzzle.
    *
    * @param This method has no input.
    *
    * @return This method returns a 2D vector which is the 8 puzzle.
    */
    std::vector<std::vector<int>> getTempVec();

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
    static std::string swap(std::vector<std::vector<int>> &vec, const std::string& pos, int i, int j);

   /*
    * @brief This is the eleventh method of the class. It is used to add the nodes which are
    *        opened using the above method.
    *
    * @param The input to this method is the 2D vector obtained from the above method.
    *
    * @return This method returns nothing.
    */
    void addNodes(std::vector<std::vector<int>> &tempVec);

   /*
    * @brief This is the twelfth method of the class. It is used to print the goal node but it
    *        isn't the private variable called goal. It prints if the puzzle is solved just as
    *        a sanity check.
    *
    * @param The input to this method is a 2D vector.
    *
    * @return This method returns nothing.
    */
    void printGoal(std::vector<std::vector<int>> &tempVec);

    /*
     * @brief This is the Destructor of the class.
     *
     * @param This method has no input.
     *
     * @return This method returns nothing.
     */
    ~Bfs();

};

#endif //BFS_BFS_H
