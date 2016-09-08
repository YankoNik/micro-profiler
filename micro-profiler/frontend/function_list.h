//	Copyright (c) 2011-2015 by Artem A. Gevorkyan (gevorkyan.org) and Denis Burenko
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.

#pragma once

#include <wpl/ui/listview.h>
#include <string>
#include <memory>

namespace std
{
	using std::tr1::shared_ptr;
}

typedef struct FunctionStatisticsDetailedTag FunctionStatisticsDetailed;

namespace micro_profiler
{
	struct function_history;
	struct symbol_resolver;

	struct linked_statistics : wpl::ui::listview::model
	{
		virtual const void *get_address(index_type item) const = 0;
	};

	struct functions_list : wpl::ui::listview::model
	{
		virtual void clear() = 0;
		virtual void update(const FunctionStatisticsDetailed *data, size_t count) = 0;
		virtual void print(std::wstring &content) const = 0;
		virtual index_type get_index(const void *address) const = 0;
		virtual std::shared_ptr<linked_statistics> watch_children(index_type item) const = 0;
		virtual std::shared_ptr<linked_statistics> watch_parents(index_type item) const = 0;
		virtual std::shared_ptr<function_history> get_history(index_type item) const = 0;

		static std::shared_ptr<functions_list> create(__int64 ticks_resolution, std::shared_ptr<symbol_resolver> resolver);
	};
}
