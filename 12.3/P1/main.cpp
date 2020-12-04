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

    int rowLength = ceil(4 * length / width);

    std::vector<std::string> map;
    std::string temp = "";
    for (auto i : inputVector)
    {
        for (int j=0; j < rowLength; ++j)
        {
            temp = temp + i;
        }
        map.push_back(temp);
        temp.clear();
    }

    char space;
    int count = 0;
    for(int i=0; i < map.size(); ++i)
    {
        space = map.at(i).at(3*i);
        if (space == '#')
        {
            count++;
        }
    }
    std::cout << "The Number of Trees is " << count << std::endl;

    return 0;
}