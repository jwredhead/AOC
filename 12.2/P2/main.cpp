#include <fstream>
#include <iostream>
#include <vector>
#include <string>

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

    inputVector = readFiletoVector("12.2/input.txt");
    if (inputVector.empty())
    {
        std::cout << "ERROR: Input File is empty!" << std::endl;
        return -1;
    }

    int min, max;
    char letter;
    std::size_t dash, space;
    int numValid = 0;
    for (auto i : inputVector)
    {
        dash = i.find('-');
        min = atoi(i.substr(0, dash).c_str());
        space = i.find(' ');
        max = atoi(i.substr(dash+1, space).c_str());
        letter = i.at(space+1);
        
        i.find(':');
        i.erase(0, i.find(':')+2);
        int count = 0;

        if ((i.at(min-1) == letter && i.at(max-1) != letter) || (i.at(max-1) == letter && i.at(min-1) != letter))
        {
            numValid++;
        }    
    }

    std::cout << "Number of Valid Passwords =" << numValid << std::endl;

    return 0;
}