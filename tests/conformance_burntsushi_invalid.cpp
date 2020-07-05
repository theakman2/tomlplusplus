// This file is a part of toml++ and is subject to the the terms of the MIT license.
// Copyright (c) 2019-2020 Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/tomlplusplus/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT
//-----
// this file was generated by generate_conformance_tests.py - do not modify it directly

#include "tests.h"
using namespace toml::impl;

TOML_PUSH_WARNINGS
TOML_DISABLE_ALL_WARNINGS // unused variable spam

namespace
{
	static constexpr auto datetime_malformed_no_leads = R"(no-leads = 1987-7-05T17:45:00Z)"sv;
	static constexpr auto datetime_malformed_no_secs = R"(no-secs = 1987-07-05T17:45Z)"sv;
	static constexpr auto datetime_malformed_no_t = R"(no-t = 1987-07-0517:45:00Z)"sv;
	static constexpr auto datetime_malformed_with_milli = R"(with-milli = 1987-07-5T17:45:00.12Z)"sv;
	static constexpr auto duplicate_key_table = R"([fruit]
type = "apple"

[fruit.type]
apple = "yes")"sv;
	static constexpr auto duplicate_keys = R"(dupe = false
dupe = true)"sv;
	static constexpr auto duplicate_tables = R"([a]
[a])"sv;
	static constexpr auto empty_implicit_table = R"([naughty..naughty])"sv;
	static constexpr auto empty_table = R"([])"sv;
	static constexpr auto float_leading_zero_neg = R"(leading-zero = -03.14)"sv;
	static constexpr auto float_leading_zero_pos = R"(leading-zero = +03.14)"sv;
	static constexpr auto float_leading_zero = R"(leading-zero = 03.14)"sv;
	static constexpr auto float_no_leading_zero = R"(answer = .12345
neganswer = -.12345)"sv;
	static constexpr auto float_no_trailing_digits = R"(answer = 1.
neganswer = -1.)"sv;
	static constexpr auto float_underscore_after_point = R"(bad = 1._2)"sv;
	static constexpr auto float_underscore_after = R"(bad = 1.2_)"sv;
	static constexpr auto float_underscore_before_point = R"(bad = 1_.2)"sv;
	static constexpr auto float_underscore_before = R"(bad = _1.2)"sv;
	static constexpr auto inline_table_linebreak = R"(simple = { a = 1 
})"sv;
	static constexpr auto integer_leading_zero_neg = R"(leading-zero = -012)"sv;
	static constexpr auto integer_leading_zero_pos = R"(leading-zero = +012)"sv;
	static constexpr auto integer_leading_zero = R"(leading-zero = 012)"sv;
	static constexpr auto integer_underscore_after = R"(bad = 123_)"sv;
	static constexpr auto integer_underscore_before = R"(bad = _123)"sv;
	static constexpr auto integer_underscore_double = R"(bad = 1__23)"sv;
	static constexpr auto key_after_array = R"([[agencies]] owner = "S Cjelli")"sv;
	static constexpr auto key_after_table = R"([error] this = "should not be here")"sv;
	static constexpr auto key_empty = R"(= 1)"sv;
	static constexpr auto key_hash = R"(a# = 1)"sv;
	static constexpr auto key_newline = R"(a
= 1)"sv;
	static constexpr auto key_no_eol = R"(a = 1 b = 2)"sv;
	static constexpr auto key_open_bracket = R"([abc = 1)"sv;
	static constexpr auto key_single_open_bracket = R"([)"sv;
	static constexpr auto key_space = R"(a b = 1)"sv;
	static constexpr auto key_start_bracket = R"([a]
