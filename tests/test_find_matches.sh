#!/usr/bin/env bash

ROOT=$(dirname $0)/..

echo banana | $ROOT/progs/find_matches na
echo
echo
# 2
# 4

echo banana | $ROOT/progs/find_matches an
echo
echo
# 1
# 3

echo AABAACAADAABAABA | $ROOT/progs/find_matches AABA
echo
echo
# 0
# 9
# 12

echo AAAAABAAABA | $ROOT/progs/find_matches AAAA
echo
echo
# 0
# 1

echo ABABDABACDABABCABAB | $ROOT/progs/find_matches ABABCABAB
echo
echo
# 10