#!/bin/bash -ex
sha1sum $1 | cut -d ' ' -f 1 > $1.sha1
mv $1 `cat $1.sha1`
git rm $1
git add $1.sha1
