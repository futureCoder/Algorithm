#!/bin/bash

nowtime=$(date "+%Y-%m-%d %H:%M:%S")

git add .
commit_msg="sync at $nowtime in $(hostname)"
git commit -m "$commit_msg"
git push origin master