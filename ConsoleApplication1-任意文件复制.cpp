/***************任意类型文件进行复制的实现*****************/
#include<stdio.h>
#include<stdlib.h>
#define  NULL 0

int main()
{
	FILE* fp_from,*fp_to;
	void* buffer = NULL;
	long file_size = 0,size_end=0,size_start=0;
	
	const char* file_from = "F:\\360Downloads\\5c.jpg";
	const char* file_to = "f:\\C\\5c.jpg";
	// 注意分割了符号要用'\\',第一个是转意符。
	printf("\n********************TEST1****************\n");
	printf("%s\n", file_from);

	if (fopen_s(&fp_from , file_from, "rb") != 0)		//  注意，需要使用rb 模式
	{
		printf("文件打开失败\a\n");
		exit(0);
	}

	if (fopen_s(&fp_to, file_to, "wb") != 0)
	{
		printf("文件创建失败\a\n");
		exit(0);
	}

   	fseek(fp_from, 0, 0);
	size_start = ftell(fp_from);  // 读取指针的位置
	fseek(fp_from, 0, 2);
	size_end = ftell(fp_from);	
	file_size = size_end - size_start; //根据指针移到大小计算文件的大小
	
	printf("\n********************TEST2 ****************\n");
	printf("file_from size is :%ld\n", file_size);
	printf("size_end =%ld\n", size_end);
	printf("size_start=%ld\n", size_start);
	printf("the adress of file_size is: %d\n\n", &file_from);
	printf("file_from adress is : %p\n\n", fp_from);
	rewind(fp_from);
	buffer = (void*)malloc(file_size);

	// 分配内存中的存储空间	

	fread(buffer, file_size, 1, fp_from);
	fwrite(buffer, file_size, 1, fp_to);
	fclose(fp_from);
	fclose(fp_to);
	free(buffer);

	system("pause");
	return 0;
	   	 	
}

