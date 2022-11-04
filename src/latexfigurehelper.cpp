#include "latexfigurehelper.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;
using std::fixed;
using std::setprecision;
using std::ofstream;

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
