#include "MyUtility.h"

//获取时间
string MyUtility::getCurrentTime()
{
	time_t t;
	time(&t);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %X", localtime((&t)));
	string timeStr = tmp;
	return timeStr;
}

//在win32下，把GBK转化为UTF-8
string MyUtility::gbk_2_utf_8(const string text)
{
	return text;
}

// 从文件按照键读取UTF-8字符串
string MyUtility::getUTF8Char(const string key)
{
	auto sharedFileUtils = FileUtils::getInstance();

	std::string fullPathForFilename = sharedFileUtils->fullPathForFilename("utf8_char.plist");

	bool isExist = false;
	isExist = sharedFileUtils->isFileExist(fullPathForFilename);
	if (!isExist) {
		log("utf8_char.plist doesn't exist.");
		return "";
	}

	ValueMap map = sharedFileUtils->getValueMapFromFile(fullPathForFilename);
	Value value = map[key];

	if (value.isNull()) {
		log("%s doesn't exist.", key.c_str());
		return "";
	}
	return value.asString();
}