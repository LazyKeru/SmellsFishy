#include "../../header/test/test.hpp"
#include "../../header/git/git.hpp"
#include "../../header/util/util.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

const char* url = "https://github.com/LazyKeru/SmellsFishy.git";
const char* path = "../temp/";

bool test::git()
{
    git_repository *repo = NULL;
    Git::git_clone_local(path, url, &repo);
    Git::git_scan_history(repo);
    Git::git_clean_local(path, &repo);
    return true;
}