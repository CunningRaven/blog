README.md: make_readme FORCE
	./make_readme

make_readme: make_readme.c
	gcc -Wall $^ -o $@

FORCE:

.PHONY: FORCE
