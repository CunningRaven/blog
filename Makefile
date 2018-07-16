README.md: make_readme FORCE
	./make_readme

make_readme: make_readme.c
	gcc -Wall --std=c99 $^ -o $@

FORCE:

.PHONY: FORCE
