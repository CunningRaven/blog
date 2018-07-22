When a foreign key is added, the database server will generate an accompanied index of the same column synchronously. It would not delete this accompanied index to drop the foreign key.

*Syntax to add a foreign key:
```SQL
ALTER TABLE altered_table ADD FOREIGN KEY key_name (constrained_column) REFERENCES referenced_table (referenced_name);
```

*Syntax to drop a foreign key:
```SQL
ALTER TABLE altered_table DROP FOREIGN KEY key_name;
```

If you didn't declare the name of a foreign key, the server would name it as well as its accompanied index automatically; This name can be found by querying information_schema.key_table_usage. That of the index can be found by querying information_schema.statistics.


