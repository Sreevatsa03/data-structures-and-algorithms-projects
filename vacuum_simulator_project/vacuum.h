#ifndef VACUUM_H_
#define VACUUM_H_

#include "world.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <queue>
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <array>

#define n 8

using namespace std;

struct point {
    int x;
    int y;
};

struct queueNode { 
    point pt;  // The cordinates of a cell 
    int dist;  // cell's distance of from the source 
};

class Vacuum {
    private:
        World myWorld;
        int dir; //0-North 1-East 2-South 3-West
        vector<vector<string>> *memory;
        int xMem, yMem; //xMen increases left to right; y increases down to up
        int rowNum[4] = {-1, 0, 0, 1}; 
        int colNum[4] = {0, -1, 1, 0};
        point src;
    public:
        Vacuum(World inWorld) {
            myWorld = inWorld;
            dir = 0;
            myWorld.clean();
            memory = new vector<vector<string>>;
            initializeMem();
        }

        void initializeMem() {
            // vector<string> init;
            // memory -> push_back(init);
            memory -> resize(n, vector<string>(n));
            for (int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    memory -> at(i).at(j)  = "o";
                }
            }
            memory -> at(0).at(0) = ("C^");
            xMem = 0;
            yMem = 0;
        }

        void mapDump() {
            // "*" represents undiscovered spaces
            for (auto i = memory -> begin(); i != memory -> end(); i++) {
                for(auto j = i -> begin(); j != i -> end(); j++) {
                    if (*j == "C")
                        cout << *j << " ";
                    else if (*j == "C^")
                        cout << *j;
                    else
                        cout << "*" << " ";
                }
                cout << endl;
            }
        }

        void turn(int d) {
            if (dir == d) {

            } else if (dir + 1 == d || dir - 3 == d) {
                myWorld.turnRight();
            } else if (dir + 2 == d || dir -2 == d) {
                myWorld.turnRight();
                myWorld.turnRight();
            } else if (dir - 1 == d || dir + 3 == d) {
                myWorld.turnLeft();
            }

            dir = d;
        }

        void move() {
            myWorld.move();
            if (dir == 0) {
                yMem -= 1;
                for (int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if (memory -> at(i).at(j) == "C^") {
                            // Always add "C" because either we clean if dirty or we pass over already clean tiles
                            if (i == 0) {
                                vector<vector<string>>temp;
                                temp.resize(n, vector<string>(n));
                                for (int i2 = 0; i2 < n; i2++) {
                                    for(int j2 = 0; j2 < memory -> at(i2).size(); j2++) {
                                        if (memory -> at(i2).at(j2) == "C") {
                                            temp.at(i2 + 1).at(j2) = memory -> at(i2).at(j2);
                                        } if (memory -> at(i2).at(j2) == "C^") {
                                            temp.at(i2 + 1).at(j2) = "C";
                                        }
                                    }
                                }
                                *memory = temp;
                                memory -> at(i).at(j) = "C^";
                            } else {
                                memory -> at(i - 1).at(j) = "C^";
                                memory -> at(i).at(j) = "C";
                            }
                            goto lab2;
                        }
                    }
                }   
            } else if (dir == 1) {
                xMem += 1;
                for (int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if (memory -> at(i).at(j) == "C^") {
                            memory -> at(i).at(j + 1) = "C^"; 
                            memory -> at(i).at(j) = "C";
                            goto lab2;
                        }
                    }
                }
            } else if (dir == 2) {
                yMem += 1;
                for (int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if (memory -> at(i).at(j) == "C^") {
                            memory -> at(i + 1).at(j) = "C^";
                            memory -> at(i).at(j) = "C";
                            goto lab2;
                        }
                    }
                }
            } else if (dir == 3) {
                xMem -= 1;
                for (int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if (memory -> at(i).at(j) == "C^") {
                            if (j == 0) {
                                vector<vector<string>>temp;
                                temp.resize(n, vector<string>(n));
                                for (int i2 = 0; i2 < n; i2++) {
                                    for(int j2 = 0; j2 < memory -> at(i2).size(); j2++) {
                                        if (memory -> at(i2).at(j2) == "C") {
                                            temp.at(i2).at(j2 + 1) = memory -> at(i2).at(j2);
                                        } if (memory -> at(i2).at(j2) == "C^") {
                                            temp.at(i2).at(j2 + 1) = "C";
                                        }
                                    }
                                }
                                *memory = temp;

                                memory -> at(i).at(j) = "C^";
                            } else {
                                memory -> at(i).at(j - 1) = "C^";
                                memory -> at(i).at(j) = "C";
                            }
                            goto lab2;
                        }
                    }
                }
            } 
            lab2:;
        }

        point checkMapAroundUnvis(int i, int j) {
            if (i == 0) {
                if (j == 0) {
                    if (memory -> at(i + 1).at(j) != "C" && memory -> at(i + 1).at(j) != "C^") {
                        return point{i + 1, j};
                    } else if (memory -> at(i).at(j + 1) != "C" && memory -> at(i).at(j + 1) != "C^") {
                        return point{i, j + 1};
                    }
                } else if (j == n - 1) {
                    if (memory -> at(i + 1).at(j) != "C" && memory -> at(i + 1).at(j) != "C^") {
                        return point{i + 1, j};
                    } else if (memory -> at(i).at(j - 1) != "C" && memory -> at(i).at(j - 1) != "C^") {
                        return point{i, j - 1};
                    }
                } else {
                    if (memory -> at(i + 1).at(j) != "C" && memory -> at(i + 1).at(j) != "C^") {
                        return point{i + 1, j};
                    } else if (memory -> at(i).at(j + 1) != "C" && memory -> at(i).at(j + 1) != "C^") {
                        return point{i, j + 1};
                    } else if (memory -> at(i).at(j - 1) != "C" && memory -> at(i).at(j - 1) != "C^") {
                        return point{i, j - 1};
                    }
                }
            } else if (i == n - 1) {
                if (j == 0) {
                    if (memory -> at(i - 1).at(j) != "C" && memory -> at(i - 1).at(j) != "C^") { 
                        return point{i - 1, j};
                    } else if (memory -> at(i).at(j + 1) != "C" && memory -> at(i).at(j + 1) != "C^") {
                        return point{i, j + 1};
                    }
                } else if (j == n - 1) {
                    if (memory -> at(i - 1).at(j) != "C" && memory -> at(i - 1).at(j) != "C^") { 
                        return point{i - 1, j};
                    } else if (memory -> at(i).at(j - 1) != "C" && memory -> at(i).at(j - 1) != "C^") {
                        return point{i, j - 1};
                    }
                } else {
                    if (memory -> at(i - 1).at(j) != "C" && memory -> at(i - 1).at(j) != "C^") { 
                        return point{i - 1, j};
                    } else if (memory -> at(i).at(j + 1) != "C" && memory -> at(i).at(j + 1) != "C^") {
                        return point{i, j + 1};
                    } else if (memory -> at(i).at(j - 1) != "C" && memory -> at(i).at(j - 1) != "C^") {
                        return point{i, j - 1};
                    }
                }
            } else if (j == 0) {
                if (memory -> at(i + 1).at(j) != "C" && memory -> at(i + 1).at(j) != "C^") {
                    return point{i + 1, j};
                } else if (memory -> at(i - 1).at(j) != "C" && memory -> at(i - 1).at(j) != "C^") { 
                    return point{i - 1, j};
                } else if (memory -> at(i).at(j + 1) != "C" && memory -> at(i).at(j + 1) != "C^") {
                    return point{i, j + 1};
                }
            } else if (j == n - 1) {
                if (memory -> at(i + 1).at(j) != "C" && memory -> at(i + 1).at(j) != "C^") {
                    return point{i + 1, j};
                } else if (memory -> at(i - 1).at(j) != "C" && memory -> at(i - 1).at(j) != "C^") { 
                    return point{i - 1, j};
                } else if (memory -> at(i).at(j - 1) != "C" && memory -> at(i).at(j - 1) != "C^") {
                    return point{i, j - 1};
                }
            } else {
                if (memory -> at(i + 1).at(j) != "C" && memory -> at(i + 1).at(j) != "C^") {
                    return point{i + 1, j};
                } else if (memory -> at(i - 1).at(j) != "C" && memory -> at(i - 1).at(j) != "C^") { 
                    return point{i - 1, j};
                } else if (memory -> at(i).at(j + 1) != "C" && memory -> at(i).at(j + 1) != "C^") {
                    return point{i, j + 1};
                } else if (memory -> at(i).at(j - 1) != "C" && memory -> at(i).at(j - 1) != "C^") {
                    return point{i, j - 1};
                }
            }
        
            return point{i, j};
        }

        vector<point> srcGreyList() {  //A "grey" node is one that is visited, but has unvisisted neighbors
            vector<point> greyList;  // index 0 = src, index 1 onwards is grey nodes
            for (int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (memory -> at(i).at(j) == "C") { 
                        if (checkMapAroundUnvis(i, j).x == i && checkMapAroundUnvis(i, j).y == j) {
                            
                        } else {
                            greyList.push_back(point{i, j});
                        }
                    } else if (memory -> at(i).at(j) == "C^") {
                        greyList.insert(greyList.begin(), point{i, j});
                    }
                }
            }
            return greyList;
        }

        bool isValid(int x, int y) {
            if (x < n && y < n && x >= 0 && y >= 0)
                return true;
            
            return false;
        }

        int BFS(vector<vector<int>> mat, point src, point dest) { 
            if (!mat[src.x][src.y] || !mat[dest.x][dest.y]) 
                return -1; 
        
            bool visited[n][n]; 
            memset(visited, false, sizeof visited); 

            visited[src.x][src.y] = true; 

            queue<queueNode> q; 

            queueNode s = {src, 0}; 
            q.push(s); 

            while (!q.empty()) { 
                queueNode curr = q.front(); 
                point pt = curr.pt; 
 
                if (pt.x == dest.x && pt.y == dest.y) 
                    return curr.dist; 

                q.pop(); 
        
                for (int i = 0; i < 4; i++) { 
                    int x = pt.x + rowNum[i]; 
                    int y = pt.y + colNum[i]; 

                    if (isValid(x, y) && mat[x][y] &&  !visited[x][y]) { 
                        visited[x][y] = true; 
                        queueNode Adjcell = { {x, y}, curr.dist + 1 }; 
                        q.push(Adjcell); 
                    } 
                } 
            } 

            return -1; 
        }

        vector<vector<int>> convertIntoBinary() {
            vector<vector<int>> binVec;
            binVec.resize(n, vector<int>(n));

            for (auto i = binVec.begin(); i != binVec.end(); i++) {
                fill(i -> begin(), i -> end(), 0);
            }

            for (int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (memory -> at(i).at(j) == "C" || memory -> at(i).at(j) == "C^") 
                        binVec.at(i).at(j) = 1; 
                    else
                        binVec.at(i).at(j) = 0;

                }
            }

            return binVec;
        }

        int minDistBtwnPts(int i, int j) {
            point dest = point {i, j};
            int minDist = BFS(convertIntoBinary(), src, dest);
            if (minDist != INT_MAX)
                return minDist;
            else 
                return -1;
        }

        void printSolution(vector<vector<int>> sol) { 
            for (int i = 0; i < n; i++) { 
                for (int j = 0; j < n; j++) 
                    printf(" %d ", sol[i][j]); 
                printf("\n"); 
            } 
        }

        bool isSafe(int x, int y, vector<vector<int>> mat, vector<vector<bool>> visited) { 
            if (x == -1 || x == n || y == -1 || y == n || visited[x][y] || mat[x][y] == 0) 
                return false; 
        
            return true; 
        }

        vector<string> solvePath(vector<vector<int>> mat, point dest) { 
            vector<string> possiblePaths; 
            string path; 
            vector<vector<bool>> visited;
            visited.resize(n, vector<bool>(n));
            for (auto i = visited.begin(); i != visited.end(); i++) {
                fill(i -> begin(), i -> end(), false);
            } 
  
            solvePathUtil(src.x, src.y, mat, dest, path, possiblePaths, visited);  
            return possiblePaths;
        }

        void solvePathUtil(int x, int y, vector<vector<int>> mat, point dest, string& path, vector<string>& possiblePaths, vector<vector<bool>> visited) { 
            if (x == -1 || x == n || y == -1 || y == n || visited[x][y] || mat[x][y] == 0) 
                return; 

            if (x == dest.x && y == dest.y) { 
                possiblePaths.push_back(path); 
                return; 
            } 

            visited[x][y] = true; 

            if (isSafe(x + 1, y, mat, visited)) { 
                path.push_back('D'); 
                solvePathUtil(x + 1, y, mat, dest, path, possiblePaths, visited); 
                path.pop_back(); 
            } 

            if (isSafe(x, y - 1, mat, visited)) { 
                path.push_back('L'); 
                solvePathUtil(x, y - 1, mat, dest, path, possiblePaths, visited); 
                path.pop_back(); 
            } 

            if (isSafe(x, y + 1, mat, visited)) { 
                path.push_back('R'); 
                solvePathUtil(x, y + 1, mat, dest, path, possiblePaths, visited); 
                path.pop_back(); 
            } 

            if (isSafe(x - 1, y, mat, visited)) { 
                path.push_back('U'); 
                solvePathUtil(x - 1, y, mat, dest, path, possiblePaths, visited); 
                path.pop_back(); 
            } 

            visited[x][y] = false; 
        } 

        string findPath(point dest) {
            return solvePath(convertIntoBinary(), dest).at(0);
        }

        void moveSrcToDest(string path) {
            for (int i = 0; i < path.size(); i++) {
                if (path[i] == 'U') {
                    turn(0);
                    myWorld.move();
                    yMem--;
                } else if (path[i] == 'D') {
                    turn(2);
                    myWorld.move();
                    yMem++;
                } else if (path[i] == 'R') {
                    turn(1);
                    myWorld.move();
                    xMem++;
                } else if (path[i] == 'L') {
                    turn(3);
                    myWorld.move();
                    xMem--;
                }
            }
            src = {xMem, yMem};
        }

        void clean() {
            spiral();
            
            vector<point> greyList;
            greyList = srcGreyList();

            src = {greyList.at(0).x, greyList.at(0).y};
            xMem = src.x;
            yMem = src.y;

            // cleanUp(greyList);
        }

        void spiral(){
            int i = 1;
            bool flag = true;
            while(flag) {
                for (int rot = 0; rot < 2; rot++) {
                    for (int j = 0; j < i; j++) {
                        if (myWorld.sensor() == 'C') {
                            move();
                        }
                        if (myWorld.sensor() == 'W') {
                            flag = false;
                            goto endloop;
                        } else {
                            move();
                            myWorld.clean();
                        }
                    }                    
                    myWorld.turnRight();
                    if (dir != 3) 
                        dir++;
                    else 
                        dir = 0;
                }
                i++;
            }
            endloop:;
        }

        void cleanUp(vector<point> greyList) {
            while (greyList.size() > 1) {
                point dest = {-1, -1};
                int minDist = INT_MAX;

                for (int i = 1; i < greyList.size(); i++) {
                    if (minDistBtwnPts(greyList.at(i).x, greyList.at(i).y) != -1) {
                        if(minDistBtwnPts(greyList.at(i).x, greyList.at(i).y) < minDist) {
                            minDist = minDistBtwnPts(greyList.at(i).x, greyList.at(i).y);
                            dest.x = greyList.at(i).x;
                            dest.y = greyList.at(i).y;
                        }
                    }
                }

                for (int i = 1; i < greyList.size(); i++) {
                    if (greyList.at(i).x == dest.x && greyList.at(i).y == dest.y) {
                        greyList.erase(greyList.begin() + 1 + i);
                    }
                }

                if (dest.x == -1 && dest.y == -1) {
                    goto lab5;
                } else {
                    moveSrcToDest(findPath(dest));
                }

                dest = {checkMapAroundUnvis(src.x, src.y).x, checkMapAroundUnvis(src.x, src.y).y};
                moveSrcToDest(findPath(dest));
                myWorld.clean();
            }
            
            lab5:;
        }

        //DONT change this method!!
        int score() {
            return myWorld.score();
        }
};

#endif