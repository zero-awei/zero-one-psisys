@rem 关闭命令行输出
@echo off
setlocal enabledelayedexpansion

@rem ===================定制化参数===================
echo --------------------------------
echo 本工具用于复制demo中必须资源到新增模块中
echo 需要你输入新建模块名称,(即：新模块所在的文件夹路径)
set /p "newm=输入模块名称(如：sample)："
echo --------------------------------
@rem ================================================

@rem 执行复制逻辑
xcopy arch-demo !newm! /S /Y /EXCLUDE:exclude.txt
@rem 构建一些空目录保证结构完整
md !newm!\dao !newm!\service
echo 文件复制完成
pause