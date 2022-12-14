export module latexfigurehelper;
//这个模块实现了打印latex插入图片的代码到同目录下out.tex文件中。

import std.core;

export class LatexFigureHelper;

using std::string;
using std::string_view;
using std::cout;
using std::fixed;
using std::setprecision;

class LatexFigureHelper
{
	
public:
	LatexFigureHelper(const string& other_name, const string& other_format, const uint32_t& other_size, const string& other_path, const uint32_t& other_numberPerRow)
		:name(other_name), size(other_size), path(other_path), format(other_format), numberPerRow(other_numberPerRow)
	{
		label = "fig:" + name;
		caption = label;
	}
	bool print();

	void setNumberPerRow(uint32_t&& intput_numberPerRow)
	{
		numberPerRow = intput_numberPerRow;
	}

	void setLabel(string& input_label)
	{
		label = input_label;
	}

	void setLabel(string_view& input_label)
	{
		label = input_label;
	}

	void setCaption(string& input_caption)
	{
		caption = input_caption;
	}

	void setCaption(string_view& input_caption)
	{
		caption = input_caption;
	}

	void setName(string& other_name)
	{
		name = other_name;
	}
	void setName(string_view& other_name)
	{
		name = other_name;
	}
	const string tab = "	";
	const string enter = "\n";
	const string begin_figure = "\\begin{figure*}[htbp]\{\n";
	const string setCentering = "\\centering\n";
	const string begin_subfigure = "\\subfigure{\n";
	const string begin_minipage_head = "\\begin{minipage}[t]{";
	const string begin_minipage_trail = "\\linewidth }\n"	;
	const string includegraphics_head = "\\includegraphics[width=1\\linewidth]{";
	const string includegraphics_trail = "}\n";
	const string end_minipage = "\\end{minipage}\n";
	const string end_subfigure = "}\n";
	const string end_figure = "}\n\\end{figure*}\n";
private:
	string caption{};
	string label{};
	string name{};
	string format{};
	string path{};
	uint32_t size{};
	uint32_t numberPerRow{};
};

bool LatexFigureHelper::print()
{
	std::ofstream out("out.tex");
	std::string index;
	std::string includegraphics;
	const uint32_t totalRowN = (size / numberPerRow) + 1;

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
