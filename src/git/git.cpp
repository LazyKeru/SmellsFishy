#include "../../header/git/git.hpp"
#include <filesystem>
INIT_LOG

void Git::git_clone_local(const char * &path_output, const char * &url, git_repository ** repo){
    /* start using the libgit2 */
    git_libgit2_init();
    int error = git_clone(repo, url, path_output, NULL);
    /* done using the libgit2 */
    git_libgit2_shutdown();
}

void Git::git_scan_history(git_repository * repo){
    /* start using the libgit2 */
    git_libgit2_init();
    git_revwalk *walk;
    if (git_revwalk_new(&walk, repo) < 0){
        Log::msg << "No commit \n";
    }
    // he sorting mode when iterating through the repository's contents.
    git_revwalk_sorting(walk, GIT_SORT_TOPOLOGICAL | GIT_SORT_TIME);
    git_revwalk_push_head(walk);
    git_oid oid;
    while (git_revwalk_next(&oid, walk) == 0)
    {
        git_commit *c;
        char oidstr[10] = {0};
        /* Fetches the commit */
        git_commit_lookup(&c, repo, &oid);
        git_oid_tostr(oidstr, 9, &oid);
        Log::msg << oidstr << "\n" << git_commit_message(c) << "\n";
        /* Free up the object */
        git_commit_free(c);
    }
    /* cleanup mess */
    /* done using the libgit2 */
    git_libgit2_shutdown();
}

void Git::git_clean_local(const char * &path_output, git_repository ** repo){
    /* start using the libgit2 */
    git_libgit2_init();
    git_repository_free(*repo);
    std::filesystem::remove_all((std::filesystem::path) path_output);
    /* done using the libgit2 */
    git_libgit2_shutdown();
}