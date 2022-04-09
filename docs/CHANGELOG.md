# 1.0.0 (2022-04-09)


### Bug Fixes

* added -g flag to make in order to use debug breakpoints ([015b6b9](https://github.com/LazyKeru/SmellsFishy/commit/015b6b993ba9bf8031022ca1d8e64adf388f8caa))
* added build and bin folder ([60dfe9d](https://github.com/LazyKeru/SmellsFishy/commit/60dfe9dfe80333dadaa6fa124ebf059d8aa81c29))
* added the '#pragma once' to a few files. And fixed the build for the unitary test ([ba6d671](https://github.com/LazyKeru/SmellsFishy/commit/ba6d671d2ff21848fe9397aa95fffe6de55cf051))
* brought the changes asked in the review ([6170bba](https://github.com/LazyKeru/SmellsFishy/commit/6170bba690d7c3afeadc40234949b202d9af5fe3))
* ci will now work on github, as path was replaced by relative path ([155ca20](https://github.com/LazyKeru/SmellsFishy/commit/155ca20bd3f1db3c89bd1c34e88f99a43cdd2eeb))
* deleted the wrong main ([4b061ef](https://github.com/LazyKeru/SmellsFishy/commit/4b061efdadd32838c4929503ca2fa602afe4edaa))
* fixed merge conflict ([67f1092](https://github.com/LazyKeru/SmellsFishy/commit/67f10922cb4519549619616022f78bbd9e167796))
* fixed merge conflict between main and feat-dir-search ([996bb65](https://github.com/LazyKeru/SmellsFishy/commit/996bb65f75d50c8fc292b1add7a8f3f2c74ee995))
* fixed the core problem ([1a7ab05](https://github.com/LazyKeru/SmellsFishy/commit/1a7ab05860b9e0803a733097939dd956fb00392a))
* gitignore ignores vs and vscode folders ([ef3a1ce](https://github.com/LazyKeru/SmellsFishy/commit/ef3a1ceefef78c57ff308471e5c577e66ea2366c))
* make breakpoints work and setting c++ standard to c++17 ([8ab0943](https://github.com/LazyKeru/SmellsFishy/commit/8ab0943726d6b917730ecc74b400c98d611514bd))
* makefile now shouldn't have any more double slash ([9c468e3](https://github.com/LazyKeru/SmellsFishy/commit/9c468e370c98127cbc189719bfb497187a194f35))
* relative paths ([25c0e63](https://github.com/LazyKeru/SmellsFishy/commit/25c0e63053f8eb8b52989d2c57ef2a836e0fa0da))
* removed unwanted file ([7a5bb3b](https://github.com/LazyKeru/SmellsFishy/commit/7a5bb3bab9a064ddbb9bb222c92a52e18890fddd))
* renamed a file, and changed the custom assert cuntion ([847feab](https://github.com/LazyKeru/SmellsFishy/commit/847feab34013371e1bb5c1d0bd244724a14fb329))
* renamed most variable which caused warnings, or even errors when building ([476461c](https://github.com/LazyKeru/SmellsFishy/commit/476461c617c52c3f37d8c14a12e3e9d112895f09))
* renamed some files, and cleaned the directory organisation ([b8c0667](https://github.com/LazyKeru/SmellsFishy/commit/b8c06678d4fa7009fbfb62b5dbdd9d3e4a0e939c))
* renamed the libraries in entropy.hpp ([dc137ae](https://github.com/LazyKeru/SmellsFishy/commit/dc137ae63f13ec225e76f497b6c3f42fa93a5472))
* reverted gitgnore ([8a30c0a](https://github.com/LazyKeru/SmellsFishy/commit/8a30c0a3fa938b6ea0cc394303d6604e33734b7f))
* test ([55fc1b9](https://github.com/LazyKeru/SmellsFishy/commit/55fc1b90a8c12bdfb4dae32c86a8ffceae03dd86))
* test for struct is now working ([55bc95e](https://github.com/LazyKeru/SmellsFishy/commit/55bc95e6086cacf3ef4924e6e2adb7887afebd3f))
* the main is now correctly built ([1fb7959](https://github.com/LazyKeru/SmellsFishy/commit/1fb7959261de72996f74a7106505712a36af3527))


### Features

* 1st demo is now ready ([4ae0c9d](https://github.com/LazyKeru/SmellsFishy/commit/4ae0c9dcd01fad0070212726b73b43597f2e2374))
* added a log function ([e8abb40](https://github.com/LazyKeru/SmellsFishy/commit/e8abb40d319f1dac07d9419d5125b5334c94bb40))
* added argument structure ([28fc0bd](https://github.com/LazyKeru/SmellsFishy/commit/28fc0bdcf79c3546683e9889c4a763487ff6ac10))
* added core ([a12e762](https://github.com/LazyKeru/SmellsFishy/commit/a12e7625db13487e25dbfb1dca1c3d4fc845315d))
* added entropy check in the core ([eff0f1d](https://github.com/LazyKeru/SmellsFishy/commit/eff0f1db090123232291e9ba6447832a79f9ff8f))
* added json loading fonctionnalities ([2e42ee0](https://github.com/LazyKeru/SmellsFishy/commit/2e42ee07563f020eca18caba8cfd4413e2f33e26))
* added more secrets ([d085a15](https://github.com/LazyKeru/SmellsFishy/commit/d085a151bed3188cbaf7f5ca5ca3388149a4f8ec))
* added secret and rule structure ([8bd7226](https://github.com/LazyKeru/SmellsFishy/commit/8bd722696c2d8c9a32fa1d56d13a4fb98b1117b8))
* added the entropy argument, to analyze with entropy ([c714144](https://github.com/LazyKeru/SmellsFishy/commit/c714144fda49406c0c51858882b1cf39647c2fbd))
* added the entropy calculator function ([f05276d](https://github.com/LazyKeru/SmellsFishy/commit/f05276d445d2918a1af7d95dc9ae16181d0bc474))
* added the option to output the log in a txt folder ([aadf66b](https://github.com/LazyKeru/SmellsFishy/commit/aadf66bd2e0edf939d6e405f5f938b8083c8e3bc))
* added the secretsPerFile struct and it's basic functions ([8695fe3](https://github.com/LazyKeru/SmellsFishy/commit/8695fe3416c1e64800f43ab8ed30847e354bd297))
* command line argument parser ([60c4cfc](https://github.com/LazyKeru/SmellsFishy/commit/60c4cfc85ebbf4506b8b72fa723f862976c59e71))
* core module ([38aa553](https://github.com/LazyKeru/SmellsFishy/commit/38aa55368239d545a00f8a8a1072ed8816136f57))
* core module ([b266a0f](https://github.com/LazyKeru/SmellsFishy/commit/b266a0fd7d25d155724be012a63a6041b5edda18))
* directory search for all files ([c6c3692](https://github.com/LazyKeru/SmellsFishy/commit/c6c3692fe3d4802af7bf6c74f686a3e911595ac7))
* function to check if it's a json file ([3d1b162](https://github.com/LazyKeru/SmellsFishy/commit/3d1b162327decc98e5911792de5712330faccd80))
* impl regex ([cc6a407](https://github.com/LazyKeru/SmellsFishy/commit/cc6a40774d61de5c488fa7dd27b3015293a56b23))
* json loading and finding in core ([1357f5b](https://github.com/LazyKeru/SmellsFishy/commit/1357f5bb638c3d3cb871b5f6f197796c97381473))
* load all json rules at once in core (not working) ([c1b977e](https://github.com/LazyKeru/SmellsFishy/commit/c1b977e43629ac4510006cecc89de5b586a8d2a6))
* started log_output ([d384982](https://github.com/LazyKeru/SmellsFishy/commit/d384982f2c0c8d328af9e6a99a3034bfe7419cf3))
* test function added ([85d5db3](https://github.com/LazyKeru/SmellsFishy/commit/85d5db35ef854b3f627bfd9454f213934f72a229))
* there is now an entropy check ([4141ea0](https://github.com/LazyKeru/SmellsFishy/commit/4141ea042c2587d4d84ea9fe9a4b37df9ec909c1))


### Performance Improvements

* regex improvements ([2f4d088](https://github.com/LazyKeru/SmellsFishy/commit/2f4d0889ff15180fb6aaef3579a5a65af5535811))
* the Makefile clean, now cleans all the exe and o files in the build and bin folder ([7177314](https://github.com/LazyKeru/SmellsFishy/commit/71773145a7369279c52652c2c21cde848cde3e34))

# 1.0.0 (2022-04-09)


### Bug Fixes

* added -g flag to make in order to use debug breakpoints ([015b6b9](https://github.com/LazyKeru/SmellsFishy/commit/015b6b993ba9bf8031022ca1d8e64adf388f8caa))
* added build and bin folder ([60dfe9d](https://github.com/LazyKeru/SmellsFishy/commit/60dfe9dfe80333dadaa6fa124ebf059d8aa81c29))
* added the '#pragma once' to a few files. And fixed the build for the unitary test ([ba6d671](https://github.com/LazyKeru/SmellsFishy/commit/ba6d671d2ff21848fe9397aa95fffe6de55cf051))
* brought the changes asked in the review ([6170bba](https://github.com/LazyKeru/SmellsFishy/commit/6170bba690d7c3afeadc40234949b202d9af5fe3))
* ci will now work on github, as path was replaced by relative path ([155ca20](https://github.com/LazyKeru/SmellsFishy/commit/155ca20bd3f1db3c89bd1c34e88f99a43cdd2eeb))
* deleted the wrong main ([4b061ef](https://github.com/LazyKeru/SmellsFishy/commit/4b061efdadd32838c4929503ca2fa602afe4edaa))
* fixed merge conflict ([67f1092](https://github.com/LazyKeru/SmellsFishy/commit/67f10922cb4519549619616022f78bbd9e167796))
* fixed merge conflict between main and feat-dir-search ([996bb65](https://github.com/LazyKeru/SmellsFishy/commit/996bb65f75d50c8fc292b1add7a8f3f2c74ee995))
* fixed the core problem ([1a7ab05](https://github.com/LazyKeru/SmellsFishy/commit/1a7ab05860b9e0803a733097939dd956fb00392a))
* gitignore ignores vs and vscode folders ([ef3a1ce](https://github.com/LazyKeru/SmellsFishy/commit/ef3a1ceefef78c57ff308471e5c577e66ea2366c))
* make breakpoints work and setting c++ standard to c++17 ([8ab0943](https://github.com/LazyKeru/SmellsFishy/commit/8ab0943726d6b917730ecc74b400c98d611514bd))
* makefile now shouldn't have any more double slash ([9c468e3](https://github.com/LazyKeru/SmellsFishy/commit/9c468e370c98127cbc189719bfb497187a194f35))
* relative paths ([25c0e63](https://github.com/LazyKeru/SmellsFishy/commit/25c0e63053f8eb8b52989d2c57ef2a836e0fa0da))
* removed unwanted file ([7a5bb3b](https://github.com/LazyKeru/SmellsFishy/commit/7a5bb3bab9a064ddbb9bb222c92a52e18890fddd))
* renamed a file, and changed the custom assert cuntion ([847feab](https://github.com/LazyKeru/SmellsFishy/commit/847feab34013371e1bb5c1d0bd244724a14fb329))
* renamed most variable which caused warnings, or even errors when building ([476461c](https://github.com/LazyKeru/SmellsFishy/commit/476461c617c52c3f37d8c14a12e3e9d112895f09))
* renamed some files, and cleaned the directory organisation ([b8c0667](https://github.com/LazyKeru/SmellsFishy/commit/b8c06678d4fa7009fbfb62b5dbdd9d3e4a0e939c))
* renamed the libraries in entropy.hpp ([dc137ae](https://github.com/LazyKeru/SmellsFishy/commit/dc137ae63f13ec225e76f497b6c3f42fa93a5472))
* reverted gitgnore ([8a30c0a](https://github.com/LazyKeru/SmellsFishy/commit/8a30c0a3fa938b6ea0cc394303d6604e33734b7f))
* test ([55fc1b9](https://github.com/LazyKeru/SmellsFishy/commit/55fc1b90a8c12bdfb4dae32c86a8ffceae03dd86))
* test for struct is now working ([55bc95e](https://github.com/LazyKeru/SmellsFishy/commit/55bc95e6086cacf3ef4924e6e2adb7887afebd3f))
* the main is now correctly built ([1fb7959](https://github.com/LazyKeru/SmellsFishy/commit/1fb7959261de72996f74a7106505712a36af3527))


### Features

* 1st demo is now ready ([4ae0c9d](https://github.com/LazyKeru/SmellsFishy/commit/4ae0c9dcd01fad0070212726b73b43597f2e2374))
* added a log function ([e8abb40](https://github.com/LazyKeru/SmellsFishy/commit/e8abb40d319f1dac07d9419d5125b5334c94bb40))
* added argument structure ([28fc0bd](https://github.com/LazyKeru/SmellsFishy/commit/28fc0bdcf79c3546683e9889c4a763487ff6ac10))
* added core ([a12e762](https://github.com/LazyKeru/SmellsFishy/commit/a12e7625db13487e25dbfb1dca1c3d4fc845315d))
* added entropy check in the core ([eff0f1d](https://github.com/LazyKeru/SmellsFishy/commit/eff0f1db090123232291e9ba6447832a79f9ff8f))
* added json loading fonctionnalities ([2e42ee0](https://github.com/LazyKeru/SmellsFishy/commit/2e42ee07563f020eca18caba8cfd4413e2f33e26))
* added more secrets ([d085a15](https://github.com/LazyKeru/SmellsFishy/commit/d085a151bed3188cbaf7f5ca5ca3388149a4f8ec))
* added secret and rule structure ([8bd7226](https://github.com/LazyKeru/SmellsFishy/commit/8bd722696c2d8c9a32fa1d56d13a4fb98b1117b8))
* added the entropy argument, to analyze with entropy ([c714144](https://github.com/LazyKeru/SmellsFishy/commit/c714144fda49406c0c51858882b1cf39647c2fbd))
* added the entropy calculator function ([f05276d](https://github.com/LazyKeru/SmellsFishy/commit/f05276d445d2918a1af7d95dc9ae16181d0bc474))
* added the option to output the log in a txt folder ([aadf66b](https://github.com/LazyKeru/SmellsFishy/commit/aadf66bd2e0edf939d6e405f5f938b8083c8e3bc))
* added the secretsPerFile struct and it's basic functions ([8695fe3](https://github.com/LazyKeru/SmellsFishy/commit/8695fe3416c1e64800f43ab8ed30847e354bd297))
* command line argument parser ([60c4cfc](https://github.com/LazyKeru/SmellsFishy/commit/60c4cfc85ebbf4506b8b72fa723f862976c59e71))
* core module ([38aa553](https://github.com/LazyKeru/SmellsFishy/commit/38aa55368239d545a00f8a8a1072ed8816136f57))
* core module ([b266a0f](https://github.com/LazyKeru/SmellsFishy/commit/b266a0fd7d25d155724be012a63a6041b5edda18))
* directory search for all files ([c6c3692](https://github.com/LazyKeru/SmellsFishy/commit/c6c3692fe3d4802af7bf6c74f686a3e911595ac7))
* function to check if it's a json file ([3d1b162](https://github.com/LazyKeru/SmellsFishy/commit/3d1b162327decc98e5911792de5712330faccd80))
* impl regex ([cc6a407](https://github.com/LazyKeru/SmellsFishy/commit/cc6a40774d61de5c488fa7dd27b3015293a56b23))
* json loading and finding in core ([1357f5b](https://github.com/LazyKeru/SmellsFishy/commit/1357f5bb638c3d3cb871b5f6f197796c97381473))
* load all json rules at once in core (not working) ([c1b977e](https://github.com/LazyKeru/SmellsFishy/commit/c1b977e43629ac4510006cecc89de5b586a8d2a6))
* started log_output ([d384982](https://github.com/LazyKeru/SmellsFishy/commit/d384982f2c0c8d328af9e6a99a3034bfe7419cf3))
* test function added ([85d5db3](https://github.com/LazyKeru/SmellsFishy/commit/85d5db35ef854b3f627bfd9454f213934f72a229))
* there is now an entropy check ([4141ea0](https://github.com/LazyKeru/SmellsFishy/commit/4141ea042c2587d4d84ea9fe9a4b37df9ec909c1))


### Performance Improvements

* regex improvements ([2f4d088](https://github.com/LazyKeru/SmellsFishy/commit/2f4d0889ff15180fb6aaef3579a5a65af5535811))
* the Makefile clean, now cleans all the exe and o files in the build and bin folder ([7177314](https://github.com/LazyKeru/SmellsFishy/commit/71773145a7369279c52652c2c21cde848cde3e34))
