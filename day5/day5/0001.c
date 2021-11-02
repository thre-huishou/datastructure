#define _CRT_SECURE_NO_WARNINGS 1

//有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
//给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
//为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着
//再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。
//将所有有记录的像素点的颜色值改为新的颜色值。
//最后返回经过上色渲染后的图像。

void flood(int** image, int x, int y, int newcolor, int imageSize, int* imageColSize)
{
	if (x > 0 && y > 0 && x < imageColSize[0]-1 && y < imageColSize[1]-1)
	{
		if (image[x - 1][y] == imageSize)
		{
			image[x - 1][y] = newcolor;
			flood(image, x - 1, y, newcolor, imageSize, imageColSize);
		}
		if (image[x + 1][y] == imageSize)
		{
			image[x + 1][y] = newcolor;
			flood(image, x + 1, y, newcolor, imageSize, imageColSize);
		}
		if (image[x][y - 1] == imageSize)
		{
			image[x][y - 1] = newcolor;
			flood(image, x, y - 1, newcolor, imageSize, imageColSize);
		}
		if (image[x][y + 1] == imageSize)
		{
			image[x][y + 1] = newcolor;
			flood(image, x, y + 1, newcolor, imageSize, imageColSize);
		}
	}
	else
	{
		if (x == 0 || x == imageColSize[0]-1)
		{
			if (y != 0 || y != imageColSize[1]-1)
			{
				image[x][y - 1] == imageSize ? newcolor : image[x][y - 1];
				image[x][y + 1] == imageSize ? newcolor : image[x][y + 1];
			}
			else if (y == 0)
			{
				image[x][y + 1] == imageSize ? newcolor : image[x][y + 1];
			}
			else {
				image[x][y - 1] == imageSize ? newcolor : image[x][y - 1];
			}
		}
		if (y == 0 || y == imageColSize[1]-1)
		{
			if (x != 0 || x != imageColSize[0]-1)
			{
				image[x - 1][y] == imageSize ? newcolor : image[x - 1][y];
				image[x + 1][y] == imageSize ? newcolor : image[x + 1][y];
			}
			else if (x == 0)
			{
				image[x + 1][y] == imageSize ? newcolor : image[x + 1][y];
			}
			else {
				image[x - 1][y] == imageSize ? newcolor : image[x - 1][y];
			}
		}
	}
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {
	int i = sr, j = sc;
	returnColumnSizes = image;
	returnSize = imageColSize;
	flood(image, i, j, newColor, imageSize, imageColSize);
	return returnColumnSizes;
}

int main()
{
	int image[][3] = { {1,1,1},{1,1,0},{1,0,1} };
	int imageColSize[] = { 3,3 };
	int sr = 1;
	int sc = 1;
	int newColor = 2;
	int returnSize[2] = { 0 };
	int returnColumnSizes[][3] = { 0 };
	floodFill(image, 1, imageColSize,sr,sc,newColor,returnSize,returnColumnSizes);
	return 0;
}