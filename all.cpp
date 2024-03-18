#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class NumberSorter
{
public:
    // ��ȡ�ļ��е����ֵ�vector��
    bool readNumbersFromFile(const std::string &inputFilename)
    {
        std::ifstream inputFile(inputFilename);
        if (!inputFile.is_open())
        {
            std::cerr << "�޷��������ļ�: " << inputFilename << std::endl;
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

    // ��vector�е����ֽ�������
    void sortNumbers()
    {
        std::sort(numbers_.begin(), numbers_.end());
    }

    // ������������д�뵽��һ���ļ���
    bool writeSortedNumbersToFile(const std::string &outputFilename)
    {
        std::ofstream outputFile(outputFilename);
        if (!outputFile.is_open())
        {
            std::cerr << "�޷�������ļ�: " << outputFilename << std::endl;
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
    const std::string inputFilename = "all.in";      // ˫�������������ȡ���ļ�·��
    const std::string outputFilename = "output.txt"; // ˫������������д�����ļ�·��

    if (sorter.readNumbersFromFile(inputFilename))
    {
        sorter.sortNumbers();
        if (sorter.writeSortedNumbersToFile(outputFilename))
        {
            std::cout << "����������ɲ���д���ļ�: " << outputFilename << std::endl;
        }
        else
        {
            std::cerr << "�޷�д������ļ���" << std::endl;
        }
    }
    else
    {
        std::cerr << "�޷���ȡ�����ļ���" << std::endl;
    }

    return 0;
}