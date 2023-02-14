# 执行SQL注意事项

两个SQL文件说明:

- zopsi_sys_tables.sql：建库和建表的SQL脚本。
- zopsi_sys_view_fun_pro.sql：建立视图、函数、存储过程的SQL脚本。

SQL脚本的执行顺序是先执行zopsi_sys_tables再执行zopsi_sys_view_fun_pro。

在执行SQL文件的时候如果运行报错的话，检查你的sql_mode是否删除了下面的选项：

```txt
ONLY_FULL_GROUP_BY
NO_ZERO_DAT
NO_ZERO_IN_DATE
```

你可以通过下面命令行查看sql_mode情况

```sql
# 查看当前sql_mode
select @@sql_mode;
# 查看全局sql_mode
select @@global.sql_mode;
```

你可以通过下列指令修改（服务器重启后将会失效）

```sql
# 修改全局
set @@global.sql_mode = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
# 修改当前
set @@sql_mode = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
```

想要永久生效需要修改`my.ini`配置文件。

