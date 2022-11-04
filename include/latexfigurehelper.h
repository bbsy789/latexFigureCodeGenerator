#pragma once

#include <iostream>
#include <string>

class LatexFigureHelper
{
public:
	LatexFigureHelper(const string& other_name, const string& other_format, const int& other_size, const string& other_path, const int& other_numberPerRow)
		:name(other_name), size(other_size), path(other_path), format(other_format), numberPerRow(other_numberPerRow)
	{
		label = "fig:" + name;
		caption = label;
	}
	bool print();

	void setNumberPerRow(int&& intput_numberPerRow)
	{
		numberPerRow = intput_numberPerRow;
	}

	void setLabel(string& input_label)
	{
		label = input_label;
	}


	void setCaption(string& input_caption)
	{
		caption = input_caption;
	}

	void setName(string& other_name)
	{
		name = other_name;
	}
private:
	string caption{};
	string label{};
	string name{};
	string format{};
	string path{};
	int size{};
	int numberPerRow{};
	const std::string tab = "	";
	const std::string enter = "\n";
	const std::string begin_figure = "\\begin{figure*}[htbp]\{\n";
	const std::string setCentering = "\\centering\n";
	const std::string begin_subfigure = "\\subfigure{\n";
	const std::string begin_minipage_head = "\\begin{minipage}[t]{";
	const std::string begin_minipage_trail = "\\linewidth }\n"	;
	const std::string includegraphics_head = "\\includegraphics[width=1\\linewidth]{";
	const std::string includegraphics_trail = "}\n";
	const std::string end_minipage = "\\end{minipage}\n";
	const std::string end_subfigure = "}\n";
	const std::string end_figure = "}\n\\end{figure*}\n";
};