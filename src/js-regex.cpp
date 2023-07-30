#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

std::string js_regex(std::string js)
{
    std::string pattern = "\"answer_text\":\"[A-C]\"(.*?)\"question_score\"";
    std::string patterns = "\"[A-C]\"";
    std::regex reg(pattern);
    std::regex regs(patterns);
    std::smatch match, ans, wer;
    std::string match_str[20];
    auto begin = std::sregex_iterator(js.begin(), js.end(), reg);
    auto end = std::sregex_iterator();
    int j = 0;
    for (std::sregex_iterator i = begin; i != end; ++i, j++)
    {
        match = *i;
        match_str[j] = match.str();
    }
    std::string out_answer;
    for (int i = 0; i < 20; i++)
    {
        std::regex_search(match_str[i], ans, regs);
        std::string patternA = "\"id\":" + ans.str() + ",\"content\":\"(.*?)\"";
        std::regex answer(patternA);
        std::regex_search(match_str[i], wer, answer);
        i++;
        out_answer += "第" + std::to_string(i) + "题：" + wer[1].str() + "\n";
        i--;
    }
    return out_answer;
}