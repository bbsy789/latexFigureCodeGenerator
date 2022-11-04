# latexFigureCodeGenertor
latexFigureCodeGenertor是一个生成latex code的生成器。
它的主要目的是用于在Paraview的Save annimation功能会产生大量的图片，并且这些图片是有固定编号的，因此可以编写一个生成器来产生latex代码，节省时间。
请使用VS2022进行编译，C++标准为lastest，启用实验性的模块。
# 样例输入：
## 文件名: d
## 文件格式：jpeg
## 你存放的图片相对latex文件夹根目录的路径: img/d/
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
# A:
1.Windows下终端默认是采用系统设置，而windows系统默认的编码是GBK。需要使用
``` chcp 65001 ```
切换终端编码为UTF-8。