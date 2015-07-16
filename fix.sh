#!/bin/sh
 
git filter-branch --env-filter '

OLD_EMAIL="thomas.kekeisen@socialbit.de"
CORRECT_NAME="Thomas Kekeisen"
CORRECT_EMAIL="thomas@thomaskekeisen.de"

if [ "$GIT_COMMITTER_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags