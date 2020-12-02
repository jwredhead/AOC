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

        int sum1, sum2, value1, value2, number;
        std::vector<int>::iterator it;
        bool success = false;
        do
        {
            for (unsigned i=0; i < inputVector.size(); ++i)
            {
                sum1 = inputVector.front() + inputVector[i];
                if (sum1 < 2020)
                {
                    for (unsigned j=0; j < inputVector.size(); ++j)
                    {
                        sum2 = inputVector[j] + sum1;
                        if (sum2 == 2020)
                        {
                            success = true;
                            value1 = inputVector[i];
                            value2 = inputVector[j];
                        }
                    }
                }
            }

            if(success == false)
            {
                inputVector.erase(inputVector.begin());
            }


        } while (success == false);
        number = inputVector.front() * value1 * value2;
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