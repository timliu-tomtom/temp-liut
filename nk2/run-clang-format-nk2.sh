#!/bin/bash

FormatFile() {
    #/usr/bin/clang-format-7 -style=file -i $1
    /usr/local/pkg/bin/clang-format-7 -style=file -i $1
}

#for file in $(git diff-index --name-only HEAD *.h *.hpp *.cpp *.proto *.java); do
#    echo "$file"
#    FormatFile "$file"
#done

#for file in $(git ls-files . --exclude-standard --others | grep -E \\.\(h\|hpp\|cpp\|proto\|java\)\$); do
#    echo "$file"
#    FormatFile "$file"
#done

for file in $(find $1 -type f | grep -E \\.\(h\|hpp\|cpp\|proto\|java\)\$); do
    echo "$file"
    FormatFile "$file"
done
