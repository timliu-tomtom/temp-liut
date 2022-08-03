#!/bin/bash

#language="zh-TW"
#type=""

#echo "po: ${po_file}"
#echo "type: ${type}"

for language in "zh-TW" "ja-JP" "ko-KR"
do
  for type in "turn" "roundabout" "exit"
  do
    ./voice_message_dumper -i "$type" --po ~/TT/repo/nk2/text-generation-temp/navigation-text-generation/src/po_files/HCP3/"$language".po &> ../../"$language"_"$type"_old.txt

    ./voice_message_dumper -i "$type" --po ~/TT/repo/nk2/nk2-navigation-text-generation/navigation-text-generation/src/po_files/HCP3/"$language".po &> ../../"$language"_"$type"_new.txt
    diff ../../"$language"_"$type"_old.txt ../../"$language"_"$type"_new.txt > "$language"_"$type"_diff.txt
    ls -l "$language"_"$type"_diff.txt
  done
done
