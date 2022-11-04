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
    
private:
    std::string caption{};
	std::string label{};
	std::string name{};
	std::string format{};
	std::string path{};
	std::string tab;
	std::string enter;
	std::string begin_figure;
	std::string setCentering;
	std::string begin_subfigure;
	std::string begin_minipage_head ;
	std::string begin_minipage_trail;
	std::string includegraphics_head;
	std::string includegraphics_trail;
	std::string end_minipage;
	std::string end_subfigure;
	std::string end_figure;
	int size{};
	int numberPerRow{};
	
};