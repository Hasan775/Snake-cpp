#pragma once
#include <vector>
#include <time.h>
using namespace std;
class Sharp{
public:
    vector<vector<int>> sharps;
    int amountToSharp = 1;
    int Spawn(vector<vector<int>> body, vector<int> apple, int width, int height){
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
        nbody[apple[1]][apple[0]] = 1;
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
        sharps.push_back(pos[ip]);
        return 0;
    }
};