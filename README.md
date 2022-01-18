# SmellsFishy

[![release](https://img.shields.io/github/v/tag/LazyKeru/SmellsFishy?style=plastic)](https://github.com/LazyKeru/SmellsFishy/tags)[![semantic-release: angular](https://img.shields.io/badge/semantic--release-angular-e10079?logo=semantic-release)](https://github.com/semantic-release/semantic-release)

A SAST tool, to detect hard coded secrets. Will be written in C, and use Entropy, Regex and machine learning algorithm for detection.

## To do list:

- [ ] Function to read files
- [ ] Linked structure to stock all the data
- [ ] Function to detect regex positive word
- [ ] Function to check the Entropy of the detected words
- [ ] Python Machine learning to find a model to check for hard coded secrets
- [ ] Exporting the best model to C

## Workflow

- [![semantic-versionning](https://img.shields.io/github/workflow/status/LazyKeru/SmellsFishy/Semantic-versionning?style=plastic&label=Versionning)](https://github.com/LazyKeru/SmellsFishy/actions/workflows/semantic_versioning.yml)

## Commit convention :
- BREAKING CHANGE: 
- build: Changes that affect the build system or external dependencies (example scopes: gulp, broccoli, npm)
- ci: Changes to our CI configuration files and scripts (examples: CircleCi, SauceLabs)
- docs: Documentation only changes
- feat: A new feature
- fix: A bug fix
- perf: A code change that improves performance
- refactor: A code change that neither fixes a bug nor adds a feature
- test: Adding missing tests or correcting existing tests