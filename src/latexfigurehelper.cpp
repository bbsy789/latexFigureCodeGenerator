#include "latexfigurehelper.h"

using std::string;
using std::cout;
using std::fixed;
using std::setprecision;
using std::ofstream;

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
	std::string tab = "	";
	std::string enter = "\n";
	std::string begin_figure = "\\begin{figure*}[htbp]\{\n";
	std::string setCentering = "\\centering\n";
	std::string begin_subfigure = "\\subfigure{\n";
	std::string begin_minipage_head = "\\begin{minipage}[t]{";
	std::string begin_minipage_trail = "\\linewidth }\n"	;
	std::string includegraphics_head = "\\includegraphics[width=1\\linewidth]{";
	std::string includegraphics_trail = "}\n";
	std::string end_minipage = "\\end{minipage}\n";
	std::string end_subfigure = "}\n";
	std::string end_figure = "}\n\\end{figure*}\n";
};

bool LatexFigureHelper::print()
{
	ofstream out("out.tex");
	string index;
	string includegraphics;
	const int totalRowN = (size / numberPerRow) + 1;

	out << begin_figure << tab << setCentering << enter;
	
	bool flag = true;

	for (int row = 0; row <= totalRowN && flag == true; ++row)
	{
		out << tab << "%No." << row + 1 << "row" << enter \
			<< tab << begin_subfigure;
		for (int i = 0; i < numberPerRow && flag ==true; ++i)
		{
			if (row * numberPerRow + i >= size)
			{
				flag = false;
			}
			if (row * numberPerRow + i < 10)
			{
				index = "000" + std::to_string(row* numberPerRow + i);
			}
			else if (row * numberPerRow + i >= 10 && row * numberPerRow + i < 100)
			{
				index = "00" + std::to_string(row * numberPerRow + i);
			}
			else if (row * numberPerRow + i >= 100 && row * numberPerRow + i < 1000)
			{
				index = "0" + std::to_string(row * numberPerRow + i);
			}
			else if (row * numberPerRow + i >= 1000 && row * numberPerRow + i < 10000)
			{
				index = std::to_string(row * numberPerRow + i);
			}
			else
			{
				cout << "Error:image total number is too large\n this program will exit!\n";
				return 1;
			}
			includegraphics = includegraphics_head + path + name + "." + index +"." + format + includegraphics_trail;
			if (out.is_open())
			{
				out << tab << tab << begin_minipage_head << fixed << setprecision(3) << 1/ static_cast<double>(numberPerRow) << begin_minipage_trail \
					<< tab << tab << setCentering \
					<< tab << tab << includegraphics \
					<< tab << tab << end_minipage;
			}
		}
		out << tab << end_subfigure \
			<< tab << "\\vspace{-3mm}\n"\
			<< tab << "\\setcounter{subfigure}{0}\n";
	}
	
	out << tab << "\\caption{" << caption << "}\n";
	out << tab << "\\label{" << label << "}\n";
	out << end_figure;
	out.close();
	return 0;
}
