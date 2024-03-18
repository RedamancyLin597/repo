#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class NumberSorter
{
public:
    // 读取文件中的数字到vector中
    bool readNumbersFromFile(const std::string &inputFilename)
    {
        std::ifstream inputFile(inputFilename);
        if (!inputFile.is_open())
        {
            std::cerr << "无法打开输入文件: " << inputFilename << std::endl;
            return false;
        }

        int number;
        while (inputFile >> number)
        {
            numbers_.push_back(number);
        }

        inputFile.close();
        return true;
    }

    // 对vector中的数字进行排序
    void sortNumbers()
    {
        std::sort(numbers_.begin(), numbers_.end());
    }

    // 将排序后的数字写入到另一个文件中
    bool writeSortedNumbersToFile(const std::string &outputFilename)
    {
        std::ofstream outputFile(outputFilename);
        if (!outputFile.is_open())
        {
            std::cerr << "无法打开输出文件: " << outputFilename << std::endl;
            return false;
        }

        for (int number : numbers_)
        {
            outputFile << number << std::endl;
        }

        outputFile.close();
        return true;
    }

private:
    std::vector<int> numbers_;
};

int main()
{
    NumberSorter sorter;
    const std::string inputFilename = "all.in";      // 双引号内填你想读取的文件路径
    const std::string outputFilename = "output.txt"; // 双引号内填你想写出的文件路径

    if (sorter.readNumbersFromFile(inputFilename))
    {
        sorter.sortNumbers();
        if (sorter.writeSortedNumbersToFile(outputFilename))
        {
            std::cout << "数字排序完成并已写入文件: " << outputFilename << std::endl;
        }
        else
        {
            std::cerr << "无法写入输出文件。" << std::endl;
        }
    }
    else
    {
        std::cerr << "无法读取输入文件。" << std::endl;
    }

    return 0;
}