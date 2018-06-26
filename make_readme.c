#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define URLPREFIX "https://github.com/CunningRaven/blog/blob/master/articles"
#define URLBUFFLEN (sizeof (((struct dirent *)0)->d_name) * 3)
#define ARTIDIR "articles"
#define ARTIDIRLEN (sizeof (ARTIDIR) - 1)

size_t str_replace(char *restrict dst, size_t maxlen,
    const char *restrict src,
    const char *restrict old, const char *restrict new)
{
  size_t nrd = 0, nwr = 0, copy_size;
  char *match_in;
  int ret;
  size_t old_size, new_size;

  if (!maxlen) {
    return 0;
  }

  old_size = strlen(old);
  new_size = strlen(new);

  while ((match_in = strstr(&src[nrd], old)) != NULL) {
    copy_size = (size_t)(match_in - &src[nrd]);
    ret = snprintf(&dst[nwr], maxlen - nwr, "%.*s", (int)copy_size, &src[nrd]);
    if (ret != copy_size) {
      return maxlen - 1;
    }
    nwr += copy_size;
    ret = snprintf(&dst[nwr], maxlen - nwr, "%s", new);
    if (ret != new_size) {
      return maxlen - 1;
    }
    nwr += new_size;
    nrd += copy_size + old_size;
  }
  copy_size = maxlen - nwr;
  ret = snprintf(&dst[nwr], copy_size, "%s", &src[nrd]);
  if (ret >= copy_size) {
    return maxlen - 1;
  } else {
    return ret + nwr;
  }
}

int main(int argc, char *argv[])
{
  FILE *readme;
  DIR *classes, *articles;
  struct dirent *cls, *article;
  char *url_dirname, *url_artiname, *path, *file;

  if ((url_dirname = calloc(URLBUFFLEN, 1)) == NULL) {
    perror("calloc");
    exit(1);
  }
  if ((url_artiname = calloc(URLBUFFLEN, 1)) == NULL) {
    perror("calloc");
    exit(1);
  }
  if ((path = calloc(URLBUFFLEN, 1)) == NULL) {
    perror("calloc");
    exit(1);
  }
  strncpy(path, ARTIDIR"/", URLBUFFLEN);
  file = &path[ARTIDIRLEN+1];

  if ((readme = fopen("README.md", "w")) == NULL) {
    perror("fopen");
    exit(1);
  }

  fprintf(readme, "**Welcome to my blog!**\n\n\nContent:\n\n");

  if ((classes = opendir(ARTIDIR)) == NULL) {
    perror("opendir");
    exit(1);
  }

  while ((cls = readdir(classes)) != NULL) {
    if (!strcmp(cls->d_name, ".") || !strcmp(cls->d_name, "..")) {
      continue;
    }
    str_replace(url_dirname, URLBUFFLEN, cls->d_name, " ", "%20");
    fprintf(readme, "* %s\n", cls->d_name);
    strncpy(file, cls->d_name, URLBUFFLEN - ARTIDIRLEN - 1);
    if ((articles = opendir(path)) == NULL) {
      perror("opendir");
      exit(1);
    }
    while ((article = readdir(articles)) != NULL) {
      if (!strcmp(article->d_name, ".") || !strcmp(article->d_name, "..")) {
        continue;
      }
      str_replace(url_artiname, URLBUFFLEN, article->d_name, " ", "%20");
      fprintf(readme, "  * [%s](%s/%s/%s)\n", article->d_name,
          URLPREFIX, url_dirname, url_artiname);
    }
    fprintf(readme, "\n");
    closedir(articles);
  }
  closedir(classes);

  fflush(readme);
  fclose(readme);

  return 0;
}

      
