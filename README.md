# ridiculous-leetcode-question


### Ord Alphlong
Write a function that takes a string as a parameter and returns its words sorted
in order of their length first and then in alphabetical order on each line:
when we say alphabetical order we ignore the case of letters.

For example aA and Aa are the same but the original order must remain
(lower and upper case are the same in alphabetical order). If there are
duplicates, they must remain.

There will be only spaces, tabs and alphanumeric caracters in strings.

You'll have only one space between same size words and ^ otherwise.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

Example 00:

> Input: "After all this time Always said Snape"
> Output: "all^said this time^After Snape^Always"

Example 01:

> Input: "A a b B cc ca cd"
> Output: "A a b B^ca cc cd"

Example 02:

> Input "Never take a gamble you are not prepared to lose"
> Output: "a^to^are not you^lose take^Never^gamble^prepared"

Example 03:

Input ""
Output: ""
