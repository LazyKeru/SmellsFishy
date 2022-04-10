#include "../../header/git/git.hpp"
#include "../../header/external/include/git2.h"

void Git::git_clone(const char * &path_output, const char * &url){
      git_libgit2_init();
      git_repository *repo = NULL;
      int error = git_clone(&repo, url, path_output, NULL);
      git_libgit2_shutdown();
}