[xyz = 5
[b])"sv;
	static constexpr auto key_two_equals = R"(key= = 1)"sv;
	static constexpr auto llbrace = R"([ [table]])"sv;
	static constexpr auto multi_line_inline_table = R"(json_like = {
          first = "Tom",
          last = "Preston-Werner"
})"sv;
	static constexpr auto multi_line_string_no_close = R"(invalid = """
    this will fail)"sv;
	static constexpr auto rrbrace = R"([[table] ])"sv;
	static constexpr auto string_bad_byte_escape = R"(naughty = "\xAg")"sv;
	static constexpr auto string_bad_codepoint = R"(invalid-codepoint = "This string contains a non scalar unicode codepoint \uD801")"sv;
	static constexpr auto string_bad_escape = R"(invalid-escape = "This string has a bad \a escape character.")"sv;
	static constexpr auto string_bad_slash_escape = R"(invalid-escape = "This string has a bad \/ escape character.")"sv;
	static constexpr auto string_bad_uni_esc = R"(str = "val\ue")"sv;
	static constexpr auto string_byte_escapes = R"(answer = "\x33")"sv;
	static constexpr auto string_no_close = R"(no-ending-quote = "One time, at band camp)"sv;
	static constexpr auto table_array_implicit = R"(# This test is a bit tricky. It should fail because the first use of
# `[[albums.songs]]` without first declaring `albums` implies that `albums`
# must be a table. The alternative would be quite weird. Namely, it wouldn't
# comply with the TOML spec: "Each double-bracketed sub-table will belong to 
# the most *recently* defined table element *above* it."
#
# This is in contrast to the *valid* test, table-array-implicit where
# `[[albums.songs]]` works by itself, so long as `[[albums]]` isn't declared
# later. (Although, `[albums]` could be.)
[[albums.songs]]
name = "Glory Days"

[[albums]]
name = "Born in the USA")"sv;
	static constexpr auto table_array_malformed_bracket = R"([[albums]
name = "Born to Run")"sv;
	static constexpr auto table_array_malformed_empty = R"([[]]
name = "Born to Run")"sv;
	static constexpr auto table_empty = R"([])"sv;
	static constexpr auto table_nested_brackets_close = R"([a]b]
zyx = 42)"sv;
	static constexpr auto table_nested_brackets_open = R"([a[b]
zyx = 42)"sv;
	static constexpr auto table_whitespace = R"([invalid key])"sv;
	static constexpr auto table_with_pound = R"([key#group]
answer = 42)"sv;
	static constexpr auto text_after_array_entries = R"(array = [
  "Is there life after an array separator?", No
  "Entry"
])"sv;
	static constexpr auto text_after_integer = R"(answer = 42 the ultimate answer?)"sv;
	static constexpr auto text_after_string = R"(string = "Is there life after strings?" No.)"sv;
	static constexpr auto text_after_table = R"([error] this shouldn't be here)"sv;
	static constexpr auto text_before_array_separator = R"(array = [
  "Is there life before an array separator?" No,
  "Entry"
])"sv;
	static constexpr auto text_in_array = R"(array = [
  "Entry 1",
  I don't belong,
  "Entry 2",
])"sv;
}

TOML_POP_WARNINGS

