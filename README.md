# 1.6.1 学生成绩管理系统1.6.1（正式）

这是2024年8月最新的版本，新增了无限弹窗，自动关机，重启等功能

新增内嵌了密码管理系统,新增内嵌密码管理系统：可以登录，注册，账号密码存放于缓存之中。

将后缀改为.txt即可查看账号密码，后期会对密码进行哈希加密

新增日志文件，新增可以查看错误的日志文件，记录某年某月某时某分某秒发生的错误，对应错误码可以找到相应的环境错误

将设置中的第一个功能---换肤开发完成
		优化部分代码
		bug：--修改意见：
		1.经过玩家测试，部分电脑由于锁定cmd终端导致了system("mode con cols=100 lines=40");运行失败，导致了RE
		2.密码没有加密，建议后期使用哈希加密，这样子不用担心数据库的丢失
		3.准备新增VIP功能

# 1.6.2 学生成绩管理系统1.6.2（测试）

这是2024年9-10月最新的版本，对用户创建的密码进行了哈希加密和后缀加密

临时赶工，这是最新的系统但不稳定，后期的版本将不定期更新了，因为要做其他项目去了，如果没有其他问题将不再进行新增（如果有时间还是会的），本版本保留了所有可修改文件，届时若重新启动项目，可以直接用本项目开发。

# 1.5 赤色领域版本介绍

这个版本分为纯净版和病毒版，病毒版需要填写用户协议，表示同意才能继续进行程序的整活

1.新增用户协议页面
        2.新增界面名字，每个页面的左上角都会显示当前页面的功能名字
		3.新增设置功能
		4.解决因输入文字导致系统崩溃的问题，但还是无法持续接收很多文字，接收到一个文字直接退出系统
		5.优化部分重复代码

# 1.0 版本介绍

这个系统满足学校进行成绩的录入、查询、增删修改等需求的功能完善，安全可靠，迅速便捷的学生成绩管理系统。
目前为1.0
文件需要老师提供有且仅有两次的考试成绩表，里面包括学号，姓名，6个科目的成绩（数据结构，高等数学，大学英语，大学物理，大学体育）
系统将对这些文件进行读取和计算，实现的功能如下

1.功能一：查看成绩（所有记录）：学生成绩总分由高到低显示所有记录。其中包括学生的学号，姓名，学科成绩（高数，数据结构，线性代数，大学物理，大学英语，大学体育），总分，校排名，班排名。支持导出

2.功能2：统计汇总校，班的各科平均分，最高分，最低分，不及格人数，第二次考试缺考名单等所有数据.支持导出

3.查询数据（即输入姓名或学号可查询该生的所有成绩与排名，支持模糊查询，即输入“李”可查询所有名字中含有“李”字学生的成绩；）

4.修改成绩：修改学生每个科目的成绩

5.成绩补录。显示第二次缺考考生的全部名单，然后可以进行成绩补录，考试成绩自定

6.删除学生成绩：按学号，或按姓名删除指定考试的学生成绩

7.降序输出成绩：能按成绩总分降序排列然后再赋与名次（班排名与校排名），分数相同名次相同。（如果有两个第二名，则没有第三名了）

8.分班导出数据：能看到学生最近考试成绩的总分升降情况，能按进步排名进行降序排列（相对上次次考试）。支持导出

9.查询挂科人员名单，优秀率名单等等

10.帮助文档，一个帮助文档

11.退出系统：直接退出系统

为了方便各位大佬的测试，本文档提供两场由AI生成的随机成绩和姓名学号，大家可以使用，其中第一场考试默认命名为1.txt，第二场默认命名为2.txt
读者在使用的时候可以更改主函数的初始值，并将注释部分取消，当然这里提供完全面向用户的版本也提供面向编程用户的版本
这个是其中一行的命名规律
2025540883339   Alex Johnson   74  42  83  68  67  85其中第十一为数字为班级识别码，3代表4班。
*********************************************************************************************************************************************************************************
其次是我们的最经典的strstr函数，让我节省了很多工作量，比较前后检查字符串子集，不同返回NULL，十分好用，五星好评，然后另外一个好评给到了我们最好用的map映射，其用法体现在对名字和其在每场考试的位置的对应，屡试不爽，真的值得推荐，也是节省了一堆的代码量
那为什么我的代码还是1000多行呢，主要是文件导出部分和直接输出部分的重合导致的代码重复，至少重复了200行，推荐后期解决这个问题。
*********************************************************************************************************************************************************************************
Ok，接下来是bug，也就是2.0的改进方向
在后期，在拿给一些人进行测试的时候发现了部分输入，如一部分选择输入1,2,3,4，我们考虑了很充分了，但是没考虑到用户输入文字，我们知道文字ASCII值如啊:21834，用户输入啊，相当于后台接收了2 1 8 3 4，导致整个系统功能混乱，这是一个问题，2.0可以思考解决。
然后是创新方面，其实在某些界面如修改界面这里，可以添加一个批量修改，不要一个科目一个科目的修改，这样子用户体验会更好，其次，可以添加重考（参加了考试，但对考试不满意重新考试）录入模块，在删除考试成绩模块还可以添加考生封杀模块(即该考生作弊，取消该考试所有成绩，并添加开除学籍模块)etc。期待2.0版本吧。
*********************************************************************************************************************************************************************************
最后是真的心得体会，这次打代码对我最大的体会就是，对于建立一个系统，我们需要整体想一个框架，其次，对基础知识要把握，要有充分接纳新知识并训练到炉火纯青的决心，要独立思考，体现在要坚持自己的想法，可以借鉴他人比较好的想法，在打代码过程中第一保持好奇心和幽默，这样子不至于打不下去，不会的先自己想，再去“骚扰”同学（这样子才有印象和作用），对于常见的错误提示，如程序无法运行（数组爆了，无限循环了...等等要去总结）要会辨认。不骄不躁，不气馁，专心致志，圣人言：“运筹帷幄之中”，对这个系统的整体框架我们需要牢记并有印象，否则就是迷茫的打代码，此之谓“预则立，不欲则废”，瞻前顾后，对于变量，我们要取好名字，这样子在好多好多复杂变量中我们才可能清晰的掌握我们的编程方向，ok，本次代码令我受益匪浅，虽然花了很多时间，学了很多新知识，但基于这个系统考察的算法十分简单，所以我收获更多是对一个系统的框架拟定，see you next article。
