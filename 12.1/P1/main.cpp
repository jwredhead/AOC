#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main (int argc, const char* argv[])
{
    
    std::vector <int> inputVector;

    std::string line;
    std::ifstream myfile;
    myfile.open("input.txt");
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            inputVector.push_back(atoi(line.c_str()));
        }    

        inputVector.push_back(-1);

        int number;
        std::vector<int>::iterator it;
        bool success = false;
        do
        {
            number = 2020 - inputVector.front();
            it = std::find(inputVector.begin(), inputVector.end(), number);

            if(it != inputVector.end())
            {
                number = inputVector.front() * *it;
                success = true;
            }
            else 
            {
                inputVector.erase(inputVector.begin());
            }

        } while (success == false);
        
        myfile.close();
        std::cout << "Number is " << number << std::endl;
        return 0;

    }
    else
    {
        std::cout << "Issue opening file" << std::endl;
        return -1;
    }

}