#pragma once
#include <vector>
using namespace std;
class Snake{
public:
    vector<vector<int>> body;
    vector<int> direction;
    vector<int> lastPos;
    int ChangePos(int width, int height){
        lastPos = body[body.size() - 1];
        for (int i = body.size() - 1; i > 0; i--){
            body[i][0] = body[i - 1][0];
            body[i][1] = body[i - 1][1];
        }
        body[0][0] += direction[0];
        body[0][1] += direction[1];
        if (body[0][0] == -1){
            body[0][0] = width - 1;
        }
        else if (body[0][0] == width)
        {
            body[0][0] = 0;
        }
        
        if (body[0][1] == -1){
            body[0][1] = height - 1;
        }
        else if (body[0][1] == height)
        {
            body[0][1] = 0;
        }
        return 0;
    };
    int ChangeDir(vector<int> dir){
        if (dir[0] + direction[0] != 0){
            direction = dir;
        }
        return 0;
    }
    int AddSegment(){
        body.push_back(lastPos);
        return 0;
    }
    bool Check(vector<vector<int>> sharps){
        for (int i = 1; i < body.size(); i++){
            if (body[i][0] == body[0][0] && body[i][1] == body[0][1]){
                return true;
            }
        }
        for (auto i : sharps){
            if (i[0] == body[0][0] && i[1] == body[0][1]){
                return true;
            }
        }
        return false;
    }
};