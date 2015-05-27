/**
* @author gsai
* @version 0.1
* @time 2015/5/27
**/


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <vector>
#include <io.h>

using std::vector;
using std::string;
using namespace cv;

//函数声明
//find the all files in the dir
void findFiles(const string, vector<string>&);

//resize the image named with the 1st param to the Size of the 2nd param
void resizeImg(const string, const Size);

int main()
{
	string filePath = "D:/cascadeClassifier/positive_images";
	Size size(300, 300);
	vector<string> files;
	findFiles(filePath, files);
	for (auto it = files.begin(); it != files.end(); it++)
		resizeImg(*it, size);

	return 0;
}
void findFiles(const string path, vector<string>& files)
{
	string p;
	struct _finddata_t info;
	long hFile;

	if ((hFile = _findfirst(p.assign(path).append("./*").c_str(), &info)) != -1)
	{
		do
		{
			if (info.attrib & _A_SUBDIR)
			{
				if ((strcmp(info.name, ".") != 0) && (strcmp(info.name, "..") != 0))
					findFiles(p.assign(path).append("/").append(info.name), files);
			}
			else
				files.push_back(p.assign(path).append("/").append(info.name));
		} while (_findnext(hFile, &info) == 0);
		_findclose(hFile);
	}
}

void resizeImg(const string path, const Size size)
{
	Mat image = imread(path);
	resize(image, image, size);
	imwrite(path, image);
}
