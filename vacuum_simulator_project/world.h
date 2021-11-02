#ifndef WORLD_H_
#define WORLD_H_

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class World {
    private:
        int numMoves;
        char map[10][10];
        int vacuumX, vacuumY;
        int vacuumDir;
    public:
        World() {
            World("world.txt");
        }

        World(string fileName) {
            numMoves = 0;
            vacuumDir = 0; //0-North 1-East 2-South 3-West
            ifstream worldFile;
            worldFile.open(fileName);
            worldFile >> vacuumX >> vacuumY;
            for(int i=0; i<10; i++) {
                string row;
                worldFile >> row;
                for(int j=0; j<10; j++) 
                    map[j][i] = row[j];
            }
        }

        char sensor() {
            numMoves++;
            if(vacuumDir==0) 
                return map[vacuumY-1][vacuumX];
            else if(vacuumDir==1) 
                return map[vacuumY][vacuumX+1];
            else if(vacuumDir==2)
                return map[vacuumY+1][vacuumX];
            else if(vacuumDir==3)
                return map[vacuumY][vacuumX-1];
            return 'E';
        }

        void move() {
            numMoves++;
            if(vacuumDir==0 && map[vacuumY-1][vacuumX]!='W') 
                vacuumY--;
            else if(vacuumDir==1 && map[vacuumY][vacuumX+1]!='W') 
                vacuumX++;
            else if(vacuumDir==2 && map[vacuumY+1][vacuumX]!='W')
                vacuumY++;
            else if(vacuumDir==3 && map[vacuumY][vacuumX-1]!='W')
                vacuumX--;
        }

        void turnRight() {
            numMoves++;
            vacuumDir = (vacuumDir+1) % 4;
        }

        void turnLeft() {
            numMoves++;
            vacuumDir--;
            if(vacuumDir==-1) vacuumDir = 3;
        }

        void clean() {
            numMoves++;
            map[vacuumY][vacuumX] = 'C';
        }

        void mapDump() {
            for(int j=0; j<10; j++) {
                for(int i=0; i<10; i++) {
                    cout << map[i][j];
                }
                cout << endl;
            }
        }

        int score() {
            int numDirty = 0;
            for(int i=0; i<10; i++) {
                for(int j=0; j<10; j++) {
                    if(map[i][j]=='D')
                        numDirty++;
                }
            }
            return numMoves+10*numDirty;
        }
};

#endif