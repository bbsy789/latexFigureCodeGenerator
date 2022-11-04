#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class LatexFigureHelper
{
public:
    LatexFigureHelper(const std::string& other_name, const std::string& other_format, const int& other_size, const std::string& other_path, const int& other_numberPerRow);

    bool print();

    void setNumberPerRow(int&& intput_numberPerRow);

    void setLabel(std::string& input_label);

	void setCaption(std::string& input_caption);

	void setName(std::string& other_name);
};