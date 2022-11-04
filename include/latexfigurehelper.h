#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <string_view>

class LatexFigureHelper
{
public:
    LatexFigureHelper(const string& other_name, const string& other_format, const int& other_size, const string& other_path, const int& other_numberPerRow);

    bool print();

    void setNumberPerRow(int&& intput_numberPerRow);

    void setLabel(string& input_label);

	void setCaption(string& input_caption);

	void setName(string& other_name);
};