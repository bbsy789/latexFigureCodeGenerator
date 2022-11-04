import latexfigurehelper;
import std.core;
auto main() -> int
{
	using std::cout;
	using std::cin;
	using std::string;
	string name{},format{},path{};
	int size{},numberPerRow{};
	cout << "这个小程序用于生成Latex多图片代码\n";
	cout << "作者：bbsy789\n";
	cout << "请输入图片文件名:\n";
	cin >> name;
	while (name.size() == 0)
	{
		cout << "Error:please input again!\n";
		cin >> name;
	}
	cout << "请输入图片格式：\n";
	cin >> format;
	while (format.size() == 0)
	{
		cout << "Error:please input again!\n";
		cin >> format;
	}
	cout << "请输入图片相对路径：\n";
	cin >> path;
	while (path.size() == 0)
	{
		cout << "Error:please input again!\n";
		cin >> format;
	}
	cout << "本程序假定Paraview默认保存的图片是四位数字！从0000开始\n";
	cout << "请输入图片结束数字（，）：\n";
	cin >> size;
	while (size == 0)
	{
		cout << "错误：输入的图片数量为0，请重新输入";
		cin >> size;
	}
	cout << "请输入每行图片数量：\n";
	cin >> numberPerRow;
	while (numberPerRow == 0)
	{
		cout << "错误：输入的图片数量为0，请重新输入";
		cin >> numberPerRow;
	}
	LatexFigureHelper hp(name,format, size, path, numberPerRow);
	if (hp.print())
	{
		return -1;
	}
	return 0;
}
