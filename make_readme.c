#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define URLPREFIX "https://github.com/CunningRaven/blog/blob/master/articles"

int main(int argc, char *argv[])
{
  FILE *readme;
  char *dirname, *artiname;
  char *url_dirname, *url_artiname;
  DIR *classes, *articles;
  struct dirent *class, *article;

  if ((url_dirname = calloc(sizeof (class->d_name) * 3, 1)) == NULL) {
    perror("calloc");
    exit(1);
  }
  if ((url_dirname = calloc(sizeof (class->d_name) * 3, 1)) == NULL) {
    perror("calloc");
    exit(1);
  }

  if ((readme = fopen("README.md", "w")) == NULL) {
    perror("fopen");
    exit(1);
  }

  fprintf(readme, "**Welcome to my blog!**\n\n\nContent:\n\n");

  if ((classes = opendir("articles")) == NULL) {
    perror("opendir");
    exit(1);
  }

  while ((class = readdir(classes)) != NULL) {
    fprintf(readme, "* %s\n", class->d_name);
    if ((articles = opendir(class->d_name)) == NULL) {
      perror("opendir");
      exit(1);
    }
    while ((article = readdir(articles)) != NULL) {
      fprintf(readme, "  * [%s](%s/
      
