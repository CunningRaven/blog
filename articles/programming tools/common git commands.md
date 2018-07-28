* .gitignore format
  * To ignore a file named 'config_bin' on the top directory of the project:
```
/config_bin
```
  * To ignore all the files with the suffix '.conf':
```
*.conf
```

  * To ignore all the files but those on the subdirectory 'foo/bar':
```
/*
!/foo
/foo/*
!/foo/bar
```

* Set up the user information:
```shell
git config --global user.name 'your name'
git config --global user.email 'your email address'
```

* Create a new git repository for a project:
```
# on the top directory of the project:
git init
git add .
git commit -a # notice any files that have been committed and have been modified since last committing.
git commit # notice new-added files in addition to those as the previous command does
```

* Manage branches:
```shell
git branch branch_name # create a new branch
git branch # list all the branches in the current project
git checkout branch_name # switch to a particular branch
git merge branch_name # merge a particular branch to the current branch
git diff # check out differences among branches
```

* Remote cooperations
```shell
git clone <URL> # This'll create a new directory on the current working one  
