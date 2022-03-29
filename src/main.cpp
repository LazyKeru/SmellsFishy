// #include "../header/util/argument.hpp"
// #include "../header/util/line_parser.hpp"
// #include "../header/files/readDir.hpp"
// #include "../header/core/core.hpp"
// #include "../header/files/json.hpp"
// #include "../header/struct/rule.hpp"
// #include "../header/struct/secretsPerFile.hpp"
// #include "../header/core/core.hpp"
// #include <fstream>
// #include <vector>
// #include <iostream>
#include "../header/core/core.hpp"


// const int HELP_I = 0;
// const int DIR_I = 1;
// const int RULES_I = 2;
// static std::vector<Argument> _Arguments = {
//     {
//         false,
//         (std::string) "--help",
//         (std::string) "-h"
//     },
//     {
//         true,
//         (std::string) "--dir",
//         (std::string) "-d"
//     },
//     {
//         true,
//         (std::string) "--rules",
//         (std::string) "-r"
//     }
// };



// int main(int argc, char *argv[])
// {
//     Line_parser::check_arguments(&_Arguments, argv, argc);
//     if(!Line_parser::ammountArguments(&_Arguments,argc)){
//         // Not enough or too much arguments
//         Core::warning();
//         Core::help();
//         return 0;
//     }
//     if(_Arguments[HELP_I].defined){
//         // Will call the help function
//         Core::help();
//         return 0;
//     }
//     if(!_Arguments[DIR_I].defined){
//         // Missing arg error
//         Core::warning();
//         Core::help();
//         return 0;
//     }
//     if(!_Arguments[RULES_I].defined){
//         // Missing arg error
//         Core::warning();
//         Core::help();
//         return 0;
//     }
//     if(!Files::isDir(_Arguments[DIR_I].value)){
//         // Missing arg error
//         Core::warning();
//         Core::help();
//         return 0;
//     }
//     /** NEED TO ADD A CHECK FOR JSON EXTENSION **/
//     // if(!Files::isDir(_Arguments[RULES_I].value)){
//     //     // Missing arg error
//     //     Core::warning();
//     //     Core::help();
//     //     return;
//     // }
//     if(_Arguments[DIR_I].defined && _Arguments[RULES_I].defined){
//         /** FOR THE LOG **/
//         std::string outFile("log.txt");
//         std::ofstream out(outFile);
//         /** ASSIGNING THE ARGS **/
//         std::string rules = _Arguments[RULES_I].value;
//         std::string dir = _Arguments[DIR_I].value;
//         /** EXECUTING THE *future* FUNCTION **/
//         JSON json(rules);
//         Core::addPath(dir);
//         Core::addRule(Rule::getRuleSharedPtr(json.getRuleFromDescription("GitHub OAuth Access Token")));
//         auto secrets(Core::getAllSecrets());
//         if (secrets.size() == 0)
//         {
//             std::cout << "No secrets found!\n";
//             return 0;
//         }
//         for (const auto &scts : secrets)
//         {
//             out << "\n\n\t\tTESTING FILE " << scts.file_path << "\n\n";
//             for (const auto &sct : scts)
//                 out << sct.rulePtr->description << "\t" << sct.matchedRegex << "\t" << sct.lineNumber << '\n' ;
//         }
//         return 0;
//     }
//     return 0;
// }

int main(int argc, char *argv[])
{
    Core::arg(argc, argv);
    return 0;
}

