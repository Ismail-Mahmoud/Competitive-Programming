# https://leetcode.com/problems/word-frequency/

# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | awk 'BEGIN{OFS="\n"} {$1=$1; print}' | sort | uniq -c | sort -r | awk '{print $2, $1}'