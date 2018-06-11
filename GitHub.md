# GitHub

> This is quick reference for Github First-hand users.

## Create a repository and add files

```sh
echo "#README" >> README.md  #新建README文档
git init 
git add 文件名
git commit -m "描述"
git remote add origin https://github.com/******.git 	#新建远程仓库分支 origin
git push -u origin master 		#上传到远程仓库分支
```

