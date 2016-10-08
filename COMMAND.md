linux common command study
====


sed
____
* 在文件前添加一行 `sed -i 1i\word` word 插入文字

grep
____
* 在文件中搜索 `grep -n "key" file` -n 显示行号
* 正则搜索  `grep -n hello.*world.* file -m 3` -m 限制显示数量

rev
____
`rev <file name>`rev命令会将你文件中的内容反转输出到命令行

bc
____
`bc`命令行计算器

cal
____
`cal` 命令行日历

ssh
___
`ssh xxx bash < xxx.sh` 远程执行脚本

vim 
___
`vim scp://xxx/~/.bashrc` vim编辑远程文件

命令行快捷键
____
`CTRL+a` 移动光标到行首
`CTRL+e` 移动光标到行末

