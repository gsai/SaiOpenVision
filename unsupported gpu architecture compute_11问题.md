  今天在服务器上（系统是**Ubuntu14.04.2 LTS**) 编译 **oepncv2.4.10** 库是，报道了一个错误，**nvcc fatal : Unsupported gpu architecture 'compute_11'** ,
  从字面上看是由于GPU architecture的问题，搜索后发现，如果要用cmake来编译opencv库，
  要设定**CUDA_GENERATION**这个选项为你的GPU architecture值。
  
  
  解决方法： 在原来的cmake 命令上加上这么一项：**—D CUDA_GENERATION=Auto**。
  
  全部的**cmake**命令为：
  **cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_TIFF=ON -D BUILD_EXAMPLES=ON -D CUDA_GENERATION=Auto -D BUILD_NEW_PYTHON_SUPPORT=ON ..**
  
  
#注意#
编译完成后，生成的可执行文件在**opencv-2.4.10/release/bin**目录下
