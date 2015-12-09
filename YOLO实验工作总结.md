**前两天有其他事情耽误了，导致现在工作更加紧张了，YOLO:Real-time Object Detection 具体设计逻辑和paper就以后看了，现在目标：定位
写入图片的函数&结果列表输出函数，修改成批量保存识别出来的物体图片。**


**定位写入图片函数：demo的识别结果保存到了一个predictions.png图片，目前定位： src/coco.c：void draw_coco(image im, float *pred, int side, char *label)函数**


**定位列表输出函数：src/yolo.c:193:void validate_yolo(char *cfgfile, char *weightfile)函数，输入图片的设定，循环处理都在此**

**11月1日-3日，该写程序，测试数据，效果不错，识别出来的基本上都是车，就是有一些很小的图片也被识别出来了，初步方法是用width ,height 和 比例  来排除，感觉还有更好的方法**

**11月4日增加：阅读paper发现，在test模式下没有过量的小图片被标注的情况，借鉴他是如何排除的，添加到自己的代码中,定位到src/yolo.c：282：test_yolo**


**12月9日更新，在源码yolo.c里面的draw_yolo函数里面，25,26,27 三行参与了物体的排除，原理要看论文才能清楚，具体操作我写在了yolo.c的注释里**

**12月9日注意一个问题，test_yolo模式下传入的double* 和realtime模式下输出的那个文本有什么关系**

**12月9日，目标，了解基本的架构，看懂数据流向，了解优化方向**
