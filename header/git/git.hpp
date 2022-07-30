#pragma once
/************************/
/**      Includes      **/
/************************/
#include <string>
#include "../external/include/git2.h"
#include "../util/log.hpp"
/************************/
/**     Functions      **/
/************************/
namespace Git
{
    void git_clone_local(const char * &path_output, const char * &url, git_repository ** repo);
    void git_scan_history(git_repository * repo);
    void git_clean_local(const char * &path_output, git_repository ** repo);
} // namespace Git
