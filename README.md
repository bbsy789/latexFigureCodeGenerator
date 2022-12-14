# latexFigureCodeGenertor
latexFigureCodeGenertor是一个生成latex code的生成器。
它的主要目的是用于节省时间。在Paraview的Save annimation功能会产生大量的图片，并且这些图片是有固定编号的，因此可以编写一个生成器来产生latex代码。
请使用VS2022进行编译，C++标准为lastest，启用实验性的模块。

# How to use?
## Windows:
直接下载编译好的程序，在终端下运行即可。
如果windows版本过低，可以自行编译。

## Linux:
```git clone https://github.com/bbsy789/latexFigureCodeGenerator.git```

```cd latexFigureCodeGenerator```

```cmake -S . -B build```

```cmake --build build```

可执行文件会生成在项目根目录的bin文件夹下。

./bin/latexFigureCodeGenerator

# 样例输入：
## 文件名: image
## 文件格式：jpeg
## 你存放的图片相对latex文件夹根目录的路径: img/
## 图片结束的数字：9
## 每行的图片数量：5

# 输出的out.tex文件内容

``` latex
\begin{figure*}[htbp]{
	\centering

	%No.1row
	\subfigure{
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0000.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0001.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0002.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0003.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0004.jpeg}
		\end{minipage}
	}
	\vspace{-3mm}
	\setcounter{subfigure}{0}
	%No.2row
	\subfigure{
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0005.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0006.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0007.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0008.jpeg}
		\end{minipage}
		\begin{minipage}[t]{0.200\linewidth }
		\centering
		\includegraphics[width=1\linewidth]{img/image.0009.jpeg}
		\end{minipage}
	}
	\vspace{-3mm}
	\setcounter{subfigure}{0}
	\caption{fig:image}
	\label{fig:image}
}
\end{figure*}
```

# Q:
1.控制台运行中出现乱码？

2.latex编译错误？
# A:
1.Windows下终端默认是采用系统设置，而Windows系统默认的编码是GBK。需要使用
``` chcp 65001 ```
切换终端编码为UTF-8。

2.可能是没有引入宏包：
``` latex
\usepackage{subfigure}
\usepackage{graphicx}
```
