
/*

## 命令行重定向
>

<


## 命令行编译
.ii
.s .S
.o .obj

-E: 到预处理
-S: 到汇编
-c: 到对象文件（只差链接了）

g++ ./hello.cpp -E > ./hello.ii # 预处理
g++ ./hello.ii -S -o ./hello.s # 编译
g++ ./hello.s -c -o ./hello.o # 汇编
g++ ./hello.o -o ./hello # 链接
/hello # 运行


## Makefile


## CMakeLists.txt

➢ add_executable(tgt srcs...)
• 从指定的源文件编译出一个可执行文件
➢ target_include_directories(tgt PRIVATE dirs...)
• 添加包含目录
➢ target_link_directories(tgt PRIVATE dirs...)
• 添加库查找目录
➢ target_link_libraries(tgt PRIVATE libs...)
• 添加库链接（-l...）
➢ target_compile_options(tgt PRIVATE opts...)
• 设置编译选项
➢ set_target_properties(tgt PROPERTIES prop1 val1 prop2
val2...)
• 设置其它的编译属性（标准版本、输出路径等等）



*/

