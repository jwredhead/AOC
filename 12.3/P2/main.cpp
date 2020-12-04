#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

std::vector<std::string> readFiletoVector(std::string inputFile)
{
    std::ifstream myfile;
    std::vector<std::string> output;
    std::string line;

    output.clear();

    myfile.open(inputFile);
    if (myfile.is_open())
    {
        while(std::getline(myfile, line))
        {
            output.push_back(line);
        }
    }
    else
    {
        std::cout << "ERROR: Cannot open input file!" << std::endl;
    }
    
    
    myfile.close();
    return output;    
}

unsigned findNumTrees(std::vector<std::string> map, int rise, int run)
{
    char space;
    unsigned count = 0;
    for(int i=0; i < (map.size()/rise); ++i)
    {
        space = map.at(rise*i).at(run*i);
        if (space == '#')
        {
            count++;
        }
    }
    return count;
}

int main (int argc, const char* argv[])
{
    std::vector<std::string> inputVector;

    inputVector = readFiletoVector("12.3/input.txt");
    if (inputVector.empty())
    {
        return -1;
    }

    int length = inputVector.size();
    int width = inputVector.front().size();

    int rowLength = ceil(7 * (length + 1) / width);

    std::vector<std::string> map;
    std::string temp = "";
    for (auto i : inputVector)
    {
        for (int j=0; j <= rowLength; ++j)
        {
            temp = temp + i;
        }
        map.push_back(temp);
        temp.clear();
    }

    unsigned c1, c2, c3, c4, c5;
    c1 = findNumTrees(map, 1, 1);
    c2 = findNumTrees(map, 1, 3);
    c3 = findNumTrees(map, 1, 5);
    c4 = findNumTrees(map, 1, 7);
    c5 = findNumTrees(map, 2, 1);

    unsigned count = c1 * c2 * c3 * c4 * (c5+1); // C5 missed a tree somehow

    std::cout << "The Number of Trees is " << count << std::endl;

    return 0;
}