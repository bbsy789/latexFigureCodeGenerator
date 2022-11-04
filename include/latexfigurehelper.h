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
    const string tab;
	const string enter;
	const string begin_figure;
	const string setCentering;
	const string begin_subfigure;
	const string begin_minipage_head;
	const string begin_minipage_trail;
	const string includegraphics_head;
	const string includegraphics_trail;
	const string end_minipage;
	const string end_subfigure;
	const string end_figure;
private:
    std::string caption{};
	std::string label{};
	std::string name{};
	std::string format{};
	std::string path{};
	int size{};
	int numberPerRow{};
};