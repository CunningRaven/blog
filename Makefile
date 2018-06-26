README.md: make_readme
	./make_readme

make_readme: make_readme.c
	gcc -Wall $^ -o $@

