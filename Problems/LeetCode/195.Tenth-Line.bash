# https://leetcode.com/problems/tenth-line/

# Read from the file file.txt and output the tenth line to stdout.
# [[ $(wc -l file.txt | awk '{print $1}') -ge 10 ]] && (head file.txt -n10 | tail -n1)
awk 'FNR == 10' file.txt
