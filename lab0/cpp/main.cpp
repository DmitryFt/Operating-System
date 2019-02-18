#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
       std::vector<int> inputData, Packages;
       std::string line;
       int counter = 0;
       char filename[] = "packages.txt";
       std::ifstream readfile;
       readfile.open(filename, std::ios_base::in);
       if (!readfile.is_open()) {
           std::cout << "can't open file" << std::endl;
           return 1;
       }
       while (std::getline(readfile, line)) {
           counter++;
           int temp = std::stoi(line);
           inputData.push_back(temp);
           Packages.push_back(temp);
           std::sort(inputData.begin(), inputData.end());
           auto last = std::unique(inputData.begin(), inputData.end());
           inputData.erase(last, inputData.end());
           int count = 0;
           for (int i : Packages)
           {
               std::cout << i << " ";
               if(inputData.size()==1)
                   cout<<"\nNo lost packages";
           }
           if(inputData.size()!=1)
               cout<<"\nLost packages: ";
           for(int i = 0; i < inputData.size()-1;i++)
           {
               if((inputData[i]+1) != inputData[i+1])
               {
                   int iter = (inputData[i+1] - (inputData[i]))-1;
                   count = count + iter;
                   for(int it = 1;it <= iter;it++)
                       cout<<""<<(inputData[i]+it)<<", ";
               }
       }
           cout<<endl;
       }
    return a.exec();
}
