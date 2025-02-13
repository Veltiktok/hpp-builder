#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <unistd.h>
#ifndef TEMPLATE_DIR
# define TEMPLATE_DIR		"."
#endif
#define TEMPLATE_NAME		"hpptemplate.hpp"
#define CLASS_NAME			"className"
#define INCLUDE_GUARD_NAME	"CLASSNAME"
#define	PATH_SIZE			4096

static std::string	load_template()
{
	std::ifstream		file;
	std::ostringstream	text;
	std::string			templatePath;

	templatePath = TEMPLATE_DIR;
	templatePath += '/';
	templatePath += TEMPLATE_NAME;
	file.open(templatePath.c_str(), std::ifstream::in);
	if (!file.good())
	{
		std::cerr << "hppbuild: missing " << templatePath << " file" << std::endl;
		return ("");
	}
	text << file.rdbuf();
	file.close();
	return (text.str());
}

static void	replace_className(	std::string &hppTemplate, std::string newClassName,
								const char *toReplace)
{
	size_t	i;

	i = 0;
	i = hppTemplate.find(toReplace);
	while (i != hppTemplate.npos)
	{
		hppTemplate.replace(i, std::strlen(toReplace), newClassName);
		i = hppTemplate.find(toReplace, i + 1);
	}
}

static void	build_hpp(std::string hppTemplate, std::string newClassName)
{
	char			path[PATH_SIZE];
	std::string		newFileName;
	std::ofstream	newFile;

	if (!getcwd(path, PATH_SIZE))
	{
		std::cerr << "hppbuild: error getting current working directory" << std::endl;
		return ;
	}
	newFileName = path;
	newFileName += '/';
	newFileName += newClassName;
	newFileName += ".hpp";
	newFile.open(newFileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!newFile.good())
	{
		std::cerr << "hppbuild: error creating " << newFileName << std::endl;
		return ;
	}
	newFile << hppTemplate;
	newFile.close();
}

static std::string	str_toupper(std::string str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	std::string	hppTemplate;
	std::string	newClassName;
	std::string	newIncludeGuardName;

	if (argc != 2) {std::cerr << "Usage: hppbuild <className>" << std::endl; return (1);}
	newClassName = argv[1];
	newIncludeGuardName = str_toupper(newClassName);
	hppTemplate = load_template();
	if (hppTemplate.empty()) {return (1);}
	replace_className(hppTemplate, newClassName, CLASS_NAME);
	replace_className(hppTemplate, newIncludeGuardName, INCLUDE_GUARD_NAME);
	build_hpp(hppTemplate, newClassName);
}
