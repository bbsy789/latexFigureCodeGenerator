#ifndef LATEXFIGUREHELPER_H
#define LATEXFIGUREHELPER_H
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
private:
    std::string caption{};
	std::string label{};
	std::string name{};
	std::string format{};
	std::string path{};
	int size{};
	int numberPerRow{};
};
#endif