TEST_CASE("conformance - burntsushi/invalid")
{
	parsing_should_fail(FILE_LINE_ARGS, datetime_malformed_no_leads);
	parsing_should_fail(FILE_LINE_ARGS, datetime_malformed_no_t);
	parsing_should_fail(FILE_LINE_ARGS, datetime_malformed_with_milli);
	parsing_should_fail(FILE_LINE_ARGS, duplicate_key_table);
	parsing_should_fail(FILE_LINE_ARGS, duplicate_keys);
	parsing_should_fail(FILE_LINE_ARGS, duplicate_tables);
	parsing_should_fail(FILE_LINE_ARGS, empty_implicit_table);
	parsing_should_fail(FILE_LINE_ARGS, empty_table);
	parsing_should_fail(FILE_LINE_ARGS, float_leading_zero_neg);
	parsing_should_fail(FILE_LINE_ARGS, float_leading_zero_pos);
	parsing_should_fail(FILE_LINE_ARGS, float_leading_zero);
	parsing_should_fail(FILE_LINE_ARGS, float_no_leading_zero);
	parsing_should_fail(FILE_LINE_ARGS, float_no_trailing_digits);
	parsing_should_fail(FILE_LINE_ARGS, float_underscore_after_point);
	parsing_should_fail(FILE_LINE_ARGS, float_underscore_after);
	parsing_should_fail(FILE_LINE_ARGS, float_underscore_before_point);
	parsing_should_fail(FILE_LINE_ARGS, float_underscore_before);
	parsing_should_fail(FILE_LINE_ARGS, integer_leading_zero_neg);
	parsing_should_fail(FILE_LINE_ARGS, integer_leading_zero_pos);
	parsing_should_fail(FILE_LINE_ARGS, integer_leading_zero);
	parsing_should_fail(FILE_LINE_ARGS, integer_underscore_after);
	parsing_should_fail(FILE_LINE_ARGS, integer_underscore_before);
	parsing_should_fail(FILE_LINE_ARGS, integer_underscore_double);
	parsing_should_fail(FILE_LINE_ARGS, key_after_array);
	parsing_should_fail(FILE_LINE_ARGS, key_after_table);
	parsing_should_fail(FILE_LINE_ARGS, key_empty);
	parsing_should_fail(FILE_LINE_ARGS, key_hash);
	parsing_should_fail(FILE_LINE_ARGS, key_newline);
	parsing_should_fail(FILE_LINE_ARGS, key_no_eol);
	parsing_should_fail(FILE_LINE_ARGS, key_open_bracket);
	parsing_should_fail(FILE_LINE_ARGS, key_single_open_bracket);
	parsing_should_fail(FILE_LINE_ARGS, key_space);
	parsing_should_fail(FILE_LINE_ARGS, key_start_bracket);
	parsing_should_fail(FILE_LINE_ARGS, key_two_equals);
	parsing_should_fail(FILE_LINE_ARGS, llbrace);
	parsing_should_fail(FILE_LINE_ARGS, multi_line_string_no_close);
	parsing_should_fail(FILE_LINE_ARGS, rrbrace);
	parsing_should_fail(FILE_LINE_ARGS, string_bad_byte_escape);
	parsing_should_fail(FILE_LINE_ARGS, string_bad_codepoint);
	parsing_should_fail(FILE_LINE_ARGS, string_bad_escape);
	parsing_should_fail(FILE_LINE_ARGS, string_bad_slash_escape);
	parsing_should_fail(FILE_LINE_ARGS, string_bad_uni_esc);
	parsing_should_fail(FILE_LINE_ARGS, string_no_close);
	parsing_should_fail(FILE_LINE_ARGS, table_array_implicit);
	parsing_should_fail(FILE_LINE_ARGS, table_array_malformed_bracket);
	parsing_should_fail(FILE_LINE_ARGS, table_array_malformed_empty);
	parsing_should_fail(FILE_LINE_ARGS, table_empty);
	parsing_should_fail(FILE_LINE_ARGS, table_nested_brackets_close);
	parsing_should_fail(FILE_LINE_ARGS, table_nested_brackets_open);
	parsing_should_fail(FILE_LINE_ARGS, table_whitespace);
	parsing_should_fail(FILE_LINE_ARGS, table_with_pound);
	parsing_should_fail(FILE_LINE_ARGS, text_after_array_entries);
	parsing_should_fail(FILE_LINE_ARGS, text_after_integer);
	parsing_should_fail(FILE_LINE_ARGS, text_after_string);
	parsing_should_fail(FILE_LINE_ARGS, text_after_table);
	parsing_should_fail(FILE_LINE_ARGS, text_before_array_separator);
	parsing_should_fail(FILE_LINE_ARGS, text_in_array);

	#if !TOML_LANG_UNRELEASED
	parsing_should_fail(FILE_LINE_ARGS, datetime_malformed_no_secs);
	parsing_should_fail(FILE_LINE_ARGS, inline_table_linebreak);
	parsing_should_fail(FILE_LINE_ARGS, multi_line_inline_table);
	parsing_should_fail(FILE_LINE_ARGS, string_byte_escapes);
	#endif // !TOML_LANG_UNRELEASED
}

