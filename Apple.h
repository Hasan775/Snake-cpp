#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Apple{
public:
    vector<int> apple;
    int count = 0;
    bool IsAppleAte(vector<vector<int>> body){
        if (body[0][0] == apple[0] && body[0][1] == apple[1]){
            count += 1;
            return true;
        }
        return false;
    }
    int Spawn(vector<vector<int>> body, vector<vector<int>> sharps, int width, int height){
        vector<vector<int>> pos, nbody;
        int ip;
        for(int i = 0; i < height; i++){
            nbody.push_back({});
            for (int j = 0; j < width; j++){
                nbody[i].push_back(0);
            }
        }
        for (auto seg : body){
            nbody[seg[1]][seg[0]] = 1;
        }
        for (auto sharp : sharps){
            nbody[sharp[1]][sharp[0]] = 1;
        }
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                if (nbody[i][j] == 0){
                    pos.push_back({j, i});
                }
            }
        }
        srand(time(0));
        if (pos.size() == 0){
            return 0;
        }
        ip = rand() % pos.size();
        apple = pos[ip];
        return 0;
    }
};