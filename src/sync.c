#include <stdio.h>
#include <stdlib.h>
#include <git2.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *curr_dir;
  git_repository *repo = NULL;
  git_status_options opts = GIT_STATUS_OPTIONS_INIT;
  git_status_list *statuses = NULL;

  char *p;
  int git_error;

  git_libgit2_init();

  p = strrchr(*argv, '/');
  if (p) {
    *p = 0;
    curr_dir = *argv;

  }

  git_error = git_repository_open(&repo, curr_dir);
  printf("Salida %d\n", git_error);

  int error = git_status_list_new(&statuses, repo, &opts);

  size_t count = git_status_list_entrycount(statuses);
  for (size_t i=0; i<count; ++i) {
    const git_status_entry *entry = git_status_byindex(statuses, i);

  }


  git_libgit2_shutdown();
}
