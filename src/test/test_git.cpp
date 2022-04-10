#include "../../header/test/test.hpp"
#include "../../header/git/git.hpp"
#include "../../header/util/util.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

const char* repo = "https://github.com/LazyKeru/SmellsFishy.git";
const char* path = "./temp/";

bool test::git()
{
    Git::git_clone(path, repo);
    return true;
}