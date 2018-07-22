The error similar with the following was always reported to me when trying to drop a foreign key:
```
ERROR 1025 (HY000): Error on rename of '.\products\customers' to '.\products\#sql2-7ec-a3' (errno: 152)
```

Later, I found [this StackOverflow Page](https://stackoverflow.com/questions/11649092/mysql-drop-foreign-key-error-152) and followed the second solution to use 'alter table drop index ...' statement instead. It worked.
I can't figure out the reason at this moment and just record this here.
