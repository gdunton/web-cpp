#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "web.hpp"

Web::Div createNameList(const std::vector<std::string>& names)
{
	std::vector<Web::P> paragraphs;

	std::transform(names.begin(), names.end(), std::back_inserter(paragraphs),
		[](const std::string& name)
	{
		return Web::P{ name };
	});

	return Web::Div{ std::move(paragraphs) };
}

int main()
{
	auto para = Web::P{ "hello" };
	std::cout << para << "\n";

	auto div = Web::Div{
		Web::P { "Hello World" }
	};
	std::cout << div << "\n";

	auto doc1 = Web::Html {
		Web::Body {
			Web::H1{ "This is our title" },
			Web::Br{},
			Web::P { "Hello World" },
			createNameList({"John", "Jane", "Eric"})
		}
	};
	std::cout << doc1 << "\n";

	auto d = Web::Div{
		Web::Attr {
			Web::Class{ "center" },
			//Web::Class{ "thingy" }, // This will not compile if uncommented
			Web::Id{ "single" }
		}
	};

	std::cout << d << "\n";

	std::cout << "Press enter to close";
	std::cin.get();
	return 0;
}
