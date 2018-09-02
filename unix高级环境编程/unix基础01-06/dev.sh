#!/bin/zsh

echo -n "源文件："
read source_c

echo -n "目标文件："
read target_c

gcc $source_c -o $target_c -L ../ -l apue